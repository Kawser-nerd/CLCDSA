//  package arc.arc078;

import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class Main {
    static InputReader in;
    static PrintWriter out;

    public static void main(String[] args) {
        in = new InputReader(System.in);
        out = new PrintWriter(System.out);
        out.println("! " + doit());
        out.flush();
    }

    static long power10() {
        long base = 1;
        long q = 9;
        while (!query(q)) {
            q *= 10;
            q += 9;
            base *= 10;
        }
        return base;
    }

    static long doit() {
        long base = 1;
        while (query(base)) {
            base *= 10;
            if (base >= 1e11) {
                return power10();
            }
        }
        long K = base / 10;

        long geta = 999999999_999999999L;
        int dec = 17;
        long who = 0;
        for (long k = K ; k >= 1 ; k /= 10) {
            long B = (long)Math.pow(10, dec);
            long min = (k == K) ? 0 : -1;
            long max = 9;
            while (max - min > 1) {
                long med = (max + min) / 2;
                long Q = geta - 9 * B + med * B;
                if (query(Q)) {
                    max = med;
                } else {
                    min = med;
                }
            }
            geta -= 9 * B;
            geta += max * B;
            who *= 10;
            who += max;
            dec--;
        }
        return who;
    }

    public static boolean query(long n) {
        out.println("? " + n);
        out.flush();
        return in.nextToken().equals("Y");
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