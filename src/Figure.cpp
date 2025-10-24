#include "Figure.hpp"

Figure::Figure(): n(0), vertices(nullptr) {};

double Figure::getArea() const {
    double amount = 0;
    for (size_t i = 0, j = n - 1; i < n; j = i++) {
        amount += vertices[j].x * vertices[i].y - vertices[j].y * vertices[i].x;
    }
    return 0.5 * std::abs(amount);
};

Point Figure::getCenter() const {
    double ax = 0, ay = 0;
    for(int i = 0; i < n; ++i) {
        ax += vertices[i].x;
        ay += vertices[i].y;
    }
    return Point(ax / n, ay / n);
};

Figure::operator double() const {
    return getArea();
};

std::istream& operator>>(std::istream& inputStream, Figure& figure) {
    for (size_t i = 0; i < figure.n; ++i) {
        inputStream >> figure.vertices[i];
    }
    if (!figure.Validate()) throw std::invalid_argument("Wrong points!");
    return inputStream;
}

std::ostream& operator<<(std::ostream& outputStream, const Figure& figure) {
    for (size_t i = 0; i < figure.n; ++i) {
        outputStream << figure.vertices[i];
    }
    return outputStream;
}

bool Figure::Validate() {
    SortVertices();
    if (n < 3) return false;
    double random_side = vertices[0].LenghtToPoint(vertices[1]);
    if (std::abs(random_side) < EPS) return false;
    for(int i = 0; i < n; ++i) {
        if (std::abs(vertices[i].LenghtToPoint(vertices[(i + 1) % n]) - random_side) > EPS) return false; 
    }
    if (vertices[0].LenghtToPoint(vertices[2]) < EPS || vertices[1].LenghtToPoint(vertices[3]) < EPS) return false;
    return true;
}

void Figure::SortVertices() {
    Point c = getCenter();
    auto comp = [c](const Point& A, const Point& B) {
        double aA = std::atan2(A.y - c.y, A.x - c.x);
        double aB = std::atan2(B.y - c.y, B.x - c.x);
        if(std::abs(aA-aB) > EPS) return aA < aB; //при равенстве углов сортируем по радиусу
        double rA = (A.x - c.x)*(A.x - c.x) + (A.y - c.y)*(A.y - c.y);
        double rB = (B.x - c.x)*(B.x - c.x) + (B.y - c.y)*(B.y - c.y);
        return rA < rB;
    };
    std::sort(vertices, vertices + n, comp);
}

Figure::~Figure() {
    delete[] vertices;
    vertices = nullptr;
}