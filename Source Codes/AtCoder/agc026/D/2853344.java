import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.StringTokenizer;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 *
 * @author kessido
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        DHistogramColoring solver = new DHistogramColoring();
        solver.solve(1, in, out);
        out.close();
    }

    static class DHistogramColoring {
        final long MOD = MathExtensions.DEFAULT_MOD;
        final long inv2 = MathExtensions.modInverse_For_M_Prime(2, MathExtensions.DEFAULT_MOD);

        long calcOptimal(int l, int r, int[] h, int fromH, boolean withNormal) {
            if (l == r) return MathExtensions.powerMod(2, h[l] - fromH, MOD);
            int nextH = h[l];
            for (int i = l + 1; i <= r; i++) {
                nextH = Math.min(nextH, h[i]);
            }
            long res = MathExtensions.powerMod(2, nextH - fromH, MOD);
            if (!withNormal) res--;
            int lastNextH = l - 1;
            for (int i = l; i <= r; i++) {
                if (h[i] == nextH) {
                    if (lastNextH + 1 != i) {
                        res = res * calcOptimal(lastNextH + 1, i - 1, h, nextH, true) % MOD;
                    }
                    lastNextH = i;
                }
            }
            if (lastNextH != r) {
                res = res * calcOptimal(lastNextH + 1, r, h, nextH, true) % MOD;
            }
            return res;
        }

        long calcNormal(int l, int r, int[] h, int fromH) {
            if (l == r) return MathExtensions.powerMod(2, h[l] - fromH, MOD);
            int nextH = h[l];
            for (int i = l + 1; i <= r; i++) {
                nextH = Math.min(nextH, h[i]);
            }
            long invProbability = MathExtensions.powerMod(inv2, r - l + 1, MOD);
            long resForNormal = 1;
            long resForOptimal = 2 * invProbability * calcOptimal(l, r, h, fromH, false) % MOD;
            int lastNextH = l - 1;
            for (int i = l; i <= r; i++) {
                if (h[i] == nextH) {
                    if (lastNextH + 1 != i) {
                        resForNormal = resForNormal * calcNormal(lastNextH + 1, i - 1, h, nextH) % MOD;
                    }
                    lastNextH = i;
                }
            }
            if (lastNextH != r) {
                resForNormal = resForNormal * calcNormal(lastNextH + 1, r, h, nextH) % MOD;
            }
            return (resForNormal + resForOptimal) % MOD;
        }

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.NextInt();
            int[] h = in.NextIntArray(n);
            long res = MathExtensions.powerMod(2, n, MOD) * calcNormal(0, h.length - 1, h, 1) % MOD;
            if (res < 0) res += MOD;
            out.println(res);
        }

    }

    static class MathExtensions {
        public static final long DEFAULT_MOD = 1_000_000_007L;

        public static long modInverse_For_M_Prime(final long a, final long m) {
            return powerMod(a, m - 2, m);
        }

        public static long powerMod(final long x, final long y, final long m) {
            if (y == 0)
                return 1;

            long p = powerMod(x, y / 2, m) % m;
            p = (p * p) % m;

            if (y % 2 == 0)
                return p;
            else
                return (x * p) % m;
        }

    }

    static class InputReader {
        BufferedReader reader;
        StringTokenizer tokenizer;

        public InputReader(InputStream stream) {
            reader = new BufferedReader(new InputStreamReader(stream), 32768);
            tokenizer = null;
        }

        public String next() {
            while (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    tokenizer = new StringTokenizer(reader.readLine(), " \t\n\r\f,");
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
            return tokenizer.nextToken();
        }

        public int NextInt() {
            return Integer.parseInt(next());
        }

        public int[] NextIntArray(int n) {
            return NextIntArray(n, 0);
        }

        public int[] NextIntArray(int n, int offset) {
            int[] a = new int[n];
            for (int i = 0; i < n; i++) {
                a[i] = NextInt() + offset;
            }
            return a;
        }

    }
}