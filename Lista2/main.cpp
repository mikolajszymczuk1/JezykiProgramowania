#include <iostream>
#include <string>
#include <stdlib.h>
#include "classes/PointsFileManager/PointsFileManager.h"
#include "classes/Point2D/Point2D.h"
#include "classes/Vector3D/Vector3D.h"

int main() {
    // -------------------------------------------------------------- PART I

    std::cout << "=== PART I ===" << std::endl;

    const std::string DATA_FILENAME_PART1 = "data/lamana2D0.csv";
    PointsFileManager *pfm = new PointsFileManager(DATA_FILENAME_PART1);
    const int numberOfPointsPfm = pfm->getSize();
    Point2D *points2d = new Point2D[numberOfPointsPfm];
    pfm->createPoints(points2d, numberOfPointsPfm);

    // Check whether the points belong to the line equation
    for (int i = 2; i < numberOfPointsPfm; i++) {
        if (!Point2D::isLineEquationSatisfied(points2d[0], points2d[1], points2d[i])) {
            std::cout << "---------- FAIL" << std::endl;
            points2d[i].printPoint();
            std::cout << "-------------\n" << std::endl;
        }
    }

    delete pfm, points2d;

    // --------------------------------------------------------------

    // -------------------------------------------------------------- PART II

    std::cout << "\n\n=== PART II ===" << std::endl;

    const std::string DATA_FILENAME_PART2 = "data/lamana3D0.csv";
    PointsFileManager *pfm2 = new PointsFileManager(DATA_FILENAME_PART2);
    const int numberOfPointsPfm2 = pfm->getSize();
    Point3D *points3d = new Point3D[numberOfPointsPfm2];
    pfm2->createPoints(points3d, numberOfPointsPfm2);

    Vector3D *a = new Vector3D(points3d[0], points3d[1]);  // AB
    Vector3D *b = new Vector3D(points3d[0], points3d[2]);  // AC
    Vector3D *c;                                           // AX

    for (int i = 3; i < numberOfPointsPfm2; i++) {
        c = new Vector3D(points3d[0], points3d[i]);  // AX
        int volume = abs(a->vectorProduct(*b).scalarProduct(*c));
        if (volume != 0) {
            std::cout << "---------- FAIL" << std::endl;
            std::cout << points3d[i].getX() << " ";
            std::cout << points3d[i].getY() << " ";
            std::cout << points3d[i].getZ() << "\n";
            std::cout << "----------" << std::endl;
        }
    }

    // --------------------------------------------------------------

    // -------------------------------------------------------------- PART III

    std::cout << "\n\n=== PART III ===" << std::endl;

    for (int i = 2; i < numberOfPointsPfm2; i++) {
        if (!Point3D::isStraightEquationSatisfied(points3d[0], points3d[1], points3d[i])) {
            std::cout << "---------- FAIL" << std::endl;
            points3d[i].printPoint();
            std::cout << "-------------\n" << std::endl;
        }
    }

    delete pfm2, points3d, a, b, c;

    // --------------------------------------------------------------

    return 0;
}
