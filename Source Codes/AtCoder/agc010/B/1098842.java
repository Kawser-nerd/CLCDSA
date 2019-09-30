import java.util.*;
import java.util.stream.LongStream;

public class Main {
    public static void main(String[] args) {
        new Main().solve();
    }

    void solve() {
        try (Scanner in = new Scanner(System.in)) {
            int n = in.nextInt();
            long a[] = new long[n];
            for (int i = 0; i < n; ++i) {
                a[i] = in.nextInt();
            }
            long sum = LongStream.of(a).sum();
            long x = (long) (n + 1) * n / 2L;
            if (sum % x != 0) {
                System.out.println("NO");
                return;
            }
            long k = sum / x;
            for (int i = 0; i < n; ++i) {
                long d = a[i] - a[(i + 1) % n];
                if ((d + k) % n != 0 || (d + k) < 0) {
                    System.out.println("NO");
                    return;
                }
            }
            System.out.println("YES");
        }
    }

    void tr(Object... o) {
        System.err.println(Arrays.deepToString(o));
    }
}