#include "src/Matrix.h"

int main() {
    int cnt = 1;

    double **arr = new double *[4];
    for (int i = 0; i < 4; i++) {
        arr[i] = new double[5];

        for (int j = 0; j < 5; j++) {
            arr[i][j] = cnt++;
        }
    }

    Matrix<double> A(4, 5, arr);

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 5; j++) {
            arr[i][j] = cnt++;
        }
    }

    Matrix<double> B(4, 5, arr);

    A.print_entries(2);
    B.print_entries();

    A = A + B;

    A.print_entries(2);

    A = A - A;

    A.print_entries();

    return 0;
}