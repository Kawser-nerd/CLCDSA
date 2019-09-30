// package atcoder.arc.arc057;

import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.*;

/**
 * Created by hama_du on 2016/07/09.
 */
public class Main {
    private static final long MOD = (long)1e9+7;

    public static void main(String[] args) {
        InputReader in = new InputReader(System.in);
        PrintWriter out = new PrintWriter(System.out);

        n = in.nextInt();
        if (n == 1) {
            out.println(1);
            out.flush();
            return;
        }

        a = new int[n-1];
        for (int i = 0; i < n-1 ; i++) {
            a[i] = in.nextInt();
        }
        notUsed = new int[n-1];
        notUsed[0] = a[0] - 1;
        for (int i = 1 ; i < n-1 ; i++) {
            notUsed[i] = notUsed[i-1] + (a[i] - a[i-1] - 1);
        }

        cmb = new long[500][500];
        for (int i = 0; i < cmb.length ; i++) {
            cmb[i][0] = cmb[i][i] = 1;
            for (int j = 1 ; j < i ; j++) {
                cmb[i][j] = (cmb[i-1][j-1] + cmb[i-1][j]) % MOD;
            }
        }
        fact = new long[501];
        fact[0] = 1;
        for (int i = 1 ; i < 500; i++) {
            fact[i] = fact[i-1] * i % MOD;
        }
        unit = fact[n*(n-1)/2-a[n-2]];

        memo = new HashMap[n-1];
        for (int i = 0; i < n-1 ; i++) {
            memo[i] = new HashMap<>();
        }


        out.println(dfs(0, new ArrayList<>()));
        out.flush();
    }

    static long unit;

    static int[] a;
    static int[] notUsed;

    static long[][] cmb;
    static long[] fact;

    static int n;
    static Map<List<Integer>,Long>[] memo;

    static long dfs(int now, List<Integer> g) {
        if (now == n-1) {
            return unit;
        }
        if (memo[now].containsKey(g)) {
            return memo[now].get(g);
        }

        int sum = 0;
        int freedom = 0;
        for (int i = 0; i < g.size() ; i++) {
            sum += g.get(i);
            freedom += g.get(i) * (g.get(i) - 1) / 2 - (g.get(i) - 1);
        }

        int one = n - sum;
        long base = 1;
        if (now >= 1) {
            int leftFreedom = freedom - notUsed[now-1];
            int pickFreedom = notUsed[now] - notUsed[now-1];
            if (leftFreedom < 0) {
                base = 0;
            } else {
                base *= cmb[leftFreedom][pickFreedom]*fact[pickFreedom]%MOD;
            }
        }

        long ret = 0;
        if (base >= 1) {
            if (one >= 2) {
                List<Integer> tg = new ArrayList<>(g);
                tg.add(2);
                Collections.sort(tg);
                ret += dfs(now+1, tg)*cmb[one][2]%MOD;
                ret %= MOD;
            }

            // combine two groups
            for (int i = 0; i < g.size(); i++) {
                for (int j = i+1; j < g.size(); j++) {
                    int tsz = g.get(i)+g.get(j);
                    List<Integer> tg = new ArrayList<>(g);
                    tg.remove(j);
                    tg.remove(i);
                    tg.add(tsz);
                    Collections.sort(tg);
                    ret += dfs(now+1, tg)*g.get(i)*g.get(j)%MOD;
                    ret %= MOD;
                }
            }
            if (one >= 1) {
                for (int i = 0; i < g.size(); i++) {
                    List<Integer> tg = new ArrayList<>(g);
                    tg.remove(i);
                    tg.add(g.get(i)+1);
                    Collections.sort(tg);
                    ret += dfs(now+1, tg)*g.get(i)*one%MOD;
                }
            }
        }
        ret *= base;
        ret %= MOD;
        memo[now].put(g, ret);

        return ret;
    }

    static class InputReader {
        private InputStream stream;
        private byte[] buf = new byte[1024];
        private int curChar;
        private int numChars;

        public InputReader(InputStream stream) {
            this.stream = stream;
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
} Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.