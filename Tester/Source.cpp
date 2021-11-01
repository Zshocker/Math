#include"MathClasses.h"
using namespace Math;
void main() {
	Vector3D V1(1, 2, 3);
	Matrix* N = V1.TurnToMatrix();
	Matrix* T = new Matrix(3,1);
	(*T)[0][1] = 5;
	(*T)[0][0] = 1;
	(*T)[0][2] = 3;
	Vector3D* V2 = T->TurnToVect();
	V2->Print();
	N->Print();
}