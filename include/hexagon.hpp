#pragma once
#include <iostream>

#include "Figure.hpp"

class Hexagon: public Figure {
public: 
    Hexagon();
    Hexagon(const Point& p1, const Point& p2, const Point& p3, const Point& p4, const Point& p5, const Point& p6);

    Hexagon(const Hexagon& other);
    Hexagon(Hexagon&& other) noexcept;
    Hexagon& operator=(const Hexagon& other);
    Hexagon& operator=(Hexagon&& other) noexcept;
    friend void swap(Hexagon& a, Hexagon& b) noexcept;

    bool operator==(const Hexagon& other) const;
};
