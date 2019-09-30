import java.util.stream.IntStream;

public class Main {
    private static java.util.Scanner scanner = new java.util.Scanner(System.in);

    public static void main(String[] args) {
        int n = scanner.nextInt();
        int[] xa = new int[n], ya = new int[n], ha = new int[n];
        for (int i = 0; i < n; i++) {
            xa[i] = scanner.nextInt();
            ya[i] = scanner.nextInt();
            ha[i] = scanner.nextInt();
        }
        for (int x = 0; x <= 100; x++) {
            for (int y = 0; y <= 100; y++) {
                int x1 = x, y1 = y, h = IntStream.range(0, n).filter(k -> ha[k] != 0).reduce(0, (l, i) -> ha[i] + Math.abs(xa[i] - x1) + Math.abs(ya[i] - y1));
                if (IntStream.range(0, n).allMatch(k -> ha[k] == Math.max(h - Math.abs(xa[k] - x1) - Math.abs(ya[k] - y1), 0)))
                    System.out.printf("%s %s %s\n", x, y, h);
            }
        }
    }
}