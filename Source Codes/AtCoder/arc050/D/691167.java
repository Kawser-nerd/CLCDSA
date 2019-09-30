// package atcoder.arc.arc050;

import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Comparator;
import java.util.InputMismatchException;

/**
 * Created by hama_du on 4/4/16.
 */
public class Main {
    public static void main(String[] args) {
        InputReader in = new InputReader(System.in);
        PrintWriter out = new PrintWriter(System.out);

        in.nextInt();
        char[] cl = in.nextToken().toCharArray();
        SuffixArray sa = new SuffixArray(cl);
        sa.buildSA();
        int[] ans = sa.solve();
        for (int i = 0 ; i < ans.length ; i++) {
            out.println(ans[i]);
        }
        out.flush();
    }

    static class SuffixArray {
        int n;
        char[] base;

        Integer[] sa;
        int[] rank;
        int[] tmp;
        int[] lcp;
        int[][] rankk;

        int compareNode(int i, int j, int k) {
            if (rank[i] != rank[j]) {
                return rank[i] - rank[j];
            } else {
                int ri = i + k <= n ? rank[i+k] : -1;
                int rj = j + k <= n ? rank[j+k] : -1;
                return ri - rj;
            }
        }

        int compareNodeIJ(int i, int j) {
            if (i == j) {
                return 0;
            } else if (i < j) {
                return -compareNodeIJ(j, i);
            } else {
                int hi = i;
                int hj = j;
                int il = n - i;
                int jl = n - j;

                // make sure that il < jl
                int res = compareNodeIJ(i, j, il);
                if (res != 0) {
                    return res;
                }
                res = compareNodeIJ(j, j+il, jl - il);
                if (res != 0) {
                    return res;
                }
                return compareNodeIJ(j+jl-il, i, il);
            }
        }

        int compareNodeIJ(int i, int j, int k) {
            for (int ki = 17 ; ki >= 0 ; ki--) {
                if ((k & (1<<ki)) >= 1) {
                    if (rankk[ki][i] != rankk[ki][j]) {
                        return rankk[ki][i] - rankk[ki][j];
                    }
                    i += 1<<ki;
                    j += 1<<ki;
                }
            }
            return 0;
        }

        public SuffixArray(char[] x) {
            base = x;
            n = base.length;
        }

        void buildSA() {
            sa = new Integer[n+1];
            rank = new int[n+1];
            tmp = new int[n+1];
            rankk = new int[18][];
            for (int i = 0 ; i <= n ; i++) {
                sa[i] = i;
                rank[i] = (i < n) ? base[i] : -1;
            }
            int ki = 0;
            rankk[ki] = rank.clone();
            for (int _k = 1 ; _k <= n ; _k *= 2) {
                ki++;
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
                rankk[ki] = rank.clone();
            }
        }

        int[] solve() {
            Integer[] sas = new Integer[n];
            for (int i = 0; i < n ; i++) {
                sas[i] = i;
            }
            Arrays.sort(sas, this::compareNodeIJ);

            int[] res = new int[n];
            for (int i = 0; i < n ; i++) {
                res[i] = sas[i]+1;
            }
            return res;
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
                res += c-'0';
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