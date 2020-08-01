#include <iostream>
#include "Students.h"

using namespace std;

int main() {
    setlocale(LC_ALL, "rus");
    
    const int students_count = 3;
    
    Students students_list[students_count];
    
    cout << "Введите данные";
    
    for (int i=0; i<students_count; i++)
    {
        students_list[i].dataInput();
    }
    
    cout << "\n\nСписок всех студентов: ";
    
    for (int i=0; i<students_count; i++)
        students_list[i].dataOutput();
    
    return 0;
}
