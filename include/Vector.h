// Vector Header.

// Header guard.
#ifndef VECTOR_H
#define VECTOR_H

// Include statements.
#include <cassert>
#include <iomanip>
#include <iostream>

template <typename T> class Vector {
  public:
    // Constructor. Dimension, defaults to 1.
    // @param n (int): Dimension of vector.
    // @param values (T*): Supplied entries; optional.
    Vector(int n = 1, T *values = NULL) {
        this->n = n;

        // Initalize entries.
        this->entries = new T[n];

        if (values != NULL) {
            for (size_t i = 0; i < n; i++) {
                this->entries[i] = values[i];
            }
        }
    }

    // Destructor.
    ~Vector() { delete[] entries; }

    // Getter function for the dimension.
    // @return n (int): The dimension of the vector.
    int dim() const { return n; }

    // Print entries to stdout on one line.
    void print_entries() const {
        for (size_t i = 0; i < n - 1; i++) {
            std::cout << entries[i] << ' ';
        }
        std::cout << entries[n - 1] << std::endl;
    }

    // Assignment operator.
    // @param u (const Vector &): Vector to be assigned.
    void operator=(const Vector &u) {
        n = u.dim();

        // Safe pointer reassignment.
        T *tmp = new T[n];
        delete[] entries;
        entries = tmp;

        for (size_t i = 0; i < n; i++) {
            entries[i] = u[i];
        }
    }

    // Subscript operator.
    // @param i (int): Index to access.
    // @return (T): The i-th entry in the vector.
    T &operator[](int i) { return entries[i]; }

    // Subscript operator but for consts.
    // @param i (int): access i-th object in constant vector.
    // @return (T): The i-th entry in the vector.
    const T &operator[](int i) const { return entries[i]; }

    // Scalar multiplication, from the right.
    // @param A (const T): Scalar to multiply against.
    // @return (Vector<T>): The scaled vector.
    Vector<T> operator*(const T A) {
        // Initialize result vector and scale each entry.
        T result[n];
        for (size_t i = 0; i < n; i++) {
            result[i] = entries[i] * A;
        }

        return Vector<T>(n, result);
    }

    // Add vectors.
    // @param u (const Vector &): Vector to add.
    // @return (Vector<T>): The sum vector.
    Vector<T> operator+(const Vector &u) {
        assert(n == u.dim());

        // Initialize result vector and add each entry.
        T result[n];
        for (size_t i = 0; i < n; i++) {
            result[i] = entries[i] + u[i];
        }

        return Vector<T>(n, result);
    }

    // Subtract vectors.
    // @param u (const Vector &): Vector to subtract.
    // @return (Vector<T>): The difference vector.
    Vector<T> operator-(const Vector &u) {
        assert(n == u.dim());

        // Initialize result vector and add each entry.
        T result[n];
        for (size_t i = 0; i < n; i++) {
            result[i] = entries[i] - u[i];
        }

        return Vector<T>(n, result);
    }

    // Calculates a dot/inner product.
    // @param u(const Vector &): The other vector.
    // @return result (T): The resulting dot product.
    T dot(const Vector &u) {
        // Verify that their dimensions match.
        assert(n == u.dim());

        // Initialize result and calculate it.
        T result = 0;
        for (size_t i = 0; i < n; i++) {
            result += entries[i] * u[i];
        }

        return result;
    }

    // Cross product. Must be in 3 dimensions.
    // @param u(const Vector &): The other vector.
    // @return result (T): The resulting vector.
    Vector<T> cross(const Vector<T> &u) {
        assert(n == u.dim() && n == 3);

        // Initialize array and calculate entries.
        T result[3];
        result[0] = entries[1] * u[2] - entries[2] * u[1];
        result[1] = entries[2] * u[0] - entries[0] * u[2];
        result[2] = entries[0] * u[1] - entries[1] * u[0];

        return Vector<T>(3, result);
    }

  private:
    // Dimension.
    size_t n;

    // Values.
    T *entries;
};

// Scalar multiplication, from the left.
// @param a (const T): Scalar value.
// @param rhs (const Vector<T> &): Vector to scale.
// @return (Vector<T>): The scaled vector.
template <typename T> Vector<T> operator*(const T a, const Vector<T> &rhs) {
    // Iniitalize result vector and scale each entry.
    T result[rhs.dim()];
    for (size_t i = 0; i < rhs.dim(); i++) {
        result[i] = rhs[i] * a;
    }

    return Vector<T>(rhs.dim(), result);
}

#endif
