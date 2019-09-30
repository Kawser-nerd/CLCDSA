// package atcoder.arc.arc055;

import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Comparator;
import java.util.InputMismatchException;

/**
 * Created by hama_du on 2016/06/03.
 */
public class Main {
    public static void main(String[] args) {
        InputReader in = new InputReader(System.in);
        PrintWriter out = new PrintWriter(System.out);

        char[] c = in.nextToken().toCharArray();
        char[] rc = new StringBuilder(String.valueOf(c)).reverse().toString().toCharArray();

        int n = c.length;
        SuffixArray sa = new SuffixArray(c);
        sa.buildSA(); sa.buildLCP();

        SuffixArray rsa = new SuffixArray(rc);
        rsa.buildSA(); rsa.buildLCP();

        long ptn = 0;
        for (int last = 2 ; last <= n ; last++) {
            if (n - last * 2 <= 0) {
                break;
            }
            int a = Math.min(sa.countCommon(0, n - last), last-1);
            int b = Math.min(rsa.countCommon(0, last), last-1);
            ptn += Math.max(0, a + b + 1 - last);
            // debug(last,a,b);
        }
        out.println(ptn);
        out.flush();
    }



    static class SuffixArray {
        int n;
        int k;
        char[] base;

        Integer[] sa;
        int[] rank;
        int[] tmp;
        int[] lcp;
        int[][] levelRank;

        int compareNode(int i, int j, int k) {
            if (rank[i] != rank[j]) {
                return rank[i] - rank[j];
            } else {
                int ri = i + k <= n ? rank[i+k] : -1;
                int rj = j + k <= n ? rank[j+k] : -1;
                return ri - rj;
            }
        }

        public SuffixArray(char[] x) {
            base = x;
            n = base.length;
            k = Integer.numberOfTrailingZeros(Integer.highestOneBit(n))+2;
        }

        void buildSA() {
            sa = new Integer[n+1];
            rank = new int[n+1];
            tmp = new int[n+1];
            levelRank = new int[k][];

            int ki = 0;
            for (int i = 0 ; i <= n ; i++) {
                sa[i] = i;
                rank[i] = (i < n) ? base[i] : -1;
            }
            levelRank[ki++] = rank.clone();
            for (int _k = 1 ; _k <= n ; _k *= 2) {
                final int k = _k;
                Arrays.sort(sa, new Comparator<Integer>() {
                    @Override
                    public int compare(Integer i, Integer j) {
                        return compareNode(i, j, k);
                    }
                });
                tmp[sa[0]] = 0;
                for (int i = 1 ; i <= n ; i++) {
                    tmp[sa[i]] = tmp[sa[i-1]] + ((compareNode(sa[i-1], sa[i], k) < 0) ? 1 : 0);
                }
                for (int i = 0 ; i <= n ; i++) {
                    rank[i] = tmp[i];
                }
                levelRank[ki++] = rank.clone();
            }
        }

        void buildLCP() {
            for (int i = 0 ; i <= n ; i++) {
                rank[sa[i]] = i;
            }
            lcp = new int[n];
            int h = 0;
            for (int i = 0 ; i < n ; i++) {
                int j = sa[rank[i]-1];
                if (h > 0) {
                    h--;
                }
                for (; j + h < n && i + h < n ; h++) {
                    if (base[j+h] != base[i+h]) {
                        break;
                    }
                }
                lcp[rank[i]-1] = h;
            }
        }

        int countCommon(int i, int j) {
            if (i > j) {
                return countCommon(j, i);
            } else if (i == j) {
                return 0;
            }
            int cnt = 0;
            int li = i;
            int lj = j;
            int limit = Math.min(j - i, n - j);

            for (int ki = k-1 ; ki >= 0 ; ki--) {
                if (levelRank[ki] == null || limit < (1<<ki)) {
                    continue;
                }
                if (levelRank[ki][li] == levelRank[ki][lj]) {
                    cnt += 1<<ki;
                    li += 1<<ki;
                    lj += 1<<ki;
                }
            }
            return cnt;
        }
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
}