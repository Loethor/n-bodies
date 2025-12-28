#include <gtest/gtest.h>
#include "config_loader.hpp"
#include <fstream>
#include <stdexcept>

class ConfigLoaderTest : public ::testing::Test {
protected:
    void SetUp() override {
        // Create a test config file
        std::ofstream file("test_config.txt");
        file << "# Test configuration\n";
        file << "# Format: name mass x y z vx vy vz radius\n";
        file << "\n";
        file << "Body1 1.0e24 0.0 0.0 0.0 1.0 2.0 3.0 1.5\n";
        file << "Body2 2.0e24 10.0 20.0 30.0 -1.0 -2.0 -3.0 2.5\n";
        file.close();
    }

    void TearDown() override {
        // Clean up test file
        std::remove("test_config.txt");
    }
};

TEST_F(ConfigLoaderTest, LoadsValidFile) {
    std::vector<Body> bodies = ConfigLoader::loadBodies("test_config.txt");
    
    ASSERT_EQ(bodies.size(), 2);
    
    EXPECT_EQ(bodies[0].name, "Body1");
    EXPECT_DOUBLE_EQ(bodies[0].mass, 1.0e24);
    EXPECT_DOUBLE_EQ(bodies[0].position[0], 0.0);
    EXPECT_DOUBLE_EQ(bodies[0].position[1], 0.0);
    EXPECT_DOUBLE_EQ(bodies[0].position[2], 0.0);
    EXPECT_DOUBLE_EQ(bodies[0].velocity[0], 1.0);
    EXPECT_DOUBLE_EQ(bodies[0].velocity[1], 2.0);
    EXPECT_DOUBLE_EQ(bodies[0].velocity[2], 3.0);
    EXPECT_DOUBLE_EQ(bodies[0].radius, 1.5);

    EXPECT_EQ(bodies[1].name, "Body2");
    EXPECT_DOUBLE_EQ(bodies[1].mass, 2.0e24);
    EXPECT_DOUBLE_EQ(bodies[1].radius, 2.5);
    EXPECT_DOUBLE_EQ(bodies[1].position[0], 10.0);
    EXPECT_DOUBLE_EQ(bodies[1].position[1], 20.0);
    EXPECT_DOUBLE_EQ(bodies[1].position[2], 30.0);
    EXPECT_DOUBLE_EQ(bodies[1].velocity[0], -1.0);
    EXPECT_DOUBLE_EQ(bodies[1].velocity[1], -2.0);
    EXPECT_DOUBLE_EQ(bodies[1].velocity[2], -3.0);
}

TEST_F(ConfigLoaderTest, ThrowsExceptionForMissingFile) {
    EXPECT_THROW(ConfigLoader::loadBodies("nonexistent.txt"), std::runtime_error);
}

TEST_F(ConfigLoaderTest, SkipsCommentsAndEmptyLines) {
    std::vector<Body> bodies = ConfigLoader::loadBodies("test_config.txt");
    
    // Should only have 2 bodies, not 4 (comments and empty lines skipped)
    EXPECT_EQ(bodies.size(), 2);
}

TEST_F(ConfigLoaderTest, HandlesEmptyFile) {
    std::ofstream file("empty_config.txt");
    file.close();
    
    std::vector<Body> bodies = ConfigLoader::loadBodies("empty_config.txt");
    
    EXPECT_EQ(bodies.size(), 0);
    
    std::remove("empty_config.txt");
}
