import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Deque;
import java.util.InputMismatchException;
import java.util.List;
import java.util.Queue;

public class Main {
    InputStream is;

    int __t__ = 1;
    int __f__ = 0;
    int __FILE_DEBUG_FLAG__ = __f__;
    String __DEBUG_FILE_NAME__ = "src/D1";

    FastScanner in;
    PrintWriter out;

    public void solve() {
        int K = in.nextInt();
        int res1 = solve1(K);
        int res2 = solve2(K);
        System.out.println(res2);
    }

    private int solve2(int K) {
        Deque<Integer> q = new ArrayDeque<>();
        q.add(1);
        int[] cost = new int[K];
        Arrays.fill(cost, Integer.MAX_VALUE);
        cost[1] = 1;
        while (!q.isEmpty()) {
            int u = q.poll();
            int one = (u + 1) % K;
            int ten = (u * 10) % K;
            if (cost[u] + 1 < cost[one]) {
                cost[one] = cost[u] + 1;
                q.addLast(one);
            }
            if (cost[u] < cost[ten]) {
                cost[ten] = cost[u];
                q.addFirst(ten);
            }
        }
        return cost[0];
    }

    // WA, s?50??????
    private int solve1(int K) {
        int s = 50;
        int[] ten = new int[s];
        ten[0] = 1;
        for (int i = 1; i < s; i++) {
            ten[i] = (ten[i-1] * 10) % K;
        }

        int[][][] dp = new int[2][s+1][K];
        for (int i = 0; i <= s; i++) {
            Arrays.fill(dp[0][i], Integer.MAX_VALUE);
            Arrays.fill(dp[1][i], Integer.MAX_VALUE);
        }
        dp[0][0][0] = 0;

        for (int i = 0; i < s; i++) {
            for (int k = 0; k < K; k++) {
                for (int d = 0; d < 10; d++) {
                    int nk = (k + ten[i] * d) % K;
                    if (dp[0][i][k] != Integer.MAX_VALUE) {
                        dp[0][i+1][nk] = Math.min(dp[0][i+1][nk], dp[0][i][k] + d);
                        if (d != 0) {
                            dp[1][i+1][nk] = Math.min(dp[1][i+1][nk], dp[0][i][k] + d);
                        }
                    }
                    if (dp[1][i][k] != Integer.MAX_VALUE) {
                        dp[1][i+1][nk] = Math.min(dp[1][i+1][nk], dp[1][i][k] + d);
                    }
                }
            }
        }
        return dp[1][s][0];
    }

    public void run() {
        if (__FILE_DEBUG_FLAG__ == __t__) {
            try {
                is = new FileInputStream(__DEBUG_FILE_NAME__);
            } catch (FileNotFoundException e) {
                // TODO ??????? catch ????
                e.printStackTrace();
            }
            System.out.println("FILE_INPUT!");
        } else {
            is = System.in;
        }
        in = new FastScanner(is);
        out = new PrintWriter(System.out);

        solve();
    }

    public static void main(final String[] args) {
        new Main().run();
    }

    class FastScanner {
        private InputStream stream;
        private byte[] buf = new byte[1024];
        private int curChar;
        private int numChars;

        public FastScanner(InputStream stream) {
            this.stream = stream;
            // stream = new FileInputStream(new File("dec.in"));

        }

        int read() {
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

        boolean isSpaceChar(int c) {
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
        }

        boolean isEndline(int c) {
            return c == '\n' || c == '\r' || c == -1;
        }

        int nextInt() {
            return Integer.parseInt(next());
        }

        int[] nextIntArray(int n) {
            int[] array = new int[n];
            for (int i = 0; i < n; i++)
                array[i] = nextInt();

            return array;
        }

        int[][] nextIntMap(int n, int m) {
            int[][] map = new int[n][m];
            for (int i = 0; i < n; i++) {
                map[i] = in.nextIntArray(m);
            }
            return map;
        }

        long nextLong() {
            return Long.parseLong(next());
        }

        long[] nextLongArray(int n) {
            long[] array = new long[n];
            for (int i = 0; i < n; i++)
                array[i] = nextLong();

            return array;
        }

        long[][] nextLongMap(int n, int m) {
            long[][] map = new long[n][m];
            for (int i = 0; i < n; i++) {
                map[i] = in.nextLongArray(m);
            }
            return map;
        }

        double nextDouble() {
            return Double.parseDouble(next());
        }

        double[] nextDoubleArray(int n) {
            double[] array = new double[n];
            for (int i = 0; i < n; i++)
                array[i] = nextDouble();

            return array;
        }

        double[][] nextDoubleMap(int n, int m) {
            double[][] map = new double[n][m];
            for (int i = 0; i < n; i++) {
                map[i] = in.nextDoubleArray(m);
            }
            return map;
        }

        String next() {
            int c = read();
            while (isSpaceChar(c))
                c = read();
            StringBuilder res = new StringBuilder();
            do {
                res.appendCodePoint(c);
                c = read();
            } while (!isSpaceChar(c));
            return res.toString();
        }

        String[] nextStringArray(int n) {
            String[] array = new String[n];
            for (int i = 0; i < n; i++)
                array[i] = next();

            return array;
        }

        String nextLine() {
            int c = read();
            while (isEndline(c))
                c = read();
            StringBuilder res = new StringBuilder();
            do {
                res.appendCodePoint(c);
                c = read();
            } while (!isEndline(c));
            return res.toString();
        }
    }
}