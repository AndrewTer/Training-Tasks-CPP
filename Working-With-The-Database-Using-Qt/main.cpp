#include "students.h"

int main()
{
    const int students_count = 3;

    // Массив студентов
    Students students_list[students_count];

    QTextStream(stdout) << "Enter data";

    // Заполнение массива студентов
    for (int i=0; i<students_count; i++)
    {
        students_list[i].dataInput();
    }

    QTextStream(stdout) << "\n\nList of all students: ";

    // Вывод массива студентов
    for (int i=0; i<students_count; i++)
        students_list[i].dataOutput();

    QTextStream(stdout) << "\n\nRetrieving data from a database...\n\n";

    Students st_object;

    // Подключение к базе данных
    st_object.databaseConnect();

    // Получение данных таблицы
    st_object.gettingTableDataFromDB();

    // Разрыв соединения с базой данных
    st_object.databaseDisconnect();

    return 0;
}
