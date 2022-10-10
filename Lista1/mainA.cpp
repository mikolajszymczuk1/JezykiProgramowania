#include "classes/Point3D/Point3D.cpp"
#include <iostream>

int main() {
    int n;
    int z0, d;
    int x, y, z;
    Point2D *points;

    std::cout << "How many points?: ";
    std::cin >> n;
    std::cout << "\n";

    points = new Point2D[n];

    for (int i = 0; i < n; i++) {
        std::cout << "Point [" << i + 1 << "]" << std::endl;

        std::cout << "Position X: ";
        std::cin >> x;
        std::cout << "\n";

        std::cout << "Position Y: ";
        std::cin >> y;
        std::cout << "\n";
        
        std::cout << "Position Z: ";
        std::cin >> z;
        std::cout << "\n";

        std::cout << "Projection z0: ";
        std::cin >> z0;
        std::cout << "\n";

        std::cout << "Projection d: ";
        std::cin >> d;
        std::cout << "\n";

        Point3D *p3d = new Point3D(x, y, z);
        Point2D p2d = p3d->projectingToPoint2D(z0, d);
        points[i] = p2d;
        system("clear");
    }

    for (int i = 0; i < n; i++) {
        points[i].printPoint();
        std::cout << "\n";
    }

    return 0;
}
