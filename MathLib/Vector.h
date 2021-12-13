#pragma once
#include<iostream>
using namespace std;
namespace Math {
	template<class T>
	class Matrix;
	template<class T>
	class Vector3D
	{
		T Vect[3];
	public:
		Vector3D(const Vector3D&) = delete;
		Vector3D(T x = 0, T y = 0, T z = 0) {
			this->Vect[0] = x;
			this->Vect[1] = y;
			this->Vect[2] = z;
		};
		void Print() {
			cout << "{ " << this->Vect[0] << ", " << this->Vect[1] << ", " << this->Vect[2] << " }";
		};
		T at(unsigned int a)const {
			try
			{
				if (a >= 0 && a <= 2)return this->Vect[a];
				throw "range error";
			}
			catch (string S)
			{
				cout << S << endl;
			}
			float b = 0.0;
			return b;
		};
		T& operator[](unsigned int a) {
			try
			{
				if (a >= 0 && a <= 2)return this->Vect[a];
				throw "range error";
			}
			catch (string S)
			{
				cout << S << endl;
			}
			T b = 0.0;
			return b;
		};
		bool operator==(const Vector3D&B)const {
			for (int i = 0; i < 3; i++)
			{
				if (this->Vect[i] != B.Vect[i])return false;
			}
			return true;
		};
		bool operator!=(const Vector3D&B)const {
			return !(*this == B);
		};
		Vector3D& operator=(const Vector3D&) = delete;
		Matrix<T>* TurnToMatrix() {
			Matrix<T>* New = new Matrix<T>(3, 1);
			for (int i = 0; i < 3; i++)
			{
				(*New)[0][i] = (*this)[i];
			}
			return New;
		};
	};
}