import java.util.*;

public class Main {
    private static Scanner scanner = new Scanner(System.in);

    public static void main(String[]$) {
        int a = scanner.nextInt(), b = scanner.nextInt();
        System.out.println(a < 0 && b > 0 ? b - a - 1 : b - a);
    }
}