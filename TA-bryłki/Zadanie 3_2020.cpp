#include <iostream>

using namespace std;


void PossibleMedals(int D, int A[], int K,int currentNumOfMedals,int pos) {
	if (pos <= K) {
		for (int i = K - pos; i < A[pos - 1]; i++) {
			A[pos] = i;
			currentNumOfMedals += i;
			PossibleMedals(D, A, K, currentNumOfMedals, pos + 1);
			currentNumOfMedals -= i;
		}
	}
	else if (pos > K && pos <= 2*K) {
		for (int i = A[pos - 1] + 1; ( currentNumOfMedals + i + (2*K - pos)*(1 + 2 * K - pos)/2 ) < D; i++) {
			A[pos] = i;
			currentNumOfMedals += i;
			PossibleMedals(D, A, K, currentNumOfMedals, pos + 1);
			currentNumOfMedals -= i;
		}
	}
	else {
		for (int i = 1; i <= 2 * K; i++) {
			cout << i << ":  " << A[i] << " medali  ";
		}
		cout << "\n";
	}
}

//int main() {
//	int A[100];
//	int K = 2;
//	int D = 30;
//	for (int i = K - 1; i <= (2 * D / K + K - 1) / 4; i++) {
//		A[1] = i;
//		PossibleMedals(D, A, K, i,2);
//	}
//
//}