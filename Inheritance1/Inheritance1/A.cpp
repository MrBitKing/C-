//CompositionPlusInheritance1 from
//: C14:Combined.cpp
// Non-polymorphic Inheritance & composition

#include <iostream>
using namespace std;

void f() { cout << "Global f()" << endl; }

class A {
	int i;
public:
	A() { cout << "A::A()" << endl; }
	A(A& RA) {
		cout << "A::A(A&)" << endl;
		i = RA.i;
	}
	A(int ii) : i(ii) { cout << "A::A(int)" << endl; }
	~A() { cout << "A::~A()" << endl; }
	void f() { cout << "A::f()" << endl; }
};
