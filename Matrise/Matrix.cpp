#include "pch.h"
#include "Matrix.h"
#include<iostream>
#include"assert.h"
using namespace std;
Matrix::Matrix(unsigned int numC, unsigned int numL)
{
	assert(numC!=0&&numL!=0);
	this->numC = numC;
	this->numL = numL;
	this->Matx = new int*[numL];
	for (int i = 0; i < numL; i++)this->Matx[i] =new int[numC];
	for (int i = 0; i < numL; i++)
	{
		for (int j = 0; j < numC; j++)
		{
			this->Matx[i][j] = 0;
		}
	}
}

void Matrix::Remplissage(int elem)
{
	for (int i = 0; i < this->numL; i++)
	{
		for (int j = 0; j < this->numC; j++)
		{
			this->Matx[i][j] = elem;
		}
	}
}

Matrix& Matrix::operator+(const Matrix& R) const
{
	assert(this->numC==R.numC&&this->numL==R.numC);
	Matrix *pt=new Matrix(this->numC, this->numL);
	for (int i = 0; i < this->numL; i++)
	{
		for (int j = 0; j < this->numC; j++)
		{
			pt->Matx[i][j] = this->Matx[i][j] + R.Matx[i][j];
		}
	}
	return *pt;
}

Matrix& Matrix::operator+(int elem) const
{
	Matrix* pt = new Matrix(this->numC, this->numL);
	for (int i = 0; i < this->numL; i++)
	{
		for (int j = 0; j < this->numC; j++)
		{
			pt->Matx[i][j] = this->Matx[i][j] + elem;
		}
	}
	return *pt;
}

Matrix& Matrix::operator-(const Matrix& R) const
{
	assert(this->numC == R.numC && this->numL == R.numC);
	Matrix* pt = new Matrix(this->numC, this->numL);
	for (int i = 0; i < this->numL; i++)
	{
		for (int j = 0; j < this->numC; j++)
		{
			pt->Matx[i][j] = this->Matx[i][j] - R.Matx[i][j];
		}
	}
	return *pt;
}

Matrix& Matrix::operator-(int elem) const
{
	Matrix* pt = new Matrix(this->numC, this->numL);
	for (int i = 0; i < this->numL; i++)
	{
		for (int j = 0; j < this->numC; j++)
		{
			pt->Matx[i][j] = this->Matx[i][j] - elem;
		}
	}
	return *pt;
}

Matrix& Matrix::operator*(int elem) const
{
	Matrix* pt = new Matrix(this->numC, this->numL);
	for (int i = 0; i < this->numL; i++)
	{
		for (int j = 0; j < this->numC; j++)
		{
			pt->Matx[i][j] = this->Matx[i][j] * elem;
		}
	}
	return *pt;
}

void Matrix::Print() const
{
	for (int i = 0; i < this->numL; i++)
	{
		for (int j = 0; j < this->numC; j++)
		{
			cout << "," << this->Matx[i][j];
		}
		cout << endl;
	}
}

Matrix::~Matrix()
{
	for (int i = 0; i < this->numL; i++)
	{
		delete this->Matx[i];
		this->Matx = NULL;
	}
	delete this->Matx;
	this->Matx = NULL;
}
