import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.List;

public class Main {
    static long __startTime = System.currentTimeMillis();

    public static void main(String[] args) {
        InputReader in = new InputReader(System.in);
        PrintWriter out = new PrintWriter(System.out);

        int n = in.nextInt();
        graph = new List[n];
        for (int i = 0; i < n ; i++) {
            graph[i] = new ArrayList<>();
        }
        for (int i = 1 ; i < n ; i++) {
            int p = in.nextInt()-1;
            graph[p].add(i);
        }
        int[] x = new int[n];
        for (int i = 0; i < n ; i++) {
            x[i] = in.nextInt();
        }


        boolean ok = true;
        int[] dp = new int[n];

        int[][] flag = new int[2][5010];
        for (int i = n-1 ; i >= 0 ; i--) {
            if (graph[i].size() == 0) {
                dp[i] = x[i];
                continue;
            }
            int cn = graph[i].size();
            Arrays.fill(flag[0], 0);
            flag[0][0] = 1;
            for (int j = 0 ; j < cn ; j++) {
                int cid = graph[i].get(j);
                int[] LR = {dp[cid]-x[cid], x[cid]};
                int fr = j % 2;
                int to = 1 - fr;
                Arrays.fill(flag[to], 0);
                for (int u = 0 ; u < flag[0].length ; u++) {
                    if (flag[fr][u] == 1) {
                        for (int l : LR) {
                            if (u+l < flag[0].length) {
                                flag[to][u+l] = 1;
                            }
                        }
                    }
                }
            }

            dp[i] = -1;
            for (int v = x[i] ; v >= 0 ; v--) {
                if (flag[cn%2][v] == 1) {
                    dp[i] = x[i] - v;
                    break;
                }
            }
            if (dp[i] == -1) {
                ok = false;
                break;
            }

            for (int j : graph[i]) {
                dp[i] += dp[j];
            }
        }

        out.println(ok ? "POSSIBLE" : "IMPOSSIBLE");
        out.flush();
    }

    static List<Integer>[] graph;

    private static void printTime(String label) {
        debug(label, System.currentTimeMillis() - __startTime);
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
} Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.