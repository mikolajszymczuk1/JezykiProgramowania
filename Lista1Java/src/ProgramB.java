import static java.lang.Math.abs;

public class ProgramB {
    /**
     * Number of points needed for some calculations
     */
    static private final int POINTS_FOR_CALCULATIONS = 4;

    public static void main(String[] args) {
        Point3d[] points = new Point3d[POINTS_FOR_CALCULATIONS];

        // Read points data from user
        for (int i = 0; i < POINTS_FOR_CALCULATIONS; i++) {
            int x = IOHelper.readIntValue("Position X");
            System.out.print("\n");
            int y = IOHelper.readIntValue("Position Y");
            System.out.print("\n");
            int z = IOHelper.readIntValue("Position Z");
            System.out.print("\n");

            points[i] = new Point3d(x, y, z);
        }

        // Create 3 vectors for calculations
        Vector3d a = new Vector3d(points[0], points[1]);  // Vector AB
        Vector3d b = new Vector3d(points[0], points[2]);  // Vector AC
        Vector3d c = new Vector3d(points[0], points[3]);  // Vector AD

        int volume = abs(a.vectorProduct(b).scalarProduct(c));
        System.out.println("Volume result: " + volume);
    }
}
