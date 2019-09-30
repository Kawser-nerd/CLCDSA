import java.io.*;
import java.util.*;

public class Main {
    static void update(int[][] dp, int i, int j, int val) {
        dp[i][j] = Math.max(dp[i][j], val);
    }
    
    public static void main(String[] args) throws Exception {
        FastScanner scan = new FastScanner(System.in);
        int taskCount = scan.nextInt();
        for (int taskIndex = 1; taskIndex <= taskCount; ++taskIndex) {
            int P = scan.nextInt();
            int Q = scan.nextInt();
            int N = scan.nextInt();
            int[] life = new int[N];
            int[] gold = new int[N];
            for (int i = 0; i < N; ++i) {
                life[i] = scan.nextInt();
                gold[i] = scan.nextInt();
            }
            int total = N * 10 + 10;
            int[][] dp = new int[N + 1][total];
            for (int[] arr : dp) {
                Arrays.fill(arr, -1);
            }
            dp[0][1] = 0;
            for (int i = 0; i < N; ++i) {
                for (int j = 0; j < total; ++j) {
                    if (dp[i][j] == -1) {
                        continue;
                    }
                    for (int k = 0; k < 20; ++k) {
                        int left = life[i] - k * Q;
                        if (left <= 0) {
                            update(dp, i + 1, j + k, dp[i][j]);
                            break;
                        }
                        int require = left / P + (left % P == 0 ? 0 : 1);
                        if (j + k >= require) {
                            update(dp, i + 1, j + k - require, dp[i][j] + gold[i]);
                        }
                    }
                }
            }
            int res = 0;
            for (int i = 0; i < total; ++i) {
                res = Math.max(res, dp[N][i]);
            }
            System.out.println(String.format("Case #%d: %d", taskIndex, res));
        }
    }
}

class FastScanner {
    BufferedReader in;
    StringTokenizer tok;

    public FastScanner(InputStream in) {
        this.in = new BufferedReader(new InputStreamReader(in));
        tok = new StringTokenizer("");
    }

    private String tryReadNextLine() {
        try {
            return in.readLine();
        } catch (Exception e) {
            throw new InputMismatchException();
        }
    }

    public String nextToken() {
        while (!tok.hasMoreTokens()) {
            tok = new StringTokenizer(next());
        }
        return tok.nextToken();
    }

    private String next() {
        String newLine = tryReadNextLine();
        if (newLine == null)
            throw new InputMismatchException();
        return newLine;
    }

    public int nextInt() {
        return Integer.parseInt(nextToken());
    }
    
    public double nextDouble() {
        return Double.parseDouble(nextToken());
    }

    public long nextLong() {
        return Long.parseLong(nextToken());
    }

}
