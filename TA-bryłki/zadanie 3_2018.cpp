#include <iostream>

using namespace std;

void Nuggets(int sum, int k, int A[100], int biggestValue) {
    if (k == 1) {
        int sum = 0;
        for (int i = 2; i < biggestValue; i++) {
            cout << "value = " << i << ": " << A[i] << " ";
            sum += A[i] * i;
        }
        cout << "   Suma to: " << sum << "\n";
        return;
    }
        
    if (sum % k != 1)
        A[k] = sum / k;
    else
        A[k] = (sum - k) / k;

    int rest;
    rest = sum - A[k] * k;

    if(rest != 1)
        Nuggets(rest, k - 1, A, biggestValue);

    if (k>3) {
        while (A[k] - 1 >= 0) {
            A[k] -= 1;
            rest = sum - A[k] * k;
            Nuggets(rest, k - 1, A, biggestValue);
        }
    }
    else if (k==3) {
        while (A[k] - 2 >= 0) {
            A[k] = A[k] - 2;
            rest = sum - A[k] * k;
            Nuggets(rest, k - 1, A, biggestValue);
        }
    }
}

//int main()
//{
//    int k = 10;
//    int biggestValue = k + 1;
//    int A[100];
//    Nuggets(19, k, A, biggestValue);
//}
