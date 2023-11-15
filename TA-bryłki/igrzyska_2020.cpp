#include <iostream>

using namespace std;

void OlympicGames(int numOfObjects, int numOfDisciplines, int currentObject, int pos, int W[], int A[][100], int M, int disciplinesToUse, int m) { //jest Ÿle
		
		if (disciplinesToUse == 0) {
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

		if (pos == 1 && currentObject > 0) {
			int j;
			if (disciplinesToUse  + 1 < M)
				j = M - disciplinesToUse;
			else j = 0;
			for (j; j < M; j++) {
				m = M - j;
				for (int i = 1; i <= numOfDisciplines; i++) {
					if (W[i] == 0 && A[currentObject][pos - 1] < i) {
						A[currentObject][pos] = i;
						W[i] = 1;
						if (pos < m)
							OlympicGames(numOfObjects, numOfDisciplines, currentObject, pos + 1, W, A, M, disciplinesToUse - 1, m);
						else if (pos == m)
							OlympicGames(numOfObjects, numOfDisciplines, currentObject - 1, 1, W, A, M, disciplinesToUse - 1, M);
						W[i] = 0;
					}
				}
			}
		}
		else if(pos > 1){
			for (int i = 1; i <= numOfDisciplines; i++) {
				if (W[i] == 0 && A[currentObject][pos - 1] < i) {
					A[currentObject][pos] = i;
					W[i] = 1;
					if (pos < m)
						OlympicGames(numOfObjects, numOfDisciplines, currentObject, pos + 1, W, A, M, disciplinesToUse - 1, m);
					else if (pos == m && currentObject >= 1)
						OlympicGames(numOfObjects, numOfDisciplines, currentObject - 1, 1, W, A, M, disciplinesToUse - 1, M);
					W[i] = 0;
				}
			}
		}
	
	A[currentObject][pos] = 0;
}

void T(int pos, int Objects, int Disciplines, int M) {

}

//int main() {
//	int A[100][100];
//	int W[100];
//	for (int i = 1; i < 100; i++)
//		W[i] = 0;
//	for (int i = 1; i < 100; i++)
//		for (int j = 1; j < 100; j++)
//			A[i][j] = 0;
//	int numOfObjects = 2;
//	int numOfDisciplines = 5;
//	int currentObject = numOfObjects;
//	int M = 4;
//	int limit = numOfDisciplines;
//
//	OlympicGames(numOfObjects, numOfDisciplines, currentObject, 1, W, A, M, limit, M);
//}