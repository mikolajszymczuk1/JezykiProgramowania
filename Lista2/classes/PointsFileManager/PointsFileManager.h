#ifndef POINTS_FILE_MANAGER_H
#define POINTS_FILE_MANAGER_H

#include <fstream>
#include <string>

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
};

#endif
