#include "stdafx.h"
#include "TripleGrafic.h"

// body realization. setting default values to NULL
Child::Child()
{
}
//Setting params values
Child::Child(const int&a, const int &b, const int &c):Parrent(a,b),c(c)
{
}
//default destructor
Child::~Child()
{
}
