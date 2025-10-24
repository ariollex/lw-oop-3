#pragma once
#include <iostream>
#include <algorithm>
#include "Point.hpp"

class Figure {
public:
    Figure();

    virtual Point getCenter() const;
    virtual double getArea() const;
    explicit virtual operator double() const;

    friend std::istream& operator>>(std::istream& inputStream, Figure& figure);
    friend std::ostream& operator<<(std::ostream& outputStream, const Figure& figure);

    bool Validate();
    void SortVertices();

    virtual ~Figure();
protected:
    int n;
    Point* vertices;
};
