#include <windows.h>
#include <iostream>
#include "Header.h"

using std::cout;
using std::endl;

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    cout << "Генератор паролей\n";
    cout << "Выберите уровень сложности:\n";
    cout << "1 - Лёгкий (строчные буквы, длина 6)\n";
    cout << "2 - Средний (буквы + цифры, длина 10)\n";
    cout << "3 - Сложный (буквы + цифры + символы, длина 14)\n";
    cout << "Ваш выбор: ";

    int choice;
    std::cin >> choice;

    //FIX_ME: раньше не было проверки диапазона
    if (choice < 1 || choice > 3) {
        cout << "Ошибка: неверный выбор!" << endl;
        return 0;
    }

    //FIX_ME: раньше вызов был через глобальную функцию
    // новый код: вызов метода класса
    std::string password = PasswordGenerator::generatePassword(
        static_cast<PasswordGenerator::Difficulty>(choice)
    );

    cout << "Сгенерированный пароль: " << password << endl;

    return 0;
}
