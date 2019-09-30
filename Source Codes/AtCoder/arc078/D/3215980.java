import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class Main {
    static long __startTime = System.currentTimeMillis();

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
            int c = in.nextInt();
            graph[a][b] = graph[b][a] = c;
        }

        int[] costTable = new int[1<<n];
        for (int p = 0; p < (1<<n) ; p++) {
            for (int i = 0; i < n ; i++) {
                if ((p & (1<<i)) >= 1) {
                    for (int j = i+1; j < n ; j++) {
                        if ((p & (1<<j)) >= 1) {
                            if (graph[i][j] != -1) {
                                costTable[p] += graph[i][j];
                            }
                        }
                    }
                }
            }
        }

        int[][] dp = new int[n][1<<n];
        for (int i = 0; i < n ; i++) {
            Arrays.fill(dp[i], -1);
        }
        dp[0][1] = 0;
        
        int ALL = (1<<(n-1))-1;
        for (int p = 1 ; p <= ALL ; p++) {
            for (int now = 0; now < n-1 ; now++) {
                int base = dp[now][p];
                if (base == -1) {
                    continue;
                }
                int lp = ALL-p;
                for (int q = lp ; q >= 0 ; q = (q-1) & lp) {
                    int cost = costTable[q|(1<<now)];
                    for (int next = 0; next < n ; next++) {
                        int tp = p|q;
                        if ((tp&(1<<next)) >= 1 || graph[now][next] == -1) {
                            continue;
                        }
                        tp |= (1<<next);
                        dp[next][tp] = Math.max(dp[next][tp], base+cost+graph[now][next]);
                    }
                    if (q == 0) {
                        break;
                    }
                }
            }
        }


        int all = 0;
        for (int i = 0; i < n ; i++) {
            for (int j = i+1 ; j < n ; j++) {
                if (graph[i][j] != -1) {
                    all += graph[i][j];
                }
            }
        }


        int best = 0;
        for (int i = 0; i < (1<<n); i++) {
            int base = dp[n-1][i];
            if (base == -1) {
                continue;
            }
            int left = (1<<n)-1-i;
            best = Math.max(best, base+costTable[left|(1<<(n-1))]);
        }
        out.println(all-best);
        out.flush();
    }

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
}