// package atcoder.arc.arc081;

import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class Main {
    public static void main(String[] args) {
        InputReader in = new InputReader(System.in);
        PrintWriter out = new PrintWriter(System.out);

        int H = in.nextInt();
        int W = in.nextInt();

        int[][] table = new int[H][W];
        for (int i = 0; i < H ; i++) {
            char[] c = in.nextToken().toCharArray();
            for (int j = 0; j < W ; j++) {
                table[i][j] = c[j] == '.' ? 0 : 1;
            }
        }

        int[][] diff = new int[H][W-1];
        for (int i = 0 ; i < H ; i++) {
            for (int j = 0; j+1 < W; j++) {
                diff[i][j] = table[i][j] ^ table[i][j+1];
            }
        }

        W--;
        int[] bottom = new int[W];
        for (int j = 0; j < W ; j++) {
            int shouldSameTo = 0;
            while (bottom[j] < H && diff[bottom[j]][j] == diff[shouldSameTo][j]) {
                bottom[j]++;
            }
        }

        int answer = Math.max(H, W+1);
        int[] height = new int[W];
        for (int i = 0 ; i < H ; i++) {
            for (int j = 0; j < W ; j++) {
                height[j] = bottom[j] - i;
            }
            answer = Math.max(answer, solve(height));

            for (int j = 0; j < W ; j++) {
                if (bottom[j] == i+1) {
                    int shouldSameTo = bottom[j];
                    while (bottom[j] < H && diff[bottom[j]][j] == diff[shouldSameTo][j]) {
                        bottom[j]++;
                    }
                }
            }
        }
        out.println(answer);
        out.flush();
    }

    static int solve(int[] a) {
        int n = a.length;
        int[] stk = new int[n+1];
        int head = 0;

        int[] l = new int[n];
        for (int i = 0 ; i < n ; i++) {
            while (head > 0 && a[stk[head-1]] >= a[i]) {
                head--;
            }
            l[i] = head == 0 ? 0 : stk[head-1]+1;
            stk[head++] = i;
        }

        int[] r = new int[n];
        head = 0;
        for (int i = n-1 ; i >= 0 ; i--) {
            while (head > 0 && a[stk[head-1]] >= a[i]) {
                head--;
            }
            r[i] = head == 0 ? n : stk[head-1];
            stk[head++] = i;
        }

        int max = 0;
        for (int i = 0; i < n ; i++) {
            max = Math.max(max, a[i] * (r[i] - l[i] + 1));
        }
        return max;
    }

    static class InputReader {
        private InputStream stream;
        private byte[] buf = new byte[1024];
        private int curChar;
        private int numChars;

        public InputReader(InputStream stream) {
            this.stream = stream;
        }

        private int[] nextInts(int n) {
            int[] ret = new int[n];
            for (int i = 0; i < n; i++) {
                ret[i] = nextInt();
            }
            return ret;
        }

        private int[][] nextIntTable(int n, int m) {
            int[][] ret = new int[n][m];
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    ret[i][j] = nextInt();
                }
            }
            return ret;
        }

        private long[] nextLongs(int n) {
            long[] ret = new long[n];
            for (int i = 0; i < n; i++) {
                ret[i] = nextLong();
            }
            return ret;
        }

        private long[][] nextLongTable(int n, int m) {
            long[][] ret = new long[n][m];
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    ret[i][j] = nextLong();
                }
            }
            return ret;
        }

        private double[] nextDoubles(int n) {
            double[] ret = new double[n];
            for (int i = 0; i < n; i++) {
                ret[i] = nextDouble();
            }
            return ret;
        }

        private int next() {
            if (numChars == -1)
                throw new InputMismatchException();
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
            int c = next();
            while (isSpaceChar(c))
                c = next();
            if ('a' <= c && c <= 'z') {
                return (char) c;
            }
            if ('A' <= c && c <= 'Z') {
                return (char) c;
            }
            throw new InputMismatchException();
        }

        public String nextToken() {
            int c = next();
            while (isSpaceChar(c))
                c = next();
            StringBuilder res = new StringBuilder();
            do {
                res.append((char) c);
                c = next();
            } while (!isSpaceChar(c));
            return res.toString();
        }

        public int nextInt() {
            int c = next();
            while (isSpaceChar(c))
                c = next();
            int sgn = 1;
            if (c == '-') {
                sgn = -1;
                c = next();
            }
            int res = 0;
            do {
                if (c < '0' || c > '9')
                    throw new InputMismatchException();
                res *= 10;
                res += c-'0';
                c = next();
            } while (!isSpaceChar(c));
            return res*sgn;
        }

        public long nextLong() {
            int c = next();
            while (isSpaceChar(c))
                c = next();
            long sgn = 1;
            if (c == '-') {
                sgn = -1;
                c = next();
            }
            long res = 0;
            do {
                if (c < '0' || c > '9')
                    throw new InputMismatchException();
                res *= 10;
                res += c-'0';
                c = next();
            } while (!isSpaceChar(c));
            return res*sgn;
        }

        public double nextDouble() {
            return Double.valueOf(nextToken());
        }

        public boolean isSpaceChar(int c) {
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
        }

        public interface SpaceCharFilter {
            public boolean isSpaceChar(int ch);
        }
    }

    static void debug(Object... o) {
        System.err.println(Arrays.deepToString(o));
    }
}