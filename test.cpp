#include "include/Matrix.h"
#include "include/Vector.h"

#include <iostream>

int main() {

    int arr1[7] = {1, 2, 3, 4, 5, 9, 1};
    int arr2[7] = {1, 6, 63, 4, 3, 9, 1};
    int arr3[7] = {1, 1, 1, 1, 0, 0, 0};
    int arr4[6] = {0, 0, 0, 0, 1, 1};
    int arr5[3] = {1, 2, 3};
    int arr6[3] = {3, 4, 2};

    Vector<int> u(7, arr1);

    // u.print_entries();

    Vector<int> v(7, arr2);

    v.print_entries();

    u = 2 * u;

    u.print_entries();

    Vector<int>(3, arr5).cross(Vector<int>(3, arr6)).print_entries();

    return 0;
}
