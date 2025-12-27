#include <gtest/gtest.h>
#include "body.hpp"
#include "math_utils.hpp"

TEST(BodyTest, ConstructorInitializesCorrectly) {
    std::string name = "TestBody";
    Vec3 pos = {1.0, 2.0, 3.0};
    Vec3 vel = {0.1, 0.2, 0.3};
    double mass = 5.0;
    
    Body body(name, pos, vel, mass);
    
    EXPECT_EQ(body.name, "TestBody");
    EXPECT_EQ(body.position[0], 1.0);
    EXPECT_EQ(body.position[1], 2.0);
    EXPECT_EQ(body.position[2], 3.0);
    EXPECT_EQ(body.velocity[0], 0.1);
    EXPECT_EQ(body.velocity[1], 0.2);
    EXPECT_EQ(body.velocity[2], 0.3);
    EXPECT_EQ(body.mass, 5.0);
}
