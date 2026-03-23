
#include <iostream>
#include <deque>
#include <list>

//FIX_ME: не было безопасного ввода
// старый код
// cin >> x;
// новый код
bool safe_input_int(int& x);

template <typename Container>
void input_container(Container& container, int n);

template <typename Container>
void print_container(const Container& container);

void insert_last_five_reversed(const std::deque<int>& d, std::list<int>& l);

