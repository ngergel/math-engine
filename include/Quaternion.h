// Vector Header.

// Header guard.
#ifndef QUATERNION_H
#define QUATERNION_H

struct quaternion {
	// Real/imaginary components, in the form a + bi + cj + dk.
	float a, b, c, d;

	// Constructor. Defaults values to 0.
	// @params a, b, c, d (float): The numerical components.
	quaternion(float a = 0, float b = 0, float c = 0, float d = 0);

	// Destructor. Should be empty.
	~quaternion();

	// Assignment operator.
	// @param u (const quaternion &): Quaternion to be assigned.
	void operator=(const quaternion &u);

	// Addition operator.
	// @param u (const quaternion &): quaternion to add.
	// @return (quaternion): Sum of this + u.
	quaternion operator+(const quaternion &u);

	// Subtraction operator.
	// @param u (const quaternion &): quaternion to subtract.
	// @return (quaternion): Difference of this - u.
	quaternion operator-(const quaternion &u);

	// Scalar multiplication from the right.
	// @param u (const float&): scalar.
	// @return (quaternion): Scalar product of this * u.
	quaternion operator*(const float &u);

	// Hamilton product with quaternion u.
	// @param u (const quaternion &): quaternion to multiply with.
	// @return (quaternion): Hamilton product of this * u.
	quaternion ham(const quaternion &u);

	// Conjugate of quaternion.
	// @return (quaternion): The conjugate of this quaternion.
	quaternion conj();
};

// Scalar multiplication from the left.
// @param u (const float &): Scalar.
// @param v (const quaternion &): Quaternion to scale.
// @return (quaternion): Scalar product of u*v.
quaternion operator*(const float &u, const quaternion &v);

#endif