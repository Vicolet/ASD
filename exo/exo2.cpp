#include <iostream>

using namespace std;

class C {
	int i;
public:
	C() : i(0) { cout << "CD " << flush; }

	C(int i) : i(i) { cout << "C" << i << " " << flush; }

	~C() { cout << "D" << i << " " << flush; }
};
// Ajouter ici les fonctions f et la fonction g

void *allocateC() {
	return ::operator new(sizeof(C));
}

void f(void *p) {
	new(p) C;
}

void f(void *p, int i) {
	new(p) C(i);
}

void g(C *p) {
	std::destroy_at(p);
}

int main() {
	void *p1 = allocateC(), *p2 = allocateC();
	f(p1);
	f(p2, 4);
	g((C *) p2);
	f(p2, 1);
	g((C *) p1);
	::operator delete(p1);
	f((C *) p2);
	::operator delete(p2);
}