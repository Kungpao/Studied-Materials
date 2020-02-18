#pragma once
class B;

class C;

class A
{
public:
	A();
	void Set(B &);
	void Set(C &);

	~A();
};

class B
{
	int value;
public:
	B(void) :value(0)
	{

	}
	int Get(void) const
	{
		return this->value;
	}

	//Marking a whole class A as a friend
	friend class A;
};

class C
{
	int value;
public:
	C(void) :value(0)
	{

	}
	int Get(void) const
	{
		return this->value;
	}

	//Marking only  method of class A as a friend
	friend void A::Set(C&);
};
