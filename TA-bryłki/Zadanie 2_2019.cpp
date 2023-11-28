#include <iostream>

using namespace std;

void Warianty(int i, int pos, int A[]) {
	A[pos] = i;
	if (pos == 1) {
		for (int i = 1; i < 5; i++)
			cout << A[i] << " ";
		cout << "\n";
		return;
	}
	if (i == 1)
	{
		Warianty(0, pos - 1, A);
		Warianty(2, pos - 1, A);
	}
	else Warianty(1, pos - 1, A);
}

//int main() {
//	int A[100];
//	for (int i = 1; i < 100; i++)
//		A[i] = 0;
//	Warianty(0, 4, A);
//	Warianty(1, 4, A);
//	Warianty(2, 4, A);
//}