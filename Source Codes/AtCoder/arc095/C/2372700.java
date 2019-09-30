// package arc.arc095;

import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class Main {
    public static void main(String[] args) {
        InputReader in = new InputReader(System.in);
        PrintWriter out = new PrintWriter(System.out);

        int h = in.nextInt();
        int w = in.nextInt();
        S = new char[h][];
        S2 = new char[w][h];
        for (int i = 0; i < h ; i++) {
            S[i] = in.nextToken().toCharArray();
        }

        out.println(solve() ? "YES" : "NO");
        out.flush();
    }

    static char[][] S;

    private static boolean solve() {
        if (S.length % 2 == 0) {
            if (dfs(0, new int[S.length / 2][2], 0, -1)) {
                return true;
            }
        } else {
            for (int i = 0; i < S.length; i++) {
                if (dfs(1<<i, new int[S.length/2][2], 0, i)) {
                    return true;
                }
            }
        }
        return false;
    }

    private static boolean dfs(int flag, int[][] rowPairs, int idx, int center) {
        if (Integer.bitCount(flag) == S.length) {
            return solveRowColumn(rowPairs, center);
        }

        for (int i = 0; i < S.length ; i++) {
            if ((flag & (1<<i)) == 0) {
                for (int j = i+1 ; j < S.length; j++) {
                    if ((flag & (1<<j)) == 0) {
                        rowPairs[idx][0] = i;
                        rowPairs[idx][1] = j;
                        if (dfs(flag | (1<<i) | (1<<j), rowPairs, idx+1, center)) {
                            return true;
                        }
                    }
                }
                break;
            }
        }
        return false;
    }

    static char[][] S2;

    private static boolean solveRowColumn(int[][] rowPairs, int center) {
        for (int i = 0; i < rowPairs.length ; i++) {
            int u = rowPairs[i][0];
            int v = rowPairs[i][1];
            for (int j = 0; j < S[0].length ; j++) {
                S2[j][i] = S[u][j];
                S2[j][S.length-1-i] = S[v][j];
            }
        }
        if (center != -1) {
            for (int j = 0; j < S[0].length ; j++) {
                S2[j][S.length/2] = S[center][j];
            }
        }

        boolean[][] match = new boolean[S2.length][S2.length];
        for (int i = 0; i < S2.length ; i++) {
            for (int j = i ; j < S2.length; j++) {
                match[i][j] = match[j][i] = String.valueOf(S2[i]).equals(new StringBuilder().append(S2[j]).reverse().toString());
            }
        }

        boolean[] used = new boolean[S2.length];
        int oc = 0;
        for (int i = 0; i < used.length ; i++) {
            if (used[i]) {
                continue;
            }
            for (int j = i+1 ; j < used.length; j++) {
                if (!used[j]) {
                    if (match[i][j]) {
                        used[i] = used[j] = true;
                        break;
                    }
                }
            }
            if (!used[i]) {
                if (S2.length % 2 == 0 || !match[i][i]) {
                    return false;
                }
                oc++;
                if (oc >= 2) {
                    return false;
                }
            }
        }
        return true;
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