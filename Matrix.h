//
// Created by Cho Yiu Ng on 29.09.19.
//

#ifndef CPPLINEARALGEBRA_MATRIX_H
#define CPPLINEARALGEBRA_MATRIX_H

#include <initializer_list>
#include <vector>

template <typename E>
class Matrix {
public:

    Matrix(size_t numRows, size_t numColumns);

    template <size_t R, size_t C>
    Matrix(const E (&matrix)[R][C]);

    Matrix(const std::initializer_list<std::initializer_list<E> >& matrix);

    size_t  getNumColumns() const noexcept;
    size_t  getNumRows()    const noexcept;
    E&      operator()(size_t row, size_t column);

private:

    std::vector<std::vector<E> > myMatrix;

};

#include <MatrixImpl.h>

#endif //CPPLINEARALGEBRA_MATRIX_H
