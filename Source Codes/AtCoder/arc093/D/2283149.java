// package arc.arc093;

import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class Main {
    static final long MOD = 1000000007;

    public static void main(String[] args) {
        InputReader in = new InputReader(System.in);
        PrintWriter out = new PrintWriter(System.out);


        prec(100000);

        int n = in.nextInt();
        int m = in.nextInt();
        int[] a = new int[m];
        for (int i = 0; i < m ; i++) {
            a[i] = in.nextInt()-1;
        }
        long[][][] dp = new long[2][2][1<<n];
        dp[0][0][0] = 1;
        for (int i = 0 ; i < m ; i++) {
            int fr = i % 2;
            int to = 1 - fr;
            for (int j = 0; j <= 1; j++) {
                Arrays.fill(dp[to][j], 0);
            }

            for (int par = 0 ; par <= 1 ; par++) {
                for (int used = 0; used < (1 << n) ; used++) {
                    long base = dp[fr][par][used];

                    dp[to][par][used] += base;
                    dp[to][par][used] %= MOD;

                    int left = ((1<<n)-1-used) - a[m-1-i] + 1;

                    for (int u = 0; u < n ; u++) {
                        if ((used & (1<<u)) >= 1) {
                            continue;
                        }
                        int need = 1<<u;
                        if (left >= need) {
                            long p = base * comb(left-1, need-1) % MOD * _fact[need-1] % MOD * need % MOD;
                            dp[to][par^1][used|need] += p;
                            dp[to][par^1][used|need] %= MOD;
                        }
                    }
                }
            }
        }

        long total = 0;
        for (int par = 0 ; par <= 1 ; par++) {
            for (int used = 0; used < (1 << n); used++) {
                long base = dp[m%2][par][used];
                if (base == 0) {
                    continue;
                }
                long ptn = base * _fact[(1<<n)-1-used] % MOD;
                if (par == 0) {
                    total += ptn;
                } else {
                    total += MOD - ptn;
                }
            }
            total %= MOD;
        }

        total *= (1<<n);
        total %= MOD;

        out.println(total);
        out.flush();
    }

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