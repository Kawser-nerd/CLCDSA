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
        FastScanner in = new FastScanner(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        TaskD solver = new TaskD();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskD {
        public void solve(int testNumber, FastScanner in, PrintWriter out) {
            String s = in.next();
            int k = in.nextInt();

            int[][][] dp = new int[s.length()][s.length()][k + 1];

            for (int i = s.length() - 1; i >= 0; i--) {
                for (int j = i; j < s.length(); j++) {
                    if (i == j) {
                        dp[i][j][0] = 1;
                    } else {
                        for (int t = 0; t <= k; t++) {
                            dp[i][j][t] = Math.max(dp[i + 1][j][t], dp[i][j - 1][t]);
                            int cost = s.charAt(i) == s.charAt(j) ? 0 : 1;
                            if (t - cost >= 0) {
                                dp[i][j][t] = Math.max(dp[i][j][t], dp[i + 1][j - 1][t - cost] + 2);
                            }
                        }
                    }
                }
            }

            int max = 0;
            for (int t = 0; t <= k; t++) {
                max = Math.max(max, dp[0][s.length() - 1][t]);
            }
            out.println(max);
        }

    }

    static class FastScanner {
        BufferedReader br;
        StringTokenizer st;

        public FastScanner(InputStream in) {
            br = new BufferedReader(new InputStreamReader(in));
        }

        public int nextInt() {
            return Integer.parseInt(next());
        }

        public String next() {
            while (st == null || !st.hasMoreElements()) {
                String line = null;
                try {
                    line = br.readLine();
                } catch (IOException e) {
                }
                st = new StringTokenizer(line);
            }
            return st.nextToken();
        }

    }
}