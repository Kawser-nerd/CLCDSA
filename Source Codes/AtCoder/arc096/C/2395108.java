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
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        FastScanner in = new FastScanner(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        TaskE solver = new TaskE();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskE {
        public void solve(int testNumber, FastScanner in, PrintWriter out) {
            int n = in.nextInt();
            int mod = in.nextInt();

            int[][] choose = new int[n + 10][n + 10];
            int[][] stirling = new int[n + 10][n + 10];
            for (int i = 0; i <= n + 9; i++) {
                choose[i][0] = 1;
                for (int j = 1; j <= i; j++) {
                    choose[i][j] = choose[i - 1][j - 1] + choose[i - 1][j];
                    if (choose[i][j] >= mod) {
                        choose[i][j] -= mod;
                    }
                }
                stirling[i][0] = (i == 0) ? 1 : 0;
                for (int j = 1; j <= i; j++) {
                    stirling[i][j] = (int) ((stirling[i - 1][j - 1] + 1L * stirling[i - 1][j] * j) % mod);
                }
            }
            int[] pow2 = new int[n * n + 1];
            pow2[0] = 1;
            for (int i = 1; i < pow2.length; i++) {
                pow2[i] = pow2[i - 1] * 2;
                if (pow2[i] >= mod) {
                    pow2[i] -= mod;
                }
            }

            int[] dp = new int[n + 1];
            for (int k = 0; k <= n; k++) {
                for (int used = 0; used <= k; used++) {
//                long mul = MathUtils.modPow(2, (n - k) * used, mod);
                    long sum = stirling[k + 1][used + 1];
                    long mul = pow2[(n - k) * used];
//                for (int x = 0; x <= k; x++) {
//                    sum += 1L * choose[k][x] * stirling[x][used] % mod;
//                }
                    dp[k] = (int) ((dp[k] + sum % mod * mul) % mod);
//                System.err.println(k + " " + used + " " + sum % mod);
                }
            }
            long ans = 0;
            for (int bits = 0; bits <= n; bits++) {
                long mul = MathUtils.modPow(2, MathUtils.modPow(2, n - bits, mod - 1), mod);
                mul = mul * choose[n][bits] % mod;
                mul = mul * dp[bits] % mod;
                ans += (bits % 2 == 0) ? mul : (-mul);
            }
            out.println((ans % mod + mod) % mod);
        }

    }

    static class MathUtils {
        public static int modPow(int a, long b, int mod) {
            while (a < 0) {
                a += mod;
            }
            int res = 1;
            while (b > 0) {
                if ((b & 1) != 0) {
                    res = (int) ((long) res * a % mod);
                }
                a = (int) ((long) a * a % mod);
                b >>>= 1;
            }
            return res;
        }

    }

    static class FastScanner {
        BufferedReader br;
        StringTokenizer st;

        public FastScanner(InputStream in) {
            br = new BufferedReader(new InputStreamReader(in));
        }

        public int nextInt() {
            return Integer.parseInt(next());
        }

        public String next() {
            while (st == null || !st.hasMoreElements()) {
                String line = null;
                try {
                    line = br.readLine();
                } catch (IOException e) {
                }
                st = new StringTokenizer(line);
            }
            return st.nextToken();
        }

    }
}