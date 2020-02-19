#pragma once
template<typename T=char,size_t s=10>
class MyVector1
{
	T t[s];
	size_t size;
public:
	
	//constructor default. receives size
	MyVector1(void) :size(s)
	{

	}
	
	//method wich returns own size
	const size_t &Size(void) const
	{
		return this->size;
	}
	
	//operator [] overload. #1of2. const
	const T & operator[] (const size_t &i)const
	{
		return this->t[i];
	}

	//operator [] overload. #2of2. no const
	T & operator[](const size_t &i)
	{
		return this->t[i];
	}
};
