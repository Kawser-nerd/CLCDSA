// package agc.agc027;

import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.*;

public class Main {
    static long __startTime = System.currentTimeMillis();

    public static void main(String[] args) {
        InputReader in = new InputReader(System.in);
        PrintWriter out = new PrintWriter(System.out);

        int n = in.nextInt();
        long T = in.nextInt();
        long[] x = new long[n];
        for (int i = 0; i < n ; i++) {
            x[i] = in.nextInt();
        }

        long total = T * n;
        for (int i = 0; i < n ; i++) {
            total += x[i] * 5;
        }
        total += T * n;

        long best = total;
        int L = 1;
        int R = n;
        for (int cur = 0 ; cur < 60 ; cur++) {
            int m1 = (L * 2 + R) / 3;
            int m2 = (L + R * 2) / 3;
            long c1 = canMakeHead(m1, x, T);
            long c2 = canMakeHead(m2, x, T);
            best = Math.min(best, total-c1);
            best = Math.min(best, total-c2);
            if (c1 < c2) {
                L = m1;
            } else {
                R = m2;
            }
        }
        for (int f = Math.max(1, L-5) ; f <= Math.min(n, R+5) ; f++) {
            best = Math.min(best, total-canMakeHead(f, x, T));
        }
        out.println(best);
        out.flush();
    }

    private static long canMakeHead(int head, long[] x, long t) {
        int n = x.length;
        long dec = t * (n - head);
        long additionalCost = 0;

        long[] col = new long[head];
        for (int i = 0 ; i < n ; i++) {
            int cur = i / head;
            if (cur >= 2) {
                col[i%head] += x[i-2*head];
                additionalCost += col[i%head] * 2;
            }
        }
        return dec-additionalCost;
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