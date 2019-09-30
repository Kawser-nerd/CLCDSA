// package atcoder.arc.arc062;

import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.HashMap;
import java.util.InputMismatchException;
import java.util.Map;

/**
 * Created by hama_du on 2016/10/19.
 */
public class Main {
    public static void main(String[] args) {
        InputReader in = new InputReader(System.in);
        PrintWriter out = new PrintWriter(System.out);

        debug(code(new int[]{0,1,1,0}), code(new int[]{1,1,0,0}));

        int n = in.nextInt();
        int[][] panels = in.nextIntTable(n, 4);

        long[] panelCodes = new long[n];
        for (int i = 0; i < n ; i++) {
            panelCodes[i] = code(panels[i]);
        }

        long ans = 0;

        long[] sideCodes = new long[n];
        for (int top = 0 ; top < n ; top++) {
            for (int bottom = top+1 ; bottom < n ; bottom++) {
                int sidx = 0;
                for (int i = top+1 ; i < n ; i++) {
                    if (i == bottom) {
                        continue;
                    }
                    sideCodes[sidx++] = panelCodes[i];
                }

                for (int d = 0 ; d < 4 ; d++) {
                    int[][] men = new int[][]{
                            { panels[top][1], panels[top][0], panels[bottom][(d+3)%4], panels[bottom][(d+2)%4] },
                            { panels[top][2], panels[top][1], panels[bottom][(d+2)%4], panels[bottom][(d+1)%4] },
                            { panels[top][3], panels[top][2], panels[bottom][(d+1)%4], panels[bottom][(d+0)%4] },
                            { panels[top][0], panels[top][3], panels[bottom][(d+0)%4], panels[bottom][(d+3)%4] }
                    };
                    ans += solve(men, sideCodes, sidx);
                }
            }
        }

        out.println(ans);
        out.flush();
    }

    private static long same(int[] men) {
        if (men[0] == men[1] && men[1] == men[2] && men[2] == men[3]) {
            return 4;
        }
        if (men[0] == men[2] && men[1] == men[3]) {
            return 2;
        }
        return 1;
    }

    private static long code(int[] men) {
        int[] minOrd = men.clone();
        for (int i = 1 ; i < 4; i++) {
            int[] ord = new int[4];
            for (int j = 0; j < 4 ; j++) {
                ord[j] = men[(j+i)%4];
            }
            for (int j = 0; j < 4 ; j++) {
                if (minOrd[j] > ord[j]) {
                    minOrd = ord;
                    break;
                } else if (ord[j] > minOrd[j]) {
                    break;
                }
            }
        }

        long wo = 0;
        for (int i = 0; i < 4; i++) {
            wo |= ((long) minOrd[i]) << (10L * i);
        }
        return wo;
    }

    private static long solve(int[][] men, long[] codes, int n) {
        long[] menCodes = new long[4];
        for (int i = 0; i < 4 ; i++) {
            menCodes[i] = code(men[i]);
        }
        long[] menCounts = new long[4];
        for (int i = 0; i < n ; i++) {
            for (int j = 0; j < 4 ; j++) {
                if (menCodes[j] == codes[i]) {
                    menCounts[j]++;
                }
            }
        }

        Map<Long,Long> dec = new HashMap<>();
        long ret = 1;
        for (int i = 0 ; i < 4 ; i++) {
            long A = same(men[i]);
            ret *= A * menCounts[i] - A * dec.getOrDefault(menCodes[i], 0L);
            dec.put(menCodes[i], dec.getOrDefault(menCodes[i], 0L) + 1);
        }
        if (ret < 0) {
            return 0;
        }
        return ret;
    }

    private static int[] match(int[][] men, int[] panel) {
        int[] x = new int[4];
        for (int i = 0; i < 4 ; i++) {
            for (int d = 0 ; d < 4 ; d++) {
                boolean isOK = true;
                for (int e = 0 ; e < 4 ; e++){
                    if (men[i][e] != panel[(d+e)%4]) {
                        isOK = false;
                        break;
                    }
                }
                if (isOK) {
                    x[i]++;
                }
            }
        }
        return x;
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
                res += c - '0';
                c = next();
            } while (!isSpaceChar(c));
            return res * sgn;
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
                res += c - '0';
                c = next();
            } while (!isSpaceChar(c));
            return res * sgn;
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