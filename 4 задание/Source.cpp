// DoublyList.cpp
#include "Header.h"

using std::cout;
using std::endl;

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

//FIX_ME: конструктор узла использовал русские имена полей
// старый код
// Uzel(int Znachenie) : Znachenie(Znachenie), Predydushiy(nullptr), Sleduyushiy(nullptr) {}
// новый код
DoublyList::Node::Node(int value) : data(value), prev(nullptr), next(nullptr) {}

DoublyList::DoublyList() : head_(nullptr) {}

DoublyList::~DoublyList() {
    clear();
}

//FIX_ME: метод DobavitElement имел русское имя и работал с Uzel
// старый код
// void DobavitElement(int Znachenie) { ... }
// новый код
void DoublyList::push_back(int value) {
    Node* new_node = new Node(value);

    if (head_ == nullptr) {
        head_ = new_node;
        return;
    }

    Node* current = head_;
    while (current->next != nullptr) {
        current = current->next;
    }

    current->next = new_node;
    new_node->prev = current;
}

//FIX_ME: метод VivodSpiska имел русское имя
// старый код
// void VivodSpiska() { ... }
// новый код
void DoublyList::print_list() const {
    if (head_ == nullptr) {
        cout << "Список пуст." << endl;
        return;
    }

    Node* current = head_;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

//FIX_ME: метод PoiskMinMax использовал русские имена и тип Uzel
// старый код
// void PoiskMinMax(Uzel*& Min, Uzel*& Max) { ... }
// новый код
void DoublyList::find_min_max(Node*& min_node, Node*& max_node) const {
    if (head_ == nullptr) {
        min_node = nullptr;
        max_node = nullptr;
        return;
    }

    min_node = head_;
    max_node = head_;
    Node* current = head_->next;

    while (current != nullptr) {
        if (current->data < min_node->data) {
            min_node = current;
        }
        if (current->data > max_node->data) {
            max_node = current;
        }
        current = current->next;
    }
}

//FIX_ME: метод ProverkaPoryadka использовал русские имена
// старый код
// bool ProverkaPoryadka(Uzel* A, Uzel* B) { ... }
// новый код
bool DoublyList::is_first_before_second(Node* a, Node* b) const {
    Node* current = head_;
    while (current != nullptr) {
        if (current == a) {
            return true;
        }
        if (current == b) {
            return false;
        }
        current = current->next;
    }
    return false;
}

//FIX_ME: метод VivodMezhduMinMax имел русское имя
// старый код
// void VivodMezhduMinMax() { ... }
// новый код
void DoublyList::print_between_min_max() const {
    Node* min_node = nullptr;
    Node* max_node = nullptr;
    find_min_max(min_node, max_node);

    if (min_node == nullptr || max_node == nullptr || min_node == max_node) {
        cout << "Нет элементов для вывода!" << endl;
        return;
    }

    bool min_first = is_first_before_second(min_node, max_node);
    Node* start = min_first ? min_node : max_node;
    Node* end = min_first ? max_node : min_node;

    cout << "Элементы между " << min_node->data << " и " << max_node->data << ": ";

    Node* current = start->next;
    bool has_elements = false;

    while (current != nullptr && current != end) {
        cout << current->data << " ";
        has_elements = true;
        current = current->next;
    }

    if (!has_elements) {
        cout << "отсутствуют";
    }
    cout << endl;
}

//FIX_ME: метод Ochistka имел русское имя
// старый код
// void Ochistka() { ... }
// новый код
void DoublyList::clear() {
    Node* current = head_;
    while (current != nullptr) {
        Node* temp = current;
        current = current->next;
        delete temp;
    }
    head_ = nullptr;
}
