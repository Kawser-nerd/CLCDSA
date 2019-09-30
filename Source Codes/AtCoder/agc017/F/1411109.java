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

    private static final int MOD = (int) (1e9 + 7);

    private void solve() throws IOException {
        int n = nextInt() - 1;
        int m = nextInt();
        int k = nextInt();
        int[][] cc = new int[m][n];
        for (int i = 0; i < k; i++) {
            cc[nextInt() - 1][nextInt() - 1] = nextInt() + 1;
        }
        int[][] d = new int[n + 1][1 << n];
        d[0][0] = 1;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                Arrays.fill(d[j + 1], 0);
                for (int x = 0; x < (1 << n); x++) {
                    if (d[j][x] > 0) {
                        int y = (x >> j) & 1;
                        if (cc[i][j] != 2 && y == 0) {
                            d[j + 1][x] += d[j][x];
                            if (d[j + 1][x] >= MOD) {
                                d[j + 1][x] -= MOD;
                            }
                        }
                        if (cc[i][j] != 1) {
                            int xx = y == 1 ? x : (x - (1 << j)) & x + (1 << j);
                            d[j + 1][xx] += d[j][x];
                            if (d[j + 1][xx] >= MOD) {
                                d[j + 1][xx] -= MOD;
                            }
                        }
                    }
                }
            }
            for (int x = 0; x < (1 << n); x++) {
                d[0][x] = d[n][x];
            }
        }
        int res = 0;
        for (int x = 0; x < (1 << n); x++) {
            res += d[0][x];
            if (res >= MOD) {
                res -= MOD;
            }
        }
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