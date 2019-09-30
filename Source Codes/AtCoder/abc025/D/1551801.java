import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.StringTokenizer;
import java.io.IOException;
import java.util.InputMismatchException;
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
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        TaskD solver = new TaskD();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskD {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int[][] a = in.nextIntArrayArray0indexed(5, 5);

            int[] dp = new int[1 << 25];
            dp[0] = 1;
            int MOD = 1_000_000_007;
            for (int i = 0; i < (1 << 25) - 1; i++) {
                if (dp[i] == 0) continue;

                int next = Integer.bitCount(i);
                for (int j = 0; j < 25; j++) {
                    if ((i >> j & 1) == 1) continue;
                    int y = j / 5;
                    int x = j % 5;
                    if (a[y][x] != -1 && a[y][x] != next) continue;
                    if (RangeUtils.isInside(y - 1, x, 5, 5)
                            && RangeUtils.isInside(y + 1, x, 5, 5)) {
                        boolean exist1 = (i >> ((y - 1) * 5 + x) & 1) == 1;
                        boolean exist2 = (i >> ((y + 1) * 5 + x) & 1) == 1;

                        if (exist1 ^ exist2) continue;
                    }
                    if (RangeUtils.isInside(y, x - 1, 5, 5)
                            && RangeUtils.isInside(y, x + 1, 5, 5)) {
                        boolean exist1 = (i >> (y * 5 + x - 1) & 1) == 1;
                        boolean exist2 = (i >> (y * 5 + x + 1) & 1) == 1;

                        if (exist1 ^ exist2) continue;
                    }

                    int tmp = i | 1 << (y * 5 + x);
                    dp[tmp] = (dp[tmp] + dp[i]) % MOD;
                }
            }

            out.println(dp[(1 << 25) - 1]);
        }

    }

    static class RangeUtils {
        public static boolean isInside(int y, int x, int h, int w) {
            return y >= 0 && x >= 0 && y < h && x < w;
        }

    }

    static class InputReader {
        BufferedReader in;
        StringTokenizer tok;

        public String nextString() {
            while (!tok.hasMoreTokens()) {
                try {
                    tok = new StringTokenizer(in.readLine(), " ");
                } catch (IOException e) {
                    throw new InputMismatchException();
                }
            }
            return tok.nextToken();
        }

        public int nextInt() {
            return Integer.parseInt(nextString());
        }

        public int[] nextIntArray0indexed(int n) {
            int[] res = new int[n];
            for (int i = 0; i < n; i++) {
                res[i] = nextInt() - 1;
            }
            return res;
        }

        public int[][] nextIntArrayArray0indexed(int n, int m) {
            int[][] res = new int[n][m];
            for (int i = 0; i < n; i++) {
                res[i] = nextIntArray0indexed(m);
            }
            return res;
        }

        public InputReader(InputStream inputStream) {
            in = new BufferedReader(new InputStreamReader(inputStream));
            tok = new StringTokenizer("");
        }

    }
}