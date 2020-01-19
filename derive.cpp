#include<iostream>

using namespace std;

class Base{
public:
	void func(double){cout << "base double" << endl;}
private:
	void func(int){cout << "base int" << endl;}
};

class Derived : public Base{
public:
	using Base::func;
	void func(int a){cout << "derived int" << a << endl;}
};

int main()
{
	Derived d;
	d.func(1234);
	d.func(12.34);
}
