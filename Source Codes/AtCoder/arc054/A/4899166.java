import java.util.Scanner;

public class Main {
    private static Scanner scanner = new Scanner(System.in);

    public static void main(String[]$) {
        double l = scanner.nextInt(), x = scanner.nextInt(), y = scanner.nextInt(), s = scanner.nextInt(), d = scanner.nextInt();
        System.out.println(s == d ? 0 : Math.min((d - s + (d > s ? 0 : l)) / (y + x), (s - d + (d > s ? l : 0)) / Math.max(y - x, 0)));
    }
}