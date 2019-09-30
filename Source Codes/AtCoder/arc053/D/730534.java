// package atcoder.arc.arc053;

import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.HashMap;
import java.util.InputMismatchException;
import java.util.Map;

/**
 * Created by hama_du on 2016/05/14.
 */
public class Main {
    private static final long MOD = 1000000007;

    public static void main(String[] args) {
        InputReader in = new InputReader(System.in);
        PrintWriter out = new PrintWriter(System.out);

        int n = in.nextInt();
        int[] a = new int[n];
        int[] b = new int[n];
        for (int i = 0; i < n ; i++) {
            a[i] = in.nextInt()-1;
        }
        for (int i = 0; i < n ; i++) {
            b[i] = in.nextInt()-1;
        }
        out.println(solve(a, b));
        out.flush();
    }

    private static long solve(int[] a, int[] b) {
        int n = a.length;
        int[] apos = new int[n];
        int[] bpos = new int[n];
        for (int i = 0; i < n ; i++) {
            apos[a[i]] = i;
            bpos[b[i]] = i;
        }

        long[][][] dp = new long[2*n+1][n][4];
        dp[0][0][1] = 1;
        for (int i = 0; i < 2*(n-1) ; i++) {
            for (int last = 0; last < n ; last++) {
                int[][] pt = new int[2][2];
                if (i >= 1) {
                    pt[0][0] = apos[last];
                    pt[0][1] = i - apos[last];
                    pt[1][0] = i - bpos[last];
                    pt[1][1] = bpos[last];
                }

                for (int flg = 1 ; flg <= 3 ; flg++) {
                    if (dp[i][last][flg] == 0) {
                        continue;
                    }
                    long base = dp[i][last][flg];
                    // debug(i,last,flg,base, pt);
                    Map<Integer,Integer> flgMap = new HashMap<>();
                    for (int p = 0 ; p <= 1 ; p++) {
                        if ((flg & (1<<p)) >= 1) {
                            if (pt[p][1]+1 < n) {
                                flgMap.put(a[pt[p][0]], flgMap.getOrDefault(a[pt[p][0]], 0) | 1);
                            }
                            if (pt[p][0]+1 < n) {
                                flgMap.put(b[pt[p][1]], flgMap.getOrDefault(b[pt[p][1]], 0) | 2);
                            }
                        }
                    }
                    // debug(i,last,flg, flgMap);
                    for (int use : flgMap.keySet()) {
                        int tflg = flgMap.get(use);
                        dp[i+1][use][tflg] += base;
                        dp[i+1][use][tflg] -= dp[i+1][use][tflg] >= MOD ? MOD : 0;
                    }
                }
            }
        }

        long ans = 0;
        for (int i = 0; i < n ; i++) {
            for (int f = 1 ; f <= 3; f++) {
                ans += dp[2*(n-1)][i][f];
            }
        }
        return ans % MOD;
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