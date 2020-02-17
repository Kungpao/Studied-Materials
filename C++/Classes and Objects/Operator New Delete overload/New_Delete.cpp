#include "stdafx.h"
#include "A.h"


A::A()
{
}


A::~A()
{
}

//body realizations
void  *A:: operator new (size_t value)
{
	cout << "My operator new" << endl;
	return::operator new(value);
}

void A:: operator delete(void *p, size_t value)
{
	cout << "My operator delete" << endl;
	:: operator delete(p, value);
}
