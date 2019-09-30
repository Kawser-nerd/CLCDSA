import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        FastScanner in = new FastScanner(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        TaskE solver = new TaskE();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskE {
        int n;
        int[] ls;
        int[] rs;
        int[][] adj;
        int[] a;
        boolean[] fixed;

        public void solve(int testNumber, FastScanner in, PrintWriter out) {
            n = in.nextInt();
            adj = readTree(n, in);
            int k = in.nextInt();
            a = new int[n];
            Arrays.fill(a, -1);
            fixed = new boolean[n];
            for (int i = 0; i < k; i++) {
                int v = in.nextInt() - 1;
                a[v] = in.nextInt();
                fixed[v] = true;
            }

            ls = new int[n];
            rs = new int[n];
            for (int v = 0; v < n; v++) {
                if (!fixed[v]) {
                    continue;
                }
                int[] seg = dfs(v, -1, a[v], a[v]);
                if (seg == null) {
                    out.println("No");
                    return;
                }
                paint(v, -1, a[v]);
            }

            out.println("Yes");
            for (int i = 0; i < n; i++) {
                out.println(a[i]);
            }
        }

        private int[] dfs(int v, int p, int l, int r) {
            int cl = l;
            int cr = r;
            for (int u : adj[v]) {
                if (u == p) {
                    continue;
                }
                int nl, nr;
                if (!fixed[u]) {
                    int[] seg = dfs(u, v, l - 1, r + 1);
                    if (seg == null) {
                        return null;
                    }
                    nl = seg[0] - 1;
                    nr = seg[1] + 1;
                } else {
                    nl = a[u] - 1;
                    nr = a[u] + 1;
                }
                boolean e1 = cl % 2 == 0;
                boolean e2 = nl % 2 == 0;
                if (e1 != e2) {
                    return null;
                }
                cl = Math.max(cl, nl);
                cr = Math.min(cr, nr);
            }
            if (cl > cr) {
                return null;
            }
            ls[v] = cl;
            rs[v] = cr;
            return new int[]{cl, cr};
        }

        private void paint(int v, int p, int c) {
            a[v] = c;
            for (int u : adj[v]) {
                if (u == p) {
                    continue;
                }
                if (!fixed[u]) {
                    for (int nc = c - 1; nc <= c + 1; nc += 2) {
                        if (nc >= ls[u] && nc <= rs[u]) {
                            fixed[u] = true;
                            paint(u, v, nc);
                            break;
                        }
                    }
                }
            }
        }

        private int[][] readTree(int n, FastScanner in) {
            int[] as = new int[n - 1];
            int[] bs = new int[n - 1];
            int[] deg = new int[n];
            for (int i = 0; i < n - 1; i++) {
                as[i] = in.nextInt() - 1;
                bs[i] = in.nextInt() - 1;
                ++deg[as[i]];
                ++deg[bs[i]];
            }
            int[][] adj = new int[n][];
            for (int i = 0; i < n; i++) {
                adj[i] = new int[deg[i]];
                deg[i] = 0;
            }
            for (int i = 0; i < n - 1; i++) {
                int a = as[i];
                int b = bs[i];
                adj[a][deg[a]] = b;
                adj[b][deg[b]] = a;
                ++deg[a];
                ++deg[b];
            }
            return adj;
        }

    }

    static class FastScanner {
        private BufferedReader in;
        private StringTokenizer st;

        public FastScanner(InputStream stream) {
            in = new BufferedReader(new InputStreamReader(stream));
        }

        public String next() {
            while (st == null || !st.hasMoreTokens()) {
                try {
                    st = new StringTokenizer(in.readLine());
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
            return st.nextToken();
        }

        public int nextInt() {
            return Integer.parseInt(next());
        }

    }
}