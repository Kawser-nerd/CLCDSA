import java.io.*;
import java.util.*;

public class Main {
    FastScanner in;
    PrintWriter out;


    void solve() {
        char[] s = in.next().toCharArray();
        int n = s.length;
        int maxChange = in.nextInt();
        int[][][] dp = new int[maxChange + 2][n][n];
        for (int i = 0; i < n; i++) {
            dp[0][i][i] = 1;
            if (i + 1 < n) {
                if (s[i] == s[i + 1]) {
                    dp[0][i][i + 1] = 2;
                } else {
                    dp[1][i][i + 1] = 2;
                }
            }
        }
        for (int len = 1; len <= n; len++) {
            for (int fr = 0; fr + len <= n; fr++) {
                int to = fr + len - 1;
                for (int ch = 0; ch <= maxChange; ch++) {
                    int cur = dp[ch][fr][to];
                    if (fr > 0) {
                        dp[ch][fr - 1][to] = Math.max(dp[ch][fr - 1][to], cur);
                    }
                    if (to + 1 < n) {
                        dp[ch][fr][to + 1] = Math.max(dp[ch][fr][to + 1], cur);
                    }
                    if (fr > 0 && to + 1 < n) {
                        if (s[fr - 1] == s[to + 1]) {
                            dp[ch][fr - 1][to + 1] = Math.max(dp[ch][fr - 1][to + 1], cur + 2);
                        } else {
                            dp[ch + 1][fr - 1][to + 1] = Math.max(dp[ch + 1][fr - 1][to + 1], cur + 2);
                        }
                    }
                }
            }
        }
        int res = 0;
        for (int ch = 0; ch <= maxChange; ch++) {
            res = Math.max(res, dp[ch][0][n - 1]);
        }
        out.println(res);
    }


    void run() {
        try {
            in = new FastScanner(new File("Main.in"));
            out = new PrintWriter(new File("Main.out"));

            solve();

            out.close();
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }
    }

    void runIO() {

        in = new FastScanner(System.in);
        out = new PrintWriter(System.out);

        solve();

        out.close();
    }

    class FastScanner {
        BufferedReader br;
        StringTokenizer st;

        public FastScanner(File f) {
            try {
                br = new BufferedReader(new FileReader(f));
            } catch (FileNotFoundException e) {
                e.printStackTrace();
            }
        }

        public FastScanner(InputStream f) {
            br = new BufferedReader(new InputStreamReader(f));
        }

        String next() {
            while (st == null || !st.hasMoreTokens()) {
                String s = null;
                try {
                    s = br.readLine();
                } catch (IOException e) {
                    e.printStackTrace();
                }
                if (s == null)
                    return null;
                st = new StringTokenizer(s);
            }
            return st.nextToken();
        }

        boolean hasMoreTokens() {
            while (st == null || !st.hasMoreTokens()) {
                String s = null;
                try {
                    s = br.readLine();
                } catch (IOException e) {
                    e.printStackTrace();
                }
                if (s == null)
                    return false;
                st = new StringTokenizer(s);
            }
            return true;
        }

        int nextInt() {
            return Integer.parseInt(next());
        }

        long nextLong() {
            return Long.parseLong(next());
        }

        double nextDouble() {
            return Double.parseDouble(next());
        }
    }

    public static void main(String[] args) {
        new Main().runIO();
    }
}