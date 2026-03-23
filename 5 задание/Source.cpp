#include "Header.h"
#include <fstream>
#include <ctime>

using std::cout;
using std::endl;
using std::ifstream;

//FIX_ME: не было безопасного ввода
// старый код
// cin >> x;
// новый код
bool safe_input_int(int& x) {
    if (!(std::cin >> x)) {
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        return false;
    }
    return true;
}

//FIX_ME: функция Input была без стиля
// старый код
// void Input(Container& N, int n)
// новый код
template <typename Container>
void input_container(Container& container, int n) {
    if (n < 5) {
        cout << "Ошибка: размер должен быть >= 5" << endl;
        return;
    }

    int mode;
    cout << "Выберите способ заполнения контейнера:\n"
        << "1) Ввод с клавиатуры\n"
        << "2) Рандом\n"
        << "3) Из файла\n";

    //FIX_ME: не было проверки корректности ввода
    // старый код
    // cin >> mode;
    // новый код
    if (!safe_input_int(mode)) {
        cout << "Ошибка: введено нечисловое значение режима." << endl;
        return;
    }

    int value;

    switch (mode) {
    case 1:
        for (int i = 0; i < n; i++) {
            cout << "Введите элемент " << i + 1 << ": ";

            //FIX_ME: не было проверки корректности ввода
            // старый код
            // cin >> value;
            // новый код
            if (!safe_input_int(value)) {
                cout << "Ошибка: введено нечисловое значение." << endl;
                return;
            }

            container.insert(container.end(), value);
        }
        break;

    case 2:
        srand(static_cast<unsigned>(time(nullptr)));
        for (int i = 0; i < n; i++) {
            container.insert(container.end(), rand() % 101 - 50);
        }
        break;

    case 3: {
        ifstream file("a.txt");

        //FIX_ME: не было проверки открытия файла
        // старый код
        // file >> value;
        // новый код
        if (!file.is_open()) {
            cout << "Ошибка: файл не открыт." << endl;
            return;
        }

        for (int i = 0; i < n; i++) {
            if (!(file >> value)) {
                cout << "Ошибка: недостаточно данных в файле." << endl;
                return;
            }
            container.insert(container.end(), value);
        }
        break;
    }

    default:
        cout << "Ошибка: некорректный режим." << endl;
    }
}

// Эксплицитная инстанциация шаблонов
template void input_container(std::deque<int>&, int);
template void input_container(std::list<int>&, int);

//FIX_ME: функция Print была без стиля
// старый код
// void Print(const Container& N)
// новый код
template <typename Container>
void print_container(const Container& container) {
    for (auto it = container.begin(); it != container.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;
}

template void print_container(const std::deque<int>&);
template void print_container(const std::list<int>&);

//FIX_ME: вставка делалась по одному элементу
// старый код
// for (...) l.insert(it, value);
// новый код
void insert_last_five_reversed(const std::deque<int>& d, std::list<int>& l) {
    if (d.size() < 5 || l.size() < 5) {
        cout << "Ошибка: оба контейнера должны содержать >= 5 элементов." << endl;
        return;
    }

    // Находим позицию вставки — пятый с конца элемент списка
    auto it = l.end();
    for (int i = 0; i < 5; i++) {
        --it;
    }

    // Создаём временный список из последних 5 элементов дека в обратном порядке
    std::list<int> temp;
    for (int i = 0; i < 5; i++) {
        temp.push_back(d[d.size() - 1 - i]);  // d[last], d[last-1], ...
    }

    // Вставляем одним insert
    l.insert(it, temp.begin(), temp.end());
}

