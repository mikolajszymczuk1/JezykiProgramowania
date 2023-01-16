import java.util.TreeSet;
import java.util.Set;

/**
 * Class for creating Set of 2D points
 */
public class SetOfPoints2d {
    private final Set<Point2d> points;

    public SetOfPoints2d() {
        this.points = new TreeSet<>();
    }

    /**
     * Add new point to set
     * @param pointToAad point to add
     */
    public void addPoint(Point2d pointToAad) {
        this.points.add(pointToAad);
    }

    /**
     * Remove point from set
     * @param pointToRemove point to remove
     */
    public void removePoint(Point2d pointToRemove) {
        this.points.remove(pointToRemove);
    }

    /**
     * Check if point is in set
     * @param pointToCheck point to check
     * @return true if point exists in set
     */
    public boolean isPointInSet(Point2d pointToCheck) {
        for (Point2d point : this.points) {
            if (point.compareTo(pointToCheck) == 0) {
                return true;
            }
        }

        return false;
    }

    /**
     * Return power of set
     * @return size of points set
     */
    public int getSetPower() {
        return this.points.size();
    }

    /**
     * Print all points from set of points
     */
    public void printPoints() {
        for (Point2d point : this.points) {
            point.printPoint();
        }
    }
}
