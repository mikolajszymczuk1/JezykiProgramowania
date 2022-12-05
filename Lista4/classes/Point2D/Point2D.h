#ifndef POINT_2D_H
#define POINT_2D_H

#include <iostream>

// Point2D class to create 2D points on X,Y coordinates
class Point2D {
    protected:
        float x;
        float y;
    public:
        Point2D();
        Point2D(float posX, float posY);
        float getX();
        float getY();
        void printPoint();
        static bool isLineEquationSatisfied(Point2D pointA, Point2D pointB, Point2D pointC);
        bool operator<(const Point2D &pointToCompare);
        bool operator==(const Point2D &pointToEqual);
};

#endif
