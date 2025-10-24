#include "Array.hpp"

Array::Array(size_t capacity): capacity(capacity), size(0), figures(new Figure*[capacity]()) {};

Array::Array(Array&& other) noexcept: size(other.size), capacity(other.capacity), figures(other.figures) {
    other.size = 0;
    other.capacity = 0;
    other.figures = nullptr;
}

Array& Array::operator=(Array&& other) noexcept {
    if (this != &other) {
        for (size_t i = 0; i < size; ++i) delete figures[i];
        delete[] figures;

        size = other.size;
        capacity = other.capacity;
        figures = other.figures;

        other.size = 0;
        other.capacity = 0;
        other.figures = nullptr;
    }
    return *this;
}

Figure*& Array::operator[](size_t index) {
    if (index + 1 > capacity) throw std::out_of_range("Index out of range!");
    if (index + 1 > size) size = index + 1;
    return figures[index];
}

size_t Array::Size() const noexcept {
    return size;
}

double Array::GlobalArea() const {
    double amount = 0;
    for(int i = 0; i < size; ++i) if (figures[i]) amount += figures[i]->getArea();
    return amount;
}

void Array::Remove(size_t index) {
    if (index + 1 > size) throw std::out_of_range("Index out of range!");
    delete figures[index];
    for (int i = index + 1; i < size; ++i) {
        figures[i - 1] = figures[i];
    }
    figures[size-- - 1] = nullptr;
}

Array::~Array() {
    for(size_t i = 0; i < size; ++i) delete figures[i];
    delete[] figures;
}
