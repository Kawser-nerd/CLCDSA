import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.*;

public class Main {

    static BufferedReader in;
    static PrintWriter out;
    static StringTokenizer tok;

    void solve() throws IOException {
        n = ni();
        a = new int[n];
        p = new boolean[n - 1];

        dp = new long[2][2][n];

        for (int i = 0; i < n; i++) {
            a[i] = ni();
            if (i < n - 1) p[i] = ns().equals("+");
        }

        dp[0][0][0] = a[0];
        dp[1][0][0] = dp[1][1][0] = dp[0][1][0] = Long.MIN_VALUE / 2;

        for (int i = 1; i < n; i++) {
            if (p[i - 1]) {
                dp[0][0][i] = Math.max(dp[0][0][i - 1] + a[i], dp[0][1][i - 1] + a[i]);
                dp[0][1][i] = dp[0][1][i - 1] - a[i];
                dp[1][0][i] = dp[1][1][i - 1] + a[i];
                dp[1][1][i] = dp[1][1][i - 1] + a[i];

            } else {
                dp[0][0][i] = dp[0][1][i - 1] + a[i];
                dp[0][1][i] = dp[0][0][i - 1] - a[i];
                long ret = Long.MIN_VALUE;
                for (int j = 0; j < 2; j++) {
                    for (int k = 0; k < 2; k++) {
                        if (j == 0 && k == 0) continue;
                        ret = Math.max(ret, dp[j][k][i - 1]);
                    }
                }
                dp[1][0][i] = Math.max(dp[0][1][i - 1] + a[i], ret + a[i]);
                dp[1][1][i] = Math.max(dp[0][1][i - 1] - a[i], ret + a[i]);
            }
        }

        long ans = Long.MIN_VALUE;

        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                ans = Math.max(ans, dp[i][j][n - 1]);
            }
        }

        out.println(ans);
    }

    int n;
    int[] a;
    boolean[] p;
    long[][][] dp;

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