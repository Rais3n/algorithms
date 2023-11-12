#include <iostream>

using namespace std;

void pizza(int pos, int N, int K, int A[100]) {
	if (A[pos - 1] == 0 || (N - A[pos - 1]) / 2 < K - (pos - 1)) // drugi warunek, ¿eby troche usprawniæ (przynajmniej mam tak¹ nadzieje ze usprawni
		return;
	for (int j = A[pos - 1] + 2; j <= N; j++) {
		A[pos] = j;
		if (pos == K) {
			for (int i = 1; i <= K; i++)
				cout << A[i] << " ";
			cout << "\n";
		}
		else
		{
			pizza(pos + 1, N, K, A);
		}
	}
}

//int main() {
//	int N=24;
//	int K=10;
//	int A[100];
//	for (int i = 1; i <= N; i++)
//		A[i] = 0;
//	for (int i = 1; i <= N; i++) {
//		A[1] = i;
//		pizza(2, N, K, A);
//	}
//}

