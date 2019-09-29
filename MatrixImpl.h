//
// Created by Cho Yiu Ng on 29.09.19.
//

#ifndef LINEARALGEBRA_MATRIXIMPL_H
#define LINEARALGEBRA_MATRIXIMPL_H

template <typename E>
Matrix<E>::Matrix(size_t numRows, size_t numColumns) : myMatrix(numRows, std::vector<E>(numColumns)) {
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
    return myMatrix[row][column];
}

#endif //LINEARALGEBRA_MATRIXIMPL_H
