#include "stdafx.h"
#include "Matrix.h"


//not using at this sample
Matrix::Matrix()
{
}

//operator() realizations
const int &Matrix:: operator() (const size_t &row, const size_t &col) const
{
	return this->m[row][col];
}

int &Matrix::operator() (const size_t &row, const size_t &col)
{
		return this->m[row][col];
}

void Matrix::operator() (void)
{
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++)
			this->m[i][j] = 0;
}


//Some cosmetics functions body realization
void Matrix::Matrix_Print()
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
			cout << m[i][j] << " ";
		cout << endl;
	}
}
void Matrix::Matrix_Rnd()
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
			this->m[i][j] = rand() % 10;
	}
}

//destructor. beacause matrix is static this time.
Matrix::~Matrix()
{

}
