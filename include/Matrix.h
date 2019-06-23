// Matrix header.

// Header guard.
#ifndef MATRIX_H
#define MATRIX_H

// Include statements.
#include <cassert>
#include <iomanip>
#include <iostream>
#include <utility>
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

    void print_entries(int w = 0) const {
        for (size_t i = 0; i < n; i++) {
            for (size_t j = 0; j < m; j++)
                std::cout << std::setw(w) << (*this)(i, j) << ' ';
            std::cout << std::endl;
        }
    }

    T det() {
        if (n != m) {
            // non square! det = 0
            return 0;
        } else {
            // square! Possible non trivial
            T out = 0;
            std::pair<const Matrix<T> *, const Matrix<T> *> LU =
                (*this).lu_decomp();
            T l_out = (*LU.first)(0, 0);
            T u_out = (*LU.second)(0, 0);
            if (n > 1) {
                for (int i = 1; i < n; i++) {
                    l_out = l_out * (*LU.first)(i, i);
                    u_out = u_out * (*LU.second)(i, i);
                }
            }
            return l_out * u_out;
        }
    }

    // Does LU decomp, returns a pair containing pointers to two matrices. First
    // is lower, second upper
    std::pair<const Matrix<T> *, const Matrix<T> *> lu_decomp() {
        assert(n == m);
        T lower[n * n] = {0};
        T upper[n * n] = {0};
        // upper
        for (size_t i = 0; i < n; i++) {
            for (size_t j = i; j < n; j++) {
                T sum = 0;
                for (size_t k = 0; k < i; k++)
                    sum += (lower[i * m + k] * upper[k * m + j]);

                upper[i * m + j] = (*this)(i, j) - sum;
            }

            // lower
            for (size_t j = i; j < n; j++) {
                if (i == j)
                    lower[i * m + i] = 1;
                else {
                    T sum = 0;
                    for (size_t k = 0; k < i; k++)
                        sum += (lower[j * m + k] * upper[k * m + i]);

                    lower[j * m + i] = ((*this)(j, i) - sum) / upper[i * m + i];
                }
            }
        }
        Matrix<T> *l = new Matrix<T>(n, m, lower);
        Matrix<T> *u = new Matrix<T>(n, m, upper);

        l->print_entries();
        u->print_entries();
        return std::make_pair(l, u);
    }

    // Assignment operator
    // @param A (const Matrix &): Matrix to assign to this one
    Matrix<T> &operator=(const Matrix &A) {
        delete[] entries;
        n = A.getN();
        m = A.getM();
        entries = new T[n * m];
        for (size_t i = 0; i < n; i++) {
            for (size_t j = 0; j < m; j++) {
                entries[i * m + j] = A(i, j);
            }
        }

        return *this;
    }

    // Add the values of another matrix to this one.
    // @param A (const Matrix &): The matrix to add to this one.
    Matrix<T> operator+(const Matrix<T> &A) {
        assert(n == A.getN() && m == A.getM());
        T *result;
        result = new T[n * m];
        for (size_t i = 0; i < n; i++) {
            for (size_t j = 0; j < m; j++)
                result[i * m + j] = (*this)(i, j) + A(i, j);
        }
        return Matrix<T>(n, m, result);
    }

    // Subtract the values of another matrix to this one.
    // @param A (const Matrix &): The matrix to subtract from this one.
    Matrix<T> operator-(const Matrix<T> &A) {
        assert(n == A.getN() && m == A.getM());
        T *result;
        result = new T[n * m];
        for (size_t i = 0; i < n; i++) {
            for (size_t j = 0; j < m; j++)
                result[i * m + j] = (*this)(i, j) - A(i, j);
        }
        return Matrix<T>(n, m, result);
    }

    // Scalar multiplication, note only works when A is on the right hand side
    // @param A(const T): A scalar
    Matrix<T> operator*(const T A) {
        T *result;
        result = new T[n * m];
        for (size_t i = 0; i < n; i++) {
            for (size_t j = 0; j < m; j++)
                result[i * m + j] = (*this)(i, j) * A;
        }
        return Matrix<T>(n, m, result);
    }

    // () operator to act as subscript replacement
    // @param n(int):row
    // @param m(int):column
    T &operator()(const size_t i, const size_t j) { return entries[i * m + j]; }
    const T &operator()(const size_t i, const size_t j) const {
        return entries[i * m + j];
    }

  private:
    // Dimensions.
    size_t n, m;
    // Values in the matrix.
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
}
#endif
