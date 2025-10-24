#pragma once
#include <iostream>
#include <cmath>
#define EPS 1e-6

class Point {
public:
    Point();
    Point(double x, double y);

    bool operator==(const Point& other) const;
    bool operator!=(const Point& other) const;

    double LenghtToPoint(const Point& other) const;

    friend std::istream& operator>>(std::istream& inputStream, Point& p);
    friend std::ostream& operator<<(std::ostream& outputStream, const Point& p);

    double x, y;
};
