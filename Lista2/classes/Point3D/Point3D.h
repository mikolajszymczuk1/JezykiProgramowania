#ifndef POINT_3D_H
#define POINT_3D_H

#include "../Point2D/Point2D.h"
#include <iostream>
class Vector3D;

// Point3D class to create 3D points on X,Y,Z coordinates
class Point3D : public Point2D {
    private:
        int z;
    public:
        Point3D();
        Point3D(int posX, int posY, int posZ);
        int getZ();
        void printPoint();
        Point2D projectingToPoint2D(int z0, int d);
        void moveByVector(Vector3D vectorToMoveBy);
};

#endif
