// package arc.arc094;

import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class Main {
    public static void main(String[] args) {
        InputReader in = new InputReader(System.in);
        PrintWriter out = new PrintWriter(System.out);

        int q = in.nextInt();
        for (int i = 0; i < q ; i++) {
            long a = in.nextLong();
            long b = in.nextLong();
            out.println(solve(a, b));
        }

        out.flush();
    }

    private static long solve(long a, long b) {
        if (a > b) {
            return solve(b, a);
        }
        if (a == b) {
            return (a - 1) * 2;
        }

        // a < b

        long sq = Math.max(1, (long)Math.sqrt(a * b) - 10);
        while (sq * sq < a * b) {
            sq++;
        }
        sq--;

        long squp = (a * b) / sq;
        if (a * b % sq == 0) {
            squp--;
        }

        if (sq == a) {
            if (squp > a) {
                return (sq - 1) * 2 + 1;
            } else {
                return (sq - 1) * 2;
            }
        } else {
            long r = (a - 1) + (sq - 1) + (squp - a);
            if ((sq+1) * (sq+1) == a * b) {
                r--;
            }
            return r;
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