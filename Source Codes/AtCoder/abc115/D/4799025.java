import java.util.*;

public class Main {
    public static void main(String[] args) {
        try (Scanner scanner = new Scanner(System.in)) {
            int N = scanner.nextInt();
            long X = scanner.nextLong();
            long[] as = new long[N];
            long[] ps = new long[N];
            as[0] = 1;
            ps[0] = 1;
            for (int i = 1; i < N; i++) {
                as[i] = as[i - 1] * 2 + 3;
                ps[i] = ps[i - 1] * 2 + 1;
            }
            System.out.println(f(N, X, as, ps));
        }
    }

    static long f(int n, long x, long[] a, long[] p) {
        if (n == 0) {
            return x > 0 ? 1 : 0;
        }
        long anp = a[n - 1];
        long pnp = p[n - 1];
        if (x <= anp + 1) {
            return f(n - 1, x - 1, a, p);
        }
        if (x == x + anp) {
            return pnp;
        }
        if (x <= 2 * anp + 2) {
            return pnp + 1 + f(n-1, x - anp - 2, a, p);
        }
        return 2 * pnp + 1;
    }

    static class Pair {
        final int kind;
        final long point;

        Pair(int kind, long point) {
            this.kind = kind;
            this.point = point;
        }
    }

}