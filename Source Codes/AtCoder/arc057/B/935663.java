import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {

    static BufferedReader in;
    static PrintWriter out;
    static StringTokenizer tok;

    int INF = Integer.MAX_VALUE / 3;

    void solve() throws IOException {
        int n = ni();
        int k = ni();
        long[] a = nla(n);

        long tmp = 0;
        long[] sum = new long[n + 1];
        for (int i = 0; i < n; i++) {
            tmp += a[i];
            sum[i + 1] = tmp;
        }

        if (tmp == k) {
            out.println(1);
            return;
        }

        long[][] dp = new long[n + 1][n + 1];
        for (int i = 0; i <= n; i++) {
            Arrays.fill(dp[i], INF);
        }
        dp[0][0] = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dp[i][j] == INF) continue;

                dp[i + 1][j] = Math.min(dp[i + 1][j], dp[i][j]);

                long need = sum[i] == 0 ? 1 : (a[i] * dp[i][j] / sum[i] + 1);
                if (need <= a[i]) {
                    dp[i + 1][j + 1] = Math.min(dp[i + 1][j + 1], dp[i][j] + need);
                }
            }
        }

        int ans = 0;
        for (int i = 0; i <= n; i++) {
            if (dp[n][i] <= k) ans = i;
        }

        out.println(ans);
    }

    String ns() throws IOException {
        while (!tok.hasMoreTokens()) {
            tok = new StringTokenizer(in.readLine(), " ");
        }
        return tok.nextToken();
    }

    int ni() throws IOException {
        return Integer.parseInt(ns());
    }

    long nl() throws IOException {
        return Long.parseLong(ns());
    }

    double nd() throws IOException {
        return Double.parseDouble(ns());
    }

    String[] nsa(int n) throws IOException {
        String[] res = new String[n];
        for (int i = 0; i < n; i++) {
            res[i] = ns();
        }
        return res;
    }

    int[] nia(int n) throws IOException {
        int[] res = new int[n];
        for (int i = 0; i < n; i++) {
            res[i] = ni();
        }
        return res;
    }

    long[] nla(int n) throws IOException {
        long[] res = new long[n];
        for (int i = 0; i < n; i++) {
            res[i] = nl();
        }
        return res;
    }

    public static void main(String[] args) throws IOException {
        in = new BufferedReader(new InputStreamReader(System.in));
        out = new PrintWriter(System.out);
        tok = new StringTokenizer("");
        Main main = new Main();
        main.solve();
        out.close();
    }
}