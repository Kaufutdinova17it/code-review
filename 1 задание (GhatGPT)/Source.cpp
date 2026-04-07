#include "Header.h"
#include <random>
#include <algorithm>

// Получаем набор символов в зависимости от сложности
std::string PasswordGenerator::getCharacters(Difficulty level) {
    std::string lower = "abcdefghijklmnopqrstuvwxyz";
    std::string upper = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    std::string digits = "0123456789";
    std::string symbols = "!@#$%^&*()_+-=[]{}|;:,.<>?";

    switch (level) {
    case EASY:
        return lower + digits;
    case MEDIUM:
        return lower + upper + digits;
    case HARD:
        return lower + upper + digits + symbols;
    default:
        return lower;
    }
}

// Длина пароля
int PasswordGenerator::getLength(Difficulty level) {
    switch (level) {
    case EASY:
        return 6;
    case MEDIUM:
        return 10;
    case HARD:
        return 16;
    default:
        return 6;
    }
}

// Генерация пароля
std::string PasswordGenerator::generatePassword(Difficulty level) {
    std::string chars = getCharacters(level);
    int length = getLength(level);
    std::string password;

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(0, chars.size() - 1);

    for (int i = 0; i < length; i++) {
        password += chars[dist(gen)];
    }

    return password;
}