/**
 * Class to creating 2D points
 */
public class Point2d implements Comparable<Point2d> {
    /** Position X */
    protected float x;

    /** Position Y */
    protected float y;

    public Point2d() { }

    public Point2d(float posX, float posY) {
        this.x = posX;
        this.y = posY;
    }

    /**
     * Return position X value
     * @return float
     */
    public float getX() {
        return this.x;
    }

    /**
     * Return position Y value
     * @return float
     */
    public float getY() {
        return this.y;
    }

    /**
     * Print some information about Point 2D
     */
    public void printPoint() {
        System.out.print("Point 2D\n");
        System.out.print("X = " + this.x + "\n");
        System.out.print("Y = " + this.y + "\n");
    }

    /**
     * Check if line equation is satisfied
     * @param pointA Point A
     * @param pointB Point B
     * @param pointC Point C
     * @return boolean
     */
    public static boolean isLineEquationSatisfied(Point2d pointA, Point2d pointB, Point2d pointC) {
        return ((pointC.getY() - pointA.getY()) * (pointB.getX() - pointA.getX())) - ((pointB.getY() - pointA.getY()) * (pointC.getX() - pointA.getX())) == 0;
    }

    @Override
    public int compareTo(Point2d point2d) {
        if (this.x < point2d.x) {
            return -1;
        }

        if (this.x == point2d.x && this.y < point2d.y) {
            return -1;
        }

        if (this.x == point2d.x && this.y == point2d.y) {
            return 0;
        }

        return 1;
    }
}
