#include "Header.h"
using std::cout;
using std::endl;

//FIX_ME: не было безопасного ввода
// старый код
// cin >> x;
// новый код
bool safe_input(int& x) {
    if (!(std::cin >> x)) {
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        return false;
    }
    return true;
}

//FIX_ME: конструктор узла был без стиля
// старый код
// TNode(int d) : data(d), next(nullptr) {}
// новый код
Stack::TNode::TNode(int value) : data(value), next(nullptr) {}

Stack::Stack() : top_(nullptr), count_(0) {}

//FIX_ME: метод add нарушал стиль
// старый код
// void add(int x)
// новый код
void Stack::push(int value) {
    TNode* new_node = new TNode(value);
    new_node->next = top_;
    top_ = new_node;
    count_++;
}

//FIX_ME: метод topdel нарушал стиль
// старый код
// void topdel()
// новый код
int Stack::pop() {
    if (top_ == nullptr) {
        cout << "Ошибка: стек пуст" << endl;
        return 0;
    }

    TNode* temp = top_;
    int value = temp->data;

    cout << "Извлечённый элемент D: " << value << endl;

    top_ = top_->next;

    cout << "Адрес новой вершины P2: " << top_ << endl;

    if (top_ != nullptr) {
        cout << "Значение новой вершины P2: " << top_->data << endl;
    }
    else {
        cout << "Стек стал пустым, P2 = nullptr" << endl;
    }

    delete temp;
    count_--;

    return value;
}

//FIX_ME: метод show нарушал стиль
// старый код
// void show()
// новый код
void Stack::print() const {
    if (top_ == nullptr) {
        cout << "Стек пуст." << endl;
        return;
    }

    cout << "Стек (сверху вниз):" << endl;
    TNode* temp = top_;
    while (temp != nullptr) {
        cout << temp->data << endl;
        temp = temp->next;
    }
}
