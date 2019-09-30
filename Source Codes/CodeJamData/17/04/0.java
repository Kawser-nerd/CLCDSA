
import java.io.*;
import java.util.Arrays;
import java.util.StringTokenizer;

public class D {

    private int nn;
    private boolean[][] a;
    private int[] p;
    private boolean[] z;

    private String solveTest() throws IOException {
        int n = nextInt();
        boolean[][] changed = new boolean[n][n];
        boolean[][] bishops = new boolean[n][n];
        boolean[][] rooks = new boolean[n][n];
        int m = nextInt();
        for (int i = 0; i < m; i++) {
            String s = next();
            int r = nextInt() - 1;
            int c = nextInt() - 1;
            switch (s) {
                case "+":
                    bishops[r][c] = true;
                    break;
                case "x":
                    rooks[r][c] = true;
                    break;
                case "o":
                    bishops[r][c] = true;
                    rooks[r][c] = true;
                    break;
            }
        }
        {
            boolean[] row = new boolean[n];
            boolean[] col = new boolean[n];
            int res = n;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (rooks[i][j]) {
                        row[i] = true;
                        col[j] = true;
                        res--;
                    }
                }
            }
            int r = 0;
            int c = 0;
            for (int i = 0; i < res; i++) {
                while (row[r]) r++;
                while (col[c]) c++;
                rooks[r][c] = true;
                changed[r][c] = true;
                r++;
                c++;
            }
        }
        {
            nn = 2 * n - 1;
            a = new boolean[nn][nn];
            p = new int[nn];
            Arrays.fill(p, -1);
            z = new boolean[nn];
            boolean[] d1 = new boolean[nn];
            boolean[] d2 = new boolean[nn];
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (bishops[i][j]) {
                        int ii = i + j;
                        int jj = i - j + n - 1;
                        d1[ii] = true;
                        d2[jj] = true;
                    }
                }
            }
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    int ii = i + j;
                    int jj = i - j + n - 1;
                    if (!d1[ii] && !d2[jj]) {
                        a[ii][jj] = true;
                    }
                }
            }
            for (int i = 0; i < nn; i++) {
                Arrays.fill(z, false);
                dfs(i);
            }
            for (int jj = 0; jj < nn; jj++) {
                if (p[jj] >= 0) {
                    int ii = p[jj];
                    int i = (ii + jj - (n - 1)) / 2;
                    int j = ii - i;
                    changed[i][j] = true;
                    bishops[i][j] = true;
                }
            }
        }
        int ans = 0;
        int fig = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (changed[i][j]) {
                    fig++;
                }
                if (rooks[i][j]) {
                    ans++;
                }
                if (bishops[i][j]) {
                    ans++;
                }
            }
        }
        StringBuilder res = new StringBuilder().append(ans).append(" ").append(fig);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (changed[i][j]) {
                    res.append("\n");
                    if (rooks[i][j] && bishops[i][j]) {
                        res.append("o");
                    } else if (rooks[i][j]) {
                        res.append("x");
                    } else if (bishops[i][j]) {
                        res.append("+");
                    }
                    res.append(" ").append(i + 1).append(" ").append(j + 1);
                }
            }
        }
        return res.toString();
    }

    private boolean dfs(int i) {
        if (z[i]) return false;
        z[i] = true;
        for (int j = 0; j < nn; j++) {
            if (a[i][j]) {
                if (p[j] == -1 || dfs(p[j])) {
                    p[j] = i;
                    return true;
                }
            }
        }
        return false;
    }

    private void solve() throws IOException {
        int n = nextInt();
        for (int i = 0; i < n; i++) {
            String res = solveTest();
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
        new D().run();
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