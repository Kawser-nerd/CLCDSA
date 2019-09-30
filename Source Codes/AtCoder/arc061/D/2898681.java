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

        prec(1000000);

        int n = in.nextInt();
        int m = in.nextInt();
        int k = in.nextInt();

        long[] pow3 = new long[1000000];
        pow3[0] = 1;
        for (int i = 1 ; i < pow3.length; i++) {
            pow3[i] = (pow3[i-1] * 3) % MOD;
        }

        long[] ptn = computePatterns(1000000, m, k);

        long ways = 0;
        for (int l = n ; l <= n + m + k ; l++) {
            long add = comb(l-1, n-1);
            add *= ptn[l-n];
            add %= MOD;
            add *= pow3[n+m+k-l];
            add %= MOD;
            ways += add;
            ways %= MOD;
        }

        out.println(ways);
        out.flush();
    }

    static long[] computePatterns(int n, int a, int b) {
        if (a > b) {
            return computePatterns(n, b, a);
        }
        n = Math.max(n, a+b+1);

        long[] ret = new long[n+1];
        ret[0] = 1;

        for (int i = 1 ; i < n ; i++) {
            ret[i] = ret[i-1] * 2 % MOD;
        }

        for (int p : new int[]{a, b}) {
            long left = 0;
            for (int i = p + 1; i < n; i++) {
                left = left * 2 % MOD;
                left = left + comb(i - 1, i - (p + 1));
                left %= MOD;
                ret[i] = (ret[i] + MOD - left) % MOD;
            }
        }
        for (int i = a+b+1 ; i < n ; i++) {
            ret[i] = 0;
        }
        return ret;

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