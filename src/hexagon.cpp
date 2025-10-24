#include "hexagon.hpp"
#include <utility>

Hexagon::Hexagon() {
    n = 6;
    vertices = new Point[n];
};

Hexagon::Hexagon(const Point& p1, const Point& p2, const Point& p3, const Point& p4, const Point& p5, const Point& p6) {
    n = 6;
    vertices = new Point[n];
    vertices[0] = p1;
    vertices[1] = p2;
    vertices[2] = p3;
    vertices[3] = p4;
    vertices[4] = p5;
    vertices[5] = p6;

    SortVertices();

    if (!Validate()) throw std::invalid_argument("Wrong Hexagon!"); 
}

Hexagon::Hexagon(const Hexagon& other) {
    n = other.n;
    vertices = new Point[n];

    for(size_t i = 0; i < n; ++i) {
        vertices[i] = other.vertices[i];
    }
}

Hexagon::Hexagon(Hexagon&& other) noexcept {
    n = other.n;
    vertices = other.vertices;

    other.n = 0;
    other.vertices = nullptr;
};

void swap(Hexagon& a, Hexagon& b) noexcept {
    std::swap(a.n, b.n);
    std::swap(a.vertices, b.vertices);
}

Hexagon& Hexagon::operator=(const Hexagon& other) {
    if (this != &other) {
        Hexagon tmp(other);
        swap(*this, tmp);
    }
    return *this;
};

Hexagon& Hexagon::operator=(Hexagon&& other) noexcept {
    if (this != &other) {
        delete[] vertices;
        n = other.n;
        vertices = other.vertices;
        other.n = 0;
        other.vertices = nullptr;
    }
    return *this;
};

bool Hexagon::operator==(const Hexagon& other) const {
    for(int i = 0; i < n; ++i) {
        if (vertices[i] != other.vertices[i]) return false;
    }
    return true;
};