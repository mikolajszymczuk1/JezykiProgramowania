#include <iostream>
#include "./classes/Point2D/Point2D.h"
#include "./classes/StringOfPoints/StringOfPoints.h"
#include "./classes/SetOfPoints/SetOfPoints.h"

int main() {
    std::cout << "========= String Of Points Tests ========= \n\n";
    
    StringOfPoints<Point2D> *stringOp2d = new StringOfPoints<Point2D>();
    SetOfPoints<Point2D> *setOp2d = new SetOfPoints<Point2D>();

    Point2D *p1 = new Point2D(2, 3);
    Point2D *p2 = new Point2D(4, 3);
    Point2D *p3 = new Point2D(3, 6);
    Point2D *p4 = new Point2D(4, 4);
    Point2D *p5 = new Point2D(1, 7);
    Point2D *p6 = new Point2D(3, 3);

    stringOp2d->addPoint(*p1);
    stringOp2d->addPoint(*p2);
    stringOp2d->addPoint(*p3);

    std::cout << "Is p1 exists: " << stringOp2d->isPointInStringOfPoints(*p1) << std::endl;
    std::cout << "Is p2 exists: " << stringOp2d->isPointInStringOfPoints(*p2) << std::endl;
    std::cout << "\n";

    stringOp2d->getPoint(0).printPoint();
    std::cout << "Get size of string of points: " << stringOp2d->getStringOfPointsSize() << std::endl;
    std::cout << "\n";

    stringOp2d->removePoint(*p1);

    stringOp2d->getPoint(0).printPoint();
    std::cout << "Get size of string of points: " << stringOp2d->getStringOfPointsSize() << std::endl;
    std::cout << "\n";

    std::cout << "Is p1 exists: " << stringOp2d->isPointInStringOfPoints(*p1) << std::endl;
    std::cout << "Is p2 exists: " << stringOp2d->isPointInStringOfPoints(*p2) << std::endl;

    std::cout << "\n\n ========= Set Of Points Tests ========= \n\n";

    setOp2d->addPoint(*p1);
    setOp2d->addPoint(*p2);
    setOp2d->addPoint(*p3);
    setOp2d->addPoint(*p4);
    setOp2d->addPoint(*p5);
    setOp2d->addPoint(*p6);

    // Print all points
    std::set<Point2D> pointsSet2d = setOp2d->getPointsSet();
    for (Point2D point : pointsSet2d) {
        point.printPoint();
        std::cout << "\n";
    }

    std::cout << "Is p4 point in set: " << (setOp2d->isPointInSet(*p4)) << std::endl;
    setOp2d->removePoint(*p4);
    std::cout << "Is p4 point in set: " << (setOp2d->isPointInSet(*p4)) << std::endl;

    delete stringOp2d, setOp2d;
    delete p1, p2, p3, p4, p5, p6;
    
    return 0;
}
