#include "iostream"

using namespace std;

void f1(int n) {
    if(n > 0) {
        cout << n << " ";
        f1(n-1);
        f1(n-1);
    }
}

int main(){
    int i = 3;
    f1(3);
}