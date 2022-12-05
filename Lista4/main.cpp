#include <iostream>
#include "./classes/StringOfPoints2D/StringOfPoints2D.h"

int main() {
    StringOfPoints2D *sop2d = new StringOfPoints2D();
    std::cout << sop2d->getStringOfPointsSize() << std::endl;

    delete sop2d;

    return 0;
}
