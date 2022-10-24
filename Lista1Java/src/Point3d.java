/**
 * Class for creating 3D points
 */
public class Point3d extends Point2d {
    /** Position Z */
    protected int z;

    public Point3d(int posX, int posY, int posZ) {
        super(posX, posY);
        this.z = posZ;
    }

    /**
     * Return position Z value
     * @return int
     */
    public int getZ() {
        return this.z;
    }

    /**
     * Print some information about Point 3D
     */
    public void printPoint() {
        System.out.print("Point 3D\n");
        System.out.print("X = " + this.x + "\n");
        System.out.print("Y = " + this.y + "\n");
        System.out.print("Z = " + this.z + "\n");
    }

    /**
     * Projection on point 2D from point 3D
     * @param z0 parameter 1
     * @param d  parameter 2
     * @return   Point2d
     */
    public Point2d projectingToPoint2d(int z0, int d) {
        if ((z0 - this.z) == 0) return new Point2d(0, 0);
        int x2 = (z0 * this.x - this.z * d) / (z0 - this.z);
        int y2 = (z0 * this.y) / (z0 - this.z);
        return new Point2d(x2, y2);
    }

    /**
     * Move point by vector 3D
     * @param vectorToMoveBy vector to move by
     */
    public void moveByVector(Vector3d vectorToMoveBy) {
        this.x += vectorToMoveBy.getX();
        this.y += vectorToMoveBy.getY();
        this.z += vectorToMoveBy.getZ();
    }
}
