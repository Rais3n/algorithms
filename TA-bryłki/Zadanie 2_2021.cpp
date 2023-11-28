#include <iostream>

using namespace std;

void Zaprzegi(int A[], int W[], int M, int K,int start, int pos) {
	if (pos % K == 1 || K == 1)
		start = 1;
	for (int i = start; i <= K * M; i++) {
		if (W[i] == 0) {
			A[pos] = i;
			W[i] = 1;
			Zaprzegi(A, W, M, K, i + 1, pos + 1);
			if(pos==M*K)
				for (int j = 1; j <= M * K; j++)
				{
					if (j % K == 1)
						cout << "\n" << j / K + 1 << " Mikolaj: ";
					else if (K == 1)
						cout << "\n" << j << " Mikolaj: ";
					cout << A[j] << " ";
				}
			W[i] = 0;
		}
	}
}

//int main() {
//	int W[100];
//	for (int i = 1; i < 100; i++)
//		W[i] = 0;
//	int A[100];
//	Zaprzegi(A, W, 4, 2, 1, 1);
//}