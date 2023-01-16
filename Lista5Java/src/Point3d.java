/**
 * Class for creating 3D points
 */
public class Point3d extends Point2d {
    /** Position Z */
    protected float z;

    public Point3d(float posX, float posY, float posZ) {
        super(posX, posY);
        this.z = posZ;
    }

    /**
     * Return position Z value
     * @return float
     */
    public float getZ() {
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
    public Point2d projectingToPoint2d(float z0, float d) {
        if ((z0 - this.z) == 0) throw new ArithmeticException("Divide by 0");
        float x2 = (z0 * this.x - this.z * d) / (z0 - this.z);
        float y2 = (z0 * this.y) / (z0 - this.z);
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

    /**
     * Check if 3D points are on the same straight
     * @param pointA Point A
     * @param pointB Point B
     * @param pointC Point C
     * @return boolean
     */
    public static boolean isStraightEquationSatisfied(Point3d pointA, Point3d pointB, Point3d pointC) {
        Vector3d a = new Vector3d(pointA, pointB);
        if (a.getX() == 0 || a.getY() == 0 || a.getZ() == 0) throw new ArithmeticException("Divide by 0");
        return (((pointC.getX() - pointA.getX()) / a.getX()) == (pointC.getY() - pointA.getY()) / a.getY()) && (((pointC.getY() - pointA.getY()) / a.getY()) == (pointC.getZ() - pointA.getZ()) / a.getZ());
    }
}
