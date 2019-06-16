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
    // Dimensions.
    int n, m;

    // Values in the matrix.
    T **entries;

    // Constructor. Dimensions default to 1.
    // @param n (int): Number of rows.
    // @param m (int): Number of rows.
    // @param values (T**): Supplied entries; optional.
    Matrix(int n = 1, int m = 1, T **values = NULL) {
        this->n = n;
        this->m = m;

        // Initialize entries.
        entries = new T *[n];
        for (size_t i = 0; i < n; i++) {
            entries[i] = new T[m];

            if (values != NULL) {
                for (size_t j = 0; j < m; j++)
                    entries[i][j] = values[i][j];
            }
        }
    }

    // Destructor.
    ~Matrix() {
        for (size_t i = 0; i < n; i++)
            delete[] entries[i];
        delete[] entries;
    }

    // Print the entries of the matrix to stdout.
    // @param w (int): Width of the columns.
    void print_entries(int w = 0) {
        for (size_t i = 0; i < n; i++) {
            for (size_t j = 0; j < m; j++)
                std::cout << std::setw(w) << entries[i][j] << ' ';
            std::cout << std::endl;
        }
    }

    // Add the values of another matrix to this one.
    // @param A (const Matrix &): The matrix to add to this one.
    Matrix &operator+(const Matrix &A) {
        assert(n == A.n && m == A.m);
        Matrix result(A.n, A.m);
        for (size_t i = 0; i < n; i++) {
            for (size_t j = 0; j < m; j++)
                result[i][j] = entries[i][j] + A.entries[i][j];
        }
        return result;
    }

    // Subtract the values of another matrix to this one.
    // @param A (const Matrix &): The matrix to subtract from this one.
    Matrix &operator-(const Matrix &A) {
        assert(n == A.n && m == A.m);
        Matrix result(A.n, A.m);
        for (size_t i = 0; i < n; i++) {
            for (size_t j = 0; j < m; j++)
                result[i][j] = entries[i][j] - A.entries[i][j];
        }
        return result;
    }
};

#endif
