// Matrix header.

// Header guard.
#ifndef MATRIX_H
#define MATRIX_H

// Include statements.
#include <cassert>
#include <iomanip>
#include <iostream>
template <typename T> class Matrix {
  public:
    int getN() { return n; }
    int getM() { return m; }

    const int getN() const { return n; }
    const int getM() const { return m; }
    // Constructor. Dimensions default to 1.
    // @param n (int): Number of rows.
    // @param m (int): Number of rows.
    // @param values (T**): Supplied entries; optional.
    Matrix(int n = 1, int m = 1, T *values = NULL) {
        this->n = n;
        this->m = m;
        entries = new T[n * m];
        // Initialize entries.
        // entries = new T *[n];
        for (size_t i = 0; i < n; i++) {
            if (values != NULL) {
                for (size_t j = 0; j < m; j++)
                    entries[i * m + j] = values[i * m + j];
            }
        }
    }

    // Destructor.
    ~Matrix() { delete[] entries; }

    // Print the entries of the matrix to stdout.
    // @param w (int): Width of the columns.
    void print_entries(int w = 0) {
        for (size_t i = 0; i < n; i++) {
            for (size_t j = 0; j < m; j++)
                std::cout << std::setw(w) << (*this)(i, j) << ' ';
            std::cout << std::endl;
        }
    }

    // Assignment operator
    // @param A (const Matrix &): Matrix to assign to this one
    void operator=(const Matrix &A) {
<<<<<<< HEAD
        if (A.getN() != n || A.getM() != m) {
            delete[] entries;
            n = A.getN();
            m = A.getM();
            entries = new T[n * m];
        }
        for (size_t i = 0; i < n; i++) {
            for (size_t j = 0; j < m; j++) {
                entries[i * m + j] = A(i, j);
=======

        n = A.getN();
        m = A.getM();
        entries = new T *[n];
        for (size_t i = 0; i < n; i++) {
            entries[i] = new T[m];
            for (size_t j = 0; j < m; j++) {
                entries[i][j] = A(i, j);
>>>>>>> 0718ce10d850f0e5a78b9b1a4587ff237030772e
            }
        }
    }

    // Add the values of another matrix to this one.
    // @param A (const Matrix &): The matrix to add to this one.
    Matrix<T> operator+(const Matrix<T> &A) {
        assert(n == A.getN() && m == A.getM());
<<<<<<< HEAD
        T *result;
        result = new T[n * m];
        for (size_t i = 0; i < n; i++) {
            for (size_t j = 0; j < m; j++)
                result[i * m + j] = (*this)(i, j) + A(i, j);
=======
        T **result;
        result = new T *[n];
        for (size_t i = 0; i < n; i++) {
            result[i] = new T[m];
            // std::cout << i << std::endl;
            for (size_t j = 0; j < m; j++) {
                result[i][j] = entries[i][j] + A(i, j);
            }
>>>>>>> 0718ce10d850f0e5a78b9b1a4587ff237030772e
        }
        return Matrix<T>(n, m, result);
    }

    // Subtract the values of another matrix to this one.
    // @param A (const Matrix &): The matrix to subtract from this one.
    Matrix<T> operator-(const Matrix<T> &A) {
        assert(n == A.getN() && m == A.getM());
<<<<<<< HEAD
        T *result;
        result = new T[n * m];
        for (size_t i = 0; i < n; i++) {
=======
        T **result;
        result = new T *[n];
        for (size_t i = 0; i < n; i++) {
            result[i] = new T[m];
>>>>>>> 0718ce10d850f0e5a78b9b1a4587ff237030772e
            for (size_t j = 0; j < m; j++)
                result[i * m + j] = (*this)(i, j) - A(i, j);
        }
        return Matrix<T>(n, m, result);
    }

    // Scalar multiplication, note only works when A is on the right hand side
    // @param A(const T): A scalar
    Matrix<T> operator*(const T A) {
<<<<<<< HEAD
        T *result;
        result = new T[n * m];
        for (size_t i = 0; i < n; i++) {
            for (size_t j = 0; j < m; j++)
                result[i * m + j] = (*this)(i, j) * A;
=======
        T **result;
        result = new T *[n];
        for (size_t i = 0; i < n; i++) {
            result[i] = new T[m];
            for (size_t j = 0; j < m; j++) {
                result[i][j] = entries[i][j] * A;
            }
>>>>>>> 0718ce10d850f0e5a78b9b1a4587ff237030772e
        }
        return Matrix<T>(n, m, result);
    }

    // () operator to act as subscript replacement
    // @param n(int):row
    // @param m(int):column
<<<<<<< HEAD
    T &operator()(const size_t i, const size_t j) { return entries[i * m + j]; }
    const T &operator()(const size_t i, const size_t j) const {
        return entries[i * m + j];
=======
    T &operator()(const size_t n, const size_t m) { return entries[n][m]; }
    const T &operator()(const size_t n, const size_t m) const {
        return entries[n][m];
>>>>>>> 0718ce10d850f0e5a78b9b1a4587ff237030772e
    }

  private:
    // Dimensions.
    size_t n, m;
    // Values in the matrix.
<<<<<<< HEAD
    T *entries;
};

template <typename T> Matrix<T> operator*(const T A, const Matrix<T> &rhs) {
    T *result;
    size_t n = rhs.getN();
    size_t m = rhs.getM();
    result = new T[n * m];
    for (size_t i = 0; i < n; i++) {
        for (size_t j = 0; j < m; j++)
            result[i * m + j] = rhs(i, j) * A;
    }
    return Matrix<T>(n, m, result);
=======
    T **entries;
};

template <typename T> Matrix<T> operator*(const T A, const Matrix<T> &rhs) {
    T **result;
    result = new T *[rhs.getN()];
    for (size_t i = 0; i < rhs.getN(); i++) {
        result[i] = new T[rhs.getM()];
        for (size_t j = 0; j < rhs.getM(); j++)
            result[i][j] = rhs(i, j) * A;
    }
    return Matrix<T>(rhs.getN(), rhs.getM(), result);
>>>>>>> 0718ce10d850f0e5a78b9b1a4587ff237030772e
}
#endif
