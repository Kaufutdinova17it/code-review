
#include <iostream>

//FIX_ME: не было безопасного ввода
// старый код
// cin >> x;
// новый код
bool safe_input(int& x);

class Queue {
private:
    struct Node {
        int data;
        Node* next;

        //FIX_ME: конструктор был без стиля
        // старый код
        // Node(int d) : data(d), next(nullptr) {}
        // новый код
        explicit Node(int value);
    };

    Node* head_;
    Node* tail_;

public:
    Queue();

    //FIX_ME: имя add нарушало стиль
    // старый код
    // void add(int x);
    // новый код
    void enqueue(int value);

    //FIX_ME: имя del нарушало стиль
    // старый код
    // int del();
    // новый код
    int dequeue();

    void print() const;

    // Геттеры для вывода адресов
    Node* get_head() const { return head_; }
    Node* get_tail() const { return tail_; }
};


