#include "gtest/gtest.h"
#include "../../Maths/Maths/Vector3.hpp"

TEST(Vector3_Constructor, AssignsAllComponents) {
    Vector3 v(3, 4, 5);
    EXPECT_EQ(v.x, 3);
    EXPECT_EQ(v.y, 4);
    EXPECT_EQ(v.z, 5);
}

TEST(Vector3_EqualityComparison, Returns_True_For_Equal_Vectors) {
    EXPECT_TRUE(Vector3(3, 4, 5) == Vector3(3, 4, 5));
}

TEST(Vector3_EqualityComparison, Returns_False_For_Inequal_Vectors) {
    EXPECT_FALSE(Vector3(3, 4, 5) == Vector3(2, 4, 5));
    EXPECT_FALSE(Vector3(3, 4, 5) == Vector3(3, 2, 5));
    EXPECT_FALSE(Vector3(3, 4, 5) == Vector3(3, 4, 2));
    EXPECT_FALSE(Vector3(3, 4, 5) == Vector3(2, 2, 2));
}

TEST(Vector3_InequalityComparison, Returns_False_For_Equal_Vectors) {
    EXPECT_FALSE(Vector3(3, 4, 5) != Vector3(3, 4, 5));
}

TEST(Vector3_InequalityComparison, Returns_True_For_Inequal_Vectors) {
    EXPECT_TRUE(Vector3(3, 4, 5) != Vector3(2, 4, 5));
    EXPECT_TRUE(Vector3(3, 4, 5) != Vector3(3, 2, 5));
    EXPECT_TRUE(Vector3(3, 4, 5) != Vector3(3, 4, 2));
    EXPECT_TRUE(Vector3(3, 4, 5) != Vector3(2, 2, 2));
}

// test and implement negate operator

TEST(Vector3_Negate, Inverts_Positive_Values) {
  EXPECT_EQ(-Vector3(3,4,5), Vector3(-3,-4,-5));
}

TEST(Vector3_ScalarMultiplication, Scales_All_Values) {
    EXPECT_EQ(Vector3(3, 4, 5)*2, Vector3(6, 8, 10));
}

TEST(Vector3_ScalarDivision, Inverse_Scales_All_Values) {
    EXPECT_EQ(Vector3(6, 8, 10) / 2, Vector3(3, 4, 5));
}

TEST(Vector3_Addition, Adds_Up_All_Values) {
    EXPECT_EQ(Vector3(1, 2, 3) + Vector3(4, 5, 6), Vector3(5, 7, 9));
}

TEST(Vector3_Subtraction, Subtracts_All_Values) {
    EXPECT_EQ(Vector3(5, 7, 9) - Vector3(4, 5, 6), Vector3(1, 2, 3));
}

TEST(Vector3_Magnitude, Returns_Correct_Magnitude_For_Non_Zero_Vectors) {
    EXPECT_FLOAT_EQ(Vector3(3, 4, 0).Magnitude(), 5);
    EXPECT_FLOAT_EQ(Vector3(3, 0, 0).Magnitude(), 3);
    EXPECT_FLOAT_EQ(Vector3(5, -3, 2).Magnitude(), sqrtf(38));
}
