//
// Created by Cho Yiu Ng on 29.09.19.
//

#ifndef LINEARALGEBRA_MATRIXIMPL_H
#define LINEARALGEBRA_MATRIXIMPL_H

#include <MatrixExceptions.h>

template <typename E>
Matrix<E>::Matrix(size_t numRows, size_t numColumns) : myMatrix(numRows, std::vector<E>(numColumns)) {
}

template <typename E>
template<size_t R, size_t C>
Matrix<E>::Matrix(const E (&matrix)[R][C]) : myMatrix(R, std::vector<E>(C)) {
    for (size_t row = 0; row < R; ++row) {
        for (size_t column = 0; column < R; ++column) {
            myMatrix[row][column] = matrix[row][column];
        }
    }
}

template <typename E>
Matrix<E>::Matrix(const std::initializer_list<std::initializer_list<E>> &matrix) {
    if (matrix.size() == 0) {
        throw EmptyInitializerListException();
    }
    size_t rowIndex = 0;
    for (const auto& row: matrix) {
        if (row.size() == 0) {
            throw EmptyRowInInitializerListException(rowIndex);
        }
        if (row.size() != matrix.begin()->size()) {
            throw UnequalRowLengthException(0, rowIndex);
        }
        ++rowIndex;
    }

    myMatrix.reserve(matrix.size());
    for (const auto& row: matrix) {
        myMatrix.push_back(row);
    }
}

template <typename E>
size_t Matrix<E>::getNumColumns() const noexcept {
    return myMatrix.at(0).size();
}

template <typename E>
size_t Matrix<E>::getNumRows() const noexcept {
    return myMatrix.size();
}

template <typename E>
E& Matrix<E>::operator()(size_t row, size_t column) {
    if (row < 0 || column < 0 || row >= getNumRows() || column >= getNumColumns()) {
        throw InvalidIndicesException(row, column, getNumRows(), getNumColumns());
    }

    return myMatrix[row][column];
}

#endif //LINEARALGEBRA_MATRIXIMPL_H
