
#include <iostream>

//FIX_ME: не было безопасного ввода
// старый код
// cin >> x;
// новый код
bool safe_input(int& x);

class LinkedList {
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

    //FIX_ME: имя head было p
    // старый код
    // Node* p;
    // новый код
    Node* head_;

public:
    LinkedList();
    ~LinkedList();

    //FIX_ME: имя add нарушало стиль
    // старый код
    // void add(int x);
    // новый код
    void add_node(int value);

    void print_list() const;

    //FIX_ME: метод не соответствовал названию
    // старый код
    // void insertM(int m);
    // новый код
    void insert_before_every_second(int m);

    Node* get_last_node() const;
    void clear_list();
};


