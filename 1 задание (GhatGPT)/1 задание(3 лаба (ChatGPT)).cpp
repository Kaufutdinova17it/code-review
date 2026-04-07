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
    cout << "1 - Легкий\n";
    cout << "2 - Средний\n";
    cout << "3 - Сложный\n";
    cout << "Ваш выбор: ";

    int choice;
    std::cin >> choice;

    //FIX_ME: не было проверки диапазона
    if (choice < 1 || choice > 3) {
        cout << "Ошибка: неверный выбор!" << endl;
        return 0;
    }

    //FIX_ME: вызов метода был через int, а не enum
    //generatePassword(choice)
    std::string password = PasswordGenerator::generatePassword(
        static_cast<PasswordGenerator::Difficulty>(choice)
    );

    cout << "Сгенерированный пароль: " << password << endl;

    return 0;
}
