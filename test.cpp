#include "include/Matrix.h"
#include "include/Quaternion.h"

#include <iostream>

using namespace std;

int main() {
    quat v((float)1, (float)2, (float)3, (float)4);

    v.rot_matrix().print_entries();

    return 0;
}
