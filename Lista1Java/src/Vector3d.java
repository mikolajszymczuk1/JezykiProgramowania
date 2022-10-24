/**
 * Class for creating vectors 3D
 */
public class Vector3d {
    /** Vector position X */
    private final int x;

    /** Vector position Y */
    private final int y;

    /** Vector position Z */
    private final int z;

    public Vector3d(int posX, int posY, int posZ) {
        this.x = posX;
        this.y = posY;
        this.z = posZ;
    }

    public Vector3d(Point3d basePoint) {
        this.x = basePoint.getX();
        this.y = basePoint.getY();
        this.z = basePoint.getZ();
    }

    public Vector3d(Point3d startPoint, Point3d endPoint) {
        this.x = endPoint.getX() - startPoint.getX();
        this.y = endPoint.getY() - startPoint.getY();
        this.z = endPoint.getZ() - startPoint.getZ();
    }

    /**
     * Return vector position X value
     * @return int
     */
    public int getX() {
        return x;
    }

    /**
     * Return vector position Y value
     * @return int
     */
    public int getY() {
        return y;
    }

    /**
     * Return vector position Z value
     * @return int
     */
    public int getZ() {
        return z;
    }

    /**
     * Return scalar product of two vectors
     * @param vectorToProd vector to calculate scalar product
     * @return                 Vector3d
     */
    public int scalarProduct(Vector3d vectorToProd) {
        int scalarX = this.x * vectorToProd.getX();
        int scalarY = this.y * vectorToProd.getY();
        int scalarZ = this.z * vectorToProd.getZ();
        return scalarX + scalarY + scalarZ;
    }

    /**
     * Return vector that is sum of two vectors
     * @param vectorToAdd vector to add
     * @return            Vector3d
     */
    public Vector3d addVector(Vector3d vectorToAdd) {
        int newX = this.x + vectorToAdd.getX();
        int newY = this.y + vectorToAdd.getY();
        int newZ = this.z + vectorToAdd.getZ();
        return new Vector3d(newX, newY, newZ);
    }

    /**
     * Return vector that is difference of two vectors
     * @param vectorToSub vector to sub
     * @return            Vector3d
     */
    public Vector3d subVector(Vector3d vectorToSub) {
        int newX = this.x - vectorToSub.getX();
        int newY = this.y - vectorToSub.getY();
        int newZ = this.z - vectorToSub.getZ();
        return new Vector3d(newX, newY, newZ);
    }

    /**
     * Return vector product of two vectors
     * @param vectorToProd vector to prod
     * @return             Vector3d
     */
    Vector3d vectorProduct(Vector3d vectorToProd) {
        int prodX = (this.y * vectorToProd.getZ()) - (this.z * vectorToProd.getY());
        int prodY = -(this.x * vectorToProd.getZ() - this.z * vectorToProd.getX());
        int prodZ = (this.x * vectorToProd.getY()) - (this.y * vectorToProd.getX());
        return new Vector3d(prodX, prodY, prodZ);
    }
}
