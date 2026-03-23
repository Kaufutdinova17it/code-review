
#include <iostream>

//FIX_ME: не было безопасного ввода
// старый код
// cin >> x;
// новый код
bool safe_input_int(int& x);

class DoublyList {
private:
    struct Node {
        int data;
        Node* prev;
        Node* next;

        //FIX_ME: конструктор был без стиля и с русским именем
        // старый код
        // Uzel(int Znachenie) : Znachenie(Znachenie), Predydushiy(nullptr), Sleduyushiy(nullptr) {}
        // новый код
        explicit Node(int value);
    };

    //FIX_ME: имя поля инициализировалось отдельным методом
    // старый код
    // Uzel* PerviyElement;
    // новый код
    Node* head_;

public:
    //FIX_ME: инициализация списка делалась отдельной процедурой Initsializatsiya
    // старый код
    // void Initsializatsiya();
    // новый код
    DoublyList();

    ~DoublyList();

    //FIX_ME: имя метода DobavitElement не по стилю
    // старый код
    // void DobavitElement(int Znachenie);
    // новый код
    void push_back(int value);

    //FIX_ME: имя метода VivodSpiska не по стилю
    // старый код
    // void VivodSpiska();
    // новый код
    void print_list() const;

    //FIX_ME: имя метода PoiskMinMax не по стилю
    // старый код
    // void PoiskMinMax(Uzel*& Min, Uzel*& Max);
    // новый код
    void find_min_max(Node*& min_node, Node*& max_node) const;

    //FIX_ME: имя метода ProverkaPoryadka не по стилю
    // старый код
    // bool ProverkaPoryadka(Uzel* A, Uzel* B);
    // новый код
    bool is_first_before_second(Node* a, Node* b) const;

    //FIX_ME: имя метода VivodMezhduMinMax не по стилю
    // старый код
    // void VivodMezhduMinMax();
    // новый код
    void print_between_min_max() const;

    //FIX_ME: имя метода Ochistka не по стилю
    // старый код
    // void Ochistka();
    // новый код
    void clear();
};


