#include "Point2D.h"

// Default constructor for point 2D
Point2D::Point2D() {}

// Create point 2D
Point2D::Point2D(float posX, float posY) {
    x = posX;
    y = posY;
}

// Return position X of point 2D
float Point2D::getX() {
    return x;
}

// Return position Y of point 2D
float Point2D::getY() {
    return y;
}

// Print point 2D information
void Point2D::printPoint() {
    std::cout << "Point 2D" << std::endl;
    std::cout << "X = " << getX() << std::endl;
    std::cout << "Y = " << getY() << std::endl;
}

// Check if line equation is satisfied
bool Point2D::isLineEquationSatisfied(Point2D pointA, Point2D pointB, Point2D pointC) {
    return (((pointC.getY() - pointA.getY()) * (pointB.getX() - pointA.getX())) - ((pointB.getY() - pointA.getY()) * (pointC.getX() - pointA.getX())) == 0);
}

// Overload compare operator <
bool Point2D::operator<(const Point2D &pointToCompare) const {
    return pointToCompare.x > x || (pointToCompare.x == x && pointToCompare.y > y);
}

// Overload equal operator ==
bool Point2D::operator==(const Point2D &pointToEqual) const {
    return (x == pointToEqual.x && y == pointToEqual.y);
}
