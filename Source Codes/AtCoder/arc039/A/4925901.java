import java.util.*;

public class Main {
    private static Scanner scanner = new Scanner(System.in);

    public static void main(String[]$) {
        int a = scanner.nextInt(), b = scanner.nextInt();
        System.out.println(Math.max(Math.max(a - b + Math.max(9 - a / 100, b / 100 - 1) * 100, a - b + Math.max(9 - a % 100 / 10, b % 100 / 10) * 10), a - b + Math.max(9 - a % 10, b % 10)));
    }
}