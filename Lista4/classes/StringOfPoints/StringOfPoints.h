#ifndef STRING_OF_POINTS_H
#define STRING_OF_POINTS_H

#include <vector>

template <class T>
class StringOfPoints {
    private:
        std::vector<T> *pointsSet;
    public:
        StringOfPoints();
        ~StringOfPoints();
        void addPoint(T pointToAdd);
        void removePoint(T pointToRemove);
        bool isPointInStringOfPoints(T pointToCheck);
        T getPoint(int i);
        int getStringOfPointsSize();
};

#endif

// --------- Class definitions ---------

/** Create empty vector set of Points */
template <class T>
StringOfPoints<T>::StringOfPoints() {
    pointsSet = new std::vector<T>;
}

/** Make free space */
template <class T>
StringOfPoints<T>::~StringOfPoints() {
    delete pointsSet;
}

/** Add new point to set of points */
template <class T>
void StringOfPoints<T>::addPoint(T pointToAdd) {
    pointsSet->push_back(pointToAdd);
}

/** Remove point from set of points */
template <class T>
void StringOfPoints<T>::removePoint(T pointToRemove) {
    for (int i = 0; i < getStringOfPointsSize(); i++) {
        if (getPoint(i) == pointToRemove) {
            pointsSet->erase(pointsSet->begin() + i);
            return;
        }
    }
}

/** Check if point is in set of points */
template <class T>
bool StringOfPoints<T>::isPointInStringOfPoints(T pointToCheck) {
    for (int i = 0; i < getStringOfPointsSize(); i++) {
        if (getPoint(i) == pointToCheck) {
            return true;
        }
    }

    return false;
}

/** Return point with index == 'i' */
template <class T>
T StringOfPoints<T>::getPoint(int i) {
    return pointsSet->at(i);
}

/** Return count of all elements in set of points */
template <class T>
int StringOfPoints<T>::getStringOfPointsSize() {
    return pointsSet->size();
}
