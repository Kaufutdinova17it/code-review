//#include <iostream>
//#include <string>
//#include <random>
//#include <vector>
//#include <algorithm>
//#include <ctime>
//
//class PasswordGenerator {
//private:
//    // Наборы символов
//    const std::string lowercase = "abcdefghijklmnopqrstuvwxyz";
//    const std::string uppercase = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
//    const std::string digits = "0123456789";
//    const std::string special = "!@#$%^&*()-_=+[]{}|;:,.<>?";
//
//    std::mt19937 rng; // Генератор случайных чисел
//
//    // Гарантирует, что пароль содержит хотя бы один символ из каждой категории
//    std::string ensureAllCategories(int length, const std::string& charSet,
//        const std::vector<std::string>& categories) {
//        std::string password;
//        std::uniform_int_distribution<> dist(0, charSet.length() - 1);
//
//        // Сначала добавляем по одному символу из каждой категории
//        for (const auto& category : categories) {
//            std::uniform_int_distribution<> catDist(0, category.length() - 1);
//            password += category[catDist(rng)];
//        }
//
//        // Заполняем остальные символы случайными из общего набора
//        for (int i = password.length(); i < length; ++i) {
//            password += charSet[dist(rng)];
//        }
//
//        // Перемешиваем символы для случайного порядка
//        std::shuffle(password.begin(), password.end(), rng);
//
//        return password;
//    }
//
//public:
//    PasswordGenerator() {
//        // Инициализация генератора случайных чисел
//        rng.seed(std::time(nullptr));
//    }
//
//    // Лёгкий уровень: только строчные буквы и цифры
//    std::string generateEasy() {
//        const int length = 8;
//        std::string charSet = lowercase + digits;
//        std::vector<std::string> categories = { lowercase, digits };
//
//        return ensureAllCategories(length, charSet, categories);
//    }
//
//    // Средний уровень: строчные, прописные буквы и цифры
//    std::string generateMedium() {
//        const int length = 12;
//        std::string charSet = lowercase + uppercase + digits;
//        std::vector<std::string> categories = { lowercase, uppercase, digits };
//
//        return ensureAllCategories(length, charSet, categories);
//    }
//
//    // Сложный уровень: все типы символов
//    std::string generateHard() {
//        const int length = 16;
//        std::string charSet = lowercase + uppercase + digits + special;
//        std::vector<std::string> categories = { lowercase, uppercase, digits, special };
//
//        return ensureAllCategories(length, charSet, categories);
//    }
//
//    // Генерация пароля по уровню сложности
//    std::string generateByLevel(int level) {
//        switch (level) {
//        case 1:
//            return generateEasy();
//        case 2:
//            return generateMedium();
//        case 3:
//            return generateHard();
//        default:
//            return generateMedium(); // По умолчанию средний уровень
//        }
//    }
//
//    // Получение описания уровня
//    static std::string getLevelDescription(int level) {
//        switch (level) {
//        case 1:
//            return "Лёгкий (8 символов): строчные буквы и цифры";
//        case 2:
//            return "Средний (12 символов): строчные, прописные буквы и цифры";
//        case 3:
//            return "Сложный (16 символов): строчные, прописные буквы, цифры и спецсимволы";
//        default:
//            return "Неизвестный уровень";
//        }
//    }
//};
//
//int main() {
//    PasswordGenerator pg;
//    int choice;
//    char continueChoice;
//
//    std::cout << "===================================\n";
//    std::cout << "   ГЕНЕРАТОР НАДЁЖНЫХ ПАРОЛЕЙ\n";
//    std::cout << "===================================\n\n";
//
//    do {
//        // Вывод меню
//        std::cout << "Выберите уровень сложности пароля:\n";
//        std::cout << "1. " << PasswordGenerator::getLevelDescription(1) << "\n";
//        std::cout << "2. " << PasswordGenerator::getLevelDescription(2) << "\n";
//        std::cout << "3. " << PasswordGenerator::getLevelDescription(3) << "\n";
//        std::cout << "Ваш выбор (1-3): ";
//
//        std::cin >> choice;
//
//        // Проверка корректности ввода
//        while (choice < 1 || choice > 3) {
//            std::cout << "Неверный выбор! Пожалуйста, введите число от 1 до 3: ";
//            std::cin >> choice;
//        }
//
//        // Генерация и вывод пароля
//        std::string password = pg.generateByLevel(choice);
//
//        std::cout << "\n===================================\n";
//        std::cout << "Ваш пароль: " << password << "\n";
//
//        // Оценка надёжности пароля
//        std::cout << "Длина пароля: " << password.length() << " символов\n";
//
//        // Подсчёт типов символов в пароле
//        bool hasLower = false, hasUpper = false, hasDigit = false, hasSpecial = false;
//        for (char c : password) {
//            if (std::islower(c)) hasLower = true;
//            else if (std::isupper(c)) hasUpper = true;
//            else if (std::isdigit(c)) hasDigit = true;
//            else hasSpecial = true;
//        }
//
//        std::cout << "Содержит:\n";
//        if (hasLower) std::cout << "  - строчные буквы\n";
//        if (hasUpper) std::cout << "  - прописные буквы\n";
//        if (hasDigit) std::cout << "  - цифры\n";
//        if (hasSpecial) std::cout << "  - специальные символы\n";
//
//        std::cout << "===================================\n\n";
//
//        // Спрашиваем, нужно ли сгенерировать ещё один пароль
//        std::cout << "Сгенерировать ещё один пароль? (y/n): ";
//        std::cin >> continueChoice;
//        std::cout << "\n";
//
//    } while (continueChoice == 'y' || continueChoice == 'Y');
//
//    std::cout << "Спасибо за использование генератора паролей!\n";
//
//    return 0;
//}