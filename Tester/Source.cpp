#include"Matrix.h"
void main() {
	Matrix Ar(2, 4);
	Ar.Remplissage(4);
	Matrix AT(5,2);
	AT.Remplissage(5);
	Matrix* Se = AT * Ar;
	Se->Print();
}