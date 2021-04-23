void AddNumbers(int k, int **A, int n, int &gl) {
    for (int i = n - k; i < k; i++) {
        A[n - k][i] = gl++;
    }
    for (int i = n - k + 1; i < k - 1; i++) {
        A[i][k - 1] = gl++;
    }
    for (int i = k - 1; i >= n - k; i--) {
        if (A[k - 1][i] == 0) {
            A[k - 1][i] = gl++;
        }
    }
    for (int i = k - 2; i > n - k; i--) {
        A[i][n - k] = gl++;
    }

}

int **CreateSpiralMatrix(int n) {
//********** YOUR CODE HERE **********
    if (n < 1)
        return nullptr;
    int k = n;
    int gl = 1;
    int **A = new int *[n];
    for (int i = 0; i < n; ++i) {
        A[i] = new int[n];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            A[i][j] = 0;
        }
    }
    for (; k > 0; k--) {
        AddNumbers(k, A, n, gl);
    }

    return A;
//************************************
}

#include <iostream>

using namespace std;

int main() {

    // This is only simple example.
    // Solution must handle all cases.

    int n = 5;
    int **mat = CreateSpiralMatrix(5);

    if (mat) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++)
                cout << mat[i][j] << " ";
            cout << endl;
        }
    } else
        cout << "Matrix not initalized!" << endl;

    return 0;
}

