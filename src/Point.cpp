#include "Point.hpp"

Point::Point(): x(0), y(0) {};

Point::Point(double cx, double cy): x(cx), y(cy) {};

double Point::LenghtToPoint(const Point& other) const {
    return std::sqrt(std::pow((x - other.x), 2) + pow((y - other.y), 2));
};

bool Point::operator==(const Point& other) const {
    return abs(x - other.x) < EPS && abs(y - other.y) < EPS;
};

bool Point::operator!=(const Point& other) const {
    return !(*this == other);
};

std::istream& operator>>(std::istream& inputStream, Point& p) {
    inputStream >> p.x >> p.y;
    return inputStream;
};

std::ostream& operator<<(std::ostream& outputStream, const Point& p) {
    outputStream << "{" << p.x << " " << p.y << "}";
    return outputStream;
};
