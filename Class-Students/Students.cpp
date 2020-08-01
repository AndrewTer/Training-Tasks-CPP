#include "Students.h"
#include <iostream>

using namespace std;

void Students::dataInput() {
    cout << "\nИмя студен(-та | -тки): ";
    cin >> student_name;
        
    cout << "Фамилия студен(-та | -тки): ";
    cin >> student_surname;
        
    cout << "Возраст студен(-та | -тки): ";
    cin >> student_age;
    
    cout << "Группа студен(-та | -тки) (шаблон: XXXXX/XX): ";
    cin >> group_number;
}
    
void Students::dataOutput() {
    cout << "\n" << student_surname << " " << student_name << " | " << student_age << " лет | " << group_number << " группа";
}
