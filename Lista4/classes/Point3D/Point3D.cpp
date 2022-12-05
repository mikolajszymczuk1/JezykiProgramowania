#include "Point3D.h"
#include "../Vector3D/Vector3D.h"

// Default constructor for point 3D
Point3D::Point3D() {}

// Create point 3D
Point3D::Point3D(float posX, float posY, float posZ) : Point2D(posX, posY) {
    z = posZ;
}

// Return position Z of point 3D
float Point3D::getZ() {
    return z;
}

// Print point 3D information
void Point3D::printPoint() {
    std::cout << "Point 3D" << std::endl;
    std::cout << "X = " << getX() << std::endl;
    std::cout << "Y = " << getY() << std::endl;
    std::cout << "Z = " << getZ() << std::endl;
}

// Projection on point 2D from point 3D
Point2D Point3D::projectingToPoint2D(float z0, float d) {
    if (z0 - getZ() == 0) throw "Divide by 0 !";
    float x2 = (z0 * getX() - getZ() * d) / (z0 - getZ());
    float y2 = (z0 * getY()) / (z0 - getZ());
    return Point2D(x2, y2);
}

// Move point by vector 3D
void Point3D::moveByVector(Vector3D vectorToMoveBy) {
    x += vectorToMoveBy.getX();
    y += vectorToMoveBy.getY();
    z += vectorToMoveBy.getZ();
}

// Check if 3D points are on the same straight
bool Point3D::isStraightEquationSatisfied(Point3D pointA, Point3D pointB, Point3D pointC) {
    Vector3D *a = new Vector3D(pointA, pointB);  // AB
    if (a->getX() == 0 || a->getY() == 0 || a->getZ() == 0) throw "Divide by 0";
    return ((((pointC.getX() - pointA.getX()) / a->getX()) == (pointC.getY() - pointA.getY()) / a->getY()) && (((pointC.getY() - pointA.getY()) / a->getY()) == (pointC.getZ() - pointA.getZ()) / a->getZ()));
}

// Overload operator <
bool Point3D::operator<(const Point3D &pointToCompare) {
    return (pointToCompare.x > x && pointToCompare.y > y && pointToCompare.z > z);
}