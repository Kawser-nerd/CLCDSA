import java.util.stream.IntStream;

public class Main {
    private static java.util.Scanner scanner = new java.util.Scanner(System.in);

    public static void main(String[]$) {
        int n = scanner.nextInt();
        int[] a = IntStream.range(0, n).map(i -> scanner.nextInt()).toArray();

        IntStream.range(0, n).map(i -> {
            int k1 = -50 * n, k2 = 0;
            for (int j = n - 1; j >= 0; j--) {
                if (i == j)
                    continue;
                int s = 0;
                for (int k = Math.min(i, j) + 1; k <= Math.max(i, j); k += 2)
                    s += a[k];
                if (k1 <= s) {
                    k1 = s;
                    k2 = j;
                }
            }
            int s = 0;
            for (int k = Math.min(i, k2); k <= Math.max(i, k2); k += 2)
                s += a[k];
            return s;
        }).max().ifPresent(System.out::println);
    }
}