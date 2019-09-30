import java.util.*;

public class Main {
    private static Scanner scanner = new Scanner(System.in);

    public static void main(String[]$) {
        System.out.println(scanner.next().replaceFirst(".{" + scanner.nextInt() + "}", "$0\"").replaceFirst(".{" + (scanner.nextInt() + 1) + "}", "$0\"").replaceFirst(".{" + (scanner.nextInt() + 2) + "}", "$0\"").replaceFirst(".{" + (scanner.nextInt() + 3) + "}", "$0\""));
    }
}