
import java.io.*;
import java.util.Arrays;
import java.util.StringTokenizer;

public class C {

    int n, m;
    char[][] a;
    int[] dx = new int[]{-1, 1, 0, 0};
    int[] dy = new int[]{0, 0, -1, 1};
    private Sat2 sat2;

    private String solveTest() throws IOException {
        n = nextInt();
        m = nextInt();
        a = new char[n][];
        for (int i = 0; i < n; i++) {
            a[i] = next().toCharArray();
            for (int j = 0; j < m; j++) {
                if (a[i][j] == '|') a[i][j] = '-';
            }
        }
        sat2 = new Sat2();
        sat2.init(n * m, 1);
        int[] xx = new int[4];
        int[] yy = new int[4];
        int[] dd = new int[4];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (a[i][j] == '-') {
//                    System.out.println(i + " " + j);
                    for (int d = 0; d < 4; d++) {
                        x = i + dx[d];
                        y = j + dy[d];
                        this.d = d;
                        go();
                        if (at(x, y) == '-') {
                            addEdge(i, j, d / 2, i, j, 1 - d / 2);
                        }
                    }
                }
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (a[i][j] == '.') {
//                    System.out.println(i + " " + j);
                    for (int d = 0; d < 4; d++) {
                        x = i;
                        y = j;
                        this.d = d;
                        go();
                        xx[d] = x;
                        yy[d] = y;
                        dd[d] = this.d >> 1;
                    }
                    int c1 = -1;
                    if (at(xx[0], yy[0]) == '-' && at(xx[1], yy[1]) == '-') {
                        addEdge(xx[0], yy[0], dd[0], xx[0], yy[0], 1 - dd[0]);
                        addEdge(xx[1], yy[1], dd[1], xx[1], yy[1], 1 - dd[1]);
                    } else if (at(xx[0], yy[0]) == '-') {
                        c1 = 0;
                    } else if (at(xx[1], yy[1]) == '-') {
                        c1 = 1;
                    }
                    int c2 = -1;
                    if (at(xx[2], yy[2]) == '-' && at(xx[3], yy[3]) == '-') {
                        addEdge(xx[2], yy[2], dd[2], xx[2], yy[2], 1 - dd[2]);
                        addEdge(xx[3], yy[3], dd[3], xx[3], yy[3], 1 - dd[3]);
                    } else if (at(xx[2], yy[2]) == '-') {
                        c2 = 2;
                    } else if (at(xx[3], yy[3]) == '-') {
                        c2 = 3;
                    }
                    if (c1 == -1 && c2 == -1) {
                        return "IMPOSSIBLE";
                    }
                    if (c1 != -1 && c2 == -1) {
                        addEdge(xx[c1], yy[c1], 1 - dd[c1], xx[c1], yy[c1], dd[c1]);
                    }
                    if (c1 == -1 && c2 != -1) {
                        addEdge(xx[c2], yy[c2], 1 - dd[c2], xx[c2], yy[c2], dd[c2]);
                    }
                    if (c1 != -1 && c2 != -1) {
                        addEdge(xx[c1], yy[c1], 1 - dd[c1], xx[c2], yy[c2], dd[c2]);
                    }
                }
            }
        }
        boolean[] res = sat2.solve();
        if (res == null) {
            return "IMPOSSIBLE";
        }
//        System.out.println(Arrays.toString(res));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (a[i][j] == '-' && !res[i * m + j]) {
                    a[i][j] = '|';
                }
            }
        }
        String ans = "POSSIBLE";
        for (int i = 0; i < n; i++) {
            ans += "\n" + new String(a[i]);
        }
        return ans;
    }

    private void addEdge(int x1, int y1, int d1, int x2, int y2, int d2) {
//        System.out.println("edge : " + x1 + " " + y1 + " " + d1 + "     " + x2 + " " + y2 + " " + d2);
        sat2.addEdge((x1 * m + y1) * 2 + d1, (x2 * m + y2) * 2 + d2);
    }

    int x, y, d;

    private void go() {
        while (true) {
            int c = at(x,y);
            if (c == '.') {
                x += dx[d];
                y += dy[d];
            } else if (c == '/') {
                d = d ^ 3;
                x += dx[d];
                y += dy[d];
            } else if (c == '\\') {
                d = d ^ 2;
                x += dx[d];
                y += dy[d];
            } else {
                return;
            }
        }
    }

    private char at(int x, int y) {
        if (x < 0 || y < 0 || x >= n || y >= m) return '#';
        return a[x][y];
    }

    public class Sat2 {

        private DFS dfs1, dfs2;
        private int n;


        void clear() {
            dfs1.clear();
            dfs2.clear();
        }

        private boolean[] solve() {
            for (int i = 0; i < 2 * n; i++) {
                dfs1.dfs(i);
            }
            int[] l = new int[2 * n];
            int[] r = new int[2 * n];
            int cc = 0;
            for (int i = 2 * n - 1; i >= 0; i--) {
                int v = dfs1.p[i];
                if (!dfs2.z[v]) {
                    l[cc] = dfs2.pn;
                    dfs2.dfs(v);
                    r[cc] = dfs2.pn;
                    cc++;
                }
            }
            int[] c = new int[2 * n];
            for (int i = 0; i < cc; i++) {
                for (int j = l[i]; j < r[i]; j++) {
                    c[dfs2.p[j]] = i;
                }
            }
            for (int i = 0; i < n; i++) {
                if (c[2 * i] == c[2 * i + 1]) {
                    return null;
                }
            }
            boolean[] set = new boolean[cc];
            boolean[] res = new boolean[n];
            for (int i = 0; i < 2 * n; i++) {
                int v = c[dfs2.p[i]];
                if (!set[v]) {
                    set[v] = true;
                    set[c[dfs2.p[l[v]] ^ 1]] = true;
                    for (int j = l[v]; j < r[v]; j++) {
                        int x = dfs2.p[j];
                        if (x < 2 * n) {
                            res[x / 2] = x % 2 == 0;
                        }
                    }
                }
            }
            return res;
        }

        private void init(int n, int m) {
            this.n = n;
            dfs1 = new DFS();
            dfs1.init(2 * n, 2 * m);
            dfs2 = new DFS();
            dfs2.init(2 * n, 2 * m);
        }

        private void addEdge(int v, int u) {
            dfs1.addEdge(v, u);
            dfs1.addEdge(u ^ 1, v ^ 1);
            dfs2.addEdge(u, v);
            dfs2.addEdge(v ^ 1, u ^ 1);
        }

        public class DFS {

            int[] p;
            int pn;

            void init(int n, int m) {
                this.n = n;
                this.m = m;
                last = 0;
                head = new int[n];
                nx = new int[m];
                dst = new int[m];
                Arrays.fill(head, -1);
                z = new boolean[n];
                p = new int[n];
            }

            public void clear() {
                Arrays.fill(head, -1);
                Arrays.fill(z, false);
                last = 0;
                pn = 0;
            }

            void addEdge(int x, int y) {
                if (last == dst.length) {
                    int newSize = dst.length * 3 / 2 + 1;
                    int[] newDst = new int[newSize];
                    System.arraycopy(dst, 0, newDst, 0, dst.length);
                    dst = newDst;
                    int[] newNx = new int[newSize];
                    System.arraycopy(nx, 0, newNx, 0, nx.length);
                    nx = newNx;
                }
                nx[last] = head[x];
                dst[last] = y;
                head[x] = last;
                last++;
            }

            private void dfs(int x) {
                if (z[x]) return;
                z[x] = true;
                int j = head[x];
                while (j >= 0) {
                    int y = dst[j];
                    dfs(y);
                    j = nx[j];
                }
                p[pn++] = x;
            }

            int n, m;
            int[] head;
            int[] nx;
            int[] dst;
            boolean[] z;
            int last;

        }
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
        new C().run();
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