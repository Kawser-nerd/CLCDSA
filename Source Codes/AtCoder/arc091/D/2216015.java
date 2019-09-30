// package arc.arc091;

import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.List;

public class Main {
    private static final int THRESHOLD = 2560000;

    public static void main(String[] args) {
        InputReader in = new InputReader(System.in);
        PrintWriter out = new PrintWriter(System.out);

        int n = in.nextInt();
        long xor = 0;
        for (int i = 0; i < n ; i++) {
            int a = in.nextInt();
            int k = in.nextInt();
            xor ^= solve(a, k);
        }

        table = new int[1800][1800];

        out.println(xor == 0 ? "Aoki" : "Takahashi");
        out.flush();
    }

    private static int solve(int a, int k) {
        if (k <= THRESHOLD) {
            return solveRecursive(a, k);
        } else {
            return solveBigK(a, k);
        }
    }

    private static int[][] table;

    private static int solveBigK(int a, int k) {
        if (a < k) {
            return 0;
        }
        if (a % k == 0) {
            return a / k;
        }

        // k*k >= a
        table[0][0] = 0;
        int tid = 0;
        for (int p = k ; p+k < a ; p += k) {
            tid++;

            int li = 0;
            table[tid][li++] = p / k;
            int lastW = p / k;
            for (int idx = k-lastW ; idx <= k-1 ; idx++) {
                table[tid][li++] = table[tid-1][idx % tid];
            }
        }
        int mod = a % k;
        return table[tid][mod % (tid+1)];
    }

    private static int solveRecursive(int a, int k) {
        if (a < k) {
            return 0;
        }
        if (a % k == 0) {
            return a / k;
        }
        int L = a / k + 1;
        int mod = a % k;
        int use = (mod + L - 1) / L;

        return solve(a - use * L, k);
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