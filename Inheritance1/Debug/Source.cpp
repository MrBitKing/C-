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

class B {
	int i;
public:
	B() { cout << "B::B()" << endl; }
	B(int ii) : i(ii) { cout << "B::B(int)" << endl; }
	B(B& RB) {
		cout << "B::B(B&)" << endl;
		i = RB.i;
	}
	~B() { cout << "B::~B()" << endl; }
	void f() { cout << "B::f()" << endl; }
};

// C "is-a" B (Inheritance), C "has-a" A (Composition)
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

int main() {
	cout << "\tInstantiate b" << endl;
	B b;
	cout << "\tInstantiate default c - note order of creation" << endl;
	C c0;
	cout << "\tInstantiate c" << endl;
	C c(47);

	cout << "\tUsing heap memory to show the order of destruction" << endl;
	cout << "\tInstantiate with new" << endl;
	C* pHeap = new C(1);
	cout << "\tkill with delete" << endl;
	delete pHeap;

	cout << "\tc.f()" << endl;
	c.f();		// C::f()
	cout << "\texplicit c.B::f();" << endl;
	c.B::f();	// B::f()
	cout << "\tf();" << endl;
	f();		// ::f();

	cout << "\t** Upcast *******" << endl;
	cout << "\t((B)c).f()" << endl;
	((B)c).f();
	cout << "\t** Upcast the new way in C++ *******" << endl;
	cout << "\tstatic_cast<B>(c).f()" << endl;
	static_cast<B>(c).f();

	cout << "\tC copy constructor" << endl;
	C cc(c);
	cout << "\tcc.f()" << endl;
	cc.f();


	cout << "\t** Using pointers *******" << endl;
	C* pc = new C(10);
	cout << "\tpc->f()" << endl;
	pc->f();
	cout << "\t** Upcasting a pointer between related types *******" << endl;
	B* pb = static_cast <B*>(pc);
	cout << "\tpb->f()" << endl;
	pb->f();
	cout << "\t** Upcasting a pointer between unrelated types *******" << endl;
	B* pbb = reinterpret_cast <B*>(pc);
	cout << "\tpb->f()" << endl;
	pbb->f();

	cout << "\t** attempting polymorphism with objects and failing *******" << endl;
	B BArray[] = { b, c };
	cout << "\tBArray[0].f()" << endl;
	BArray[0].f();
	cout << "\tBArray[1].f()" << endl;
	BArray[1].f();


	cout << "\t** attempting polymorphism with pointers (fails without virtual) *******" << endl;
	B* pB = &b;
	cout << "\tpB->f()" << endl;
	pB->f();
	cout << "\tpB = &c" << endl;
	pB = &c;
	cout << "\tpB->f()" << endl;
	pB->f();

	cout << endl << "\t*** deleting pc *******" << endl;
	delete pc;

	cout << "\t*** End of code *******" << endl;
	cout << "\tAll objects call their destructors in reverse order of instantiation" << endl;
} ///:~