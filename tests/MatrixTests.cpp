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

TEST_F(MatrixTests, TestConstructor1) {
    Matrix<double> testMatrix(2, 3);

    ASSERT_EQ(testMatrix.getNumColumns(), 3);
    ASSERT_EQ(testMatrix.getNumRows(), 2);
}

TEST_F(MatrixTests, TestConstructor2) {
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

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
