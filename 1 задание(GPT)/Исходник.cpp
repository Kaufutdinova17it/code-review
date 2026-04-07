//https://chatgpt.com
//#include <iostream>
//#include <string>
//#include <random>
//
//using namespace std;
//
//// Функция генерации случайного пароля
//string generatePassword(int length, const string& chars) {
//    random_device rd;
//    mt19937 gen(rd());
//    uniform_int_distribution<> dist(0, chars.size() - 1);
//
//    string password;
//    for (int i = 0; i < length; i++) {
//        password += chars[dist(gen)];
//    }
//    return password;
//}
//
//int main() {
//    setlocale(LC_ALL, "ru");
//
//    cout << "Выберите уровень сложности:\n";
//    cout << "1 - Лёгкий (только строчные буквы, длина 6)\n";
//    cout << "2 - Средний (буквы + цифры, длина 10)\n";
//    cout << "3 - Сложный (буквы + цифры + символы, длина 14)\n";
//
//    int choice;
//    cin >> choice;
//
//    string chars;
//    int length;
//
//    switch (choice) {
//    case 1:
//        chars = "abcdefghijklmnopqrstuvwxyz";
//        length = 6;
//        break;
//    case 2:
//        chars = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
//        length = 10;
//        break;
//    case 3:
//        chars = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()_+-=";
//        length = 14;
//        break;
//    default:
//        cout << "Неверный выбор!\n";
//        return 1;
//    }
//
//    string password = generatePassword(length, chars);
//
//    cout << "Сгенерированный пароль: " << password << endl;
//
//    return 0;
//}