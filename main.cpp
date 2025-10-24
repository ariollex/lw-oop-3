#include <iostream>
#include "Array.hpp"
#include "rhomb.hpp"
#include "pentagon.hpp"
#include "hexagon.hpp"

int main() {
    Array arr(4);

    arr[0] = new Rhomb();
    std::cin >> *arr[0];

    arr[1] = new Pentagon();
    std::cin >> *arr[1];

    arr[2] = new Hexagon();
    std::cin >> *arr[2];

    arr[3] = new Rhomb();
    std::cin >> *arr[3];
    arr.Remove(3);

    std::cout << "Area and center:" << std::endl;
    for(int i = 0; i < arr.Size(); ++i) {
        std::cout << "=================" << std::endl;
        std::cout << *arr[i] << std::endl;
        std::cout << arr[i]->getArea() << std::endl;
        std::cout << arr[i]->getCenter() << std::endl;
        std::cout << "=================" << std::endl;
    }

    while(arr.Size() > 0) {
        arr.Remove(0);
    }

    return 0;
}

// 0 1 1 0 0 -1 -1 0 , площадь 2, центр {0, 0}
// 0 1 -0.9510565163 0.309016988 -0.5877852523 -0.809016988 0.5877852523 -0.809016988 0.9510565163 0.309016988, площадь 2.37764, центр {0, 0}
// 0 0 2 1 3 3 2 5 0 4 -1 2 , площадь 12, центр {1, 2.5}
// 0 1 1 0 0 -1 -1 0 