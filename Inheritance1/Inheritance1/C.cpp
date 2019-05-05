// C "is-a" B (Inheritance), C "has-a" A (Composition)


#include <iostream>
//#include "A"
//#include "B"

using namespace std;
class C : public B {
	A a;
public:
	C() { cout << "C::C()" << endl; }
	C(int ii) : B(ii), a(ii) { cout << "C::C(int)" << endl; }

	C(C& RC) {
		cout << "C::C(C&) - no pseudoconstructors" << endl;
		a = RC.a;
	}
	/*
	// Or explicitly
	C(C& RC):B(RC),a(RC.a){
	cout << "C::C(C&) - with pseudoconstructors" << endl;
	}
	*/
	~C() { cout << "C::~C()" << endl; } // Calls ~A() and ~B()
	void f() { // Redefinition (becomes overridden in polymorphism)
		cout << "C::f()" << endl;
		a.f();	// composition
		B::f(); // explicit base class call
		::f();	// explicit global
	}
};
