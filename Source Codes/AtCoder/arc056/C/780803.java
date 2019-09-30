// package atcoder.arc.arc056;

import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.PriorityQueue;
import java.util.Queue;

/**
 * Created by hama_du on 2016/06/25.
 */
public class Main {
    static int n;
    static int K;
    static int[] memo;
    static int[] rel;

    static int dfs(int ptn) {
        if (memo[ptn] != -1) {
            return memo[ptn];
        }
        int max = K+rel[ptn];
        if (Integer.bitCount(ptn) >= 2) {
//            int head = -1;
//            for (int i = 0; i < n ; i++) {
//                if ((ptn & (1<<i)) >= 1) {
//                    head = i;
//                }
//            }
//            int set = ptn^(1<<head);

            int set = ptn;
            for (int sub = (set-1)&set; sub > 0; sub = (sub-1)&set) {
                max = Math.max(max, dfs(sub)+dfs(ptn-sub));
            }
            memo[ptn] = max;
        }

        return max;
    }

    public static void main(String[] args) {
        InputReader in = new InputReader(System.in);
        PrintWriter out = new PrintWriter(System.out);

        n = in.nextInt();
        K = in.nextInt();
        memo = new int[1<<n];
        Arrays.fill(memo, -1);

        int[][] re = new int[n][n];
        for (int i = 0; i < n ; i++) {
            for (int j = 0; j < n ; j++) {
                re[i][j] = in.nextInt();
            }
        }

        rel = new int[1<<n];
        for (int ptn = 0; ptn < (1<<n) ; ptn++) {
            for (int j = 0; j < n ; j++) {
                if ((ptn & (1<<j)) == 0) {
                    continue;
                }
                for (int k = j+1 ; k < n ; k++) {
                    if ((ptn & (1<<k)) >= 1) {
                        rel[ptn] += re[j][k];
                    }
                }
            }
        }
        out.println(dfs((1<<n)-1)-rel[(1<<n)-1]);
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