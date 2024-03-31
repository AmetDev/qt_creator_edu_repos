#include "admincheck.h"
#include "authclass.hpp"
#include <QApplication>
#include "formtable.h"
#include <QInputDialog> // Для использования QInputDialog
#include <QDebug>
#include <QMessageBox>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    // admincheck w;
    FormTable formtable;
    // // Получаем логин и пароль от пользователя через диалоговое окно
    // QString login = QInputDialog::getText(&w, "Введите логин", "Логин:");
    // QString password = QInputDialog::getText(&w, "Введите пароль", "Пароль:", QLineEdit::Password);

    // // Проверяем логин и пароль
    // int isAdmin = checkAdmin(login.toStdString(), password.toStdString(), &w);

    // // В зависимости от результата проверки делаем что-то
    // if (isAdmin == 1) {
    //     // Если администратор
    //     formtable.setIsAdmin("1");
    //     QMessageBox::information(nullptr, "Успех", "Вы смогли войти в аккаунт как администратор");
    //     formtable.show();
    // } else if(isAdmin == 0) {
    //     // Если не администратор
    //     // Выводим сообщение об ошибке или что-то еще
    //     QMessageBox::critical(nullptr, "Провал", "Вам не удалось войти");
    // } else if(isAdmin == 2) {
    //     // если обычный пользователь
    //     formtable.setIsAdmin("2");
    //     QMessageBox::information(nullptr, "Успех", "Вы смогли войти в аккаунт как читатель");
    formtable.show();
    // }


    return a.exec();
}
