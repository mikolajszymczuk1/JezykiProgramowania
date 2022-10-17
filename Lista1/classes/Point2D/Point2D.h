#ifndef POINT_2D_H
#define POINT_2D_H

#include <iostream>

// Point2D class to create 2D points on X,Y coordinates
class Point2D {
    protected:
        int x;
        int y;
    public:
        Point2D();
        Point2D(int posX, int posY);
        int getX();
        int getY();
        void printPoint();
};

#endif
