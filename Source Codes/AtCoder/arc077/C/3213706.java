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

        int n = in.nextInt();
        int m = in.nextInt();
        int[] a = new int[n];
        for (int i = 0; i < n ; i++) {
            a[i] = in.nextInt()-1;
        }

        long[] imo = new long[2*m+10];
        for (int i = 0; i+1 < n ; i++) {
            imo[a[i]+2] += 1;
            int to = (a[i+1] < a[i]) ? a[i+1]+m : a[i+1];
            imo[to+1] -= 1;
        }

        for (int i = 1; i < imo.length ; i++) {
            imo[i] += imo[i-1];
        }

        for (int i = 0; i+1 < n ; i++) {
            int to = (a[i+1] < a[i]) ? a[i+1]+m : a[i+1];
            int d = to-a[i]-1;
            imo[to+1] -= d;
        }
        for (int i = 1 ; i < imo.length ; i++) {
            imo[i] += imo[i-1];
        }

        long total = 0;
        for (int i = 1 ; i < n ; i++) {
            total += dist(a[i-1], a[i], m);
        }

        long best = 0;
        for (int i = 0; i < m ; i++) {
            long t = 0;
            for (int j = i; j < imo.length ; j += m) {
                t += imo[j];
            }
            best = Math.max(best, t);
        }
        out.println(total-best);
        out.flush();
    }

    private static int dist(int a, int b, int m) {
        if (a <= b) {
            return b-a;
        } else {
            return b+m-a;
        }
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
}