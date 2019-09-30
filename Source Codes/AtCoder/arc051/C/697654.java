// package atcoder.arc.arc051;

import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Comparator;
import java.util.InputMismatchException;

/**
 * Created by hama_du on 4/17/16.
 */
public class Main {

    private static final double EPS = 1e-9;

    // compare a*A^b and c*A^d
    static int compare(long a, long b, long c, long d, long A) {
        double la = Math.log(A);
        double d1 = Math.log(a) + b * la;
        double d2 = Math.log(c) + d * la;
        return Double.compare(d1, d2);
    }

    static long count(long a, long b, long c, long A) {
        double la = Math.log(A);
        double d1 = Math.log(a) + b * la;
        double dd = d1 - Math.log(c);
        if (dd <= 0) {
            return 0;
        }
        return 1 + (long)((dd - EPS) / la);
    }

    public static void main(String[] args) {
        InputReader in = new InputReader(System.in);
        PrintWriter out = new PrintWriter(System.out);

        int n = in.nextInt();
        long A = in.nextLong();
        long B = in.nextLong();
        long[] a = new long[n];
        for (int i = 0; i < n ; i++) {
            a[i] = in.nextInt();
        }
        for (int i = 0; i < n ; i++) {
            long min = 0;
            long max = B+1;
            while (max - min > 1) {
                long med = (max + min) / 2;
                long sum = med;
                for (int j = 0; j < n ; j++) {
                    if (i == j) {
                        continue;
                    }
                    sum += count(a[i], med, a[j], A);
                }
                if (sum > B) {
                    max = med;
                } else {
                    min = med;
                }
            }
            long sum = 0;
            long[] cts = new long[n];
            for (int j = 0; j < n ; j++) {
                cts[j] = (i == j) ? min : count(a[i], min, a[j], A);
                sum += cts[j];
            }
            if (sum == B) {
                Integer[] idx = new Integer[n];
                for (int j = 0; j < n ; j++) {
                    idx[j] = j;
                }
                Arrays.sort(idx, (o1, o2) -> compare(a[o1], cts[o1], a[o2], cts[o2], A));

                for (int j = 0; j < n ; j++) {
                    out.println(a[idx[j]] * pow(A, cts[idx[j]], MOD) % MOD);
                }
                break;
            }
        }
        out.flush();
    }

    static final long MOD = 1000000007;
    static long pow(long a, long x, long MOD) {
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

    static class InputReader {
        private InputStream stream;
        private byte[] buf = new byte[1024];
        private int curChar;
        private int numChars;

        public InputReader(InputStream stream) {
            this.stream = stream;
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
            return res * sgn;
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
            return res * sgn;
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