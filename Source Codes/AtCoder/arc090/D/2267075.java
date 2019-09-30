// package arc.arc090;

import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.*;

public class Main {
    private static final long MOD = 1000000007;

    static final long INF = (long)1e16;

    static final int THRESHOLD = 9;

    public static void main(String[] args) {
        InputReader in = new InputReader(System.in);
        PrintWriter out = new PrintWriter(System.out);

        long S = in.nextLong();

        long[] ketaCount = new long[THRESHOLD+1];
        long[] ketaPrefix = new long[THRESHOLD+1];
        for (int i = 1 ; i < ketaCount.length ; i++) {
            ketaCount[i] = 9 * (long)Math.pow(10, i-1);
            ketaPrefix[i] = ketaPrefix[i-1] + ketaCount[i-1] * (i-1);
        }

        long sum = 0;
        long tail = 0;
        for (int f = 1 ; f < ketaCount.length ; f++) {
            for (int t = f + 1 ; t < ketaCount.length ; t++) {
                sum += findMatch(S+tail, f, ketaCount[f], ketaPrefix[t]+t, t, ketaCount[t]);
                sum %= MOD;
            }
            tail += ketaCount[f] * f;
        }

        for (int n = 1 ; n * n <= S ; n++) {
            if (S % n == 0) {
                if (n * n == S) {
                    sum += solve1(n, S / n);
                } else {
                    sum += solve1(n, S / n);
                    sum += solve1(S / n, n);
                }
            } else {
                if (S / n >= THRESHOLD) {
                    sum++;
                }
            }
            if (n * n < S && n >= THRESHOLD) {
                long from = Math.max(n + 1, S / (n + 1) + 1);
                long to = S / n;
                if (S % n == 0) {
                    to--;
                }
                if (to - from + 1 >= 0) {
                    sum += to - from + 1;
                }
            }
            sum %= MOD;
        }

        out.println(sum % MOD);
        out.flush();
    }

    private static long solve1(long a, long b) {
        long kc = ketaCount(a);
        if (a <= THRESHOLD && kc < b) {
            return 0;
        }
        return (kc - b + 1 + MOD) % MOD;
    }

    public static long ketaCount(long a) {
        return pow(10, a-1) * 9 % MOD;
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

    public static long findMatch2(long a0, long d0, long n0, long a1, long d1, long n1) {
        Set<Long> X = coseq(a0, d0, n0);
        Set<Long> Y = coseq(a1, d1, n1);
        X.retainAll(Y);
        return X.size();
    }

    public static Set<Long> coseq(long a0, long d0, long n0) {
        Set<Long> X = new HashSet<>();
        for (int i = 0; i < n0; i++) {
            X.add(a0 + i * d0);
        }
        return X;
    }

    public static long findMatch(long a0, long d0, long n0, long a1, long d1, long n1) {
        long b0 = a0 + d0 * (n0 - 1);
        long b1 = a1 + d1 * (n1 - 1);
        if (b0 < a1 || b1 < a0) {
            return 0;
        }
        long from = Math.max(a0, a1);
        long to = Math.min(b0, b1);

        long lcm = lcm(d0, d1);
        long match = findMatch(a0, d0, a1, d1);
        if (match == INF) {
            return 0;
        }
        long m = ((match % lcm) + lcm) % lcm;
        return count(to, lcm, m) - count(from-1, lcm, m);
    }

    public static long count(long a, long mod, long m) {
        return Math.max(0, (a-m)/mod);
    }

    public static long lcm(long a, long b) {
        long g = gcd(a, b);
        a /= g;
        return a * b;
    }


    public static long gcd(long a, long b) {
        return b == 0 ? a : gcd(b, a%b);
    }

    public static long findMatch(long a, long d, long b, long e) {
        long[] g = extGCD(d, -e);
        if (Math.abs(a - b) % Math.abs(g[0]) != 0) {
            return INF;
        }
        long diff = (b - a) / g[0];
        long za = a + d * g[1] * diff;
        long zb = b + e * g[2] * diff;
        if (za != zb) {
            throw new RuntimeException("arien");
        }
        return za;
    }

    /**
     * Finds (x, y) s.t. ax + by = gcd(a, b)
     *
     * @param a
     * @param b
     * @return (gcd(a, b), x, y)
     */
    static long[] extGCD(long a, long b) {
        if (b == 0) {
            return new long[]{a, 1, 0};
        }
        long[] gyx = extGCD(b, a%b);
        long g = gyx[0];
        long y = gyx[1];
        long x = gyx[2];
        y -= (a / b) * x;
        return  new long[]{g, x, y};
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