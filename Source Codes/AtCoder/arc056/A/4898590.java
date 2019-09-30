import java.util.*;

public class Main {
    private static Scanner scanner = new Scanner(System.in);

    public static void main(String[]$) {
        long a = scanner.nextInt(), b = scanner.nextInt(), k =scanner.nextInt(), l = scanner.nextInt();
        System.out.println(k / l * b + Math.min(k % l * a, b));
    }
}