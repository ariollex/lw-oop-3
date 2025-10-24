#pragma once
#include <iostream>

#include "Figure.hpp"

class Rhomb: public Figure {
public: 
    Rhomb();
    Rhomb(const Point& p1, const Point& p2, const Point& p3, const Point& p4);

    Rhomb(const Rhomb& other);
    Rhomb(Rhomb&& other) noexcept;
    Rhomb& operator=(const Rhomb& other);
    Rhomb& operator=(Rhomb&& other) noexcept;
    friend void swap(Rhomb& a, Rhomb& b) noexcept;

    bool operator==(const Rhomb& other) const;
};
