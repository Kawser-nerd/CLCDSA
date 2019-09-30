import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

/**
 * @author Pavel Mavrin
 */
public class Main {

    private long MOD = (long) (1e9 + 7);

    private void solve() throws IOException {
        int n = nextInt();
        long[] a = new long[2];
        a[0] = nextLong();
        a[1] = nextLong();
        long[] x = new long[n];
        for (int i = 0; i < n; i++) {
            x[i] = nextLong();
        }
        int[][] d = new int[2][n];
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < n; j++) {
                if (j > 0 && x[j] >= x[j - 1] + a[i]) {
                    d[i][j] = d[i][j - 1] + 1;
                }
            }
        }
        long[][] e = new long[2][n];
        int[] l = new int[2];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 2; j++) {
                while (x[l[j]] <= x[i] - a[j]) l[j]++;
                if (l[j] == i) {
                    if (l[j] == 0) {
                        e[j][i]++;
                    } else {
                        e[j][i] += e[0][i - 1] + e[1][i - 1];
                    }
                } else {
                    if (d[1 - j][i - 1] >= i - l[j] - 1) {
                        e[j][i] += e[1 - j][l[j]];
                    }
                }
                e[j][i] %= MOD;
//                System.out.println(i + " " + j + " " + e[j][i]);
            }
        }
        out.println((e[0][n - 1] + e[1][n - 1]) % MOD);
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

    long nextLong() throws IOException {
        return Long.parseLong(next());
    }

    public static void main(String[] args) throws IOException {
        new Main().run();
    }

    private void run() throws IOException {
        solve();
        out.close();
    }

}