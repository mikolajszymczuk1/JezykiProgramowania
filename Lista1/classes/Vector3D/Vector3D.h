#ifndef VECTOR_3D_H
#define VECTOR_3D_H

#include "../Point3D/Point3D.cpp"

// Vector class to create 3D vectors
class Vector3D {
    private:
        int x;
        int y;
        int z;
    public:
        Vector3D(int posX, int posY, int posZ);
        Vector3D(Point3D basePoint);
        Vector3D(Point3D startPoint, Point3D endPoint);
        int getX();
        int getY();
        int getZ();
        int scalarProduct(Vector3D vectorToMultiply);
        Vector3D addVector(Vector3D vectorToAdd);
        Vector3D subVector(Vector3D vectorToSub);
        Vector3D vectorProduct(Vector3D vectorToProd);
};

#endif
