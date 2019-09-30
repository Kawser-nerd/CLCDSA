// package agc.agc021;

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
        int h = in.nextInt();
        int v = in.nextInt();

        char[][] a = solve(n, m, h, v);

        if (a == null) {
            out.println("NO");
        } else {
            out.println("YES");
            for (int i = 0 ; i < n ; i++) {
                for (int j = 0; j < m ; j++) {
                    out.print(a[i][j]);
                }
                out.println();
            }
        }


        out.flush();
    }

    private static char[][] solve(int n, int m, int h, int v) {
        int space = n * m;
        int blk = (h + v) * 2;
        if (space < blk) {
            return null;
        }

        char[][] ret = new char[n][m];
        for (int i = 0; i < n ; i++) {
            Arrays.fill(ret[i], '.');
        }
        for (int i = 0; i < n ; i++) {
            for (int j = 0; j+1 < m ; j += 2) {
                ret[i][j] = '<';
                ret[i][j + 1] = '>';
            }
        }

        int filledV = 0;
        if (m % 2 == 1) {
            for (int i = 0; i+1 < n ; i += 2) {
                if (filledV < v) {
                    filledV++;
                    ret[i][m-1] = '^';
                    ret[i+1][m-1] = 'v';
                }
            }

        }
        for (int i = 0; i+1 < n ; i += 2) {
            for (int j = 0; j+1 < m ; j += 2) {
                if (filledV + 2 <= v) {
                    filledV += 2;
                    ret[i][j] = '^';
                    ret[i+1][j] = 'v';
                    ret[i][j+1] = '^';
                    ret[i+1][j+1] = 'v';
                }
            }
        }
        if (filledV + 1 == v) {
            if (n >= 3 && n % 2 == 1 && m >= 3 && m % 2 == 1 && ret[n-3][m-3] == '<' && ret[n-2][m-3] == '<' && ret[n-1][m-3] == '<') {
                ret[n-2][m-3] = '^';
                ret[n-1][m-3] = 'v';
                ret[n-1][m-2] = '<';
                ret[n-1][m-1] = '>';
                ret[n-2][m-2] = '.';
            } else {
                fillLastV: for (int i = 0; i+1 < n ; i += 2) {
                    for (int j = 0; j+1 < m ; j += 2) {
                        if (ret[i][j] == '<') {
                            ret[i][j] = '^';
                            ret[i+1][j] = 'v';
                            ret[i][j+1] = '.';
                            ret[i+1][j+1] = '.';
                            break fillLastV;
                        }
                    }
                }
            }
        }

        int[] pair = count(ret);

        if (pair[0] < h || pair[1] < v) {
            return null;
        }
        for (int i = 0; i < n ; i++) {
            for (int j = 0; j < m ; j++) {
                if (pair[0] > h && ret[i][j] == '<') {
                    ret[i][j] = '.';
                    ret[i][j+1] = '.';
                    pair[0]--;
                }
            }
        }
        return ret;
    }

    private static int[] count(char[][] ret) {
        int v = 0;
        int h = 0;
        for (int i = 0; i < ret.length; i++) {
            for (int j = 0; j < ret[0].length; j++) {
                if (ret[i][j] == '<') {
                    h++;
                } else if (ret[i][j] == '^') {
                    v++;
                }
            }
        }
        return new int[]{h, v};
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