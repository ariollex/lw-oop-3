#pragma once
#include <iostream>

#include "Figure.hpp"

class Pentagon: public Figure {
public: 
    Pentagon();
    Pentagon(const Point& p1, const Point& p2, const Point& p3, const Point& p4, const Point& p5);

    Pentagon(const Pentagon& other);
    Pentagon(Pentagon&& other) noexcept;
    Pentagon& operator=(const Pentagon& other);
    Pentagon& operator=(Pentagon&& other) noexcept;
    friend void swap(Pentagon& a, Pentagon& b) noexcept;

    bool operator==(const Pentagon& other) const;
};
