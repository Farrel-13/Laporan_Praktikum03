#include <iostream>
using namespace std;

void tampil(int arr[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

void tukar(int A[3][3], int B[3][3], int baris, int kolom) {
    int temp = A[baris][kolom];
    A[baris][kolom] = B[baris][kolom];
    B[baris][kolom] = temp;
}

void tukarPointer(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int A[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    int B[3][3] = {
        {10, 11, 12},
        {13, 14, 15},
        {16, 17, 18}
    };

    int *pA = &A[0][0];
    int *pB = &B[0][0];

    cout << "Array A sebelum ditukar:" << endl;
    tampil(A);

    cout << "\nArray B sebelum ditukar:" << endl;
    tampil(B);

    tukar(A, B, 1, 1);

    cout << "\nArray A setelah pertukaran:" << endl;
    tampil(A);

    cout << "\nArray B setelah pertukaran:" << endl;
    tampil(B);

    tukarPointer(pA, pB);

    cout << "\nSetelah pertukaran pointer:" << endl;
    cout << "A[0][0] = " << A[0][0] << endl;
    cout << "B[0][0] = " << B[0][0] << endl;

    return 0;
}