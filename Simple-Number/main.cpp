#include <iostream>
#include <string>

using namespace std;

// Функция проверки числа на простоту
bool Сheck_simple_number(unsigned long int natural_number_for_check) {
    if (natural_number_for_check > 1)
    {
        for (unsigned long int i = 2; i < natural_number_for_check; i++)
            if (natural_number_for_check % i == 0)
                return false;
        return true;
    } else
        return false;
}

int main() {
    setlocale(LC_ALL, "rus");
    
    unsigned long int natural_number = 0;
    
    cout << "Введите натуральное число: ";
    cin >> natural_number;
    
    // Перевод натурального числа в строку
    string natural_number_string = to_string(natural_number);
    
    // Добавление в начало и конец строки цифры 1
    natural_number_string = '1' + natural_number_string + '1';
    
    cout << natural_number_string << " - ";
    
    // Вызов функции проверки числа на простоту
    // stoi - oбратный перевод строки в число
    Сheck_simple_number(stoi(natural_number_string)) ? cout << "число простое" : cout << "число не простое";
    
    return 0;
}
