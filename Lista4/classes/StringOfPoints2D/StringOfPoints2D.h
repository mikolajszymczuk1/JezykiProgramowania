#ifndef STRING_OF_POINTS_2D_H
#define STRING_OF_POINTS_2D_H

#include <vector>
#include "../Point2D/Point2D.h"

class StringOfPoints2D {
    private:
        std::vector<Point2D> *pointsSet;
    public:
        StringOfPoints2D();
        ~StringOfPoints2D();
        void addPoint(Point2D pointToAdd);
        void removePoint(Point2D pointToRemove);
        bool isPointInStringOfPoints(Point2D pointToCheck);
        Point2D getPoint(int i);
        int getStringOfPointsSize();
};

#endif
