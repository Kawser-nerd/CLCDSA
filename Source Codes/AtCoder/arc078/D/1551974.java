// package arc.arc078;

import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        InputReader in = new InputReader(System.in);
        PrintWriter out = new PrintWriter(System.out);

        int n = in.nextInt();
        int m = in.nextInt();
        int[][] graph = new int[n][n];
        for (int i = 0; i < n ; i++) {
            Arrays.fill(graph[i], -1);
        }
        for (int i = 0; i < m ; i++) {
            int a = in.nextInt()-1;
            int b = in.nextInt()-1;
            graph[a][b] = graph[b][a] = in.nextInt();
        }

        int[] subInner = new int[1<<n];
        int[][] subOuter = new int[1<<n][n];
        for (int p = 0 ; p < (1<<n) ; p++) {
            for (int i = 0; i < n ; i++) {
                if ((p & (1<<i)) >= 1) {
                    for (int j = i+1 ; j < n ; j++) {
                        if ((p & (1<<j)) >= 1 && graph[i][j] >= 1) {
                            subInner[p] += graph[i][j];
                        }
                    }
                    for (int outer = 0 ; outer < n ; outer++) {
                        if (graph[i][outer] >= 1) {
                            subOuter[p][outer] += graph[i][outer];
                        }
                    }
                }
            }
        }

        int best = 0;
        int allExceptGoal = (1<<(n-1))-1;
        int[][] dp = new int[1<<n][n];
        for (int i = 0; i < 1<<n ; i++) {
            Arrays.fill(dp[i], -1);
        }
        for (int p = 0 ; p < (1<<(n-1)) ; p++) {
            if ((p & 1) == 0) {
                continue;
            }
            dp[p][0] = subInner[p^1] + subOuter[p^1][0];
        }
        for (int p = 0 ; p < (1<<(n-1)) ; p++) {
            for (int from = 0; from <= n-2 ; from++) {
                if (dp[p][from] == -1) {
                    continue;
                }
                int base = dp[p][from];

                // go to the goal
                if (graph[from][n-1] >= 0) {
                    int left = ((1<<n)-1) ^ p;
                    int leftExceptGoal = left ^ (1<<(n-1));
                    best = Math.max(best, base + graph[from][n-1] + subInner[leftExceptGoal] + subOuter[leftExceptGoal][n-1]);
                }

                // to next group
                {
                    int left = allExceptGoal^p;
                    for (int sub = left ; sub >= 1 ; sub = (sub - 1) & left) {
                        for (int to = 0; to < n ; to++) {
                            if ((sub & (1<<to)) >= 1 && (p & (1<<to)) == 0 && graph[from][to] >= 1) {
                                int tp = p | sub;
                                int subExceptNext = sub ^ (1<<to);
                                int val = base + graph[from][to] + subInner[subExceptNext] + subOuter[subExceptNext][to];
                                dp[tp][to] = Math.max(dp[tp][to], val);
                            }
                        }
                    }
                }
            }
        }

        int total = 0;
        for (int i = 0; i < n ; i++) {
            for (int j = i+1 ; j < n ; j++) {
                if (graph[i][j] >= 1) {
                    total += graph[i][j];
                }
            }
        }

        out.println(total - best);
        out.flush();
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