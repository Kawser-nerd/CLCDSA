// package agc.agc007;

import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.*;

public class Main {
    static final int SIZE = 131072;

    public static void main(String[] args) {
        InputReader in = new InputReader(System.in);
        PrintWriter out = new PrintWriter(System.out);

        int n = in.nextInt();
        N = n;
        parent = new int[n];
        parent[0] = -1;

        children = new int[n][2];
        weight = new int[n][2];
        cn = new int[n];
        ptr = new int[n];
        for (int i = 0; i < n-1; i++) {
            int idx = i+1;
            int p = in.nextInt()-1;
            int w = in.nextInt();
            parent[idx] = p;
            children[p][cn[p]] = idx;
            weight[p][cn[p]] = w;
            cn[p]++;
        }
        dpPos = new int[n];
        prepare();

        long min = -1;
        long max = (long)1e9;
        while (max - min > 1) {
            long med = (max + min) / 2;
            if (isPossible(med)) {
                max = med;
            } else {
                min = med;
            }
        }
        out.println(max);
        out.flush();
    }

    static void prepare() {
        dp = new int[N][];
        tmplong = new long[N];
        int[] c = new int[N];
        for (int i = N-1; i >= 0 ; i--) {
            if (cn[i] == 0) {
                c[i] = 1;
            } else {
                c[i] = Math.min(c[children[i][0]], c[children[i][1]]) * 2;
            }
            dp[i] = new int[c[i]*2];
        }
    }

    static long[] tmplong;
    static int[][] dp;
    static int[] dpPos;

    private static void dfs(long K, int vi) {
        if (cn[vi] == 0) {
            dpPos[vi] = 1;
            return;
        }

        dfs(K, children[vi][0]);
        dfs(K, children[vi][1]);

        long limit = K - weight[vi][0] - weight[vi][1];
        if (limit < 0) {
            dpPos[vi] = 0;
            return;
        }

        int tcnt = 0;
        for (int par = 0 ; par <= 1 ; par++) {
            int li = children[vi][par];
            int ri = children[vi][par^1];
            int[] L = dp[li];
            int[] R = dp[ri];
            int ln = dpPos[li];
            int rn = dpPos[ri];
            int ridx = 0;

            for (int i = 0; i < ln; i++) {
                long left = limit - L[i*2+1];
                while (ridx < rn && R[ridx*2] > left) {
                    ridx++;
                }
                if (ridx == rn) {
                    break;
                }
                long p0 = L[i*2] + weight[vi][par];
                long p1 = R[ridx*2+1] + weight[vi][par^1];
                tmplong[tcnt++] = (p1 << 30) + p0;
            }
        }
        Arrays.sort(tmplong, 0, tcnt);

        long ymask = (1L<<30)-1;
        long xmask = ~ymask;
        long lastY = Long.MAX_VALUE;
        for (int i = 0 ; i < tcnt ; ) {
            int j = i;
            while (j < tcnt && (tmplong[i] & xmask) == (tmplong[j] & xmask)) {
                j++;
            }
            long p = tmplong[i];
            long Y = (p & ymask);
            long X = ((p & xmask) >> 30);
            if (lastY > Y) {
                lastY = Y;
                dp[vi][dpPos[vi]*2] = (int)Y;
                dp[vi][dpPos[vi]*2+1] = (int)X;
                dpPos[vi]++;
            }
            i = j;
        }
    }

    private static boolean isPossible(long K) {
        Arrays.fill(dpPos, 0);
        dfs(K, 0);
        return dpPos[0] >= 1;
    }

    static int[] ptr;

    static int N;
    static int[] cn;
    static int[] parent;
    static int[][] children;
    static int[][] weight;

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