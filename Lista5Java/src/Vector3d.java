/**
 * Class for creating vectors 3D
 */
public class Vector3d {
    /** Vector position X */
    private final float x;

    /** Vector position Y */
    private final float y;

    /** Vector position Z */
    private final float z;

    public Vector3d(float posX, float posY, float posZ) {
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
     * @return float
     */
    public float getX() {
        return x;
    }

    /**
     * Return vector position Y value
     * @return float
     */
    public float getY() {
        return y;
    }

    /**
     * Return vector position Z value
     * @return float
     */
    public float getZ() {
        return z;
    }

    /**
     * Return scalar product of two vectors
     * @param vectorToProd vector to calculate scalar product
     * @return             float
     */
    public float scalarProduct(Vector3d vectorToProd) {
        float scalarX = this.x * vectorToProd.getX();
        float scalarY = this.y * vectorToProd.getY();
        float scalarZ = this.z * vectorToProd.getZ();
        return scalarX + scalarY + scalarZ;
    }

    /**
     * Return vector that is sum of two vectors
     * @param vectorToAdd vector to add
     * @return            Vector3d
     */
    public Vector3d addVector(Vector3d vectorToAdd) {
        float newX = this.x + vectorToAdd.getX();
        float newY = this.y + vectorToAdd.getY();
        float newZ = this.z + vectorToAdd.getZ();
        return new Vector3d(newX, newY, newZ);
    }

    /**
     * Return vector that is difference of two vectors
     * @param vectorToSub vector to sub
     * @return            Vector3d
     */
    public Vector3d subVector(Vector3d vectorToSub) {
        float newX = this.x - vectorToSub.getX();
        float newY = this.y - vectorToSub.getY();
        float newZ = this.z - vectorToSub.getZ();
        return new Vector3d(newX, newY, newZ);
    }

    /**
     * Return vector product of two vectors
     * @param vectorToProd vector to prod
     * @return             Vector3d
     */
    Vector3d vectorProduct(Vector3d vectorToProd) {
        float prodX = (this.y * vectorToProd.getZ()) - (this.z * vectorToProd.getY());
        float prodY = -(this.x * vectorToProd.getZ() - this.z * vectorToProd.getX());
        float prodZ = (this.x * vectorToProd.getY()) - (this.y * vectorToProd.getX());
        return new Vector3d(prodX, prodY, prodZ);
    }
}
