#include <iostream>

using namespace std;

void OlympicGames(int numOfObjects, int numOfDisciplines, int currentObject, int pos, int W[], int A[][100], int M, int limit) {
	for (int i = 1; i <= numOfDisciplines; i++) {
		if (W[i] == 0)
			break;
		if (i == numOfDisciplines) {
			for (int k = 1; k <= numOfObjects; k++) {
				cout << "\n" << "Object " << k << ": ";
				for (int j = 1; j <= numOfDisciplines; j++) {
					if (A[k][j] == 0)
						break;
					cout << A[k][j] << " ";
				}
			}
			cout << "\n";
			return;
		}
	}

	for (int j = 0; j < M; j++) {
		for (int i = 1; i <= numOfDisciplines; i++) {
			if (W[i] == 0 && A[currentObject][pos - 1] < i) {
				A[currentObject][pos] = i;
				W[i] = 1;
				if (pos < M - j)
					OlympicGames(numOfObjects, numOfDisciplines, currentObject, pos + 1, W, A, M, limit);
				else if (pos == M - j)
					OlympicGames(numOfObjects, numOfDisciplines, currentObject - 1, 1, W, A, M, limit);
				W[i] = 0;
			}
		}
	}

	
	A[currentObject][pos] = 0;
}


int main() {
	int A[100][100];
	int W[100];
	for (int i = 1; i < 100; i++)
		W[i] = 0;
	for (int i = 1; i < 100; i++)
		for (int j = 1; j < 100; j++)
			A[i][j] = 0;
	int numOfObjects = 2;
	int numOfDisciplines = 4;
	int currentObject = numOfObjects;
	int M = 3;
	int limit;
	if (M < numOfDisciplines)
		limit = M;
	else
		limit = numOfDisciplines;
	OlympicGames(numOfObjects, numOfDisciplines, currentObject, 1, W, A, M, limit);
}