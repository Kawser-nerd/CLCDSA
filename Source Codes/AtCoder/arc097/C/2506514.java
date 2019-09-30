import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 *
 * @author kessido
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        ESortedAndSorted solver = new ESortedAndSorted();
        solver.solve(1, in, out);
        out.close();
    }

    static class ESortedAndSorted {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.NextInt();
            int[] balls = new int[2 * n];
            for (int i = 0; i < 2 * n; i++) {
                if (in.next().charAt(0) == 'W') balls[i] = -in.NextInt();
                else balls[i] = in.NextInt();
            }
            int[][] dp = new int[n + 1][n + 1];
            for (int[] dpp : dp) Arrays.fill(dpp, (2 * n) * (2 * n) * 10);
            int[][][] cost = new int[2][n + 1][n + 1];
            boolean[][] saw = new boolean[2][n];
            dp[0][0] = 0;
            for (int i = 0; i < n * 2; i++) {
                int curr = balls[i];
                int par = balls[i] < 0 ? 0 : 1;
                curr = Math.abs(curr) - 1;
                int sum = 0;
                for (int j = curr + 1; j < n; j++) {
                    if (saw[par][j]) {
                        sum++;
                    }
                }
                cost[par][curr + 1][n] = sum;
                for (int j = n - 1; j >= 0; j--) {
                    if (saw[par ^ 1][j])
                        sum++;
                    cost[par][curr + 1][j] = sum;
                }
                saw[par][curr] = true;
            }
            for (int i = 0; i <= n; i++) {
                for (int j = 0; j <= n; j++) {
                    if (i != 0) dp[i][j] = Math.min(dp[i][j], dp[i - 1][j] + cost[0][i][j]);
                    if (j != 0) dp[i][j] = Math.min(dp[i][j], dp[i][j - 1] + cost[1][j][i]);
                }
            }
            out.println(dp[n][n]);
        }

    }

    static class InputReader {
        BufferedReader reader;
        StringTokenizer tokenizer;

        public InputReader(InputStream stream) {
            reader = new BufferedReader(new InputStreamReader(stream), 32768);
            tokenizer = null;
        }

        public String next() {
            while (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    tokenizer = new StringTokenizer(reader.readLine(), " \t\n\r\f,");
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
            return tokenizer.nextToken();
        }

        public int NextInt() {
            return Integer.parseInt(next());
        }

    }
}