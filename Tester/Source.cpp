#include"Vector.h"
#include"Matrix.h"
using namespace Math;
void main() {
	Vector3D<float> V1(1, 2, 3);
	Matrix<float>* N = V1.TurnToMatrix();
	Matrix<float>* T = new Matrix<float>(3,1);
	(*T)[0][1] = 5;
	(*T)[0][0] = 1;
	(*T)[0][2] = 3;
	Vector3D<float>* V2 = T->TurnToVect();
	V2->Print();
	N->Print();
}