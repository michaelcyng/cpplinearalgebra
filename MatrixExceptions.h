//
// Created by Cho Yiu Ng on 01.10.19.
//

#ifndef LINEARALGEBRA_MATRIXEXCEPTIONS_H
#define LINEARALGEBRA_MATRIXEXCEPTIONS_H

#include <exception>
#include <sstream>

class MatrixExceptionBase: public std::exception {
public:

    MatrixExceptionBase(const std::string& message): myMessage(message) {};
    virtual ~MatrixExceptionBase() = default;

    virtual const char* what() const throw() {
        return myMessage.c_str();
    }

private:

    std::string myMessage;

};

class EmptyInitializerListException: MatrixExceptionBase {
public:
    EmptyInitializerListException():
    MatrixExceptionBase("Attempt to create matrix with empty initializer list") {}
};

class EmptyRowInInitializerListException: MatrixExceptionBase {
public:
    EmptyRowInInitializerListException(size_t row):
    MatrixExceptionBase((std::stringstream() << "Row " << row << " is empty.").str()) {}
};

class InvalidIndicesException: MatrixExceptionBase {
public:
    InvalidIndicesException(size_t row, size_t column, size_t numRows, size_t numColumns):
    MatrixExceptionBase((std::stringstream() << "Invalid indices ("
                                                      << row << ", " << column
                                                      << ") for matrix of dimension ("
                                                      << numRows << ", " << numColumns << ")").str()) {}
};

class UnequalRowLengthException: MatrixExceptionBase {
public:
    UnequalRowLengthException(size_t row1, size_t row2):
    MatrixExceptionBase((std::stringstream() << "Rows " << row1 << " and " << row2
                                                      << " have unequal length.").str()) {}
};

#endif //LINEARALGEBRA_MATRIXEXCEPTIONS_H
