// package atcoder.arc.arc058;

import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.*;

/**
 * Created by hama_du on 2016/07/23.
 */
public class Main {
    private static final long MOD = (long) 1e9+7;

    static int n, x, y, z;
    static int flg;

    static int[][] table;
    static int[][] memo;
    static long[] pow10;

    static int go(int ptn, int c) {
        if (table[c][ptn] != -1) {
            return table[c][ptn];
        }
        int result;
        if ((ptn & (1<<x+y+z)) >= 1) {
            result = 1<<x+y+z;
        } else {
            int tptn = ((ptn<<c)|(1<<(c-1)))&((1<<x+y+z)-1);
            List<Integer> history = doit(decode(tptn));
            if (history == null) {
                result = 1<<x+y+z;
            } else {
                result = encode(history);
            }
        }
        table[c][ptn] = result;
        return result;
    }

    static long dfs(int idx, int ptn) {
        if (idx == n) {
            return (ptn & flg) >= 1 ? 1 : 0;
        }

        if (memo[idx][ptn] != -1) {
            return memo[idx][ptn];
        }
        long res = 0;
        if ((ptn & flg) >= 1) {
            res = pow10[n-idx];
        } else {
            for (int c = 1; c <= 10 ; c++) {
                res += dfs(idx+1, go(ptn, c));
            }
        }
        res %= MOD;
        memo[idx][ptn] = (int)res;
        return res;
    }

    private static List<Integer> doit(List<Integer> next) {
        int n = next.size();
        for (int i = 0 ; i <= n ; i++) {
            int[] ord = new int[]{x,y,z};
            int idx = 0;
            boolean isOK = true;
            List<Integer> newOrd = new ArrayList<>();
            for (int j = i ; j < n ; j++) {
                int o = next.get(j);
                newOrd.add(o);
                if (ord[idx] >= o && idx <= 2) {
                    ord[idx] -= o;
                    if (ord[idx] == 0) {
                        idx++;
                    }
                } else {
                    isOK = false;
                    break;
                }
            }
            if (isOK) {
                if (ord[2] == 0) {
                    return null;
                } else {
                    return newOrd;
                }
            }
        }
        return new ArrayList<>();
    }

    private static int encode(List<Integer> next) {
        int n = next.size();
        int code = 0;
        for (int i = 0; i < n ; i++) {
            int c = next.get(i);
            code = (code<<c)|(1<<(c-1));
        }
        int all = (1<<x+y+z)-1;
        return code&all;
    }

    private static List<Integer> decode(int ptn) {
        List<Integer> history = new ArrayList<>();
        int last = -1;
        for (int i = 0 ; i < x+y+z ; i++) {
            if ((ptn & (1<<i)) >= 1) {
                history.add(i-last);
                last = i;
            }
        }
        Collections.reverse(history);
        return history;
    }
    
    public static void main(String[] args) {
        InputReader in = new InputReader(System.in);
        PrintWriter out = new PrintWriter(System.out);
        n = in.nextInt();
        x = in.nextInt();
        y = in.nextInt();
        z = in.nextInt();
        flg = 1<<(x+y+z);
        pow10 = new long[n+1];
        pow10[0] = 1;
        for (int i = 1 ; i <=  n ; i++) {
            pow10[i] = pow10[i-1] * 10 % MOD;
        }

        table = new int[11][1<<x+y+z+1];
        memo = new int[n+1][1<<x+y+z+1];
        for (int i = 0; i <= 10 ; i++) {
            Arrays.fill(table[i], -1);
        }
        for (int i = 0; i <= n; i++) {
            Arrays.fill(memo[i], -1);
        }
        out.println(dfs(0, 0));
        out.flush();
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

        private long[] nextLongs(int n) {
            long[] ret = new long[n];
            for (int i = 0; i < n; i++) {
                ret[i] = nextLong();
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