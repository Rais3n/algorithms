#include <iostream>

using namespace std;

void roses(int A[]) {
	int suma;
	int koniec;
	int wpis;
	while (A[1] != 1) {
		suma = 0;
		koniec = 2;
		while (A[koniec] == 1) {
			suma++;
			koniec--;
		}
		wpis = A[koniec] - 2;
		suma = suma + A[koniec];
		while (suma > wpis) {
			A[koniec] = wpis;
			koniec++;
			suma -= wpis;
		}
		if (suma % 2 == 1) {
			A[koniec] = suma;
			//print A
		}
		else {
			A[koniec] = suma - 1;
			koniec++;
			A[koniec] = 1;
		}
	}

}

//int main() {
//	int A[100];
//	int n = 12;
//	A[1] = n - 1;
//	A[2] = 1;
//
//}