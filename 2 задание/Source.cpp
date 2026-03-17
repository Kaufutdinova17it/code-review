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

//FIX_ME: конструктор был без стиля
// старый код
// Node(int d) : data(d), next(nullptr) {}
// новый код
Queue::Node::Node(int value) : data(value), next(nullptr) {}

Queue::Queue() : head_(nullptr), tail_(nullptr) {}

//FIX_ME: метод add нарушал стиль
// старый код
// void add(int x)
// новый код
void Queue::enqueue(int value) {
    Node* new_node = new Node(value);

    if (tail_ != nullptr) {
        tail_->next = new_node;
    }
    else {
        head_ = new_node;
    }

    tail_ = new_node;
}

//FIX_ME: метод del нарушал стиль
// старый код
// int del()
// новый код
int Queue::dequeue() {
    if (head_ == nullptr) {
        cout << "Ошибка: очередь пуста" << endl;
        return 0;
    }

    Node* temp = head_;
    int value = temp->data;

    head_ = head_->next;

    if (head_ == nullptr) {
        tail_ = nullptr;
    }

    delete temp;
    return value;
}

void Queue::print() const {
    if (head_ == nullptr) {
        cout << "Очередь пуста." << endl;
        return;
    }

    cout << "Очередь (от начала к концу): ";
    Node* cur = head_;
    while (cur != nullptr) {
        cout << cur->data << " ";
        cur = cur->next;
    }
    cout << endl;
}
