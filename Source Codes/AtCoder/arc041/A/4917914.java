import java.util.*;

public class Main {
    private static Scanner scanner = new Scanner(System.in);

    public static void main(String[]$) {
        int x = scanner.nextInt(), y = scanner.nextInt(), k = scanner.nextInt();
        System.out.println(y < k ? x + y + y - k : x + k);
    }
}