#include <gtest/gtest.h>
#include <fstream>
#include "output.hpp"
#include "body.hpp"
#include "vector_math.hpp"

TEST(OutputTest, WriteHeaderAndStep) {
    std::string filename = "test_output.csv";
    {
        Output out(filename);
        out.writeHeader();
        std::vector<Body> bodies = {
            Body("A", {1,2,3}, {4,5,6}, 1.0, 1.1),
            Body("B", {7,8,9}, {10,11,12}, 2.0, 2.2)
        };
        out.writeStep(0.0, bodies);
        out.writeStep(1.0, bodies);
    }
    std::ifstream file(filename);
    ASSERT_TRUE(file.is_open());
    std::string line;
    std::getline(file, line);
    EXPECT_EQ(line, "time,body_name,x,y,z,vx,vy,vz");
    std::getline(file, line);
    EXPECT_EQ(line, "0,A,1,2,3,4,5,6");
    std::getline(file, line);
    EXPECT_EQ(line, "0,B,7,8,9,10,11,12");
    std::getline(file, line);
    EXPECT_EQ(line, "1,A,1,2,3,4,5,6");
    std::getline(file, line);
    EXPECT_EQ(line, "1,B,7,8,9,10,11,12");
    file.close();
    std::remove(filename.c_str());
}
