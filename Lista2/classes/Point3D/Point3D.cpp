#include "Point3D.h"
#include "../Vector3D/Vector3D.h"

// Default constructor for point 3D
Point3D::Point3D() {}

// Create point 3D
Point3D::Point3D(int posX, int posY, int posZ) : Point2D(posX, posY) {
    z = posZ;
}

// Return position Z of point 3D
int Point3D::getZ() {
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
Point2D Point3D::projectingToPoint2D(int z0, int d) {
    if ((z0 - getZ()) == 0) return *new Point2D(0, 0);
    int x2 = (z0 * getX() - getZ() * d) / (z0 - getZ());
    int y2 = (z0 * getY()) / (z0 - getZ());
    return *new Point2D(x2, y2);
}

// Move point by vector 3D
void Point3D::moveByVector(Vector3D vectorToMoveBy) {
    x += vectorToMoveBy.getX();
    y += vectorToMoveBy.getY();
    z += vectorToMoveBy.getZ();
}
