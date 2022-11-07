import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.Scanner;

public class ProgramC {
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

        for (int i = 2; i < points3d.size(); i++) {
            if (!Point3d.isStraightEquationSatisfied(points3d.get(0), points3d.get(1), points3d.get(i))) {
                System.out.println("----------- FAIL");
                points3d.get(i).printPoint();
                System.out.println("-----------\n");
            }
        }
    }
}
