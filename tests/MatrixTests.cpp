//
// Created by Cho Yiu Ng on 29.09.19.
//

#include <gtest/gtest.h>
#include <Matrix.h>

class MatrixTests : public ::testing::Test {
protected:

    MatrixTests() = default;
    ~MatrixTests() override = default;
    void SetUp() override {}
    void TearDown() override {}

};

TEST_F(MatrixTests, TestConstructorWithMatrixDimensions) {
    Matrix<double> testMatrix(2, 3);

    ASSERT_EQ(testMatrix.getNumColumns(), 3);
    ASSERT_EQ(testMatrix.getNumRows(), 2);
}

TEST_F(MatrixTests, TestConstructorWith2dArray) {
    Matrix<double> testMatrix({{0.0, 1.0},
                               {2.0, 3.0},
                               {4.0, 5.0}});

    ASSERT_DOUBLE_EQ(testMatrix(0, 0), 0.0);
    ASSERT_DOUBLE_EQ(testMatrix(0, 1), 1.0);
    ASSERT_DOUBLE_EQ(testMatrix(1, 0), 2.0);
    ASSERT_DOUBLE_EQ(testMatrix(1, 1), 3.0);
    ASSERT_DOUBLE_EQ(testMatrix(2, 0), 4.0);
    ASSERT_DOUBLE_EQ(testMatrix(2, 1), 5.0);

}

TEST_F(MatrixTests, TestConstructionWithInitializerList) {

    ASSERT_THROW(Matrix<double> testMatrix1 = {}, EmptyInitializerListException);

    const std::initializer_list<std::initializer_list<double> > testInitializerList2 = {{}};
    ASSERT_THROW(Matrix<double> testMatrix2 = testInitializerList2, EmptyRowInInitializerListException);

    const std::initializer_list<std::initializer_list<double> > testInitializerList3 = {{0.0}, {}};
    ASSERT_THROW(Matrix<double> testMatrix3 = testInitializerList3, EmptyRowInInitializerListException);

    const std::initializer_list<std::initializer_list<double> > testInitializerList4 = {{0.0}, {1.0, 2.0}};
    ASSERT_THROW(Matrix<double> testMatrix4 = testInitializerList4, UnequalRowLengthException);

    Matrix<double> testMatrix5 = {{0.0, 1.0},
                                  {2.0, 3.0},
                                  {4.0, 5.0}};
    ASSERT_DOUBLE_EQ(testMatrix5(0, 0), 0.0);
    ASSERT_DOUBLE_EQ(testMatrix5(0, 1), 1.0);
    ASSERT_DOUBLE_EQ(testMatrix5(1, 0), 2.0);
    ASSERT_DOUBLE_EQ(testMatrix5(1, 1), 3.0);
    ASSERT_DOUBLE_EQ(testMatrix5(2, 0), 4.0);
    ASSERT_DOUBLE_EQ(testMatrix5(2, 1), 5.0);

}

TEST_F(MatrixTests, TestElementAssignment) {

    Matrix<double> testMatrix(2, 3);
    testMatrix(0, 0) = 0.0;
    testMatrix(0, 1) = 1.0;
    testMatrix(0, 2) = 2.0;
    testMatrix(1, 0) = 3.0;
    testMatrix(1, 1) = 4.0;
    testMatrix(1, 2) = 5.0;

    ASSERT_DOUBLE_EQ(testMatrix(0, 0), 0.0);
    ASSERT_DOUBLE_EQ(testMatrix(0, 1), 1.0);
    ASSERT_DOUBLE_EQ(testMatrix(0, 2), 2.0);
    ASSERT_DOUBLE_EQ(testMatrix(1, 0), 3.0);
    ASSERT_DOUBLE_EQ(testMatrix(1, 1), 4.0);
    ASSERT_DOUBLE_EQ(testMatrix(1, 2), 5.0);

}

TEST_F(MatrixTests, TestInvalidMatrixIndices) {

    Matrix<double> testMatrix({{0.0, 1.0},
                               {2.0, 3.0},
                               {4.0, 5.0}});

    ASSERT_THROW(testMatrix(-1, 0), InvalidIndicesException);
    ASSERT_THROW(testMatrix(2, -2), InvalidIndicesException);
    ASSERT_THROW(testMatrix(3, 1), InvalidIndicesException);
    ASSERT_THROW(testMatrix(0, 3), InvalidIndicesException);
    ASSERT_THROW(testMatrix(1, 4) = 6.0, InvalidIndicesException);

}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
