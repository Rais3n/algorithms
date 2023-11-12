#include <iostream>

using namespace std;

void OlympicGames(int numOfObjects, int numOfDisciplines,int currentObject,int pos, int W[100], int A[100][100], int M) {
	for (int i = 1; i <= numOfDisciplines; i++) {
		if (W[i] == 0) {
			A[currentObject][pos] = i;
			W[i] = 1;
			if (pos < M)
				OlympicGames(numOfObjects, numOfDisciplines, currentObject, pos + 1, W, A, M);
			if(currentObject>1)
				OlympicGames(numOfObjects, numOfDisciplines, currentObject - 1, 1, W, A, M);
			if (A[currentObject][pos] == numOfDisciplines) {
				for (int k = 1; k <= numOfObjects; k++) {
					cout <<"\n" << "Object " << k << ": ";
					for (int j = 1; j <= numOfDisciplines; j++) {
						if (A[k][j] == 0)
							break;
						cout << A[k][j] << " ";
					}
				}
				cout << "\n";
			}
			W[i] = 0;
		}
	}
}


int main() {
	int A[100][100];
	int W[100];
	for (int i = 1; i < 100; i++)
		W[i] = 0;
	for (int i = 1; i < 100; i++)
		for (int j = 1; j < 100; j++)
			A[i][j] = 0;
	int numOfObjects=2;
	int numOfDisciplines=4;
	int currentObject = numOfObjects;
	OlympicGames(numOfObjects, numOfDisciplines, currentObject, 1, W, A, 3);
}