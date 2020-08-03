#ifndef STUDENTS_H
#define STUDENTS_H

#include <QCoreApplication>
#include <QString>
#include <QDebug>
#include <QTextStream>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QSqlQueryModel>

class Students
{
    private:
        QString student_name;
        QString student_surname;
        int student_age;
        char group_number[8];

    public:
        void dataInput();
        void dataOutput();
        void databaseConnect();
        void gettingTableDataFromDB();
        void databaseDisconnect();
};

#endif // STUDENTS_H
