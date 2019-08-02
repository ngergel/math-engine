#include "include/Matrix.h"
#include "include/Vector.h"

#include <iostream>

int main() {
    double *arr = new double[20];
    for (int i = 0; i < 4; i++) {

        for (int j = 0; j < 5; j++) {
            arr[i * 5 + j] = cnt++;
        }
    }

    Vector<int> u(7, arr1);


    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 5; j++) {
            arr[i * 5 + j] = cnt++;
        }
    }

    Vector<int> v(7, arr2);

    v.print_entries();

    u = 2 * u;

    u.print_entries();

    Vector<int>(3, arr5).cross(Vector<int>(3, arr6)).print_entries();

    double square[] = {1, 2, 3, 4};
    Matrix<double> det(2, 2, square);
    det.print_entries();
    double d = det.det();
    std::cout << d << std::endl;
    Matrix<double> *detinv = det.inverse();
    detinv->print_entries(10);
    return 0;
}
