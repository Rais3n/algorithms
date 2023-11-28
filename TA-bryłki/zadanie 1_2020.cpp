#include <iostream>

using namespace std;

int globalS = 4;
int globalM = 4;

void igrzyska(int A[], int W[], int pos, int D, int S,int M, int start) {
	/*if (pos == D + globalS && S == 1) {             // nie potrzebne, ale zostawi³em sobie w razie czego
		for (int i = 1; i < D + globalS; i++)
			cout << A[i] << " ";
		cout << "\n";
		return;
	}*/
	for (int i = start; i <= D; i++) {
		if (W[i] == 0) {
			A[pos] = i;
			W[i] = 1;
			if(M>1)
			igrzyska(A, W, pos + 1, D, S, M-1, i + 1);
			if (S > 1) {
				A[pos + 1] = 0;
				igrzyska(A, W, pos + 2, D, S - 1,globalM , 0);
			}
			if (pos == D + globalS - 1 && S == 1) {
				for (int i = 1; i < D + globalS; i++)
					cout << A[i] << " ";
				cout << "\n";
			}
			W[i] = 0;
		}
		if (i == 0 && S>1) {
			A[pos] = 0;
			igrzyska(A, W, pos + 1, D, S - 1, globalM, 0);
		}
	}
}

int main() {
	int A[100];
	int W[100];
	for (int i = 1; i < 100; i++)
		W[i] = 0;

	igrzyska(A, W, 1, 4, globalS,globalM,0);
}