import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Objects;
import java.util.Arrays;
import java.util.stream.Stream;
import java.util.Map;
import java.util.Scanner;
import java.util.HashMap;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 *
 * @author mikit
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        Scanner in = new Scanner(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        D solver = new D();
        solver.solve(1, in, out);
        out.close();
    }

    static class D {
        private static int n;
        private static int[] w;
        private static int[] v;
        private static final Map<D.Key, Long> dp0 = new HashMap<>();
        private static long[][] dp1;

        public void solve(int testNumber, Scanner in, PrintWriter out) {
            n = in.nextInt();
            int wa = in.nextInt();
            w = new int[n];
            int wmax = 0;
            v = new int[n];
            int vmax = 0;
            for (int i = 0; i < n; i++) {
                v[i] = in.nextInt();
                vmax = Math.max(vmax, v[i]);
                w[i] = in.nextInt();
                wmax = Math.max(wmax, w[i]);
            }

            if (n <= 30) {
                dp0.clear();
                out.println(calc(new D.Key(0, wa)));
            } else if (wmax <= 3000) {
                dp1 = new long[n][wa + 1];
                Arrays.stream(dp1).forEach(a -> Arrays.fill(a, -1));
                out.println(calc1(0, wa));
            } else if (vmax <= 3000) {
                out.println(calc2(wa));
            }
        }

        private long calc(D.Key key) {
            if (key.index == n) {
                return 0;
            } else if (dp0.containsKey(key)) {
                return dp0.get(key);
            }
            long ans = calc(new D.Key(key.index + 1, key.toughness));
            int nt = key.toughness - w[key.index];
            if (nt >= 0) {
                ans = Math.max(ans, calc(new D.Key(key.index + 1, nt)) + v[key.index]);
            }
            dp0.put(key, ans);
            return ans;
        }

        private long calc1(int index, int toughness) {
            if (index == n) {
                return 0;
            } else if (dp1[index][toughness] >= 0) {
                return dp1[index][toughness];
            }
            long ans = calc1(index + 1, toughness);
            int nt = toughness - w[index];
            if (nt >= 0) {
                ans = Math.max(ans, calc1(index + 1, nt) + v[index]);
            }
            return dp1[index][toughness] = ans;
        }

        private long calc2(int toughness) {
            final int wmax = 200_001;
            long[][] dp2 = new long[n + 1][wmax];
            Arrays.stream(dp2).forEach(a -> Arrays.fill(a, 100_000_000_000L));
            dp2[0][0] = 0;
            long ans = 0;
            for (int i = 1; i <= n; i++) {
                for (int j = 0; j < v[i - 1]; j++) {
                    dp2[i][j] = dp2[i - 1][j];
                }
                for (int j = v[i - 1]; j < wmax; j++) {
                    long one = dp2[i - 1][j];
                    long other = dp2[i - 1][j - v[i - 1]] + w[i - 1];
                    dp2[i][j] = Math.min(one, other);
                    if (dp2[i][j] <= toughness) {
                        ans = Math.max(ans, j);
                    }
                }
            }
            return ans;
        }

        private static class Key {
            int index;
            int toughness;

            public Key(int index, int toughness) {
                this.index = index;
                this.toughness = toughness;
            }

            public boolean equals(Object o) {
                if (this == o) return true;
                if (o == null || getClass() != o.getClass()) return false;
                D.Key key = (D.Key) o;
                return index == key.index &&
                        toughness == key.toughness;
            }

            public int hashCode() {
                return Objects.hash(index, toughness);
            }

            public String toString() {
                return "Key(" +
                        index +
                        ", " + toughness +
                        ')';
            }

        }

    }
}