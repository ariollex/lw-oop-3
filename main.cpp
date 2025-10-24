#include <iostream>
#include "Figure.hpp"
#include "rhomb.hpp"
#include "pentagon.hpp"
#include "hexagon.hpp"

int main() {
    Figure* arr[3];

    arr[0] = new Rhomb();
    std::cin >> *arr[0];

    arr[1] = new Pentagon();
    std::cin >> *arr[1];

    arr[2] = new Hexagon();
    std::cin >> *arr[2];

    for(int i = 0; i < 3; ++i) {
        std::cout << *arr[i] << std::endl;
        std::cout << arr[i]->getArea() << std::endl;
        std::cout << arr[i]->getCenter() << std::endl;
        delete arr[i];
    }
}

// 0 1 1 0 0 -1 -1 0 , площадь 2, центр {0, 0}
// 0 0 4 0 5 2 2 4 -1 2 , площадь 16, центр {2.0 1.6667}
// 2 0 3 2 2 4 -2 4 -3 2 -2 0 , площадь 20, центр {0, 2}