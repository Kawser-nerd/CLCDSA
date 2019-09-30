// package agc.agc022;

import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class Main {
    static final int MAX = 30000;
    public static void main(String[] args) {
        InputReader in = new InputReader(System.in);
        PrintWriter out = new PrintWriter(System.out);

        int n = in.nextInt();
        int[] a = solve(n);
        StringBuilder line = new StringBuilder();
        for (int i = 0; i < n ; i++) {
            line.append(' ').append(a[i]);
        }
        out.println(line.substring(1));
        out.flush();
    }

    private static int[] solve(int n) {
        int[] ret = new int[n];
        int ri = 0;
        long sum = 0;

        boolean[] used = new boolean[MAX+1];
        {
            int x = 1;
            while (ri < n-1) {
                if (x % 2 == 0 || x % 3 == 0) {
                    used[x] = true;
                    sum += x;
                    ret[ri++] = x;
                }
                x++;
            }
        }

        for (int x = 1 ; x <= MAX ; x++) {
            if (used[x]) {
                continue;
            }
            if ((sum + x) % 2 == 0 && (sum + x) % 3 == 0 && gcd(sum, x) >= 2) {
                // debug(sum, x, gcd(sum, x));
                ret[n-1] = x;
                break;
            }
        }

        return ret;
    }

    public static long gcd(long a, long b) {
        return b == 0 ? a : gcd(b, a%b);
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