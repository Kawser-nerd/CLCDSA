import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.Reader;
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
        MyInput in = new MyInput(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        DInversionSum solver = new DInversionSum();
        solver.solve(1, in, out);
        out.close();
    }

    static class DInversionSum {
        static final int mod = (int) 1e9 + 7;

        public void solve(int testNumber, MyInput in, PrintWriter out) {
            int n = in.nextInt();
            int q = in.nextInt();
            int[] a = in.nextIntArray(n);
            int[][] qs = in.nextIntArray2D(q, 2);

            long[][] dp = new long[n][n];
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    dp[i][j] = a[i] > a[j] ? 1 : 0;
                }
            }

            long inv2 = (mod + 1) / 2;
            long pow = 1;

            for (int i = 0; i < q; i++) {
                int x = qs[i][0] - 1, y = qs[i][1] - 1;
                if (x > y) {
                    int t = x;
                    x = y;
                    y = t;
                }
                for (int j = 0; j < n; j++) {
                    if (j != x && j != y) {
                        dp[x][j] = dp[y][j] = (dp[x][j] + dp[y][j]) * inv2 % mod;
                        dp[j][x] = dp[j][y] = (dp[j][x] + dp[j][y]) * inv2 % mod;
                    }
                }
                dp[x][y] = dp[y][x] = (dp[x][y] + dp[y][x]) * inv2 % mod;
                pow = pow * 2 % mod;
            }

            long ans = 0;
            for (int i = 0; i < n; i++) {
                for (int j = i + 1; j < n; j++) {
                    ans += dp[i][j] * pow % mod;
                }
            }

            out.println(ans % mod);
        }

    }

    static class MyInput {
        private final BufferedReader in;
        private static int pos;
        private static int readLen;
        private static final char[] buffer = new char[1024 * 8];
        private static char[] str = new char[500 * 8 * 2];
        private static boolean[] isDigit = new boolean[256];
        private static boolean[] isSpace = new boolean[256];
        private static boolean[] isLineSep = new boolean[256];

        static {
            for (int i = 0; i < 10; i++) {
                isDigit['0' + i] = true;
            }
            isDigit['-'] = true;
            isSpace[' '] = isSpace['\r'] = isSpace['\n'] = isSpace['\t'] = true;
            isLineSep['\r'] = isLineSep['\n'] = true;
        }

        public MyInput(InputStream is) {
            in = new BufferedReader(new InputStreamReader(is));
        }

        public int read() {
            if (pos >= readLen) {
                pos = 0;
                try {
                    readLen = in.read(buffer);
                } catch (IOException e) {
                    throw new RuntimeException();
                }
                if (readLen <= 0) {
                    throw new MyInput.EndOfFileRuntimeException();
                }
            }
            return buffer[pos++];
        }

        public int nextInt() {
            int len = 0;
            str[len++] = nextChar();
            len = reads(len, isSpace);
            int i = 0;
            int ret = 0;
            if (str[0] == '-') {
                i = 1;
            }
            for (; i < len; i++) ret = ret * 10 + str[i] - '0';
            if (str[0] == '-') {
                ret = -ret;
            }
            return ret;
        }

        public char nextChar() {
            while (true) {
                final int c = read();
                if (!isSpace[c]) {
                    return (char) c;
                }
            }
        }

        int reads(int len, boolean[] accept) {
            try {
                while (true) {
                    final int c = read();
                    if (accept[c]) {
                        break;
                    }
                    if (str.length == len) {
                        char[] rep = new char[str.length * 3 / 2];
                        System.arraycopy(str, 0, rep, 0, str.length);
                        str = rep;
                    }
                    str[len++] = (char) c;
                }
            } catch (MyInput.EndOfFileRuntimeException e) {
            }
            return len;
        }

        public int[] nextIntArray(final int n) {
            final int[] res = new int[n];
            for (int i = 0; i < n; i++) {
                res[i] = nextInt();
            }
            return res;
        }

        public int[][] nextIntArray2D(final int n, final int k) {
            final int[][] res = new int[n][];
            for (int i = 0; i < n; i++) {
                res[i] = nextIntArray(k);
            }
            return res;
        }

        static class EndOfFileRuntimeException extends RuntimeException {
        }

    }
}