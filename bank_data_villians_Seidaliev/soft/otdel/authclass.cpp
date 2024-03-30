#include "authclass.hpp"
#include <iostream>
#include <QString>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>
#include <globalpath.h>
#include <QSqlError>
#include <QWidget>
#include <QMessageBox>

int checkAdmin(const std::string& login, const std::string& password, QWidget *parent) {
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(globalPath::getDatabasePath());
    if (!db.open()) {
        QMessageBox::critical(parent, "Error", "Error opening database: " + db.lastError().text());
        return 0;
    }

    QSqlQuery checkAdminQuery;
    checkAdminQuery.prepare("SELECT * FROM users WHERE login = :login AND password = :password");
    checkAdminQuery.bindValue(":login", QString::fromStdString(login));
    checkAdminQuery.bindValue(":password", QString::fromStdString(password));

    if (!checkAdminQuery.exec()) {
        qDebug() << "Error executing query: " << checkAdminQuery.lastError().text();
        return 0;
    }

    if (checkAdminQuery.next()) {
        QString retrievedLogin = checkAdminQuery.value(0).toString();
        QString retrievedPassword = checkAdminQuery.value(1).toString();
        QString retrievedStatus = checkAdminQuery.value(2).toString();
        if (retrievedLogin.toStdString() == login && retrievedPassword.toStdString() == password && retrievedStatus.toStdString() == "true") {
            return 1;
        } else if(retrievedLogin.toStdString() == login && retrievedPassword.toStdString() == password && retrievedStatus.toStdString() == "false") {
            return 2;
        } else {
            return 0;
        }
    } else {
        return false; // No matching user found
    }
}
