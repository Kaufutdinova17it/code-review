#include <windows.h>
#include <iostream>
#include "Header.h"

using std::cout;
using std::endl;

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    PasswordGenerator pg;
    int choice;
    char continueChoice;

    cout << "===================================\n";
    cout << "   ГЕНЕРАТОР НАДЁЖНЫХ ПАРОЛЕЙ\n";
    cout << "===================================\n\n";

    do {
        cout << "Выберите уровень сложности пароля:\n";
        cout << "1. " << PasswordGenerator::getLevelDescription(1) << "\n";
        cout << "2. " << PasswordGenerator::getLevelDescription(2) << "\n";
        cout << "3. " << PasswordGenerator::getLevelDescription(3) << "\n";
        cout << "Ваш выбор (1-3): ";

        // ✅ Проверка на корректный ввод
        while (!(std::cin >> choice) || choice < 1 || choice > 3) {
            std::cin.clear();              // очищаем флаг ошибки
            std::cin.ignore(10000, '\n');  // убираем лишний ввод
            cout << "Ошибка! Введите число от 1 до 3: ";
        }

        std::string password = pg.generateByLevel(choice);

        cout << "\n===================================\n";
        cout << "Ваш пароль: " << password << "\n";
        cout << "Длина пароля: " << password.length() << " символов\n";

        bool hasLower = false, hasUpper = false, hasDigit = false, hasSpecial = false;
        for (char c : password) {
            if (std::islower(c)) hasLower = true;
            else if (std::isupper(c)) hasUpper = true;
            else if (std::isdigit(c)) hasDigit = true;
            else hasSpecial = true;
        }

        cout << "Содержит:\n";
        if (hasLower) cout << "  - строчные буквы\n";
        if (hasUpper) cout << "  - прописные буквы\n";
        if (hasDigit) cout << "  - цифры\n";
        if (hasSpecial) cout << "  - специальные символы\n";

        cout << "===================================\n\n";

        cout << "Сгенерировать ещё один пароль? (y/n): ";
        std::cin >> continueChoice;
        cout << "\n";

    } while (continueChoice == 'y' || continueChoice == 'Y');

    cout << "Спасибо за использование генератора паролей!\n";

    return 0;
}
