#include "Header.h"
#include <random>
#include <algorithm>

using std::string;

//FIX_ME: раньше набор символов задавался прямо в switch main()
// новый код: отдельный метод getCharacters
string PasswordGenerator::getCharacters(Difficulty level) {
    string lower = "abcdefghijklmnopqrstuvwxyz";
    string upper = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string digits = "0123456789";
    string symbols = "!@#$%^&*()_+-=";

    switch (level) {
    case EASY:
        return lower;
    case MEDIUM:
        return lower + upper + digits;
    case HARD:
        return lower + upper + digits + symbols;
    default:
        return lower;
    }
}

//FIX_ME: раньше длина задавалась прямо в main()
// новый код: отдельный метод getLength
int PasswordGenerator::getLength(Difficulty level) {
    switch (level) {
    case EASY:
        return 6;
    case MEDIUM:
        return 10;
    case HARD:
        return 14;
    default:
        return 6;
    }
}

//FIX_ME: раньше функция generatePassword была глобальной
// новый код: метод класса
string PasswordGenerator::generatePassword(Difficulty level) {
    string chars = getCharacters(level);
    int length = getLength(level);
    string password;

    //FIX_ME: генерация была в глобальной функции
    // новый код: внутри метода класса
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(0, chars.size() - 1);

    for (int i = 0; i < length; i++) {
        password += chars[dist(gen)];
    }

    return password;
}
