import java.util.ArrayList;

public class MainProgram {
    public static void main(String[] args) {
        ArrayList<Point2d> pointsToAdd = new ArrayList<>();
        pointsToAdd.add(new Point2d(0, 3));
        pointsToAdd.add(new Point2d(4, 2));
        pointsToAdd.add(new Point2d(2, 6));
        pointsToAdd.add(new Point2d(4, 2));
        pointsToAdd.add(new Point2d(10, 1));

        StringOfPoints2d strOfPoints2d = new StringOfPoints2d();
        SetOfPoints2d setOfPoints2d = new SetOfPoints2d();

        for (Point2d point : pointsToAdd) {
            strOfPoints2d.addPoint(point);
            setOfPoints2d.addPoint(point);
        }

        setOfPoints2d.printPoints();
        System.out.println(setOfPoints2d.getSetPower());
    }
}
