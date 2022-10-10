#include "Point2D.h"

// Default constructor for point 2D
Point2D::Point2D() {}

// Create point 2D
Point2D::Point2D(int posX, int posY) {
    x = posX;
    y = posY;
}

// Return position X of point 2D
int Point2D::getX() {
    return x;
}

// Return position Y of point 2D
int Point2D::getY() {
    return y;
}

// Print point 2D information
void Point2D::printPoint() {
    std::cout << "Point 2D" << std::endl;
    std::cout << "X = " << getX() << std::endl;
    std::cout << "Y = " << getY() << std::endl;
}
