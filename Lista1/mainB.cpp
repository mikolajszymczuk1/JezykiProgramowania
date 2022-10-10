#include "classes/Vector3D/Vector3D.cpp"
#include <iostream>
#include <stdlib.h>

int main() {
    const int NUMBER_OF_POINTS = 4;
    int x, y, z;
    int volume;
    Point3D *points = new Point3D[NUMBER_OF_POINTS];
    
    // Create n 3D points
    for (int i = 0; i < NUMBER_OF_POINTS; i++) {
        std::cout << "Position X: ";
        std::cin >> x;
        std::cout << "\n";

        std::cout << "Position Y: ";
        std::cin >> y;
        std::cout << "\n";
        
        std::cout << "Position Z: ";
        std::cin >> z;
        std::cout << "\n";

        points[i] = *new Point3D(x, y, z);
        system("clear");
    }

    Vector3D *a = new Vector3D(points[0], points[1]);  // Vector AB
    Vector3D *b = new Vector3D(points[0], points[2]);  // Vector AC
    Vector3D *c = new Vector3D(points[0], points[3]);  // Vector AD

    volume = abs(a->vectorProduct(*b).scalarProduct(*c));
    std::cout << "Volume: " << volume << std::endl;
    
    return 0;
}
