// package arc.arc077;

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
        int m = in.nextInt();
        int[] a = new int[n];
        for (int i = 0; i < n ; i++) {
            a[i] = in.nextInt();
        }

        long[] cur0 = new long[2*m+10];
        long[] cur1 = new long[2*m+10];
        long[] ans = new long[2*m+10];
        for (int i = 0 ; i + 1 < n ; i++) {
            int from = a[i];
            int to = a[i+1];
            if (to < from) {
                to += m;
            }
            to += 1;
            if (to - from >= 3) {
                from += 2;
                cur0[from]++;
                cur0[to]--;
                cur1[to] -= to-from;
            }
        }

        long spd = 0;
        for (int i = 0 ; i < cur0.length ; i++) {
            spd += cur0[i];
            cur1[i] += spd;
        }
        long val = 0;
        for (int i = 0; i < cur1.length ; i++) {
            val += cur1[i];
            ans[i] = val;
        }


        long all = 0;
        for (int i = 0; i+1 < a.length ; i++) {
            all += a[i] < a[i+1] ? a[i+1]-a[i] : a[i+1]-a[i]+m;
        }
        long max = 0;
        for (int i = 0; i < m ; i++) {
            long ho = 0;
            for (int j = i ; j < ans.length ; j += m) {
                ho += ans[j];
            }
            max = Math.max(max, ho);
        }

        out.println(all - max);
        out.flush();
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