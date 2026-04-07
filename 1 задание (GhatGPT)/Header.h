
#include <string>

//FIX_ME: класс был без стиля и с лишними функциями в одном файле
class PasswordGenerator {
public:
    //FIX_ME: enum был без имён и использовались "магические числа"
    //int choice = 1/2/3
    enum Difficulty {
        EASY = 1,
        MEDIUM,
        HARD
    };

    //FIX_ME: метод назывался без стиля
    //genPass(int level)
    static std::string generatePassword(Difficulty level);

private:
    //FIX_ME: вспомогательные функции были в main
    // новый код: вынесены в приватные методы
    static std::string getCharacters(Difficulty level);
    static int getLength(Difficulty level);
};


