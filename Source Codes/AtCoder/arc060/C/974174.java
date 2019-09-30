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
        int n = ni();
        int[] x = nia(n);

        int l = ni();
        int q = ni();
        int[] a = new int[q];
        int[] b = new int[q];
        for (int i = 0; i < q; i++) {
            a[i] = ni() - 1;
            b[i] = ni() - 1;
        }

        int[][] dp = new int[n][20];
        int can = 0;
        for (int i = 0; i < n; i++) {
            while (can < n - 1 && x[can + 1] - x[i] <= l) can++;
            dp[i][0] = can;
        }
        for (int i = 1; i < 20; i++) {
            for (int j = 0; j < n; j++) {
                dp[j][i] = dp[dp[j][i - 1]][i - 1];
            }
        }

        for (int i = 0; i < q; i++) {
            if (a[i] > b[i]) {
                int tmp = a[i];
                a[i] = b[i];
                b[i] = tmp;
            }

            int high = 100000;
            int low = 0;
            while (high - low > 1) {
                int mid = (high + low) / 2;
                int now = a[i];
                int t = 0;
                int tmp = mid;
                while (tmp > 0) {
                    if (tmp % 2 == 1) {
                        now = dp[now][t];
                    }
                    tmp >>= 1;
                    t++;
                }
                if (now >= b[i]) {
                    high = mid;
                } else {
                    low = mid;
                }
            }

            out.println(high);
        }
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