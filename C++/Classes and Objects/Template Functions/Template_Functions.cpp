
#include "stdafx.h"
#include "User.h"

//not much here. most of functionality was realized in header file this time for saving some time purpose
User::User()
{
}
ostream &operator <<(ostream &os, const User &m)
{

	os << m.iAge << " " << m.strName<<" ";
	
	return os;
}

User::~User()
{
}
