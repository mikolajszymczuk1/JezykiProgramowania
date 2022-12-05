#ifndef POINT_3D_H
#define POINT_3D_H

#include "../Point2D/Point2D.h"
#include <iostream>
class Vector3D;

// Point3D class to create 3D points on X,Y,Z coordinates
class Point3D : public Point2D {
    private:
        float z;
    public:
        Point3D();
        Point3D(float posX, float posY, float posZ);
        float getZ();
        void printPoint();
        Point2D projectingToPoint2D(float z0, float d);
        void moveByVector(Vector3D vectorToMoveBy);
        static bool isStraightEquationSatisfied(Point3D pointA, Point3D pointB, Point3D pointC);
        bool operator<(const Point3D &pointToCompare);
        bool operator==(const Point3D &pointToEqual);
};

#endif
