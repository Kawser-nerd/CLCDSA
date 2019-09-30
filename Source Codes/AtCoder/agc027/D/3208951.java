// package agc.agc027;

import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.*;

public class Main {
    static long __startTime = System.currentTimeMillis();

    private static int[] dx = new int[]{0, -1, 0, 1};
    private static int[] dy = new int[]{-1, 0, 1, 0};

    private static long THE_NUMBER = 14414400;

    /**
     * Generates primes less than upto.
     *
     * O(nlog(logn))
     *
     * @param upto limit
     * @return array of primes
     */
    static int[] generatePrimes(int upto) {
        boolean[] isp = new boolean[upto];
        Arrays.fill(isp, true);
        isp[0] = isp[1] = false;

        int pi = 0;
        for (int i = 2; i < upto ; i++) {
            if (isp[i]) {
                pi++;
                for (int j = i * 2; j < upto; j += i) {
                    isp[j] = false;
                }
            }
        }

        int[] ret = new int[pi];
        int ri = 0;
        for (int i = 2 ; i < upto ; i++) {
            if (isp[i]) {
                ret[ri++] = i;
            }
        }
        return ret;
    }


    public static void main(String[] args) {
        InputReader in = new InputReader(System.in);
        PrintWriter out = new PrintWriter(System.out);

        List<Long> divisors = new ArrayList<>();
        for (long i = 1; i * i < THE_NUMBER ; i++) {
            if (THE_NUMBER % i == 0) {
                divisors.add(i);
                divisors.add(THE_NUMBER / i);
            }
        }
        Collections.sort(divisors);

        int n = in.nextInt();
        long[][] f = new long[n][n];

        int[] p = generatePrimes(10000);

        int pi = 10;
        int pf0 = 10;
        int pf1 = 260;

        int idx = 0;
        int flg = 0;
        for (int i = 0 ; i < n ; i++) {
            for (int j = (i & 1); j < n ; j += 2) {
                f[i][j] = p[pi] * divisors.get(idx++);
            }
            if (i % 2 == 1) {
                if (flg == 0) {
                    pf0++;
                    pi = pf1;
                } else {
                    pf1--;
                    pi = pf0;
                }
                idx = 0;
                flg ^= 1;
            }
        }


        Set<Long> used = new HashSet<>();

        int bestC = 0;
        for (int i = 0; i < n ; i++) {
            for (int j = 0; j < n ; j++) {
                if (f[i][j] == 0) {
                    long m = 1;
                    for (int d = 0; d < 4 ; d++) {
                        if (i+dy[d] < 0 || i+dy[d] >= n || j+dx[d] < 0 || j+dx[d] >= n) {
                            continue;
                        }
                        m = lcm(m, f[i+dy[d]][j+dx[d]]);
                    }
                    long mm = m;
                    int cnt = 0;
                    while (used.contains(mm)) {
                        mm += m;
                        cnt += 1;
                    }
                    used.add(mm);
                    f[i][j] = mm+1;
                    bestC = Math.max(bestC, cnt);
                }
            }
        }

        for (int i = 0; i < n ; i++) {
            StringBuilder line = new StringBuilder();
            for (int j = 0; j < n ; j++) {
                line.append(' ').append(f[i][j]);
            }
            out.println(line.substring(1));
        }
        out.println();
        out.flush();


    }

    static long gcd(long a, long b) {
        return b == 0 ? a : gcd(b, a%b);
    }

    static long lcm(long a, long b) {
        long w = gcd(a, b);
        a /= w;
        return a * b;
    }


    static long largestP(long a) {
        long best = 0;
        for (long i = 2 ; i * i <= a ; i++) {
            int cnt = 0;
            while (a % i == 0) {
                a /= i;
                cnt++;
            }
            if (cnt == 1) {
                best = Math.max(best, i);
            }
        }
        best = Math.max(best, a);
        return best;
    }

    static void check(long[][] a) {
        Set<Long> s = new HashSet<>();
        int n = a.length;
        for (int i = 0; i < a.length ; i++) {
            for (int j = 0; j < a[0].length ; j++) {
                if (a[i][j] > 1e15 || s.contains(a[i][j])) {

                    for (int d = 0 ; d < 4 ; d++) {
                        if (i+dy[d] < 0 || i+dy[d] >= n || j+dx[d] < 0 || j+dx[d] >= n) {
                            continue;
                        }
                        debug(a[i+dy[d]][j+dx[d]], largestP(a[i+dy[d]][j+dx[d]]));
                    }

                    debug(i, j, a[i][j]);
                    if (s.contains(a[i][j])) {
                        throw new RuntimeException("mul");
                    } else {
                        throw new RuntimeException("over");
                    }
                }

                for (int d = 0 ; d < 4 ; d++) {
                    if (i+dy[d] < 0 || i+dy[d] >= n || j+dx[d] < 0 || j+dx[d] >= n) {
                        continue;
                    }
                    long max = Math.max(a[i][j], a[i+dy[d]][j+dx[d]]);
                    long min = Math.min(a[i][j], a[i+dy[d]][j+dx[d]]);
                    if (max % min != 1) {
                        debug(i, j, i+dy[d], j+dx[d], a[i][j], a[i+dy[d]][j+dx[d]], max % min);
                        throw new RuntimeException("mod err");
                    }
                }
                s.add(a[i][j]);
            }
        }
        if (s.size() != a.length *  a[0].length) {
            throw new RuntimeException("mul");
        }
    }

    private static void printTime(String label) {
        debug(label, System.currentTimeMillis() - __startTime);
    }

    private static void debug(Object... o) {
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