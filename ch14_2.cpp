#include"std_lib_facilities.h"

class B2 {
public:
	virtual void pvf() = 0;
};

class D21 : public B2 {
public:
	void pvf() override { cout << s << endl; }
	string s;
};

class D22 : public B2 {
public:
	void pvf() override { cout << i << endl; }
	void f(B2& b2Ref) { b2Ref.pvf(); }
	int i;
};

int main()
{
	D21 d21;
	d21.s = "this is a string";
	
	D22 d22;
	d22.i = 10;

	d22.f(d21);
	d22.f(d22);

	return 0;
}

