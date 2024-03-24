#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSqlError>
#include <QSqlQueryModel>
#include <dialog2.h>
#include <QMessageBox>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //connect(ui->switchTableButton, &QPushButton::clicked, this, &MainWindow::switchToPostuplenieTable);
    //swtichtableknigi
    //connect(ui->swtichtableknigi, &QPushButton::clicked, this, &MainWindow::switchToKnigiTable);
    connect(ui->postBtn, &QPushButton::clicked, this, &MainWindow::ToSwtchNewForm);
    //AddNewDataBooks
    connect(ui->addBtnBooks, &QPushButton::clicked, this, &MainWindow::AddNewDataBooks);

    connect(ui->updateBtnBooks, &QPushButton::clicked, this, &MainWindow::UpdateNewDataBooks);
    connect(ui->deleteBtnBooks_2, &QPushButton::clicked, this, &MainWindow::DeleteNewDataBooks);
    //deleteBtnBooks
    //connect(ui->deleteBtnBooks)
        //UpdateNewDataBooks
    // Загрузка данных из базы данных

    loadDataFromDatabase();

    // Отображение данных из таблицы "Книги" в QTableView
    displayData("SELECT * FROM Книги");
}


MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::ToSwtchNewForm() {
    // Form *secondform = new Form(); // Instantiate SecondForm
    // secondform->show(); // Show the form
    Dialog2* dialog2 = new Dialog2();
    dialog2->show();
}

void MainWindow::DeleteNewDataBooks()
{
    QString code_books = ui->textEdit_delete->toPlainText();
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("/home/amexdev/docs/library.db");
    if (!db.open()) {
        QMessageBox::critical(this, "Ошибка", "Ошибка при открытии базы данных: " + db.lastError().text());
        return;
    }

    QSqlQuery checkQuery;
    checkQuery.prepare("SELECT COUNT(*) FROM Книги WHERE Код_книги = :code_books");
    checkQuery.bindValue(":code_books", code_books.toInt());
    if(!checkQuery.exec())
    {
        QMessageBox::critical(this, "Ошибка", "Ошибка выполнения запроса:"+checkQuery.lastError().text());
        db.close();
        return;
    }
    checkQuery.next();
    int count = checkQuery.value(0).toInt();
    if(count == 0)
    {
        QMessageBox::critical(this, "Ошибка", "Код поступления книги не существует");
        db.close();
        return;
    }
    QSqlQuery query;
    query.prepare("DELETE FROM Книги WHERE Код_книги = :code_books");
    query.bindValue(":code_books", code_books.toInt());
    if(!query.exec())
    {
        QMessageBox::critical(this, "Ошибка", "Ошибка выполнения запроса:"+checkQuery.lastError().text());
    } else {
        QMessageBox::information(this, "Успешно", "Данные успешно удалены из базы данных");
    }
    displayData("SELECT * FROM Книги");
}
void MainWindow::loadDataFromDatabase()
{
    // Connect to the database
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("/home/amexdev/docs/library.db");

    if (!db.open()) {
        qDebug() << "Ошибка при открытии базы данных:" << db.lastError().text();
        return;
    }

    qDebug() << "База данных открыта успешно";

    // Retrieve data from the database
    QString tableName = "Книги";
    QSqlQuery query;
    query.prepare("SELECT * FROM Книги");
    if (!query.exec()) {
        qDebug() << "Ошибка выполнения запроса:" << query.lastError().text();
        return;
    }

    while (query.next()) {
        Book book;
        book.id = query.value("Код_книги").toInt();
        book.name = query.value("Название").toString().toStdString();
        book.typebook = query.value("Жанр").toString().toStdString();
        book.author = query.value("Авторы").toString().toStdString();
        book.izdatelstvo = query.value("Издательство").toString().toStdString();
        book.count_pages = query.value("Количество_страниц").toInt();
        books.push_back(book);
    }
}

void MainWindow::UpdateNewDataBooks()
{
    QString code_books = ui->textEdit->toPlainText();
    QString name_books = ui->textEdit_2->toPlainText();
    QString type_book = ui->textEdit_3->toPlainText();
    QString authors_books = ui->textEdit_4->toPlainText();
    QString izatelstvo= ui->textEdit_5->toPlainText();
    QString cout_pages = ui->textEdit_6->toPlainText();
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("/home/amexdev/docs/library.db");
    if (!db.open()) {
        QMessageBox::critical(this, "Ошибка", "Ошибка при открытии базы данных: " + db.lastError().text());
        return;
    }
    QSqlQuery checkQuery;
    checkQuery.prepare("SELECT COUNT(*) FROM Книги WHERE Код_книги = :code_books");
    checkQuery.bindValue(":code_books", code_books.toInt());
    if(!checkQuery.exec()){
        QMessageBox::critical(this, "Ошибка", "Ошибка выполнения запроса:1"+checkQuery.lastError().text());
        db.close();
        return;

    }
    checkQuery.next();
    int count = checkQuery.value(0).toInt();
    if(count == 0) {
        QMessageBox::critical(this, "Ошибка", "Код поступления не существует");
        db.close();
        return;
    }
    QSqlQuery query;
    query.prepare("UPDATE Книги SET Код_книги= :code_books, Название= :name_books, Жанр= :type_book, Авторы= :authors_books, Издательство = :izatelstvo, Количество_страниц= :cout_pages WHERE Код_книги= :code_books");
    query.bindValue(":code_books", code_books.toInt());
    query.bindValue(":name_books", name_books);
    query.bindValue(":type_book", type_book);
    query.bindValue(":authors_books",authors_books);
    query.bindValue(":izatelstvo", izatelstvo);
    query.bindValue(":cout_pages", cout_pages.toInt());
    if (!query.exec()) {
        QMessageBox::critical(this, "Ошибка", "Ошибка выполнения запроса: " + query.lastError().text());
    } else {
        QMessageBox::information(this, "Успех", "Данные успешно добавлены в базу данных");
    }

    // Reload data to update the table view
    displayData("SELECT * FROM Книги");
}
void MainWindow::AddNewDataBooks()  {
    QString code_books = ui->textEdit->toPlainText();
    QString name_books = ui->textEdit_2->toPlainText();
    QString type_book = ui->textEdit_3->toPlainText();
    QString authors_books = ui->textEdit_4->toPlainText();
    QString izatelstvo= ui->textEdit_5->toPlainText();
    QString cout_pages = ui->textEdit_6->toPlainText();
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("/home/amexdev/docs/library.db");
    if (!db.open()) {
        QMessageBox::critical(this, "Ошибка", "Ошибка при открытии базы данных: " + db.lastError().text());
        return;
    }
    QSqlQuery checkQuery;
    checkQuery.prepare("SELECT COUNT(*) FROM Книги WHERE Код_книги = :code_books");
    checkQuery.bindValue(":code_books", code_books.toInt());
    if(!checkQuery.exec()){
        QMessageBox::critical(this, "Ошибка", "Ошибка выполнения запроса:"+checkQuery.lastError().text());
        db.close();
        return;
    }
    QSqlQuery query;
    query.prepare("INSERT INTO Книги (Код_книги, Название, Жанр, Авторы, Издательство, Количество_страниц)" "VALUES(:code_books, :name_books, :type_books, :authors_books, :izatelstvo, :cout_pages)");
    query.bindValue(":code_books", code_books.toInt());
    query.bindValue(":name_books", name_books);
    query.bindValue(":type_book", type_book);
    query.bindValue(":authors_books",authors_books);
    query.bindValue(":izatelstvo", izatelstvo);
    query.bindValue(":cout_pages", cout_pages.toInt());
    if (!query.exec()) {
        QMessageBox::critical(this, "Ошибка", "Ошибка выполнения запроса: " + query.lastError().text());
    } else {
        QMessageBox::information(this, "Успех", "Данные успешно добавлены в базу данных");
    }

    // Reload data to update the table view
    displayData("SELECT * FROM Книги");

}
void MainWindow::displayData(const QString &queryStr)
{
    // Создаем модель данных
    QSqlQueryModel *model = new QSqlQueryModel(this);

    // Устанавливаем запрос в модель данных
    model->setQuery(queryStr);

    // Проверяем ошибки при выполнении запроса
    if (model->lastError().isValid()) {
        qDebug() << "Ошибка выполнения запроса:" << model->lastError().text();
        return;
    }

    // Устанавливаем модель в QTableView
    ui->tableView->setModel(model);
}
