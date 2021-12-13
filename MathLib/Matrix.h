#pragma once
#include<iostream>
#include"assert.h"
using namespace std;
namespace Math {
	template<class T>
	class Vector3D;
	template<class T>
	class Matrix
	{
		int numL;
		int numC;
		T** Matx;
	public:
		Matrix(unsigned int numC, unsigned int numL) {
			assert(numC != 0 && numL != 0);
			this->numC = numC;
			this->numL = numL;
			this->Matx = new T* [numL];
			for (int i = 0; i < numL; i++)
			{
				this->Matx[i] = new T[numC]();
			}
		}
		Matrix(const Matrix&) = delete;
		void Remplissage(T elem) {
			for (int i = 0; i < this->numL; i++)
			{
				for (int j = 0; j < this->numC; j++)
				{
					this->Matx[i][j] = elem;
				}
			}
		}
		Matrix& operator=(const Matrix&)const = delete;
		Matrix& operator+(const Matrix&R)const {
			assert(this->numC == R.numC && this->numL == R.numC);
			Matrix* pt = new Matrix(this->numC, this->numL);
			for (int i = 0; i < this->numL; i++)
			{
				for (int j = 0; j < this->numC; j++)
				{
					pt->Matx[i][j] = this->Matx[i][j] + R.Matx[i][j];
				}
			}
			return *pt;
		};
		Matrix& operator-(const Matrix&R)const {
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
		Matrix& operator*(const Matrix&R)const {
			assert(this->numC == R.numL);
			Matrix* nM = new Matrix(R.numC, this->numL);
			for (int i = 0; i < nM->numL; i++)
			{
				for (int j = 0; j < nM->numC; j++)
				{
					nM->Matx[i][j] = 0;
					for (int k = 0; k < this->numC; k++)
					{
						nM->Matx[i][j] += this->Matx[i][k] * R.Matx[k][j];
					}
				}
			}
			return *nM;
		};
		Matrix& operator*(T elem)const {
			Matrix* pt = new Matrix(this->numC, this->numL);
			for (int i = 0; i < this->numL; i++)
			{
				for (int j = 0; j < this->numC; j++)
				{
					pt->Matx[i][j] = this->Matx[i][j] * elem;
				}
			}
			return *pt;
		};
		float* operator[](int i) {
			assert(this->numL > i);
			return this->Matx[i];
		}
		Vector3D<T>* TurnToVect() {
			assert(this->numL == 1 && this->numC == 3);
			Vector3D<T>* E = new Vector3D<T>();
			for (int i = 0; i < 3; i++)
			{
				(*E)[i] = (*this)[0][i];
			}
			return E;
		};
		void Print()const {
			cout << endl << "{ ";
			for (int i = 0; i < this->numL; i++)
			{
				for (int j = 0; j < this->numC; j++)
				{
					cout << this->Matx[i][j];
					if (j != this->numC - 1) cout << ",";
				}
				if (this->numL - 1 != i)cout << endl << "  ";
			}
			cout << " }";
		};
		~Matrix() {
			for (int i = 0; i < this->numL; i++)
			{
				delete[] this->Matx[i];
				this->Matx[i] = NULL;
			}
			delete this->Matx;
			this->Matx = NULL;
		};
	};
};
