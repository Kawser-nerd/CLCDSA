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
        long x = in.nextInt();
        int k = in.nextInt();
        long[] r = new long[k+1];
        for (int i = 0; i < k ; i++) {
            r[i+1] = in.nextInt();
        }
        k++;

        long[][] rng = new long[k][4];

        rng[0][0] = 0;
        rng[0][1] = x;
        rng[0][2] = 0;
        rng[0][3] = x;
        long dir = -1;
        for (int i = 1 ; i < k ; i++) {
            long diff = r[i] - r[i-1];

            rng[i][2] = rng[i-1][2];
            rng[i][3] = rng[i-1][3];

            long t0 = rng[i-1][0] + dir * diff;
            if (t0 < 0) {
                rng[i][2] += -t0;
            }
            long t1 = rng[i-1][1] + dir * diff;
            if (t1 > x) {
                rng[i][3] -= t1-x;
            }
            t0 = Math.max(0, Math.min(x, t0));
            t1 = Math.max(0, Math.min(x, t1));
            rng[i][0] = t0;
            rng[i][1] = t1;
            dir *= -1;
        }

        debug(rng);

        int q = in.nextInt();
        int ri = 0;
        while (--q >= 0) {
            long t = in.nextInt();
            long a = in.nextInt();
            while (ri < k && r[ri] <= t) {
                ri++;
            }
            long now;
            if (a < rng[ri-1][2]) {
                now = rng[ri-1][0];
            } else if (a > rng[ri-1][3]) {
                now = rng[ri-1][1];
            } else {
                now = rng[ri-1][0] + (a - rng[ri-1][2]);
            }
            long tw = t-r[ri-1];
            long di = ri % 2 == 1 ? -1 : 1;
            long m = Math.min(x, Math.max(0, now + tw * di));
            out.println(m);
        }



        out.flush();
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
} ./Main.java:49: warning: non-varargs call of varargs method with inexact argument type for last parameter;
        debug(rng);
              ^
  cast to Object for a varargs call
  cast to Object[] for a non-varargs call and to suppress this warning
1 warning