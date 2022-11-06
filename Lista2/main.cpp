#include <iostream>
#include <fstream>
#include <string>
#include "classes/PointsFileManager/PointsFileManager.h"
#include "classes/Point2D/Point2D.h"

int main() {
    const std::string DATA_FILENAME = "data/lamana2D0.csv";
    Point2D *points;
    PointsFileManager *pfm = new PointsFileManager(DATA_FILENAME);

    std::cout << pfm->getPath() << std::endl;

    return 0;
}
