#include "PointsFileManager.h"

// Create new file manager
PointsFileManager::PointsFileManager(std::string pathToFile) {
    path = pathToFile;
    dataFile = new std::ifstream(path);
}

// Delete unused things
PointsFileManager::~PointsFileManager() {
    delete dataFile;
}

// Return file number of lines
int PointsFileManager::getSize() {
    return 5;
}

// Return filename
std::string PointsFileManager::getFilename() {
    return filename;
}

// Return path to file
std::string PointsFileManager::getPath() {
    return path;
}
