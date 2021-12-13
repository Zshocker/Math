#include"Vector.h"
#include"Matrix.h"
#include"queue.h"
#include"Stack.h"
using namespace Math;
using namespace Algo;
void main() {
	/*Vector3D<float> V1(1, 2, 3);
	Matrix<float>* N = V1.TurnToMatrix();
	Matrix<float>* T = new Matrix<float>(3,1);
	(*T)[0][1] = 5;
	(*T)[0][0] = 1;
	(*T)[0][2] = 3;
	Vector3D<float>* V2 = T->TurnToVect();
	V2->Print();
	N->Print();*/
	Stack<float> stack;
	stack.push(50);
	stack.push(4);
	stack.push(7);
	stack.push(4);
	stack.push(5);
	stack.push(4);
	stack.pop();
	stack.pop();
	stack.Print();
	Queue<float> ques;
	ques.add(50);
	ques.add(4);
	ques.add(7);
	ques.add(4);
	ques.add(5);
	ques.add(4);
	ques.Print();
}