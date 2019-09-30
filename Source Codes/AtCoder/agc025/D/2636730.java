// package agc.agc025;

import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.*;
import java.util.concurrent.ArrayBlockingQueue;

public class Main {
    public static void main(String[] args) {
        InputReader in = new InputReader(System.in);
        PrintWriter out = new PrintWriter(System.out);

        int n = in.nextInt();
        int d1 = in.nextInt();
        int d2 = in.nextInt();

        char[][] map1 = doit(n*2, d1);
        char[][] map2 = doit(n*2, d2);

        int[][] d0 = new int[map1.length][map1[0].length];

        int[] cnt = new int[4];
        for (int i = 0; i < d0.length ; i++) {
            for (int j = 0; j < d0[0].length ; j++) {
                int a = map1[i][j] == '@' ? 1 : 0;
                int b = map2[i][j] == '@' ? 2 : 0;
                d0[i][j] = a+b;
                cnt[a+b]++;
            }
        }

        List<int[]> ans = new ArrayList<>();
        for (int k = 0; k < 4 ; k++) {
            if (cnt[k] >= n*n) {
                sch: for (int i = 0; i < d0.length ; i++) {
                    for (int j = 0; j < d0[0].length; j++) {
                        if (d0[i][j] == k) {
                            ans.add(new int[]{i, j});
                            if (ans.size() == n*n) {
                                break sch;
                            }
                        }
                    }
                }
                break;
            }
        }
        printAndFlush(out, ans);
    }

    static void paint(char[][] map, List<int[]> p, int i, int j, char c) {
        if (map[i][j] != 0) {
            return;
        }
        map[i][j] = c;
        for (int[] dd : p) {
            int ti = i + dd[0];
            int tj = j + dd[1];
            if (ti < 0 || tj < 0 || ti >= map.length || tj >= map[0].length) {
                continue;
            }
            paint(map, p, ti, tj, c == '@' ? '.' : '@');
        }
    }

    static char[][] doit(int n, int d) {
        List<int[]> p = checkPair(n, d);
        char[][] map = new char[n][n];

        for (int i = 0; i < n ; i++) {
            for (int j = 0; j < n ; j++) {
                if (map[i][j] != 0) {
                    continue;
                }
                paint(map, p, i, j, '@');
            }
        }
        return map;
    }

    static void printAndFlush(PrintWriter out, List<int[]> ans) {
        for (int[] a : ans) {
            out.println(a[0] + " " + a[1]);
        }
        out.flush();
    }

    static List<int[]> checkPair(int n, int d) {
        List<int[]> wo = new ArrayList<>();
        for (int i = 0; i < 2*n ; i++) {
            for (int j = 0; j < 2*n; j++) {
                int ii = i*i;
                int jj = j*j;
                if (ii + jj == d) {
                    for (int dy = -1 ; dy <= 1 ; dy += 2) {
                        for (int dx = -1 ; dx <= 1 ; dx += 2) {
                            wo.add(new int[]{i * dy, j * dx});
                        }
                    }
                }
            }
        }
        return wo;
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