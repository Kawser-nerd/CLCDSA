// package arc.arc075;

import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class Main {
    public static void main(String[] args) {
        InputReader in = new InputReader(System.in);
        PrintWriter out = new PrintWriter(System.out);
        
        // 1, 10, 100 ...
        char[] k = new StringBuilder(in.nextToken()).reverse().toString().toCharArray();
        int[] digit = new int[128];
        for (int i = 0; i < k.length ; i++) {
            digit[i] = k[i] - '0';
        }
        long ans = 0;
        for (int keta = k.length ; keta <= 18 ; keta++) {
            for (int krag = 0 ; krag < (1<<(keta-1)) ; krag++) {
                long partialAns = 1;
                for (int f = 0 ; f * 2 < keta ; f++) {
                    if (f == keta-1-f) {
                        int L = rightValue(f, krag, digit);
                        partialAns *= L == 0 ? 10 : 0;
                    } else {
                        int L = rightValue(f, krag, digit);
                        int R = rightValue(keta - 1 - f, krag, digit);
                        partialAns *= doit(f, L, R);
                    }
                }
                ans += partialAns;
            }
        }
        out.println(ans);
        out.flush();
    }

    static long doit(int f, int l, int r) {
        long cnt = 0;
        int min = f == 0 ? 1 : 0;
        for (int X = f == 0 ? 1 : 0 ; X <= 9 ; X++) {
            int Y = X + r;
            if (Y + l == X && min <= Y && Y <= 9) {
                cnt++;
            }
        }
        return cnt;
    }

    private static int rightValue(int f, int krag, int[] digit) {
        int L = -digit[f];
        if (f >= 1 && (krag & (1<<(f-1))) >= 1) {
            L--;
        }
        if ((krag & (1<<f)) >= 1) {
            L += 10;
        }
        return L;
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