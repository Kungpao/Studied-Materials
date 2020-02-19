#pragma once
template<typename T>
class MyVector
{
	T *p;
	size_t s;
public:

  //Constructor default
	MyVector(void) :p(nullptr), s(0)
	{

	}
  
  //DESTRUCTOR
	~MyVector(void)
	{
		delete[]this->p;
	}
  
  //method for return the size
	const size_t &Size(void)const 
	{
		return this->s;
	}

  //operator [] overload. #1 of 2 const variation
	const T &operator [](const size_t &i) const // перегрузка оператора доступа по индексу. два метода.
	{
		return this->p[i];
	}
  
  //operator [] overload. #2 of 2
	T & operator [] (const size_t &i)
	{
		return this->p[i];
	}
  
  //explicit constructor. delegating to default then allocating dynamic memory for a received size 
	explicit MyVector(const size_t s) :MyVector()// метод получает в параметры размер. выделяет память под													указатель.
	{
		this->p = new T[s];
		this->s = s;
	}
  
  //separate realization of constructor copy #1of2. Protorype. just for practise
	MyVector(const MyVector&);
};

//separate realization of constructor copy #2of2
template<typename T>
MyVector<T>::MyVector(const MyVector<T> &v): MyVector<T>(v.s)
{
	for (size_t i = 0; i < v.s;i++)
		this->p[i] = v[i];
}
