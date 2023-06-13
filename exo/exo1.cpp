// Insertion sort in C++

#include <iostream>
using namespace std;

void f5(int n) {
    if(n > 0) {
        f5(n-2);
        f5(n-1);
    }
    if(n >= 0)
        cout << n << " ";
}

int main() {
    f5(3);
}