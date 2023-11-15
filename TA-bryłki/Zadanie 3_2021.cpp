#include <iostream>

using namespace std;

void reindeerSet(int k,int W[],int A[], int pos, int limit) {

	while (limit > 0 && pos == 1) {
		limit -= 2;
		for (int x = 1; x <= k; x++) {
			if (W[x] == 0) {
				A[pos] = x;
				W[x] = 1;
				for (int y = 1; y <= k; y++) {
					if (W[y] == 0) {
						A[pos + 1] = y;
						W[y] = 1;
					}
					if (pos + 1 < limit)
						reindeerSet(k, W, A, pos + 2,limit);

					W[y] = 0;
				}
				W[x] = 0;
			}
		}
	}
	if(pos>1)
	for (int x = 1; x <= k; x++) {
		if (W[x] == 0) {
			A[pos] = x;
			W[x] = 1;
			for (int y = 1; y <= k; y++) {
				if (W[y] == 0) {
					A[pos + 1] = y;
					W[y] = 1;
				}
				if (pos + 1 < limit)
					reindeerSet(k, W, A, pos + 2, limit);
				W[y] = 0;
			}
			W[x] = 0;
		}
	}
	if (pos + 1 == limit ) {
		for (int i = 1; i <= k; i++) {
			if (A[i] != 0)
				cout << A[i] << " ";
			else break;
		}
		cout << "\n";
	}
}

int main() {
	int k = 6;
	int W[100];
	int A[100];
	for (int i = 1; i < 100; i++) {
		A[i] = 0;
		W[i] = 0;
	}
	reindeerSet(k, W, A, 1, k + 2);
}