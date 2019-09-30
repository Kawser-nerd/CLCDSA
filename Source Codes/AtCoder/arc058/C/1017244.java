import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class Main {

    static BufferedReader in;
    static PrintWriter out;
    static StringTokenizer tok;

    void solve() throws IOException {
        n = ni();
        x = ni();
        y = ni();
        z = ni();

        dp = new long[n][1 << (x + y + z - 1)];
        mask = (1 << (x + y + z - 1)) - 1;

        long pow10 = 1;
        for (int i = 0; i < n; i++) {
            pow10 = (pow10 * 10) % MOD;
        }

        out.println((pow10 - rec(0, 0) + MOD) % MOD);
    }

    int n, x, y, z;
    long[][] dp;
    int mask;
    long MOD = (long) 1e9 + 7;

    long rec(int i, int state) {
        if (i == n) return 1;
        if (dp[i][state] > 0) return dp[i][state];

        long ret = 0;
        for (int j = 1; j <= 10; j++) {
            int t = state << j | 1 << (j - 1);
            if ((t >> (z - 1) & 1) == 0 || (t >> (y + z - 1) & 1) == 0 || (t >> (x + y + z - 1) & 1) == 0) {
                ret = (ret + rec(i + 1, t & mask)) % MOD;
            }
        }

        return dp[i][state] = ret;
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