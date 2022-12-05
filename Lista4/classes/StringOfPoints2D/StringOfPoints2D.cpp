#include "StringOfPoints2D.h"

/** Create empty vector set of Points 2D */
StringOfPoints2D::StringOfPoints2D() {
    pointsSet = new std::vector<Point2D>;
}

/** Make free space */
StringOfPoints2D::~StringOfPoints2D() {
    delete pointsSet;
}

/** Add new point to set of points */
void StringOfPoints2D::addPoint(Point2D pointToAdd) {

}

/** Remove point from set of points */
void StringOfPoints2D::removePoint(Point2D pointToRemove) {

}

/** Check if point is in set of points */
bool StringOfPoints2D::isPointInStringOfPoints(Point2D pointToCheck) {
    return true;
}

/** Return point with index == 'i' */
Point2D StringOfPoints2D::getPoint(int i) {
    return Point2D(0, 0);
}

/** Return count of all elements in set of points */
int StringOfPoints2D::getStringOfPointsSize() {
    return pointsSet->size();
}
