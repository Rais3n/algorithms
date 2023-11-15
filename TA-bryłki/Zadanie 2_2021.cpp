#include <iostream>

using namespace std;

void Presents(int M, int k, int A[][100], int W[], int pos, int santa) {

	if (santa == 0) {
		for (int i = 1; i <= M; i++) {
			cout << i << "Mikolaj: ";
			for (int j = 1; j <= k; j++) {
				cout << A[i][j]<<" ";
			}
		}
		cout << "\n";
		return;
	}

	for (int i = 1; i <= M * k; i++) {
		if (W[i] == 0) {
			A[santa][pos] = i;
			W[i] = 1;
			if (pos < k)
				Presents(M, k, A, W, pos + 1, santa);
			else if(pos==k)
				Presents(M, k, A, W, 1, santa - 1);
			W[i] = 0;
		}
	}
}

//int main() {
//	int A[100][100];
//	int W[100];
//	for (int i = 1; i < 100; i++)
//		W[i] = 0;
//	Presents(3, 2, A, W, 1, 3);
//}