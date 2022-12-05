#include <iostream>
#include "./classes/StringOfPoints/StringOfPoints.h"

int main() {
    StringOfPoints<Point2D> *sop2d = new StringOfPoints<Point2D>();
    Point2D *p1 = new Point2D(2, 3);
    Point2D *p2 = new Point2D(5, 6);

    sop2d->addPoint(*p1);
    sop2d->addPoint(*p2);

    std::cout << "Is p1 exists: " << sop2d->isPointInStringOfPoints(*p1) << std::endl;
    std::cout << "Is p2 exists: " << sop2d->isPointInStringOfPoints(*p2) << std::endl;
    std::cout << "\n";

    sop2d->getPoint(0).printPoint();
    std::cout << "Get size of string of points: " << sop2d->getStringOfPointsSize() << std::endl;
    std::cout << "\n";

    sop2d->removePoint(*p1);

    sop2d->getPoint(0).printPoint();
    std::cout << "Get size of string of points: " << sop2d->getStringOfPointsSize() << std::endl;
    std::cout << "\n";

    std::cout << "Is p1 exists: " << sop2d->isPointInStringOfPoints(*p1) << std::endl;
    std::cout << "Is p2 exists: " << sop2d->isPointInStringOfPoints(*p2) << std::endl;

    delete sop2d, p1, p2;

    return 0;
}
