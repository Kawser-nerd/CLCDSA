import java.util.*;

public class Main {
    private static Scanner scanner = new Scanner(System.in);

    public static void main(String[]$) {
        int x = scanner.nextInt(), y = scanner.nextInt(), r = scanner.nextInt(), x2 = scanner.nextInt(), y2 = scanner.nextInt(), x3 = scanner.nextInt(), y3 = scanner.nextInt();
        System.out.println(x2 > x - r || x3 < x + r || y2 > y - r || y3 < y + r ? "YES" : "NO");
        System.out.println((x2 - x) * (x2 - x) + (y3 - y) * (y3 - y) > r * r || (x3 - x) * (x3 - x) + (y2 - y) * (y2 - y) > r * r ? "YES" : "NO");
    }
}