import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Comparator;
import java.util.StringTokenizer;

/**
 * @author Pavel Mavrin
 */
public class Main {

    private int[] x;
    private int[] q;
    private Sat2 sat2;
    private int k;

    private void solve() throws IOException {
        int n = nextInt();
        int[][] points = new int[2 * n][2];
        for (int i = 0; i < n; i++) {
            points[2 * i][0] = nextInt();
            points[2 * i][1] = 2 * i;
            points[2 * i + 1][0] = nextInt();
            points[2 * i + 1][1] = 2 * i + 1;
        }
        Arrays.sort(points, new Comparator<int[]>() {
            @Override
            public int compare(int[] o1, int[] o2) {
                return Integer.compare(o1[0], o2[0]);
            }
        });
        x = new int[2 * n];
        q = new int[2 * n];
        for (int i = 0; i < 2 * n; i++) {
            x[i] = points[i][0];
            q[i] = points[i][1];
        }
        int l = 0;
        int r = 1000000001;
        sat2 = new Sat2();
        k = 1;
        while (k < 2 * n) k *= 2;
        sat2.init(k + n, 1000000);
        while (r > l + 1) {
            int m = (l + r) / 2;
            if (check(n, m)) l = m; else r = m;
        }
        out.println(l);
    }

    private boolean check(int n, int m) {
        sat2.clear();
        for (int i = 1; i < k - 1; i++) {
            int j = (i - 1) / 2;
            sat2.addEdge(2 * j, 2 * i);
        }
        for (int i = 0; i < 2 * n; i++) {
            int j = i / 2 + k / 2 - 1;
            sat2.addEdge(2 * j, (q[i] ^ 1) + 2 * k);
        }
        int l = 0;
        int r = 0;
        for (int i = 0; i < 2 * n; i++) {
            while (x[i] - x[l] >= m) l++;
            while (r < 2 * n && x[r] - x[i] < m) r++;
            ban(l, i, q[i] + 2 * k, 0, 0, k);
        }
        return sat2.solve() != null;
    }

    private void ban(int l, int r, int fr, int i, int L, int R) {
        if (L >= r || l >= R) return;
        if (L >= l && R <= r) {
            if (R == L + 1) {
                sat2.addEdge(fr, (q[L] ^ 1) + 2 * k);
            } else {
                sat2.addEdge(fr, 2 * i);
            }
            return;
        }
        int M = (L + R) / 2;
        ban(l, r, fr, 2 * i + 1, L, M);
        ban(l, r, fr, 2 * i + 2, M, R);
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
//            boolean[] set = new boolean[cc];
//            boolean[] res = new boolean[n];
//            for (int i = 0; i < 2 * n; i++) {
//                int v = c[dfs2.p[i]];
//                if (!set[v]) {
//                    set[v] = true;
//                    set[c[dfs2.p[l[v]] ^ 1]] = true;
//                    for (int j = l[v]; j < r[v]; j++) {
//                        int x = dfs2.p[j];
//                        if (x < 2 * n) {
//                            res[x / 2] = x % 2 == 0;
//                        }
//                    }
//                }
//            }
            return new boolean[0];
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