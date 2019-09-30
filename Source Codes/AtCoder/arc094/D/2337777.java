// package arc.arc094;

import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.*;

public class Main {
    private static final int MOD = 998244353;

    public static void main(String[] args) {
        InputReader in = new InputReader(System.in);
        PrintWriter out = new PrintWriter(System.out);
        out.println(solve(in.nextToken().toCharArray()));
        out.flush();
    }


    public static long solve(char[] s) {
        if (s.length < 5) {
            return build(String.valueOf(s));
        }
        
        int[][][][] dp = new int[2][2][3][3];
        dp[0][0][0][0] = 1;
        for (int i = 0; i < s.length; i++) {
            int fr = i % 2;
            int to = 1 - fr;
            for (int f = 0; f <= 1; f++) {
                for (int l = 0; l <= 2; l++) {
                    Arrays.fill(dp[to][f][l], 0);
                }
            }

            for (int f = 0; f <= 1; f++) {
                for (int l = 0; l <= 2; l++) {
                    for (int m = 0 ; m <= 2 ; m++) {
                        int base = dp[fr][f][l][m];
                        for (int c = 0; c <= 2; c++) {
                            int nf = Math.max(f, (i >= 1 && l == c) ? 1 : 0);
                            int nm = (m + c) % 3;
                            add(dp, to, nf, c, nm, base);
                        }
                    }
                }
            }
        }

        int mo = 0;
        for (int i = 0; i < s.length; i++) {
            mo += s[i]-'a';
        }
        mo %= 3;

        long sum = 0;
        for (int i = 0; i <= 2; i++) {
            sum += dp[s.length%2][1][i][mo];
        }
        int diff = 0;
        for (int i = 0; i+1 < s.length; i++) {
            if (s[i] != s[i+1]) {
                diff++;
            }
        }
        if (diff == 0) {
            return 1;
        }
        if (diff == s.length-1) {
            sum++;
        }
        return sum % MOD;
    }
    
    static void add(int[][][][] dp, int i, int f, int l, int m, int v) {
        dp[i][f][l][m] += v;
        dp[i][f][l][m] -= (dp[i][f][l][m] >= MOD) ? MOD : 0;
    }

    static int build(String a) {
        Set<String> set = new HashSet<>();
        set.add(a);
        while (true) {
            Set<String> nset = new HashSet<>(set);
            for (String s : set) {
                for (int i = 0; i+1 < s.length(); i++) {
                    if (s.charAt(i) != s.charAt(i+1)) {
                        char l = (char)('a' + (3 - ((s.charAt(i) - 'a') + (s.charAt(i+1) - 'a'))));
                        String t = s.substring(0, i) + l + l + s.substring(i+2);
                        nset.add(t);
                    }
                }
            }
            if (nset.size() == set.size()) {
                break;
            }
            set = nset;
        }
        return set.size();

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