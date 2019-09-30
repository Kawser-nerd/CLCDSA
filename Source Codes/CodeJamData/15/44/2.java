
import java.io.*;
import java.math.BigInteger;
import java.util.StringTokenizer;

public class D2 {


    private int n;
    private int m;
    private int[][] a;
    double res;
    private long MOD = (long) (1e9 + 7);

    private int solveTest() throws IOException {
        n = nextInt();
        m = nextInt();
        long[][] d = new long[n + 1][13];
        d[0][1] = 1;
        for (int i = 0; i < n; i++) {
            for (int j = 1; j <= 12; j++) if (d[i][j] > 0) {
                if (i == 0 && n >= 2) {
                    // 3
                    d[i + 2][j] += d[i][j];
                    d[i + 2][j] %= MOD;
                }
                // 2
                if (i + 1 == n) {
                    d[i + 1][j] += d[i][j];
                    d[i + 1][j] %= MOD;
                }
                if (i + 3 <= n) {
                    d[i + 3][j] += d[i][j];
                    d[i + 3][j] %= MOD;
                }
                // 221
                int jj = lcm(j, 3);
                if (m % jj == 0 && i + 2 == n) {
                    d[i + 2][jj] += d[i][j] * 3;
                    d[i + 2][jj] %= MOD;
                }
                if (m % jj == 0 && i + 4 <= n) {
                    d[i + 4][jj] += d[i][j] * 3;
                    d[i + 4][jj] %= MOD;
                }
                // 222112
                jj = lcm(j, 6);
                if (m % jj == 0 && i + 2 == n) {
                    d[i + 2][jj] += d[i][j] * 6;
                    d[i + 2][jj] %= MOD;
                }
                if (m % jj == 0 && i + 4 <= n) {
                    d[i + 4][jj] += d[i][j] * 6;
                    d[i + 4][jj] %= MOD;
                }
                // 2221
                jj = lcm(j, 4);
                if (m % jj == 0 && i + 3 == n) {
                    d[i + 3][jj] += d[i][j] * 4;
                    d[i + 3][jj] %= MOD;
                }
                if (m % jj == 0 && i + 5 <= n) {
                    d[i + 5][jj] += d[i][j] * 4;
                    d[i + 5][jj] %= MOD;
                }
            }
        }
        long res = 0;
        for (int i = 1; i <= 12; i++) if (d[n][i] > 0) {
//            System.out.println(d[n][i] + " " + i);
            res += d[n][i] * BigInteger.valueOf(i).modInverse(BigInteger.valueOf(MOD)).longValue() % MOD;
            res %= MOD;
        }
        return (int) res;
    }

    private int lcm(int a, int b) {
        int res = 1;
        while (res % a > 0 || res % b > 0) res++;
        return res;
    }

    private void bt(int i, int j) {
        if (j == m) {
            i++;
            j = 0;
        }
        if (i == n) {
            for (i = 0; i < n; i++) {
                for (j = 0; j < m; j++) {
                    int r = 0;
                    if (i > 0 && a[i - 1][j] == a[i][j]) r++;
                    if (i < n - 1 && a[i + 1][j] == a[i][j]) r++;
                    if (a[i][(j + 1) % m] == a[i][j]) r++;
                    if (a[i][(j + m - 1) % m] == a[i][j]) r++;
                    if (a[i][j] != r) return;
                }
            }
            int c = 0;
            for (int w = 0; w < m; w++) {
                boolean ok = true;
                for (i = 0; i < n; i++) {
                    for (j = 0; j < m; j++) {
                        if (a[i][j] != a[i][(j+w)%m]) ok = false;
                    }
                }
                if (ok) c++;
            }
//            for (i = 0; i < n; i++) {
//                for (j = 0; j < m; j++) {
//                    System.out.print(a[i][j]);
//                }
//                System.out.println();
//            }
//            System.out.println();
            res += 1.0 * c / m;
            return;
        }
        for (a[i][j] = 1; a[i][j] <= 3; a[i][j]++) {
            if (i > 0) {
                if (!check(a, i - 1, j)) continue;
            }
            bt(i, j + 1);
        }
    }

    private boolean check(int[][] a, int i, int j) {
        int r = 0;
        if (i > 0 && a[i - 1][j] == a[i][j]) r++;
        if (i < n - 1 && a[i + 1][j] == a[i][j]) r++;
        if (a[i][(j + 1) % m] == a[i][j]) r++;
        if (a[i][(j + m - 1) % m] == a[i][j]) r++;
        return  (a[i][j] == r);
    }

    private void solve() throws IOException {
        int n = nextInt();
        for (int i = 0; i < n; i++) {
            int res = solveTest();
            System.out.println("Case #" + (i + 1) + ": " + res);
            out.println("Case #" + (i + 1) + ": " + res);
        }
    }


    BufferedReader br;
    StringTokenizer st;
    PrintWriter out;

    String next() throws IOException {
        while (st == null || !st.hasMoreTokens()) {
            st = new StringTokenizer(br.readLine());
        }
        return st.nextToken();
    }

    int nextInt() throws IOException {
        return Integer.parseInt(next());
    }

    public static void main(String[] args) throws FileNotFoundException {
        new D2().run();
    }

    private void run() throws FileNotFoundException {
        br = new BufferedReader(new FileReader(this.getClass().getSimpleName().substring(0, 1) + ".in"));
        out = new PrintWriter(this.getClass().getSimpleName().substring(0, 1) + ".out");
        try {
            solve();
        } catch (IOException e) {
            e.printStackTrace();
        }
        out.close();
    }

}