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

        char[] s = in.nextToken().toCharArray();
        s = Arrays.copyOf(s, s.length / 2);
        int c = s.length - errorFunction(s)[s.length];

        long l = in.nextLong() - 1;
        long r = in.nextLong();

        long[] ans = s.length % c == 0 ? solve(s, c, l, r) : solve2(s, c, l, r);
        for (int i = 0; i < 26 ; i++) {
            if (i >= 1) {
                out.print(' ');
            }
            out.print(ans[i]);
        }
        out.println();
        out.flush();
    }

    private static long[] solve(char[] s, int c, long l, long r) {
        long[] ans = new long[26];
        long[] x = solveSame(r, s);
        long[] y = solveSame(l, s);
        for (int i = 0; i < 26; i++) {
            ans[i] = x[i] - y[i];
        }
        return ans;
    }


    private static long[] solve2(char[] s, int lp, long l, long r) {
        int MAX = 2000;
        long[] ans = new long[26];
        S = s;
        wl = new long[MAX];
        wl[0] = s.length;
        wl[1] = s.length + lp;

        wcnt = new long[MAX][26];
        for (int i = 0; i < s.length ; i++) {
            wcnt[0][s[i]-'a']++;
            wcnt[1][s[i]-'a']++;
        }
        for (int i = 0; i < lp ; i++) {
            wcnt[1][s[i]-'a']++;
        }

        for (int i = 2 ; i < MAX ; i++) {
            wl[i] = wl[i-1] + wl[i-2];
            for (int c = 0 ; c < 26 ; c++) {
                wcnt[i][c] = wcnt[i-1][c] + wcnt[i-2][c];
            }

            if (wl[i] > r) {
                long[] R = solveRec(r, i);
                long[] L = solveRec(l, i);
                for (int c = 0; c < 26 ; c++) {
                    ans[c] = R[c] - L[c];
                }
                break;
            }
        }
        return ans;
    }

    static char[] S;
    static long[] wl;
    static long[][] wcnt;

    private static long[] solveRec(long r, int depth) {
        if (depth <= 1) {
            long[] cnt = new long[26];
            for (int i = 0; i < Math.min(r, S.length); i++) {
                cnt[S[i]-'a']++;
            }
            r -= S.length;
            for (int i = 0; i < Math.min(r, S.length); i++) {
                cnt[S[i]-'a']++;
            }
            return cnt;
        }

        long left = wl[depth-1];
        if (r <= left) {
            return solveRec(r, depth-1);
        } else {
            long[] ri = solveRec(r -  left, depth-2);
            for (int i = 0; i < 26; i++) {
                ri[i] += wcnt[depth-1][i];
            }
            return ri;
        }
    }


    private static long[] solveSame(long r, char[] s) {
        long cur = r / s.length;
        long mod = r % s.length;
        long[] ret = new long[26];
        for (int i = 0; i < s.length ; i++) {
            ret[s[i]-'a'] += cur;
        }
        for (int i = 0; i < mod ; i++) {
            ret[s[i]-'a']++;
        }
        return ret;
    }

    public static int[] errorFunction(char[] a) {
        int len = a.length;
        int[] err = new int[len+1];
        err[0] = -1;
        for (int i = 2 ; i <= len ; i++) {
            int now = err[i-1];
            while (now > 0 && a[i-1] != a[now]) {
                now = err[now];
            }
            if (a[i-1] == a[now]) {
                now++;
            } else {
                now = 0;
            }
            err[i] = now;
        }
        return err;
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