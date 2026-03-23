
#include <iostream>

//FIX_ME: не было безопасного ввода
// старый код
// cin >> x;
// новый код
bool safe_input(int& x);

class Stack {
private:
    struct TNode {
        int data;
        TNode* next;

        //FIX_ME: имя параметра было d
        // старый код
        // TNode(int d) : data(d)
        // новый код
        explicit TNode(int value);
    };

    //FIX_ME: имя p1 не отражало смысл
    // старый код
    // TNode* p1;
    // новый код
    TNode* top_;

    int count_;

public:
    Stack();

    //FIX_ME: имя add нарушало стиль
    // старый код
    // void add(int x);
    // новый код
    void push(int value);

    //FIX_ME: имя topdel нарушало стиль
    // старый код
    // void topdel();
    // новый код
    int pop();

    //FIX_ME: имя show нарушало стиль
    // старый код
    // void show();
    // новый код
    void print() const;
};
