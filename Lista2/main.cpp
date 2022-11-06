#include <iostream>
#include <string>
#include "classes/PointsFileManager/PointsFileManager.h"
#include "classes/Point2D/Point2D.h"

int main() {
    const std::string DATA_FILENAME = "data/lamana2D0.csv";
    PointsFileManager *pfm = new PointsFileManager(DATA_FILENAME);
    const int numberOfPoints = pfm->getSize();
    Point2D *points = new Point2D[numberOfPoints];
    pfm->createPoints(points, numberOfPoints);

    // Check whether the points belong to the line equation
    for (int i = 2; i < numberOfPoints; i++) {
        if (Point2D::isLineEquationSatisfied(points[0], points[1], points[i])) {
            std::cout << "---------- OK" << std::endl;
        } else {
            std::cout << "---------- FAIL" << std::endl;
        }

        points[i].printPoint();
        std::cout << "-------------\n" << std::endl;
    }

    delete pfm, points;

    return 0;
}
