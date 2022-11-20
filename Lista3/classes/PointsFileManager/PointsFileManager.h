#ifndef POINTS_FILE_MANAGER_H
#define POINTS_FILE_MANAGER_H

#include <fstream>
#include <string>
#include "../Point2D/Point2D.h"
#include "../Point3D/Point3D.h"

class PointsFileManager {
    private:
        std::string filename;
        std::string path;
        std::ifstream *dataFile;
    public:
        PointsFileManager(std::string pathToFile);
        ~PointsFileManager();
        int getSize();
        std::string getFilename();
        std::string getPath();
        void createPoints(Point2D *pointsArray, int size);
        void createPoints(Point3D *pointsArray, int size);
        void clearFlag();
        Point2D create2dPoint(std::string line);
        Point3D create3dPoint(std::string line);
};

#endif
