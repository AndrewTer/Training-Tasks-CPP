#include "students.h"

// QPSQL - название драйвера для подключения к СУБД PostgreSQL
QSqlDatabase db = QSqlDatabase::addDatabase("QPSQL");

// Ввод данных с клавиатуры
void Students::dataInput() {
    QTextStream(stdout) << "\nStudent name: ";
    QTextStream(stdin) >> student_name;

    QTextStream(stdout)  << "Student surname: ";
    QTextStream(stdin) >> student_surname;

    QTextStream(stdout)  << "Student age: ";
    QTextStream(stdin) >> student_age;

    QTextStream(stdout)  << "Student group (template: XXXXX/XX): ";
    QTextStream(stdin) >> group_number;
}

// Вывод данных в консоль
void Students::dataOutput() {
    QTextStream(stdout)  << "\n" << student_surname << " " << student_name << " | " << QString::number(student_age) << " ages | " << group_number << " group";
}

// Подключение к БД
void Students::databaseConnect() {
    db.setHostName("localhost");

    // Название базы данных
    db.setDatabaseName("Students");

    // Имя пользователя
    db.setUserName("postgres");

    // Пароль пользователя
    db.setPassword("caan");

    bool db_connect = db.open();

    // Вывод сообщения о подключении к базе данных
    !db_connect ? QTextStream(stdout)  << "\n\n********************************************\n\nError connecting to the database!" : QTextStream(stdout) << "\n\n********************************************\n\nConnect to the database was successful!";
}

// Получение данных таблицы БД
void Students::gettingTableDataFromDB() {
    int j = 0;

    QTextStream(stdout) << "\n\nTable 'Students'\n\n";

    // Сам запрос к БД
    QSqlQuery query("SELECT \"name\", \"surname\", \"age\", \"group\" FROM \"Students_list\"");

    while (query.next())
    {
        j++;
        QTextStream(stdout) << "\n" << j << ": " << query.value(0).toString() << " " << query.value(1).toString() << " | " << query.value(2).toString() << " ages | " << query.value(3).toString() << " group\n";
    }
}

void Students::databaseDisconnect() {
    // Закрытие БД
    db.close();

    // Удаление соединения с БД
    QSqlDatabase::removeDatabase("Students");

    QTextStream(stdout) << "\n\nDisconnect from database successful!\n\n";
}
