#include <iostream>

using namespace std;

void Money(int B, int W, int A[], int pos, int money) {
	if (pos == W + 1) {
		if (money == B) {
			for (int j = 1; j <= W; j++) {
				cout << A[j] << " ";
			}cout << "\n";
		}
		return;
	}
	for (int i = A[pos - 1]; i >= 0; i--) {
		A[pos] = i;
		money += i;
		Money(B, W, A, pos + 1, money);
		money -= i;
	}
}

//int main() {
//	int B=14;
//	int W=3;
//	int A[100];
//	A[0] = B;
//	Money(B, W, A, 1, 0);
//}