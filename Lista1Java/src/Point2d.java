/**
 * Class to creating 2D points
 */
public class Point2d {
    /** Position X */
    protected int x;

    /** Position Y */
    protected int y;

    public Point2d() { }

    public Point2d(int posX, int posY) {
        this.x = posX;
        this.y = posY;
    }

    /**
     * Return position X value
     * @return int
     */
    public int getX() {
        return this.x;
    }

    /**
     * Return position Y value
     * @return int
     */
    public int getY() {
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
}
