#include "pentagon.hpp"
#include <utility>

Pentagon::Pentagon() {
    n = 5;
    vertices = new Point[n];
};

Pentagon::Pentagon(const Point& p1, const Point& p2, const Point& p3, const Point& p4, const Point& p5) {
    n = 5;
    vertices = new Point[n];
    vertices[0] = p1;
    vertices[1] = p2;
    vertices[2] = p3;
    vertices[3] = p4;
    vertices[4] = p5;

    SortVertices();

    if (std::abs(vertices[0].LenghtToPoint(vertices[1])) < EPS) throw std::invalid_argument("Wrong Pentagon!");
    for(int i = 0; i < n; ++i) { //фигура д.б. равносторонней по условию
        if (std::abs(vertices[i].LenghtToPoint(vertices[(i + 1) % n]) - vertices[(i + 1) % n].LenghtToPoint(vertices[(i + 2) % n])) > EPS) {
            throw std::invalid_argument("Wrong Pentagon!"); 
        }
    }
    if (vertices[0].LenghtToPoint(vertices[2]) < EPS || vertices[1].LenghtToPoint(vertices[3]) < EPS) throw std::invalid_argument("Wrong Pentagon!"); 
}

Pentagon::Pentagon(const Pentagon& other) {
    n = other.n;
    vertices = new Point[n];

    for(size_t i = 0; i < n; ++i) {
        vertices[i] = other.vertices[i];
    }
}

Pentagon::Pentagon(Pentagon&& other) noexcept {
    n = other.n;
    vertices = other.vertices;

    other.n = 0;
    other.vertices = nullptr;
};

void swap(Pentagon& a, Pentagon& b) noexcept {
    std::swap(a.n, b.n);
    std::swap(a.vertices, b.vertices);
}

Pentagon& Pentagon::operator=(const Pentagon& other) {
    if (this != &other) {
        Pentagon tmp(other);
        swap(*this, tmp);
    }
    return *this;
};

Pentagon& Pentagon::operator=(Pentagon&& other) noexcept {
    if (this != &other) {
        delete[] vertices;
        n = other.n;
        vertices = other.vertices;
        other.n = 0;
        other.vertices = nullptr;
    }
    return *this;
};

bool Pentagon::operator==(const Pentagon& other) const {
    for(int i = 0; i < n; ++i) {
        if (vertices[i] != other.vertices[i]) return false;
    }
    return true;
};