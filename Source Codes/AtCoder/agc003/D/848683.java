// package atcoder.agc.agc003;

import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.*;

/**
 * Created by hama_du on 2016/08/21.
 */
public class Main {
    public static void main(String[] args) {
        InputReader in = new InputReader(System.in);
        PrintWriter out = new PrintWriter(System.out);


        //debug(generatePrimes(1000000)[500]);

        int n = in.nextInt();
        long[] s = in.nextLongs(n);

        int[] p = generatePrimes(100010);

        Map<Long,Integer> deg = new HashMap<>();
        Map<Long,Long> amap = new HashMap<>();
        boolean one = false;

        for (int si = 0 ; si < n ; si++) {
            long S = s[si];
            if (S == 1) {
                one = true;
                continue;
            }
            long kay = 1;
            long anti = 1;
            for (int pi = 0 ; pi < 380 ; pi++) {
                int P = p[pi];
                if (S < P) {
                    break;
                }
                int cnt = 0;
                while (S % P == 0) {
                    S /= P;
                    cnt++;
                }
                cnt %= 3;
                if (cnt >= 1) {
                    kay *= Math.pow(P, cnt);
                    if (anti >= 1) {
                        anti *= Math.pow(P, 3-cnt);
                    }
                    if (anti > 1e11) {
                        anti = -1;
                    }
                }
            }
            if (S >= 2) {
                // S will be p0p1 or p0^2(p0 and p1 are some large primes)
                kay *= S;
                long ss = (long)Math.sqrt(S);
                if (ss * ss == S) {
                    if (anti >= 1) {
                        BigInteger anbig = BigInteger.valueOf(anti);
                        anbig = anbig.multiply(BigInteger.valueOf(ss));
                        if (anbig.compareTo(BigInteger.valueOf((long) 1e11)) < 0) {
                            anti = anbig.longValue();
                        } else {
                            anti = -1;
                        }
                    }
                } else {
                    if (anti >= 1) {
                        BigInteger anbig = BigInteger.valueOf(anti);
                        anbig = anbig.multiply(BigInteger.valueOf(S));
                        anbig = anbig.multiply(BigInteger.valueOf(S));
                        if (anbig.compareTo(BigInteger.valueOf((long) 1e11)) < 0) {
                            anti = anbig.longValue();
                        } else {
                            anti = -1;
                        }
                    }
                }
            }
            if (kay == 1) {
                one = true;
                continue;
            }
            deg.put(kay, deg.getOrDefault(kay, 0)+1);
            amap.put(kay, anti);
            amap.put(anti, kay);
        }

        int total = 0;
        Set<Long> done = new HashSet<>();
        for (long A : deg.keySet()) {
            if (A == -1 || done.contains(A)) {
                continue;
            }
            long B = amap.get(A);
            done.add(B);
            total += Math.max(deg.getOrDefault(A, 0), deg.getOrDefault(B, 0));
        }
        if (one) {
            total++;
        }
        out.println(total);
        out.flush();
    }

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

    static class InputReader {
        private InputStream stream;
        private byte[] buf = new byte[1024];
        private int curChar;
        private int numChars;

        public InputReader(InputStream stream) {
            this.stream = stream;
        }

        private int[] nextInts(int n) {
            int[] ret = new int[n];
            for (int i = 0; i < n; i++) {
                ret[i] = nextInt();
            }
            return ret;
        }


        private int[][] nextIntTable(int n, int m) {
            int[][] ret = new int[n][m];
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    ret[i][j] = nextInt();
                }
            }
            return ret;
        }

        private long[] nextLongs(int n) {
            long[] ret = new long[n];
            for (int i = 0; i < n; i++) {
                ret[i] = nextLong();
            }
            return ret;
        }

        private long[][] nextLongTable(int n, int m) {
            long[][] ret = new long[n][m];
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    ret[i][j] = nextLong();
                }
            }
            return ret;
        }

        private double[] nextDoubles(int n) {
            double[] ret = new double[n];
            for (int i = 0; i < n; i++) {
                ret[i] = nextDouble();
            }
            return ret;
        }

        private int next() {
            if (numChars == -1)
                throw new InputMismatchException();
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
            int c = next();
            while (isSpaceChar(c))
                c = next();
            if ('a' <= c && c <= 'z') {
                return (char) c;
            }
            if ('A' <= c && c <= 'Z') {
                return (char) c;
            }
            throw new InputMismatchException();
        }

        public String nextToken() {
            int c = next();
            while (isSpaceChar(c))
                c = next();
            StringBuilder res = new StringBuilder();
            do {
                res.append((char) c);
                c = next();
            } while (!isSpaceChar(c));
            return res.toString();
        }

        public int nextInt() {
            int c = next();
            while (isSpaceChar(c))
                c = next();
            int sgn = 1;
            if (c == '-') {
                sgn = -1;
                c = next();
            }
            int res = 0;
            do {
                if (c < '0' || c > '9')
                    throw new InputMismatchException();
                res *= 10;
                res += c-'0';
                c = next();
            } while (!isSpaceChar(c));
            return res*sgn;
        }

        public long nextLong() {
            int c = next();
            while (isSpaceChar(c))
                c = next();
            long sgn = 1;
            if (c == '-') {
                sgn = -1;
                c = next();
            }
            long res = 0;
            do {
                if (c < '0' || c > '9')
                    throw new InputMismatchException();
                res *= 10;
                res += c-'0';
                c = next();
            } while (!isSpaceChar(c));
            return res*sgn;
        }

        public double nextDouble() {
            return Double.valueOf(nextToken());
        }

        public boolean isSpaceChar(int c) {
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
        }

        public interface SpaceCharFilter {
            public boolean isSpaceChar(int ch);
        }
    }

    static void debug(Object... o) {
        System.err.println(Arrays.deepToString(o));
    }
}