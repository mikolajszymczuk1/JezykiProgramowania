import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.Scanner;
import static java.lang.Math.abs;

public class ProgramB {
    public static void main(String[] args) {
        final String dataFilename = "data/lamana3D0.csv";
        ArrayList<Point3d> points3d = new ArrayList<>();

        try {
            File dataFile = new File(dataFilename);
            Scanner reader = new Scanner(dataFile);
            while (reader.hasNextLine()) {
                String line = reader.nextLine();
                int semiIndexA = 0;
                int semiIndexB = 0;
                for (int i = 0; i < line.length(); i++) {
                    if (line.charAt(i) == ';' && semiIndexA == 0) {
                        semiIndexA = i;
                    } else if (line.charAt(i) == ';' && semiIndexB == 0) {
                        semiIndexB = i;
                    }
                }

                float x = Float.parseFloat(line.substring(0, semiIndexA));
                float y = Float.parseFloat(line.substring(semiIndexA + 1, semiIndexB));
                float z = Float.parseFloat(line.substring(semiIndexB + 1, line.length() - 1));
                points3d.add(new Point3d(x, y, z));
            }
        } catch (FileNotFoundException e) {
            System.out.println("Error reading the file");
            e.printStackTrace();
        }

        Vector3d a = new Vector3d(points3d.get(0), points3d.get(1));  // Vector AB
        Vector3d b = new Vector3d(points3d.get(0), points3d.get(2));  // Vector AC
        Vector3d c;                                                   // Vector AX

        for (Point3d point3d : points3d) {
            c = new Vector3d(points3d.get(0), point3d);  // Vector AX
            float volume = abs(a.vectorProduct(b).scalarProduct(c));
            if (volume != 0) {
                System.out.println("----------- FAIL");
                System.out.print(point3d.getX() + " ");
                System.out.print(point3d.getY() + " ");
                System.out.print(point3d.getZ() + "\n");
                System.out.println("-----------\n");
            }
        }
    }
}
