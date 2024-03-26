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
    , deleteButton(nullptr) // Initialize deleteButton to nullptr
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

void FormTable::deleteData() {
    QModelIndex index = ui->tableView->selectionModel()->currentIndex();
    int id = index.sibling(index.row(), 0).data().toInt(); // Assuming id is in the first column
    QString tableName; /* Get the table name */
    deleteDataById(tableName, id);
}

void FormTable::deleteDataById(const QString& tableName, int id) {
    // Construct SQL query
    QString queryText = "DELETE FROM " + tableName + " WHERE id = ?";

    // Execute SQL query
    QSqlQuery query;
    query.prepare(queryText);
    query.addBindValue(id);

    if (query.exec()) {
        QMessageBox::information(this, "Success", "Data with ID " + QString::number(id) + " deleted successfully.");
        // Optionally update table view after successful deletion
        updateTableView(tableName);
    } else {
        QMessageBox::critical(this, "Error", "Failed to delete data with ID " + QString::number(id) + ": " + query.lastError().text());
    }
}

void FormTable::updateTableView(const QString& tableName) {
    QSqlQuery query;
    query.exec("SELECT * FROM " + tableName);
    QSqlRecord record = query.record();

    // Create delete data button if it doesn't exist
    if (!deleteButton) {
        deleteButton = new QPushButton("Delete Data");
        ui->verticalLayout_3->addWidget(deleteButton);

        // Connect the delete button to the deleteData slot
        connect(deleteButton, &QPushButton::clicked, this, &FormTable::deleteData);
    }

    // Update input fields
    QVBoxLayout *layout = new QVBoxLayout();
    QList<QPair<QString, QWidget*>> inputWidgets; // Store input widgets to access them later
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
        inputWidgets.append(qMakePair(fieldName, widget)); // Store the widget with the field name
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

void FormTable::addData(const QList<QPair<QString, QWidget*>>& inputWidgets, const QString& tableName) {
    QStringList fieldNames;
    QStringList fieldValues;

    // Gather field names and values from input widgets
    for (const auto& pair : inputWidgets) {
        const QString& fieldName = pair.first;
        const QWidget* widget = pair.second;

        if (const QLineEdit* lineEdit = dynamic_cast<const QLineEdit*>(widget)) {
            fieldNames.append(fieldName);
            fieldValues.append(lineEdit->text());
        } else if (const QDateEdit* dateEdit = dynamic_cast<const QDateEdit*>(widget)) {
            fieldNames.append(fieldName);
            fieldValues.append(dateEdit->date().toString("yyyy-MM-dd"));
        } else if (const QComboBox* comboBox = dynamic_cast<const QComboBox*>(widget)) {
            fieldNames.append(fieldName);
            fieldValues.append(comboBox->currentText());
        }
    }

    // Construct SQL query
    QString queryText = "INSERT INTO " + tableName + " (" + fieldNames.join(", ") + ") VALUES (";
    QStringList valuePlaceholders;
    for (int i = 0; i < fieldValues.size(); ++i) {
        valuePlaceholders.append("?");
    }
    queryText += valuePlaceholders.join(", ") + ")";

    // Execute SQL query
    QSqlQuery query;
    query.prepare(queryText);
    for (const QString& value : fieldValues) {
        query.addBindValue(value);
    }



            if (query.exec()) {
            QMessageBox::information(this, "Success", "Data added successfully.");
            // Optionally update table view after successful addition
            updateTableView(tableName);
        } else {
            QMessageBox::critical(this, "Error", "Failed to add data: " + query.lastError().text());
        }
    }
void FormTable::tableButtonClicked() {
        QPushButton *button = qobject_cast<QPushButton*>(sender());
        if (button) {
            QString tableName = button->text();
            updateTableView(tableName);
        }
}


    FormTable::~FormTable()
    {
        delete ui;
        // Clean up deleteButton
        delete deleteButton;
    }

