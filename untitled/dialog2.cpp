#include "dialog2.h"
#include "ui_dialog2.h"
#include "QSqlQueryModel"
#include <QtSql>
#include <QMessageBox>
#include <QMainWindow>
Dialog2::Dialog2(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Dialog2)


{
    ui->setupUi(this);
    // //connect(ui->swtichtableknigi, &QPushButton::clicked, this, &MainWindow::switchToKnigiTable);
    connect(ui->addData, &QPushButton::clicked, this, &Dialog2::addNewData);
    //switchToPostuplenieTable();
    //updatePostBtn
    //deleteBtn
    connect(ui->updatePostBtn, &QPushButton::clicked, this, &Dialog2::UpdateData);
     connect(ui->deleteBtn, &QPushButton::clicked, this, &Dialog2::deleteData);
    connect(ui->gobackBtn, &QPushButton::clicked, this, &Dialog2::closeAndReturnToParent);
    displayDataDialog2("SELECT * FROM Поступление_книги");
}
void Dialog2::displayDataDialog2(const QString &queryStr) {
    QSqlQueryModel *model = new QSqlQueryModel(this);

    // Устанавливаем запрос в модель данных
    model->setQuery(queryStr);

    // Проверяем ошибки при выполнении запроса
    if (model->lastError().isValid()) {
        qDebug() << "Ошибка выполнения запроса:" << model->lastError().text();
        return;
    }

    // Устанавливаем модель в QTableView
    ui->TableDialog2->setModel(model);

    // После установки модели в таблицу, мы можем вызвать switchToPostuplenieTable()
    switchToPostuplenieTable();
}
void Dialog2::deleteData()
{
    // Get the ID to delete from the QTextEdit widget
    QString code_post = ui->textEdit_5->toPlainText();

    // Open the database connection
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("/home/amexdev/docs/library.db");
    if (!db.open()) {
        QMessageBox::critical(this, "Ошибка", "Ошибка при открытии базы данных: " + db.lastError().text());
        return;
    }

    // Check if the ID exists in the database
    QSqlQuery checkQuery;
    checkQuery.prepare("SELECT COUNT(*) FROM Поступление_книги WHERE Код_поступления_книги = :code_post");
    checkQuery.bindValue(":code_post", code_post.toInt());
    if (!checkQuery.exec()) {
        QMessageBox::critical(this, "Ошибка", "Ошибка выполнения запроса: " + checkQuery.lastError().text());
        db.close();
        return;
    }
    checkQuery.next();
    int count = checkQuery.value(0).toInt();
    if (count == 0) {
        QMessageBox::critical(this, "Ошибка", "Код поступления книги не существует.");
        db.close();
        return;
    }

    // Execute the SQL query to delete data from the database
    QSqlQuery query;
    query.prepare("DELETE FROM Поступление_книги WHERE Код_поступления_книги = :code_post");
    query.bindValue(":code_post", code_post.toInt());

    if (!query.exec()) {
        QMessageBox::critical(this, "Ошибка", "Ошибка выполнения запроса: " + query.lastError().text());
    } else {
        QMessageBox::information(this, "Успех", "Данные успешно удалены из базы данных");
    }

    // Close the database connection

    // Reload data to update the table view
    displayDataDialog2("SELECT * FROM Поступление_книги");
}
void Dialog2::closeAndReturnToParent(){
    this->close();

    // Получить указатель на родительское окно
    QWidget *parent = this->parentWidget();

    // Проверить, является ли родительское окно действительным и является ли его тип QMainWindow
    if (parent && qobject_cast<QMainWindow*>(parent)) {
        // Показать родительское окно (главное окно приложения)
        parent->show();
    }
}
void Dialog2::UpdateData() {
    // Get the values from QTextEdit widgets
    QString code_post = ui->textEdit->toPlainText();
    QString number_doc = ui->textEdit_2->toPlainText();
    QString svedenyua = ui->textEdit_3->toPlainText();
    QString count_ekz = ui->textEdit_4->toPlainText();

    // Open the database connection
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("/home/amexdev/docs/library.db");
    if (!db.open()) {
        QMessageBox::critical(this, "Ошибка", "Ошибка при открытии базы данных: " + db.lastError().text());
        return;
    }

    // Check if the code_post exists
    QSqlQuery checkQuery;
    checkQuery.prepare("SELECT COUNT(*) FROM Поступление_книги WHERE Код_поступления_книги = :code_post");
    checkQuery.bindValue(":code_post", code_post.toInt());
    if (!checkQuery.exec()) {
        QMessageBox::critical(this, "Ошибка", "Ошибка выполнения запроса: " + checkQuery.lastError().text());
        db.close();
        return;
    }
    checkQuery.next();
    int count = checkQuery.value(0).toInt();
    if (count == 0) {
        QMessageBox::critical(this, "Ошибка", "Код поступления книги не существует.");
        db.close();
        return;
    }

    // Execute the SQL query to update data in the database
    QSqlQuery query;
    query.prepare("UPDATE Поступление_книги SET Номер_документа = :number_doc, Сведения_о_поставщике = :svedenyua, Количество_экземпляров = :count_ekz WHERE Код_поступления_книги = :code_post");
    query.bindValue(":number_doc", number_doc.toInt());
    query.bindValue(":svedenyua", svedenyua);
    query.bindValue(":count_ekz", count_ekz.toInt());
    query.bindValue(":code_post", code_post.toInt());

    if (!query.exec()) {
        QMessageBox::critical(this, "Ошибка", "Ошибка выполнения запроса: " + query.lastError().text());
    } else {
        QMessageBox::information(this, "Успех", "Данные успешно обновлены в базе данных");
    }

    // Close the database connection

    // Reload data to update the table view
    displayDataDialog2("SELECT * FROM Поступление_книги");
}
void Dialog2::addNewData() {
    // Get the values from QTextEdit widgets
    QString code_post = ui->textEdit->toPlainText();
    QString number_doc = ui->textEdit_2->toPlainText();
    QString svedenyua = ui->textEdit_3->toPlainText();
    QString count_ekz = ui->textEdit_4->toPlainText();

    // Open the database connection
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("/home/amexdev/docs/library.db");
    if (!db.open()) {
        QMessageBox::critical(this, "Ошибка", "Ошибка при открытии базы данных: " + db.lastError().text());
        return;
    }

    // Check if the code_post already exists
    QSqlQuery checkQuery;
    checkQuery.prepare("SELECT COUNT(*) FROM Поступление_книги WHERE Код_поступления_книги = :code_post");
    checkQuery.bindValue(":code_post", code_post.toInt());
    if (!checkQuery.exec()) {
        QMessageBox::critical(this, "Ошибка", "Ошибка выполнения запроса: " + checkQuery.lastError().text());
        db.close();
        return;
    }
    checkQuery.next();
    int count = checkQuery.value(0).toInt();
    if (count > 0) {
        QMessageBox::critical(this, "Ошибка", "Код поступления книги уже существует.");
        db.close();
        return;
    }

    // Execute the SQL query to insert data into the database
    QSqlQuery query;
    query.prepare("INSERT INTO Поступление_книги (Код_поступления_книги, Номер_документа, Сведения_о_поставщике, Количество_экземпляров) "
                  "VALUES (:code_post, :number_doc, :svedenyua, :count_ekz)");
    query.bindValue(":code_post", code_post.toInt());
    query.bindValue(":number_doc", number_doc.toInt());
    query.bindValue(":svedenyua", svedenyua);
    query.bindValue(":count_ekz", count_ekz.toInt());

    if (!query.exec()) {
        QMessageBox::critical(this, "Ошибка", "Ошибка выполнения запроса: " + query.lastError().text());
    } else {
        QMessageBox::information(this, "Успех", "Данные успешно добавлены в базу данных");
    }

    // Reload data to update the table view
    displayDataDialog2("SELECT * FROM Поступление_книги");
}

void Dialog2::switchToPostuplenieTable()
{
    // Clear existing data
    booksPost.clear();
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("/home/amexdev/docs/library.db");

    if (!db.open()) {
        qDebug() << "Ошибка при открытии базы данных:" << db.lastError().text();
        return;
    }

    qDebug() << "База данных открыта успешно";

    // Retrieve data from the database
   // QString tableName = "Поступление_книги";
    QSqlQuery query;
    query.prepare("SELECT * FROM Поступление_книги");
    if (!query.exec()) {
        qDebug() << "Ошибка выполнения запроса:" << query.lastError().text();
        return;
    }

    // Load data from the "Поступление_книги" table
    while (query.next()) {
        BookPost bookPost;
        bookPost.id = query.value("Код_поступления_книги").toInt();
        bookPost.number_document = query.value("Номер_документа").toInt();
        bookPost.svedeniya= query.value("Сведения_о_поставщике").toString().toStdString();
        bookPost.count_ezk = query.value("Количество_экземпляров").toInt();
        booksPost.push_back(bookPost);
    }

    // After loading data, display it

}

Dialog2::~Dialog2()
{
    delete ui;
}
