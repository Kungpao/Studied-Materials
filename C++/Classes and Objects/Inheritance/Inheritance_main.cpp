
#include "stdafx.h"
#include <iostream>
#include "Parrent.h"
#include "Child.h"

// inheritance
class A
{
	//making some fields for a test
private:
	int a;

protected:
	int b;

public:
	int c;
	//default constructor
	A(void)
	{
		std::cout << "A constructor " << std::endl;
	}
	//default destructor
	~A(void)
	{
		std::cout << "~A destructor " << std::endl;
	}
	//simple method
	void F(void)
	{
		std::cout << "Class A void F (void) Method " << std::endl;
	}
};

//class B is inherit class A
class B: A
{

public:
	//default constructor
	B(void)
	{
		std::cout << "B constructor " << std::endl;
	}
	//default destructor
	~B(void)
	{
		std::cout << "~B destructor " << std::endl;
	}

	//some method to show class's fields
	void Show(void)
	{
		std::cout << this->b << std::endl;
		std::cout << this->c << std::endl;
	}
	//accesing class A method 
	A::F;

};
int main()
{
	//some accesebility checks
	std::cout << "Declaring class B object: " << std::endl;
	B b;
	b.F();
	std::cout << "Done " << std::endl;

	std::cout<< "Declaring class DoubleGrafic object: " << std::endl;
	Parrent Dg(5,6);
	std::cout << Dg << std::endl;
	std::cout << "Done " << std::endl;

	std::cout << "Declaring class TrippleGrafic object: " << std::endl;
	Child Tg(7,8,9);
	std::cout << Tg << std::endl;
	std::cout << "Done " << std::endl;

    return 0;
}
