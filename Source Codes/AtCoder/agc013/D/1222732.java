import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

/**
 * @author Pavel Mavrin
 */
public class Main {

    private long MOD = (long) (1e9 + 7);

    private void solve() throws IOException {

        int n = nextInt();
        int m = nextInt();
        long[][] d = new long[2][n];
        long[][] dd = new long[2][n];
        Arrays.fill(d[0], 1);
        d[0][0] = 0;
        d[1][0] = 1;
        for (int i = 0; i < m - 1; i++) {
            Arrays.fill(dd[0], 0);
            Arrays.fill(dd[1], 0);

            for (int j = 0; j < n; j++) {
                for (int k = 0; k < 2; k++) {
                    dd[k][j] += 2 * d[k][j];
                    if (j > 0) {
                        dd[j - 1 == 0 ? 1 : k][j - 1] += d[k][j];
                    }
                    if (j < n - 1) {
                        dd[k][j + 1] += d[k][j];
                    }
                }
            }

            for (int j = 0; j < n; j++) {
                dd[0][j] %= MOD;
                dd[1][j] %= MOD;
            }

            long[][] t = d; d = dd; dd = t;
        }
        long res = 0;
        for (int i = 0; i < n; i++) {
            res += d[1][i];
            res %= MOD;
        }
        res *= 4;
        res %= MOD;
        out.println(res);
    }

    // ------------------

    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st;
    PrintWriter out = new PrintWriter(System.out);

    String next() throws IOException {
        while (st == null || !st.hasMoreTokens()) {
            st = new StringTokenizer(br.readLine());
        }
        return st.nextToken();
    }

    int nextInt() throws IOException {
        return Integer.parseInt(next());
    }

    public static void main(String[] args) throws IOException {
        new Main().run();
    }

    private void run() throws IOException {
        solve();
        out.close();
    }

}