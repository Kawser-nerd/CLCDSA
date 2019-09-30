// package arc.arc091;

import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class Main {
    public static void main(String[] args) {
        InputReader in = new InputReader(System.in);
        PrintWriter out = new PrintWriter(System.out);

        int n = in.nextInt();
        int a = in.nextInt();
        int b = in.nextInt();

        int[] ret = solve(n, a, b);
        if (ret == null) {
            out.println(-1);
        } else {
            StringBuilder line = new StringBuilder();
            for (int i = 0; i < n ; i++) {
                line.append(' ').append(ret[i]);
            }
            out.println(line.substring(1));
        }

        out.flush();
    }

    private static int[] solve(int n, int a, int b) {
        if (a < b) {
            int[] x = solve(n, b, a);
            if (x == null) {
                return null;
            }
            int[] ret = new int[n];
            for (int i = 0; i < n; i++) {
                ret[i] = x[n - 1 - i];
            }
            return ret;
        }

        // a >= b
        if (a + b > n + 1) {
            return null;
        }
        if (n >= 2 && a == 1 && b == 1) {
            return null;
        }

        int[] ret = new int[n];
        int part = (n + a - 1) / a;
        if (b < part) {
            return null;
        }

        {
            int tail = (n % a == 0) ? a : (n % a);
            for (int x = part - 1; x >= 0; x--) {
                if (x == part - 1) {
                    for (int i = 0; i < tail; i++) {
                        ret[x * a + i] = i;
                    }
                } else {
                    for (int i = 0; i < a; i++) {
                        ret[x * a + i] = tail + ((part - 2) - x) * a + i;
                    }
                }
            }
        }

        int need = b - part + 1;
        int[] tw = ret.clone();

        int tail = Math.min(n, a*2);
        int head = tail - need;
        for (int i = 0 ; i < need ; i++) {
            ret[head+i] = tw[tail-1-i];
        }
        for (int i = 0; i < n ; i++) {
            ret[i] += 1;
        }
        return ret;
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