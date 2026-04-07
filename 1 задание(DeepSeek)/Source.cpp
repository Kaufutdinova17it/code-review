#include "Header.h"
#include <random>
#include <algorithm>
#include <vector>
#include <ctime>

//FIX_ME: раньше генератор и seed были в main
// новый код: инициализация в конструкторе класса
PasswordGenerator::PasswordGenerator()
    : lowercase("abcdefghijklmnopqrstuvwxyz"),
    uppercase("ABCDEFGHIJKLMNOPQRSTUVWXYZ"),
    digits("0123456789"),
    special("!@#$%^&*()-_=+[]{}|;:,.<>?") {
    rng.seed(std::time(nullptr));
}

//FIX_ME: раньше логика категорий была в main
// новый код: отдельный метод ensureAllCategories
std::string PasswordGenerator::ensureAllCategories(int length, const std::string& charSet,
    const std::vector<std::string>& categories) {
    std::string password;
    std::uniform_int_distribution<> dist(0, charSet.length() - 1);

    for (const auto& category : categories) {
        std::uniform_int_distribution<> catDist(0, category.length() - 1);
        password += category[catDist(rng)];
    }

    for (int i = password.length(); i < length; ++i) {
        password += charSet[dist(rng)];
    }

    std::shuffle(password.begin(), password.end(), rng);

    return password;
}

std::string PasswordGenerator::generateEasy() {
    const int length = 8;
    std::string charSet = lowercase + digits;
    std::vector<std::string> categories = { lowercase, digits };
    return ensureAllCategories(length, charSet, categories);
}

std::string PasswordGenerator::generateMedium() {
    const int length = 12;
    std::string charSet = lowercase + uppercase + digits;
    std::vector<std::string> categories = { lowercase, uppercase, digits };
    return ensureAllCategories(length, charSet, categories);
}

std::string PasswordGenerator::generateHard() {
    const int length = 16;
    std::string charSet = lowercase + uppercase + digits + special;
    std::vector<std::string> categories = { lowercase, uppercase, digits, special };
    return ensureAllCategories(length, charSet, categories);
}

std::string PasswordGenerator::generateByLevel(int level) {
    switch (level) {
    case 1: return generateEasy();
    case 2: return generateMedium();
    case 3: return generateHard();
    default: return generateMedium();
    }
}

std::string PasswordGenerator::getLevelDescription(int level) {
    switch (level) {
    case 1: return "Лёгкий (8 символов): строчные буквы и цифры";
    case 2: return "Средний (12 символов): строчные, прописные буквы и цифры";
    case 3: return "Сложный (16 символов): строчные, прописные буквы, цифры и спецсимволы";
    default: return "Неизвестный уровень";
    }
}
