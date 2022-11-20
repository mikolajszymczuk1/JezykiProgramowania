#include "PointsFileManager.h"

// Create new file manager
PointsFileManager::PointsFileManager(std::string pathToFile) {
    path = pathToFile;
    dataFile = new std::ifstream(path);
}

// Delete unused things
PointsFileManager::~PointsFileManager() {
    dataFile->close();
    delete dataFile;
}

// Return file number of lines
int PointsFileManager::getSize() {
    clearFlag();
    int count = 0;
    std::string line;
    while (dataFile->peek() != EOF) {
        std::getline(*dataFile, line);
        count++;
    }

    return count;
}

// Return filename
std::string PointsFileManager::getFilename() {
    std::string preparedFilename = "";
    int lastSlash = 0;

    for (int i = 0; i < path.length(); i++) {
        if (path[i] == '/' || path[i] == '\\') {
            lastSlash = i;
        }
    }

    return path.substr(lastSlash + 1, path.length() - 1);
}

// Return path to file
std::string PointsFileManager::getPath() {
    return path;
}

// Create 2D points and save in array
void PointsFileManager::createPoints(Point2D *pointsArray, int size) {
    clearFlag();
    std::string line;
    int i = 0;
    while (std::getline(*dataFile, line)) {
        Point2D newPoint = create2dPoint(line);
        pointsArray[i] = newPoint;
        i++;
    }
}

// Create 3D points and save in array
void PointsFileManager::createPoints(Point3D *pointsArray, int size) {
    clearFlag();
    std::string line;
    int i = 0;
    while (std::getline(*dataFile, line)) {
        Point3D newPoint = create3dPoint(line);
        pointsArray[i] = newPoint;
        i++;
    }
}

// Clear ifstream flag
void PointsFileManager::clearFlag() {
    dataFile->clear();
    dataFile->seekg(0, std::ios::beg);
}

// Create 2D point based on string line from file
Point2D PointsFileManager::create2dPoint(std::string line) {
    int semiIndex = 0;
    for (int i = 0; i < line.length(); i++) {
        if (line[i] == ';') {
            semiIndex = i;
            break;
        }
    }

    float x = std::stof(line.substr(0, semiIndex));
    float y = std::stof(line.substr(semiIndex + 1, line.length() - 1));
    return Point2D(x, y);
}

// Create 3D point based on string line from file
Point3D PointsFileManager::create3dPoint(std::string line) {
    int semiIndexA = 0;
    int semiIndexB = 0;

    for (int i = 0; i < line.length(); i++) {
        if (line[i] == ';' && semiIndexA == 0) {
            semiIndexA = i;
        } else if (line[i] == ';' && semiIndexB == 0) {
            semiIndexB = i;
        }
    }

    float x = std::stof(line.substr(0, semiIndexA));
    float y = std::stof(line.substr(semiIndexA + 1, semiIndexB));
    float z = std::stof(line.substr(semiIndexB + 1, line.length() - 1));
    return Point3D(x, y, z);
}
