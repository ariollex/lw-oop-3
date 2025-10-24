#include <gtest/gtest.h>
#include "../include/Figure.hpp"
#include "../include/rhomb.hpp"
#include "../include/pentagon.hpp"
#include "../include/hexagon.hpp"

TEST(test_01, Rhomb)
{
    Rhomb r(Point(0, 2), Point(2, 0), Point(0, -2), Point(-2, 0));
    EXPECT_NEAR(r.getArea(), 8.0, EPS);
    Point center = r.getCenter();
    EXPECT_NEAR(center.x, 0.0, EPS);
    EXPECT_NEAR(center.y, 0.0, EPS);
    EXPECT_NEAR(static_cast<double>(r), 8.0, EPS);
}

TEST(test_02, RhombWithUnsortedPoints)
{
    Rhomb r(Point(0, -2), Point(0, 2), Point(-2, 0), Point(2, 0));
    EXPECT_NEAR(r.getArea(), 8.0, EPS);
    Point center = r.getCenter();
    EXPECT_NEAR(center.x, 0.0, EPS);
    EXPECT_NEAR(center.y, 0.0, EPS);
    EXPECT_NEAR(static_cast<double>(r), 8.0, EPS);
}

TEST(test_03, Wrong_Rhomb)
{
    EXPECT_THROW({Rhomb r(Point(0, 2), Point(2, 0), Point(0, -2), Point(-234242, 0));}, std::invalid_argument);
}

TEST(test_04, Pentagon)
{
    Pentagon p(Point(0.0000000000,  1.7013016167), 
               Point(1.6180339887,  0.5257311121), 
               Point(1.0000000000, -1.3763819205), 
               Point(-1.0000000000, -1.3763819205),
               Point(-1.6180339887,  0.5257311121));
    EXPECT_NEAR(p.getArea(), 6.8819096023559, EPS);
    Point center = p.getCenter();
    EXPECT_NEAR(center.x, 0.0, EPS);
    EXPECT_NEAR(center.y, 0.0, EPS);
    EXPECT_NEAR(static_cast<double>(p), 6.8819096023559, EPS);
}

TEST(test_05, Wrong_Pentagon)
{
    EXPECT_THROW({Pentagon r(Point(0, 2), Point(2, 0), Point(0, -2), Point(-234242, 0), Point(-234242, 0));}, std::invalid_argument);
}

TEST(test_06, Hexagon)
{
    Hexagon p(Point(0, 0), Point(2, 1), Point(3, 3), Point(2, 5), Point(0,4), Point(-1,2));
    EXPECT_NEAR(p.getArea(), 12.0, EPS);
    Point center = p.getCenter();
    EXPECT_NEAR(center.x, 1.0, EPS);
    EXPECT_NEAR(center.y, 5.0/2.0, EPS);
    EXPECT_NEAR(static_cast<double>(p), 12.0, EPS);
}

TEST(test_07, Wrong_Hexagon)
{
    EXPECT_THROW({Hexagon r(Point(0, 2), Point(2, 0), Point(0, -2), Point(-234242, 0), Point(-234242, 0), Point(-234242, 0));}, std::invalid_argument);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
