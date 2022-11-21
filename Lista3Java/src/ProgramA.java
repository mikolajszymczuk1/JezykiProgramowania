import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;
import java.util.ArrayList;

public class ProgramA {
    public static void main(String[] args) {
        final String dataFilename = "data/lamana2D0.csv";
        ArrayList<Point2d> points2d = new ArrayList<>();

        try {
            File dataFile = new File(dataFilename);
            Scanner reader = new Scanner(dataFile);
            while (reader.hasNextLine()) {
                String line = reader.nextLine();
                int semiIndex = 0;
                for (int i = 0; i < line.length(); i++) {
                    if (line.charAt(i) == ';') {
                        semiIndex = i;
                        break;
                    }
                }

                float x = Float.parseFloat(line.substring(0, semiIndex));
                float y = Float.parseFloat(line.substring(semiIndex + 1, line.length() - 1));
                points2d.add(new Point2d(x, y));
            }
        } catch (FileNotFoundException e) {
            System.out.println("Error reading the file");
            e.printStackTrace();
        }

        for (int i = 2; i < points2d.size(); i++) {
            if (!Point2d.isLineEquationSatisfied(points2d.get(0), points2d.get(1), points2d.get(i))) {
                System.out.println("----------- FAIL");
                points2d.get(i).printPoint();
                System.out.println("-----------\n");
            }
        }
    }
}
