// Quaternion implimentation.

// Include statements needed for implimentation.
#include "Quaternion.h"
#include <cassert>
#include <cmath>

// Constructor.
quaternion::quaternion(float a, float b, float c, float d) {
    this->a = a;
    this->b = b;
    this->c = c;
    this->d = d;
}

// Destructor.
quaternion::~quaternion(){};

// Assignment operator.
void quaternion::operator=(const quaternion &u) {
    a = u.a;
    b = u.b;
    c = u.c;
    d = u.d;
}

// Addition operator.
quaternion quaternion::operator+(const quaternion &u) {
    return quaternion(a + u.a, b + u.b, c + u.c, d + u.d);
}

// Subtraction operator.
quaternion quaternion::operator-(const quaternion &u) {
    return quaternion(a - u.a, b - u.b, c - u.c, d - u.d);
}

// Scalar multiplication from the right.
quaternion quaternion::operator*(const float &u) {
    return quaternion(a * u, b * u, c * u, d * u);
}

// Scalar multiplication from the left.
quaternion operator*(const float &u, const quaternion &v) {
    return quaternion(v.a * u, v.b * u, v.c * u, v.d * u);
}

// Hamilton product.
quaternion quaternion::ham(const quaternion &u) {
    return quaternion((a * u.a) - (b * u.b) - (c * u.c) - (d * u.d),
                      (a * u.b) + (b * u.a) + (c * u.d) - (d * u.c),
                      (a * u.c) - (b * u.d) + (c * u.a) + (d * u.b),
                      (a * u.d) + (b * u.c) - (c * u.b) + (d * u.a));
}

// Conjugate.
quaternion quaternion::conj() { return quaternion(a, -1 * b, -1 * c, -1 * d); }

// Norm.
float quaternion::norm() { return (float)sqrt(a * a + b * b + c * c + d * d); }

// Versor, or unit quaternion.
quaternion quaternion::versor() {
    // Verify the quaternion is non-zero.
    assert(norm() != 0);

    // Still immutible as scalar prod returns new quaternion.
    return *this * (1 / norm());
}

// Inverse.
quaternion quaternion::inverse() {
    // Verify the quaternion is non-zero.
    assert(norm() != 0);

    return conj() * (1 / (norm() * norm()));
}

// Rotation matrix.
Matrix<float> quaternion::rot_matrix() {
    // Initialize value arrayand unit quaternion.
    float *val_arr = new float[9];
    quat v = versor();

    // Calculate all the entries.
    val_arr[0] = (v.a * v.a) + (v.b * v.b) - (v.c * v.c) - (v.d * v.d);
    val_arr[1] = (2 * v.b * v.c) - (2 * v.a * v.d);
    val_arr[2] = (2 * v.b * v.d) + (2 * v.a * v.c);
    val_arr[3] = (2 * v.b * v.c) + (2 * v.a * v.d);
    val_arr[4] = (v.a * v.a) - (v.b * v.b) + (v.c * v.c) - (v.d * v.d);
    val_arr[5] = (2 * v.c * v.d) - (2 * v.a * v.b);
    val_arr[6] = (2 * v.b * v.d) - (2 * v.a * v.c);
    val_arr[7] = (2 * v.c * v.d) + (2 * v.a * v.b);
    val_arr[8] = (v.a * v.a) - (v.b * v.b) - (v.c * v.c) + (v.d * v.d);

    return Matrix<float>(3, 3, val_arr);
}
