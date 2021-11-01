#pragma once
namespace Math {
	class Vector3D;
	class Matrix
	{
		int numL;
		int numC;
		float** Matx;
	public:
		Matrix(unsigned int numC, unsigned int numL);
		Matrix(const Matrix&) = delete;
		void Remplissage(float elem);
		Matrix& operator=(const Matrix&)const = delete;
		Matrix* operator+(const Matrix&)const;
		Matrix* operator-(const Matrix&)const;
		Matrix* operator*(const Matrix&)const;
		Matrix* operator*(int elem)const;
		float* operator[](int i);
		Vector3D* TurnToVect();
		void Print()const;
		~Matrix();
	};
	class Vector3D
	{
		float Vect[3];
	public:
		Vector3D(const Vector3D&) = delete;
		Vector3D(float x = 0, float y = 0, float z = 0);
		void Print();
		float at(unsigned int)const;
		float& operator[](unsigned int);
		bool operator==(const Vector3D&)const;
		bool operator!=(const Vector3D&)const;
		Vector3D& operator=(const Vector3D&) = delete;
		Matrix* TurnToMatrix();
	};
};