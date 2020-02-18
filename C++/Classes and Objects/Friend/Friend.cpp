#include "stdafx.h"
#include "A.h"


A::A()
{
}

//Setting B class value by A class function
void A::Set(B &b)
{	
	b.value = 10;
}

//Setting C class value by A class function
void A::Set(C &c)
{
	c.value = 20;
}


A::~A()
{
}
