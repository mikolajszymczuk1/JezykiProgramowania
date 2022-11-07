import java.util.Scanner;

/**
 * Class to help manage input / output
 */
public class IOHelper {
    /**
     * Read some integer value from user
     * @param inputMessage some input message
     * @return             int
     */
    public static int readIntValue(String inputMessage) {
        Scanner sca = new Scanner(System.in);
        System.out.print(inputMessage + ": ");
        return Integer.parseInt(sca.nextLine());
    }
}
