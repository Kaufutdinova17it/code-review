
#include <string>

//FIX_ME: раньше всё было в main.cpp, без класса
// новый код: вынесен отдельный класс PasswordGenerator
class PasswordGenerator {
public:
    enum Difficulty {
        EASY = 1,
        MEDIUM,
        HARD
    };

    //FIX_ME: функция была глобальной
    // старый код: string generatePassword(int length, const string& chars)
    // новый код: метод класса generatePassword(Difficulty level)
    static std::string generatePassword(Difficulty level);

private:
    //FIX_ME: набор символов и длина задавались прямо в main
    // новый код: вынесены в отдельные методы
    static std::string getCharacters(Difficulty level);
    static int getLength(Difficulty level);
};


