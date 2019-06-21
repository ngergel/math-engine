// Vector Header

// Header guard
#ifndef VECTOR_H
#define VECTOR_H
// Include statements

#include <cassert>
#include <iomanip>
#include <iostream>

template <typename T> class Vector {
  public:
    int getN() { return n; }

    // Constructor. Dimension default to 1
    // @param n (int): Dimension of vector
    // @param values (T*): Supplied entries; optional
    Vector(int n = 1, T *values = NULL) {
        this->n = n;

        // Init entries
        entries = new T[n];
        for (size_t i = 0; i < n; i++) {
            entries[i] = values[i];
        }
    }

    // Destructor
    ~Vector() { delete[] entries; }

    // Print entries to stdout on one line
    void print_entries() {
        for (size_t i = 0; i < n - 1; i++) {
            std::cout << entries[i] << ", ";
        }
        std::cout << entries[n - 1] << std::endl;
    }

    // Calculates a dot product
    // @param A(const Vector &): other vector
    T dot(const Vector &A) {
        assert(n == A.getN());
        T result = 0;
        for (size_t i = 0; i < n; i++) {
            result += entries[i] * A[i];
        }
        return result;
    }

    // Assignment operator
    void operator=(const Vector &A){
	n = A.getN();
	entries = new T[n];
	for(size_t i = 0; i < n; i++)
	    entries[n] = A[i];
    }

    // Subscript operator
    // @param n(int): access nth object in vector
    T &operator[](int n) { return entries[n]; }

    // Subscript operator but for consts
    // @param n(int): access nth object in constant vector
    const T &operator[](int n) const { return entries[n]; }

    // Scalar multiplication
    // A
    Vector<T> operator*(const T A) {
        T result[n];
        for (size_t i = 0; i < n; i++) {
            result[i] = entries[i] * A;
        }
        return Vector<T>(n, result);
    }

  private:
    // Dimension
    size_t n;

    // Values
    T *entries;
};

template <typename T> Vector<T> operator*(const T A, const Vector<T> &rhs) {
    T result[rhs.getN()];
    for (size_t i = 0; i < rhs.getN(); i++)
        result[i] = rhs[i] * A;
    return Vector<T>(rhs.getN(), result);
}

#endif
