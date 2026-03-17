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

//FIX_ME: конструктор был без стил€
// старый код
// Node(int d) : data(d), next(nullptr) {}
// новый код
LinkedList::Node::Node(int value) : data(value), next(nullptr) {}

LinkedList::LinkedList() : head_(nullptr) {}

LinkedList::~LinkedList() {
    clear_list();
}

//FIX_ME: им€ add нарушало стиль
// старый код
// void add(int x)
// новый код
void LinkedList::add_node(int value) {
    Node* new_node = new Node(value);

    if (head_ == nullptr) {
        head_ = new_node;
        return;
    }

    Node* cur = head_;
    while (cur->next != nullptr) {
        cur = cur->next;
    }
    cur->next = new_node;
}

void LinkedList::print_list() const {
    if (head_ == nullptr) {
        cout << "—писок пуст." << endl;
        return;
    }

    cout << "—писок: ";
    Node* cur = head_;
    while (cur != nullptr) {
        cout << cur->data << " ";
        cur = cur->next;
    }
    cout << endl;
}

//FIX_ME: метод не соответствовал названию
// старый код
// void insertM(int m)
// новый код
void LinkedList::insert_before_every_second(int m) {
    if (head_ == nullptr || head_->next == nullptr) {
        cout << "Ќедостаточно элементов дл€ вставки." << endl;
        return;
    }

    int count = 1;
    Node* cur = head_;

    while (cur != nullptr && cur->next != nullptr) {
        if (count % 2 == 0) {
            Node* new_node = new Node(m);
            new_node->next = cur->next;
            cur->next = new_node;
            cur = new_node->next;
        }
        else {
            cur = cur->next;
        }
        count++;
    }
}

LinkedList::Node* LinkedList::get_last_node() const {
    if (head_ == nullptr) return nullptr;

    Node* cur = head_;
    while (cur->next != nullptr) {
        cur = cur->next;
    }
    return cur;
}

void LinkedList::clear_list() {
    while (head_ != nullptr) {
        Node* temp = head_;
        head_ = head_->next;
        delete temp;
    }
}
