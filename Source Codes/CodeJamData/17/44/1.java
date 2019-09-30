
import java.io.*;
import java.util.Arrays;
import java.util.StringTokenizer;

public class D {

    int n, m, k;
    char[][] a;
    int[] dx = new int[]{-1, 1, 0, 0};
    int[] dy = new int[]{0, 0, -1, 1};
    int[][] aa;
    int[] r;
    int sn;
    int tn;
    private boolean[] z;
    private String ans;
    private int[] pp;
    private int[] l;

    private String solveTest() throws IOException {
        m = nextInt();
        n = nextInt();
        k = nextInt();
        a = new char[n][];
        int[] sx = new int[n * m];
        int[] sy = new int[n * m];
        sn = 0;
        int[] tx = new int[n * m];
        int[] ty = new int[n * m];
        tn = 0;
        for (int i = 0; i < n; i++) {
            a[i] = next().toCharArray();
            for (int j = 0; j < m; j++) {
                if (a[i][j] == 'S') {
                    sx[sn] = i;
                    sy[sn] = j;
                    sn++;
                }
                if (a[i][j] == 'T') {
                    tx[tn] = i;
                    ty[tn] = j;
                    tn++;
                }
            }
        }
        int[][] d = new int[n][m];
        int[] qx = new int[n * m];
        int[] qy = new int[n * m];
        aa = new int[sn][tn];
        for (int i = 0; i < tn; i++) {
            for (int[] ints : d) {
                Arrays.fill(ints, Integer.MAX_VALUE);
            }
            int t = 0;
            int h = 0;
            for (int dd = 0; dd < 4; dd++) {
                int xx = tx[i] + dx[dd];
                int yy = ty[i] + dy[dd];
                while (at(xx, yy) != '#') {
                    d[xx][yy] = 0;
                    qx[t] = xx;
                    qy[t] = yy;
                    t++;
                    xx += dx[dd];
                    yy += dy[dd];
                }
            }
            while (t > h) {
                int x = qx[h];
                int y = qy[h];
                h++;
                for (int dd = 0; dd < 4; dd++) {
                    int xx = x + dx[dd];
                    int yy = y + dy[dd];
                    if (at(xx, yy) != '#' && d[xx][yy] == Integer.MAX_VALUE) {
                        d[xx][yy] = d[x][y] + 1;
                        qx[t] = xx;
                        qy[t] = yy;
                        t++;
                    }
                }
            }
            for (int j = 0; j < sn; j++) {
                aa[j][i] = d[sx[j]][sy[j]];
            }
        }

        r = new int[tn];
        for (int i = 0; i < tn; i++) {
            r[i] = -1;
        }

        int res = 0;
        z = new boolean[sn];
        for (int i = 0; i < sn; i++) {
            Arrays.fill(z, false);
            if (dfs(i)) {
                res++;
            }
        }

        l = new int[sn];
        Arrays.fill(l, -1);
        for (int i = 0; i < tn; i++) {
            if (r[i] != -1) {
                l[r[i]] = i;
            }
        }

        ans = "" + res;
        pp = new int[sn];
        boolean[] sh = new boolean[sn];
        boolean[] dd = new boolean[tn];
        int c = 0;
        while (c < res) {
            Arrays.fill(pp, -1);
            int xx = 0;
            while (sh[xx] || l[xx] == -1) xx++;
            while (true) {
                int min = l[xx];
                if (sh[xx]) throw new RuntimeException();
                if (dd[l[xx]]) throw new RuntimeException();
                for (int j = 0; j < tn; j++)
                    if (!dd[j]) {
                        if (aa[xx][j] < aa[xx][min]) {
                            min = j;
                        }
                    }
                if (r[min] == -1) {
                    r[l[xx]] = -1;
                    r[min] = xx;
                    l[xx] = min;
                    sh[xx] = true;
                    dd[min] = true;
                    for (int i = 0; i < sn; i++) {
                        if (!sh[i] && l[i] != -1 && dd[l[i]]) {
                            throw new RuntimeException();
                        }
                    }
                    ans += "\n" + (xx + 1) + " " + (min + 1);
                    c++;
                    break;
                } else {
                    pp[xx] = r[min];
                    if (pp[pp[xx]] >= 0) {
                        while (pp[xx] >= 0) {
                            sh[xx] = true;
                            dd[l[pp[xx]]] = true;
                            ans += "\n" + (xx + 1) + " " + (l[pp[xx]] + 1);
                            c++;
                            int t = pp[xx];
                            pp[xx] = -1;
                            xx = t;
                        }
                        for (int i = 0; i < sn; i++) {
                            if (!sh[i] && l[i] != -1 && dd[l[i]]) {
                                throw new RuntimeException();
                            }
                        }
                        break;
                    }
                    xx = pp[xx];
                }
            }
        }

        return ans;
    }

    private boolean dfs(int i) {
        if (z[i]) return false;
        z[i] = true;
        for (int j = 0; j < tn; j++) {
            if (aa[i][j] <= k) {
                if (r[j] == -1 || dfs(r[j])) {
                    r[j] = i;
                    return true;
                }
            }
        }
        return false;
    }

    private char at(int x, int y) {
        if (x < 0 || y < 0 || x >= n || y >= m) return '#';
        return a[x][y];
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