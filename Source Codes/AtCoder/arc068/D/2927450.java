import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class Main {
    static long __startTime = System.currentTimeMillis();

    public static void main(String[] args) {
        InputReader in = new InputReader(System.in);
        PrintWriter out = new PrintWriter(System.out);

        prec(100000);

//        debug(ways(2), generate(2));
//        debug(ways(3), generate(3));
//        debug(ways(4), generate(4));
//        debug(ways(5), generate(5));
//        debug(ways(6), generate(6));

        int n = in.nextInt();
        int k = in.nextInt();

        int left = k-1;
        int right = n-left-1;

        long ans = ways(n, right) % MOD * (right >= 1 ? pow(2, right-1) : 1) % MOD;

        out.println(ans);
        out.flush();
    }

    private static long ways(int n, int k) {
        long[][][] dp = new long[2][2][n+1];
        dp[0][0][0] = 1;
        for (int i = 0; i < n ; i++) {
            int fr = i % 2;
            int to = 1 - fr;
            for (int j = 0; j <= 1; j++) {
                Arrays.fill(dp[to][j], 0);
            }
            for (int f = 0; f <= 1; f++) {
                for (int j = n-1 ; j >= 0 ; j--) {
                    long base = dp[fr][f][j];
                    if (base == 0) {
                        continue;
                    }

                    // down
                    if (f == 0 && j >= 1) {
                        add(dp, fr, 0, j-1, base);
                    }

                    // load
                    add(dp, to, 1, j+1, base);

                    // next
                    add(dp, to, 0, j, base);
                }
            }
        }
        return dp[n%2][0][k] % MOD;
    }

    static void add(long[][][] dp, int a, int b, int c, long v) {
        dp[a][b][c] += v;
        dp[a][b][c] -= dp[a][b][c] >= MOD ? MOD : 0;
    }

    static final int MOD = 1000000007;

    static long pow(long a, long x) {
        long res = 1;
        while (x > 0) {
            if (x % 2 != 0) {
                res = (res * a) % MOD;
            }
            a = (a * a) % MOD;
            x /= 2;
        }
        return res;
    }

    static long inv(long a) {
        return pow(a, MOD - 2) % MOD;
    }

    static long[] _fact;
    static long[] _invfact;

    static long comb(long ln, long lr) {
        int n = (int) ln;
        int r = (int) lr;
        if (n < 0 || r < 0 || r > n) {
            return 0;
        }
        if (r > n / 2) {
            r = n - r;
        }
        return (((_fact[n] * _invfact[n - r]) % MOD) * _invfact[r]) % MOD;
    }

    static void prec(int n) {
        _fact = new long[n + 1];
        _invfact = new long[n + 1];
        _fact[0] = 1;
        _invfact[0] = 1;
        for (int i = 1; i <= n; i++) {
            _fact[i] = _fact[i - 1] * i % MOD;
            _invfact[i] = inv(_fact[i]);
        }
    }


    private static void printTime(String label) {
        debug(label, System.currentTimeMillis() - __startTime);
    }

    public static void debug(Object... o) {
        System.err.println(Arrays.deepToString(o));
    }

    public static class InputReader {
        private static final int BUFFER_LENGTH = 1 << 12;
        private InputStream stream;
        private byte[] buf = new byte[BUFFER_LENGTH];
        private int curChar;
        private int numChars;

        public InputReader(InputStream stream) {
            this.stream = stream;
        }

        private int next() {
            if (numChars == -1) {
                throw new InputMismatchException();
            }
            if (curChar >= numChars) {
                curChar = 0;
                try {
                    numChars = stream.read(buf);
                } catch (IOException e) {
                    throw new InputMismatchException();
                }
                if (numChars <= 0)
                    return -1;
            }
            return buf[curChar++];
        }

        public char nextChar() {
            return (char) skipWhileSpace();
        }

        public String nextToken() {
            int c = skipWhileSpace();
            StringBuilder res = new StringBuilder();
            do {
                res.append((char) c);
                c = next();
            } while (!isSpaceChar(c));
            return res.toString();
        }

        public int nextInt() {
            return (int) nextLong();
        }

        public long nextLong() {
            int c = skipWhileSpace();
            long sgn = 1;
            if (c == '-') {
                sgn = -1;
                c = next();
            }
            long res = 0;
            do {
                if (c < '0' || c > '9') {
                    throw new InputMismatchException();
                }
                res *= 10;
                res += c - '0';
                c = next();
            } while (!isSpaceChar(c));
            return res * sgn;
        }

        public double nextDouble() {
            return Double.valueOf(nextToken());
        }

        int skipWhileSpace() {
            int c = next();
            while (isSpaceChar(c)) {
                c = next();
            }
            return c;
        }

        boolean isSpaceChar(int c) {
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
        }
    }
}