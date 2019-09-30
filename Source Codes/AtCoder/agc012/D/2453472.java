// package agc.agc012;

import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        InputReader in = new InputReader(System.in);
        PrintWriter out = new PrintWriter(System.out);

        int n = in.nextInt();
        int x = in.nextInt();
        int y = in.nextInt();
        int[][] balls = new int[n][2];
        for (int i = 0; i < n ; i++) {
            for (int j = 0; j < 2 ; j++) {
                balls[i][j] = in.nextInt();
            }
        }
        Arrays.sort(balls, (u, v) -> u[0] == v[0] ? u[1] - v[1] : u[0] - v[0]);


        List<int[]> goodBalls = new ArrayList<>();
        for (int i = 0; i < n ; ) {
            int j = i;
            while (j < n && balls[i][0] == balls[j][0]) {
                j++;
            }
            goodBalls.add(balls[i]);
            i = j;
        }
        Collections.sort(goodBalls, Comparator.comparingInt(u -> u[1]));

        int[] availableBalls = new int[n+1];
        int total = 0;
        for (int i = 0; i < n ;) {
            int c = balls[i][0];
            int j = i;
            while (j < n && balls[i][0] == balls[j][0]) {
                j++;
            }
            boolean canChangeExternal = false;
            for (int k = i ; k < j ; k++) {
                boolean isOK = false;
                if (j-i >= 2) {
                    int tk = k == i ? k+1 : i;
                    if (balls[tk][1] + balls[k][1] <= x) {
                        isOK = true;
                    }
                }
                for (int[] w : goodBalls) {
                    if (w[0] == c) {
                        continue;
                    }
                    isOK |= w[1] + balls[k][1] <= y;
                    canChangeExternal |= w[1] + balls[k][1] <= y;
                    break;
                }
                if (isOK) {
                    availableBalls[c-1]++;
                    total++;
                }
            }
            if (!canChangeExternal) {
                total -= availableBalls[c-1];
                availableBalls[c-1] = 0;
            }
            i = j;
        }

        // debug(total, availableBalls);

        long ways = 1;
        prec(200010);
        for (int i = 0; i < n ; i++) {
            ways *= comb(total, availableBalls[i]);
            ways %= MOD;
            total -= availableBalls[i];
        }

        out.println(ways);
        out.flush();
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