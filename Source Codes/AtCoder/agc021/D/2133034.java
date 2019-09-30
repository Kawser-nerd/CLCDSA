import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.StringTokenizer;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        TaskD solver = new TaskD();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskD {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            String T = in.next();
            int N = T.length();
            int K = in.nextInt();

            int[][][] dp = new int[N][N][K + 1];

            for (int right = 0; right < N; right++) {
                for (int left = right; left >= 0; left--) {
                    if (left == right) {
                        dp[left][right][0] = 1;
                    } else {
                        for (int k = 0; k <= K; k++) {
                            dp[left][right][k] = Math.max(dp[left + 1][right][k], dp[left][right - 1][k]);
                            if (T.charAt(left) == T.charAt(right)) {
                                dp[left][right][k] = Math.max(dp[left][right][k], 2 + dp[left + 1][right - 1][k]);
                            } else if (k > 0) {
                                dp[left][right][k] = Math.max(dp[left][right][k], 2 + dp[left + 1][right - 1][k - 1]);
                            }
                        }
                    }
                }
            }
            int best = 0;
            for (int k = 0; k <= K; k++) {
                best = Math.max(best, dp[0][N - 1][k]);
            }
            out.println(best);
        }

    }

    static class InputReader {
        public BufferedReader reader;
        public StringTokenizer tokenizer;

        public InputReader(InputStream stream) {
            reader = new BufferedReader(new InputStreamReader(stream), 32768);
            tokenizer = null;
        }

        public String next() {
            while (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    tokenizer = new StringTokenizer(reader.readLine());
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
            return tokenizer.nextToken();
        }

        public int nextInt() {
            return Integer.parseInt(next());
        }

    }
}