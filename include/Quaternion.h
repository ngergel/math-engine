// Vector Header.

// Header guard.
#ifndef QUATERNION_H
#define QUATERNION_H

// Include statements needed for definitions.
#include "../include/Matrix.h"

struct quaternion {
    // Real/imaginary components, in the form a + bi + cj + dk.
    float a, b, c, d;

    // Constructor. Defaults values to 0.
    // @params a, b, c, d (float): The numerical components.
    quaternion(float a = 0, float b = 0, float c = 0, float d = 0);

    // Destructor. Should be empty.
    ~quaternion();

    // Assignment operator.
    // @param u (const quaternion &): Quaternion to assign.
    void operator=(const quaternion &u);

    // Addition and subtraction operators.
    // @param u (const quaternion &): quaternion to add or subtract.
    // @return (quaternion): Sum or difference of this and u.
    quaternion operator+(const quaternion &u);
    quaternion operator-(const quaternion &u);

    // Scalar multiplication from the right.
    // @param u (const float&): scalar.
    // @return (quaternion): Scalar product of this * u.
    quaternion operator*(const float &u);

    // Hamilton product with quaternion u.
    // @param u (const quaternion &): quaternion to multiply with.
    // @return (quaternion): Hamilton product of this * u.
    quaternion ham(const quaternion &u);

    // Calculate the norm.
    // @return (float): The norm.
    float norm();

    // Calculate the conjugate, versor, and inversen.
    // @return (quaternion): The conjugate, versor, or inverse.
    quaternion conj();
    quaternion versor();
    quaternion inverse();

    // Calculate the rotation matrix.
    // @return (Matrix<float>): The 3 x 3 rotation matrix.
    Matrix<float> rot_matrix();
};

// Shortform.
typedef quaternion quat;

// Scalar multiplication from the left.
// @param u (const float &): Scalar.
// @param v (const quaternion &): Quaternion to scale.
// @return (quaternion): Scalar product of u*v.
quaternion operator*(const float &u, const quaternion &v);

#endif