#include "rhomb.hpp"
#include <utility>

Rhomb::Rhomb() {
    n = 4;
    vertices = new Point[n];
};

Rhomb::Rhomb(const Point& p1, const Point& p2, const Point& p3, const Point& p4) {
    n = 4;
    vertices = new Point[n];
    vertices[0] = p1;
    vertices[1] = p2;
    vertices[2] = p3;
    vertices[3] = p4;

    SortVertices();

    if (!Validate()) throw std::invalid_argument("Wrong Rhomb!"); 
}

Rhomb::Rhomb(const Rhomb& other) {
    n = other.n;
    vertices = new Point[n];

    for(size_t i = 0; i < n; ++i) {
        vertices[i] = other.vertices[i];
    }
}

Rhomb::Rhomb(Rhomb&& other) noexcept {
    n = other.n;
    vertices = other.vertices;

    other.n = 0;
    other.vertices = nullptr;
};

void swap(Rhomb& a, Rhomb& b) noexcept {
    std::swap(a.n, b.n);
    std::swap(a.vertices, b.vertices);
}

Rhomb& Rhomb::operator=(const Rhomb& other) {
    if (this != &other) {
        Rhomb tmp(other);
        swap(*this, tmp);
    }
    return *this;
};

Rhomb& Rhomb::operator=(Rhomb&& other) noexcept {
    if (this != &other) {
        delete[] vertices;
        n = other.n;
        vertices = other.vertices;
        other.n = 0;
        other.vertices = nullptr;
    }
    return *this;
};

bool Rhomb::operator==(const Rhomb& other) const {
    for(int i = 0; i < n; ++i) {
        if (vertices[i] != other.vertices[i]) return false;
    }
    return true;
};