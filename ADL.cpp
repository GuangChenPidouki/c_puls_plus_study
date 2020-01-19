#include <iostream>
#include <typeinfo>
void f() { std::cout << "::f()\n"; }
namespace N1
{
   struct A
   {
      friend void f() { std::cout << "N1::f()\n"; }
      friend void f(A *) { std::cout << "N1::f(A *)" << std::endl; }
      //void h() { f();  f(this);}
      //void g();
   };
   //void A::g() { f(); f(this); }
}

class Person
{
	public:
		Person(int p) : private_info(p) {std::cout << "cp ctor" << p << std::endl;} 
		void snoop(Person *other_person);
	private:
		int private_info;
};

void Person::snoop(Person *other_person)
{
	std::cout << this->private_info << other_person->private_info << std::endl;
}

class C;
class B
{
	static B zero;
public:
	B(){}
	B(int i){}
	C* c;
};

class C
{
	B* b;
};

struct String
{
	String(const char* const s): buf(s) {}
	String(int length_): buf(0) {}
	int length;
	const char* const buf;
};

void print(const String& s)
{
	std::cout << s.buf << std::endl;
}


int main()
{
   N1::A a;
   //a.h();
   //a.g();
	Person s2(2);
	Person s3 = 3;
	s2.snoop(&s3);
	B b;   
	B b1(); 
	B b2(3); 
	std::cout << typeid(b).name() << std::endl;
	std::cout << typeid(b1).name() << std::endl;
	std::cout << typeid(b2).name() << std::endl;

	int nl = 100;
	print(nl);
}

