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

    private Graph c;

    private void solve() throws IOException {
        int n = nextInt();
        Graph a = new Graph();
        Graph b = new Graph();
        c = new Graph();
        a.init(n, n - 1);
        b.init(n, n - 1);
        c.init(n, 2 * n);

        int aRoot = -1;
        int bRoot = -1;
        for (int i = 0; i < n; i++) {
            int x = nextInt() - 1;
            if (x >= 0) {
                a.addEdge(i, x);
            } else {
                aRoot = i;
            }
        }
        for (int i = 0; i < n; i++) {
            int x = nextInt() - 1;
            if (x >= 0) {
                b.addEdge(i, x);
            } else {
                bRoot = i;
            }
        }

        a.dfs(aRoot);
        b.dfs(bRoot);

        for (int i = 0; i < n; i++) {
            if (a.d[i] != b.d[i]) {
                out.println("IMPOSSIBLE");
                return;
            }
        }
        out.println("POSSIBLE");

        for (int i = 0; i < n; i++) {
            if (!c.z[i] && a.d[i] == 0) {
                c.dfs2(i);
            }
        }

        for (int i = 0; i < n; i++) {
            if (a.d[i] == 1) {
                out.print(0 + " ");
            } else {
                out.print(c.d[i] + " ");
            }
        }
        out.println();
    }

    public class Graph {

        void init(int n, int m) {
            m *= 2;
            this.n = n;
            this.m = m;
            last = 0;
            head = new int[n];
            nx = new int[m];
            dst = new int[m];
            src = new int[m];
            d = new int[n];
            repr = new int[n];
            Arrays.fill(head, -1);
            z = new boolean[n];
        }

        void addEdge(int x, int y) {
            nx[last] = head[x];
            src[last] = x;
            dst[last] = y;
            head[x] = last;
            last++;
            nx[last] = head[y];
            src[last] = y;
            dst[last] = x;
            head[y] = last;
            last++;
        }

        private void dfs(int x) {
            z[x] = true;
            int j = head[x];
            int last = -1;
            while (j >= 0) {
                int y = dst[j];
                if (!z[y]) {
                    dfs(y);
                    if (last == -1) {
                        last = y;
                    } else {
                        c.addEdge(repr[last], repr[y]);
                        last = -1;
                    }
                }
                j = nx[j];
            }
            if (last == -1) {
                d[x] = 0;
                repr[x] = x;
            } else {
                d[x] = 1;
                repr[x] = repr[last];
            }
        }

        private void dfs2(int x) {
            z[x] = true;
            int j = head[x];
            d[x] = 1;
            while (j >= 0) {
                int y = dst[j];
                if (!z[y]) {
                    dfs2(y);
                    d[x] = -d[y];
                }
                j = nx[j];
            }
        }

        int n, m;
        int[] d;
        int[] head;
        int[] repr;
        int[] nx;
        int[] src;
        int[] dst;
        boolean[] z;
        int last;
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