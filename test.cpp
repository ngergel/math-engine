#include "src/Matrix.h"

int main() {
    Matrix<int> A(3, 4);

    int cnt = 1;

    int **arr = new int *[4];
    for (int i = 0; i < 4; i++) {
        arr[i] = new int[5];

        for (int j = 0; j < 5; j++) {
            arr[i][j] = cnt++;
        }
    }

    Matrix<int> B(4, 5, arr);

    A.print_entries();
    B.print_entries();

    return 0;
}