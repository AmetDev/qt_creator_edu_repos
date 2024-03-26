#include "formtable.h"
#include "ui_formtable.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QPushButton>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QLabel>
#include <QDateEdit>
#include <QComboBox>
#include <QTableView>
#include <globalpath.h>
#include <QMessageBox>
#include <QSqlError>
#include <QDebug>
#include <QSqlTableModel>

FormTable::FormTable(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::FormTable)
{
    ui->setupUi(this);
    connectToDB();
}

void FormTable::connectToDB() {
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(globalPath::getDatabasePath());
    if (!db.open()) {
        QMessageBox::critical(this, "Error", "Error opening database: " + db.lastError().text());
        return;
    }

    QSqlQuery query("SELECT name FROM sqlite_master WHERE type='table'");
    while (query.next()) {
        QString tableName = query.value(0).toString();
        if (tableName != "users" && tableName != "sqlite_sequence") { // Exclude the 'users' table and 'sqlite_sequence' table
            QPushButton *button = new QPushButton(tableName);
            ui->verticalLayout->addWidget(button); // Assuming you have a QVBoxLayout named verticalLayout in your form
            connect(button, &QPushButton::clicked, this, [this, tableName]() {
                updateTableView(tableName);
            });
        }
    }
}
void FormTable::updateTableView(const QString& tableName) {
    QSqlQuery query;
    query.exec("SELECT * FROM " + tableName);
    QSqlRecord record = query.record();

    // Update input fields
    QVBoxLayout *layout = new QVBoxLayout();
    QList<QWidget*> inputWidgets; // Store input widgets to access them later
    for (int i = 0; i < record.count(); ++i) {
        QString fieldName = record.fieldName(i);
        if (fieldName.startsWith("id"))
            continue; // Skip fields starting with 'id'
        QLabel *label = new QLabel(fieldName);
        layout->addWidget(label);

        QWidget *widget = nullptr;
        if (fieldName.startsWith("data")) {
            QDateEdit *dateEdit = new QDateEdit();
            widget = dateEdit;
        } else if (fieldName.contains("combox")) {
            QComboBox *comboBox = new QComboBox();
            // Execute SQL query to populate comboBox
            QString queryText = "SELECT DISTINCT " + fieldName + " FROM " + tableName;
            QSqlQuery comboQuery(queryText);
            while (comboQuery.next()) {
                QString value = comboQuery.value(0).toString();
                comboBox->addItem(value);
            }
            widget = comboBox;
        } else {
            QLineEdit *lineEdit = new QLineEdit();
            widget = lineEdit;
        }

        layout->addWidget(widget);
        inputWidgets.append(widget); // Store the widget
    }

    // Clear previous input layout and create a new inputWidget
    QWidget *inputWidget = new QWidget();
    inputWidget->setLayout(layout);

    // Remove previous inputWidget from the main input layout
    QLayoutItem *item;
    while ((item = ui->verticalLayout_2->takeAt(0)) != nullptr) {
        delete item->widget();
        delete item;
    }

    // Add the new inputWidget to the main input layout
    ui->verticalLayout_2->addWidget(inputWidget);

    // Add a QPushButton to submit data
    QPushButton *submitButton = new QPushButton("Add Data");
    ui->verticalLayout_2->addWidget(submitButton);

    // Connect the button to a slot that will handle adding data
    connect(submitButton, &QPushButton::clicked, this, [this, inputWidgets, tableName]() {
        addData(inputWidgets, tableName);
    });

    // Update table view
    QSqlTableModel *model = new QSqlTableModel(this);
    model->setTable(tableName);
    model->select();
    ui->tableView->setModel(model); // Assuming you have a QTableView named tableView in your form
}
void FormTable::addData(const QList<QWidget*>& inputWidgets, const QString& tableName) {
    // Check the database connection
    QSqlDatabase db = QSqlDatabase::database();
    if (!db.isValid()) {
        QMessageBox::critical(this, "Error", "Database connection is invalid.");
        return;
    }

    // Prepare the INSERT query
    QStringList fieldNames;
    QStringList placeholders;
    for (QWidget *widget : inputWidgets) {
        if (QLineEdit *lineEdit = qobject_cast<QLineEdit*>(widget)) {
            fieldNames << lineEdit->objectName(); // Assuming objectName is set to the field name
            placeholders << ":" + lineEdit->objectName();
            qDebug() << "LineEdit: " << lineEdit->objectName() << " Value: " << lineEdit->text();
        } else if (QComboBox *comboBox = qobject_cast<QComboBox*>(widget)) {
            fieldNames << comboBox->objectName();
            placeholders << ":" + comboBox->objectName();
            qDebug() << "ComboBox: " << comboBox->objectName() << " Value: " << comboBox->currentText();
        } else if (QDateEdit *dateEdit = qobject_cast<QDateEdit*>(widget)) {
            fieldNames << dateEdit->objectName();
            placeholders << ":" + dateEdit->objectName();
            qDebug() << "DateEdit: " << dateEdit->objectName() << " Value: " << dateEdit->date().toString(Qt::ISODate);
        }
    }
    QString fieldsStr = fieldNames.join(", ");
    QString placeholdersStr = placeholders.join(", ");

    QString queryString = "INSERT INTO " + tableName + " (" + fieldsStr + ") VALUES (" + placeholdersStr + ")";
    qDebug() << "Query: " << queryString;

    QSqlQuery query(db);
    query.prepare(queryString);

    // Bind values to placeholders
    for (QWidget *widget : inputWidgets) {
        if (QLineEdit *lineEdit = qobject_cast<QLineEdit*>(widget)) {
            query.bindValue(":" + lineEdit->objectName(), lineEdit->text());
        } else if (QComboBox *comboBox = qobject_cast<QComboBox*>(widget)) {
            query.bindValue(":" + comboBox->objectName(), comboBox->currentText());
        } else if (QDateEdit *dateEdit = qobject_cast<QDateEdit*>(widget)) {
            query.bindValue(":" + dateEdit->objectName(), dateEdit->date().toString(Qt::ISODate));
        }
    }

    // Execute the query
    if (!query.exec()) {
        QMessageBox::critical(this, "Error", "Error adding data: " + query.lastError().text());
    } else {
        QMessageBox::information(this, "Success", "Data added successfully!");
    }
}


FormTable::~FormTable()
{
    delete ui;
}
