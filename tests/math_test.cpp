#include <gtest/gtest.h>
#include "math_utils.hpp"

TEST(Vec3Test, AdditionWorks) {
    Vec3 a = {1.0, 2.0, 3.0};
    Vec3 b = {4.0, 5.0, 6.0};
    
    Vec3 result = a + b;
    
    EXPECT_EQ(result[0], 5.0);
    EXPECT_EQ(result[1], 7.0);
    EXPECT_EQ(result[2], 9.0);
}

TEST(Vec3Test, SubtractionWorks) {
    Vec3 a = {4.0, 5.0, 6.0};
    Vec3 b = {1.0, 2.0, 3.0};
    
    Vec3 result = a - b;
    
    EXPECT_EQ(result[0], 3.0);
    EXPECT_EQ(result[1], 3.0);
    EXPECT_EQ(result[2], 3.0);
}

TEST(Vec3Test, ScalarMultiplicationWorks) {
    Vec3 v = {1.0, 2.0, 3.0};
    
    Vec3 result = v * 2.0;
    
    EXPECT_EQ(result[0], 2.0);
    EXPECT_EQ(result[1], 4.0);
    EXPECT_EQ(result[2], 6.0);
}

TEST(Vec3Test, DotProductWorks) {
    Vec3 a = {1.0, 2.0, 3.0};
    Vec3 b = {4.0, 5.0, 6.0};
    
    double result = dot(a, b);
    
    EXPECT_DOUBLE_EQ(result, 32.0);
}

TEST(Vec3Test, NormWorks) {
    Vec3 v = {3.0, 4.0, 0.0};
    
    double result = norm(v);
    
    EXPECT_DOUBLE_EQ(result, 5.0);
}

TEST(Vec3Test, NormalizeWorks) {
    Vec3 v = {3.0, 4.0, 0.0};
    
    Vec3 result = normalize(v);
    
    EXPECT_DOUBLE_EQ(result[0], 0.6);
    EXPECT_DOUBLE_EQ(result[1], 0.8);
    EXPECT_DOUBLE_EQ(result[2], 0.0);
    EXPECT_DOUBLE_EQ(norm(result), 1.0);
}

TEST(Vec3Test, NormalizeZeroVectorReturnsZero) {
    Vec3 v = {0.0, 0.0, 0.0};
    
    Vec3 result = normalize(v);
    
    EXPECT_DOUBLE_EQ(result[0], 0.0);
    EXPECT_DOUBLE_EQ(result[1], 0.0);
    EXPECT_DOUBLE_EQ(result[2], 0.0);
}
