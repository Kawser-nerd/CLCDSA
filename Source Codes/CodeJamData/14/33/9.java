import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class Solution {
    BufferedReader in;
    PrintWriter out;
    StringTokenizer st;

    String nextToken() throws IOException {
        while (st == null || !st.hasMoreTokens()) {
            st = new StringTokenizer(in.readLine());
        }
        return st.nextToken();
    }
    int nextInt() throws IOException {
        return Integer.parseInt(nextToken());
    }
    long nextLong() throws IOException {
        return Long.parseLong(nextToken());
    }
    double nextDouble() throws IOException {
        return Double.parseDouble(nextToken());
    }

    int resdfs = 2;

    void dfs(int[][] a, int[][] w, int i, int j) {
        if (w[i][j] != 0) {
            resdfs = w[i][j];
            return;
        }
        int[] dx = {-1, 0, 1, 0};
        int[] dy = {0, -1, 0, 1};
        int n = a.length;
        int m = a[0].length;
        w[i][j] = 3;
        if (i == 0 || i == n - 1 || j == 0 || j == m - 1) resdfs = 1;
        for (int d = 0; d < 4; d++) {
            int ni = i + dx[d];
            int nj = j + dy[d];
            if (ni < 0 || ni >= n || nj < 0 || nj >= m) continue;
            if (a[ni][nj] == 0 && w[ni][nj] == 0) {
                dfs(a, w, ni, nj);
            }
        }
    }

    void paint(int[][] w, int q) {
        for (int i = 0; i < w.length; i++) {
            for (int j = 0; j < w[i].length; j++) {
                if (w[i][j] == 3) w[i][j] = q;
            }
        }
    }

    boolean valid(int[][] a, int k) {
        int n = a.length;
        int m = a[0].length;
        int[][] w = new int[n][m];
        int q = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (a[i][j] == 0) {
                    resdfs = 2;
                    dfs(a, w, i, j);
                    paint(w, resdfs);
                    if (resdfs == 2) q++;
                } else q++;
            }
        }
        return q >= k;
    }

    void solve() throws IOException {
        int n = nextInt();
        int m = nextInt();
        int k = nextInt();
        int[][] a = new int[n][m];
        int ans = Integer.MAX_VALUE;
        for (int q = 0; q < (1 << (n * m)); q++) {
            int qq = 0;
            for (int i = 0; i < n * m; i++) {
                if ((q & (1 << i)) != 0) {
                    a[i / m][i % m] = 1;
                    qq++;
                } else a[i / m][i % m] = 0;
            }
            if (valid(a, k)) {
                ans = Math.min(ans, qq);
            }
        }
        out.println(ans);
    }

    void run() {
        try {
            in = new BufferedReader(new FileReader("input.txt"));
            out = new PrintWriter("output.txt");
            //in = new BufferedReader(new InputStreamReader(System.in));
            //out = new PrintWriter(System.out);
            Locale.setDefault(Locale.UK);
            int tt = nextInt();
            for (int t = 1; t <= tt; t++) {
                out.print("Case #" + t + ": ");
                System.err.println("Case " + t);
                System.err.flush();
                solve();
            }
        } catch (Exception e) {
            e.printStackTrace();
        } finally {
            out.close();
        }
    }

    public static void main(String Args[]) {
        new Solution().run();
    }
}