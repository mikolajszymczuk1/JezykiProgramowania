import java.util.ArrayList;

/**
 * Class for creating string of 2D points
 */
public class StringOfPoints2d {
    private final ArrayList<Point2d> points;

    public StringOfPoints2d() {
        this.points = new ArrayList<>();
    }

    /**
     * Add new point 2D to array
     * @param pointToAdd new point to add
     */
    public void addPoint(Point2d pointToAdd) {
        this.points.add(pointToAdd);
    }

    /**
     * Remove point from array
     * @param pointToRemove point to remove
     */
    public void removePoint(Point2d pointToRemove) {
        this.points.remove(pointToRemove);
    }

    /**
     * Check if point is in string of points
     * @param pointToCheck point to check
     * @return true if point exists in string
     */
    public boolean isPointInString(Point2d pointToCheck) {
        return this.points.contains(pointToCheck);
    }

    /**
     * Return specific point from string of points
     * @param index index to get
     * @return point from string with index === 'index'
     */
    public Point2d getPoint(int index) {
        return this.points.get(index);
    }

    /**
     * Return size of string of points
     * @return size of string of points
     */
    public int getSize() {
        return this.points.size();
    }

    /**
     * Print all points from string of points
     */
    public void printPoints() {
        for (Point2d point : this.points) {
            point.printPoint();
        }
    }
}
