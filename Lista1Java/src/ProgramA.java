public class ProgramA {
    public static void main(String[] args) {
        int n;
        Point2d[] points;
        n = IOHelper.readIntValue("How many points ?");
        points = new Point2d[n];

        // Read points data from user
        for (int i = 0; i < n; i++) {
            int x = IOHelper.readIntValue("Position X");
            System.out.print("\n");
            int y = IOHelper.readIntValue("Position Y");
            System.out.print("\n");
            int z = IOHelper.readIntValue("Position Z");
            System.out.print("\n");
            int z0 = IOHelper.readIntValue("Parameter z0");
            System.out.print("\n");
            int d = IOHelper.readIntValue("Parameter d");
            System.out.print("\n");

            Point3d p3d = new Point3d(x, y, z);
            Point2d p2d = p3d.projectingToPoint2d(z0, d);
            points[i] = p2d;
        }

        // Print all points
        for (Point2d p : points) {
            p.printPoint();
        }
    }
}
