#include <iostream>
#include <string>
#include <string>
#include <vector>
#include <random>

//FIX_ME: раньше весь класс был в main.cpp
// новый код: вынесен в отдельный заголовочный файл
class PasswordGenerator {
public:
    PasswordGenerator();

    //FIX_ME: раньше методы назывались без единого стиля
    // новый код: generateEasy / generateMedium / generateHard
    std::string generateEasy();
    std::string generateMedium();
    std::string generateHard();

    //FIX_ME: раньше выбор уровня был через int
    // новый код: метод generateByLevel(int level)
    std::string generateByLevel(int level);

    //FIX_ME: описание уровня было захардкожено в main
    // новый код: отдельный статический метод
    static std::string getLevelDescription(int level);

private:
    const std::string lowercase;
    const std::string uppercase;
    const std::string digits;
    const std::string special;

    std::mt19937 rng;

    //FIX_ME: раньше проверка категорий была встроена в main
    // новый код: отдельный приватный метод ensureAllCategories
    std::string ensureAllCategories(int length, const std::string& charSet,
        const std::vector<std::string>& categories);
};


