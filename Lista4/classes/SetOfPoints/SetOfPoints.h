#ifndef SET_OF_POINTS_H
#define SET_OF_POINTS_H

#include <set>

template <class T>
class SetOfPoints {
    private:
        std::set<T> *pointsSet;
        typename std::set<T>::iterator it;
    public:
        SetOfPoints();
        ~SetOfPoints();
        void addPoint(T pointToAdd);
        void removePoint(T pointToRemove);
        std::set<T> getPointsSet();
        bool isPointInSet(T pointToCheck);
        int getSetPower();
};

#endif


// --------- Class definitions ---------

template <class T>
SetOfPoints<T>::SetOfPoints() {
    pointsSet = new std::set<T>;
}

template <class T>
SetOfPoints<T>::~SetOfPoints() {
    delete pointsSet;
}

template <class T>
void SetOfPoints<T>::addPoint(T pointToAdd) {
    pointsSet->insert(pointToAdd);
}

template <class T>
void SetOfPoints<T>::removePoint(T pointToRemove) {
    pointsSet->erase(pointToRemove);
}

template <class T>
std::set<T> SetOfPoints<T>::getPointsSet() {
    return *pointsSet;
}

template <class T>
bool SetOfPoints<T>::isPointInSet(T pointToCheck) {
    return pointsSet->find(pointToCheck) != pointsSet->end();
}

template <class T>
int SetOfPoints<T>::getSetPower() {
    return pointsSet->size();
}

// -------------------------------------
