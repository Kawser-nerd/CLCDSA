// package arc.arc089;

import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class Main {
    static final int MOD = 1000000007;

    static char[] S;
    static long[][] C;

    static long dfs(int[] a, int idx, int last, int left) {
        if (left < 0) {
            return 0;
        }

        long ret = way(a, idx, left);
        for (int l = last ; l >= 1 ; l--) {
            int cost = ((l <= 2) ? 1 : ((l-2)*2+1)) + Math.min(idx, 1);
            a[idx] = l;
            ret += dfs(a, idx+1, l, left - cost);
        }
        ret %= MOD;
        return ret;
    }

    static long way(int[] a, int n, int space) {
        if (!canDoit(a, n, S)) {
            return 0;
        }
        if (n == 0) {
            return 1;
        }

        long pway = 1;
        int left = n;
        for (int i = 0; i < n ; ) {
            int j = i+1;
            while (j < n && a[i] == a[j]) {
                j++;
            }
            pway *= C[left][j-i];
            pway %= MOD;
            left -= j-i;
            i = j;
        }

        long total = 0;
        int free = 0;
        for (int i = 0; i < n; i++) {
            free += a[i] * 2 - 1;
        }

        for (int s = 0 ; s <= space ; s++) {
            long sway = C[s+n][s];
            int L = space - s;
            total += C[free+L-1][free-1] * sway % MOD;
        }
        total %= MOD;
        return total * pway % MOD;
    }

    public static void main(String[] args) {
        InputReader in = new InputReader(System.in);
        PrintWriter out = new PrintWriter(System.out);

        int n = in.nextInt();
        in.nextInt();
        S = in.nextToken().toCharArray();
        C = new long[200][200];
        for (int i = 0; i < C.length; i++) {
            C[i][0] = C[i][i] = 1;
            for (int j = 1 ; j < i; j++) {
                C[i][j] = (C[i-1][j-1] + C[i-1][j]) % MOD;
            }
        }

        out.println(dfs(new int[140], 0, 70, n));
        out.flush();
    }

    private static boolean canDoit(int[] a, int n, char[] s) {
        int[] b = new int[n];
;

        int ridx = 0;
        int bidx = 0;
        for (char c : s) {
            if (c == 'r') {
                if (ridx < n) {
                    b[ridx] = 1;
                    ridx++;
                } else {
                    for (int i = 0 ; i < n ; i++) {
                        if (b[i] >= 2 && b[i] < a[i]) {
                            b[i]++;
                            break;
                        }
                    }
                }
            } else {
                if (ridx == bidx || a[bidx] == 1) {
                    for (int i = 0 ; i < n ; i++) {
                        if (b[i] >= 2 && b[i] < a[i]) {
                            b[i]++;
                            break;
                        }
                    }
                } else {
                    b[bidx] = 2;
                    bidx++;
                }
            }
        }

        for (int i = 0; i < n ; i++) {
            if (b[i] < a[i]) {
                return false;
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