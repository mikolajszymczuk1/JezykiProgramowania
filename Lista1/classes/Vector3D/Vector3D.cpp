#include "Vector3D.h"

// Create new vector 3D with x, y, z coordinates
Vector3D::Vector3D(int posX, int posY, int posZ) {
    x = posX;
    y = posY;
    z = posZ;
}

// Create new vector 3D base on Point3D object
Vector3D::Vector3D(Point3D basePoint) {
    x = basePoint.getX();
    y = basePoint.getY();
    z = basePoint.getZ();
}

// Create new vector 3D base on start point and end point
Vector3D::Vector3D(Point3D startPoint, Point3D endPoint) {
    x = endPoint.getX() - startPoint.getX();
    y = endPoint.getY() - startPoint.getY();
    z = endPoint.getZ() - startPoint.getZ();
}

// Return vector X postion
int Vector3D::getX() {
    return x;
}

// Return vector Y postion
int Vector3D::getY() {
    return y;
}

// Return vector Z postion
int Vector3D::getZ() {
    return z;
}

// Return scalar product of two vectors
int Vector3D::scalarProduct(Vector3D vectorToProd) {
    return (x * vectorToProd.getX()) + (y * vectorToProd.getY()) + (z * vectorToProd.getZ());
}

// Return vector that is sum of two vectors
Vector3D Vector3D::addVector(Vector3D vectorToAdd) {
    return Vector3D(x + vectorToAdd.getX(), y + vectorToAdd.getY(), z + vectorToAdd.getZ());
}

// Return vector that is difference of two vectors
Vector3D Vector3D::subVector(Vector3D vectorToSub) {
    return Vector3D(x - vectorToSub.getX(), y - vectorToSub.getY(), z - vectorToSub.getZ());
}

// Return vector product of two vectors
Vector3D Vector3D::vectorProduct(Vector3D vectorToProd) {
    return Vector3D((y * vectorToProd.getZ()) - (z * vectorToProd.getY()), -(x * vectorToProd.getZ() - z * vectorToProd.getX()), (x * vectorToProd.getY()) - (y * vectorToProd.getX()));
}
