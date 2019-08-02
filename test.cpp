#include "include/Quaternion.h"

#include <iostream>

using namespace std;

int main() {
    quaternion v((float)1, (float)2, (float)3, (float)4);
    quaternion u((float)5, (float)6, (float)1, (float)7);

    v = v.conj();

    cout << v.a << ' ' << v.b << ' ' << v.c << ' ' << v.d << endl;

    return 0;
}
