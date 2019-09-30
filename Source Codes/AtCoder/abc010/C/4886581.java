import java.util.*;

public class Main {
    private static Scanner scanner = new Scanner(System.in);

    public static void main(String[]$) {
        int txa = scanner.nextInt(), tya = scanner.nextInt(), txb = scanner.nextInt(), tyb = scanner.nextInt(), t = scanner.nextInt(), v = scanner.nextInt(), n = scanner.nextInt();
        for (int i = 0; i < n; i++) {
            int x = scanner.nextInt(), y = scanner.nextInt();
            if (Math.sqrt((txa - x) * (txa - x) + (tya - y) * (tya - y)) + Math.sqrt((txb - x) * (txb - x) + (tyb - y) * (tyb - y)) <= t * v) {
                System.out.println("YES");
                return;
            }
        }
        System.out.println("NO");
    }
}