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
 */
public class Main {

    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        BReversi solver = new BReversi();
        solver.solve(1, in, out);
        out.close();
    }

    static class BReversi {

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            int[] a = new int[n];
            for (int i = 0; i < n; i++) {
                a[i] = in.nextInt();
            }
            int[] last = new int[(int) 2e5 + 1];
            Arrays.fill(last, -1);
            long[] dp = new long[n];
            dp[0] = 1;
            last[a[0]] = 0;
            long MOD = (int) 1e9 + 7;
            for (int i = 1; i < n; i++) {
                int l = last[a[i]];
                dp[i] = dp[i - 1];
                if (l != -1 && l != i - 1) {
                    dp[i] = (dp[i] + dp[l]) % MOD;
                }
                last[a[i]] = i;
            }
            out.println(dp[n - 1]);
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