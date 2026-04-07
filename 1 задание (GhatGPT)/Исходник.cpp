//https://chatgpt.org/chat
//#include <iostream>
//#include <string>
//#include <random>
//
//// Класс генератора паролей
//class PasswordGenerator {
//public:
//    enum Difficulty {
//        EASY = 1,
//        MEDIUM,
//        HARD
//    };
//
//    static std::string generatePassword(Difficulty level) {
//        std::string chars = getCharacters(level);
//        int length = getLength(level);
//        std::string password;
//
//        std::random_device rd;
//        std::mt19937 gen(rd());
//        std::uniform_int_distribution<> dist(0, chars.size() - 1);
//
//        for (int i = 0; i < length; i++) {
//            password += chars[dist(gen)];
//        }
//
//        return password;
//    }
//
//private:
//    static std::string getCharacters(Difficulty level) {
//        std::string lower = "abcdefghijklmnopqrstuvwxyz";
//        std::string upper = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
//        std::string digits = "0123456789";
//        std::string symbols = "!@#$%^&*()_+-=[]{}|;:,.<>?";
//
//        switch (level) {
//        case EASY:
//            return lower + digits;
//        case MEDIUM:
//            return lower + upper + digits;
//        case HARD:
//            return lower + upper + digits + symbols;
//        default:
//            return lower;
//        }
//    }
//
//    static int getLength(Difficulty level) {
//        switch (level) {
//        case EASY:
//            return 6;
//        case MEDIUM:
//            return 10;
//        case HARD:
//            return 16;
//        default:
//            return 6;
//        }
//    }
//};
//
//int main() {
//    int choice;
//
//    std::cout << "Генератор паролей\n";
//    std::cout << "Выберите уровень сложности:\n";
//    std::cout << "1 - Легкий\n";
//    std::cout << "2 - Средний\n";
//    std::cout << "3 - Сложный\n";
//    std::cout << "Ваш выбор: ";
//    std::cin >> choice;
//
//    if (choice < 1 || choice > 3) {
//        std::cout << "Неверный выбор!\n";
//        return 1;
//    }
//
//    std::string password = PasswordGenerator::generatePassword(
//        static_cast<PasswordGenerator::Difficulty>(choice)
//    );
//
//    std::cout << "Сгенерированный пароль: " << password << std::endl;
//
//    return 0;
//}