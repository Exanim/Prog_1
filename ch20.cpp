#include "std_lib_facilities.h"
#include <stdexcept>
#include <vector>
#include <algorithm>
#include <list>
#include <array>
#include <string>

template<typename C>
void print_contents(const C& c, const string& s = "")
{
    cout << s << '\t';
    for (auto& a : c)
        cout << a << ' ';
    cout << '\n';
}

template<typename C>
void inc_contents(C& c, int n = 1)
{
    for (auto& a : c)
        a += n;
}

template<typename Iter1, typename Iter2>
Iter2 my_copy(Iter1 f1, Iter1 e1, Iter2 f2)
{
    for (Iter1 p = f1; p != e1; ++p)
        *f2++ = *p;
    return f2;
}

int main()
try {
    constexpr int size = 10;

    int arr[size]; 
    for (int i = 0; i < size; ++i) arr[i] = i;
    print_contents(arr, "built-in []: ");

    array<int, size> ai;
    copy(arr, arr + size, ai.begin());
    print_contents(ai, "array: ");

    vector<int> vi(size);
    copy(arr, arr + size, vi.begin());
    print_contents(vi, "vector: ");

    list<int> li(size);
    copy(arr, arr + size, li.begin());
    print_contents(li, "list: ");

    cout << '\n';

    array<int, size> ai2 = ai;
    vector<int> vi2 = vi;
    list<int> li2 = li;
    print_contents(ai2, "array copy: ");
    print_contents(vi2, "vector copy: ");
    print_contents(li2, "list copy: ");

    cout << '\n';

    inc_contents(ai2, 2);
    inc_contents(vi2, 3);
    inc_contents(li2, 5);
    print_contents(ai2, "array inc'd: ");
    print_contents(vi2, "vector inc'd: ");
    print_contents(li2, "list inc'd: ");

    cout << '\n';

    my_copy(ai2.begin(), ai2.end(), vi2.begin());
    my_copy(li2.begin(), li2.end(), ai2.begin());
    print_contents(ai2, "array copied: ");
    print_contents(vi2, "vector copied: ");
    print_contents(li2, "list copied: ");

    vector<int>::iterator vit;
    vit = find(vi2.begin(), vi2.end(), 3);
    if (vit != vi2.end())
        cout << "Found at: " << distance(vi2.begin(), vit) << '\n';
    else
        cout << "Not found..\n";

    list<int>::iterator lit;
    lit = find(li2.begin(), li2.end(), 27);
    if (lit != li2.end())
        cout << "Found at: " << distance(li2.begin(), lit) << '\n';
    else
        cout << "Not found..\n";
}
catch(exception& e) {
    cerr << "Exception: " << e.what() << '\n';
    return 1;
}
catch(...) {
    cerr << "Unknown exception\n";
    return 2;
}

