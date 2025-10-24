#pragma once
#include <stdlib.h>
#include "Figure.hpp"

class Array {
public:
    Array() = default;

    Array(size_t capacity);
    Figure*& operator[](size_t index);

    Array(const Array& other) = delete;
    Array& operator=(const Array& other) = delete;
    Array(Array&& other) noexcept;
    Array& operator=(Array&& other) noexcept;

    size_t Size() const noexcept;

    double GlobalArea() const;

    void Remove(size_t index);

    virtual ~Array();
private:
    size_t size = 0;
    size_t capacity = 0;
    Figure** figures = nullptr;
};
