#include "include/Matrix.h"
#include "include/Vector.h"

int main() {
    int cnt = 1;

    double *arr = new double[20];
    for (int i = 0; i < 4; i++) {

        for (int j = 0; j < 5; j++) {
            arr[i * 5 + j] = cnt++;
        }
    }

    Matrix<double> A(4, 5, arr);

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 5; j++) {
            arr[i * 5 + j] = cnt++;
        }
    }

    Matrix<double> B(4, 5, arr);

    A.print_entries(2);
    std::cout << "new" << std::endl;
    B.print_entries();
    std::cout << "new" << std::endl;
    A = A + B;

    A.print_entries(2);
    std::cout << "new" << std::endl;
    A = A - A;

    A.print_entries(2);
    std::cout << "new" << std::endl;
    A = A * 2;

    A.print_entries();

    double square[] = {1, 2, 3, 4};
    Matrix<double> det(2, 2, square);
    det.print_entries();
    double d = det.det();
    std::cout << d << std::endl;
    Matrix<double> *detinv = det.inverse();
    detinv->print_entries(10);
    return 0;
}
