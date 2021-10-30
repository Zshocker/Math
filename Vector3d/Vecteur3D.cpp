#include"pch.h"
#include "Vector3D.h"
#include<iostream>
using namespace std;
// TODO: This is an example of a library function


Math3d::Vector3D::Vector3D(float x, float y, float z)
{
	this->Vect[0] = x;
	this->Vect[1] = y;
	this->Vect[2] = z;
}

void Math3d::Vector3D::Print()
{
	cout << "{ " << this->Vect[0] << ", " << this->Vect[1] << ", " << this->Vect[2] << " }";
}

float Math3d::Vector3D::at(unsigned int a)const
{
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
}

float& Math3d::Vector3D::operator[](unsigned int a)
{
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
}

bool Math3d::Vector3D::operator==(const Vector3D& B)const
{
	for (int i = 0; i < 3; i++)
	{
		if (this->Vect[i] != B.Vect[i])return false;
	}
	return true;
}

bool Math3d::Vector3D::operator!=(const Vector3D& B)const
{
	return !(*this==B);
}
