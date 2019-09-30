import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;
import java.io.BufferedReader;
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
        TaskF solver = new TaskF();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskF {
        public void solve(int testNumber, FastScanner in, PrintWriter out) {
            int n = in.nextInt();
            int[] a = new int[n];
            for (int i = 0; i < n; i++) {
                a[i] = in.nextInt();
            }

            List<Integer> b = new ArrayList<>();
            {
                int l = -1;
                int r = -1;
                for (int x : a) {
                    if (x == r + 1) {
                        ++r;
                    } else {
                        if (l >= 0) {
                            b.add(l);
                            b.add(r + 1);
                        }
                        l = x;
                        r = x;
                    }
                }
                if (l >= 0) {
                    b.add(l);
                    b.add(r + 1);
                }
            }

            List<Integer> even = new ArrayList<>();
            List<Integer> odd = new ArrayList<>();
            for (int x : b) {
                if (x % 2 == 0) {
                    even.add(x);
                } else {
                    odd.add(x);
                }
            }
            boolean[][] g = new boolean[even.size()][odd.size()];
            for (int i = 0; i < even.size(); i++) {
                for (int j = 0; j < odd.size(); j++) {
                    if (f(Math.abs(even.get(i) - odd.get(j))) == 1) {
                        g[i][j] = true;
                    }
                }
            }
            int k = matching(g);
            if (b.size() % 2 != 0) {
                throw new AssertionError();
            }
            int ans = k;
            ans += ((even.size() - k) / 2) * 2;
            ans += ((odd.size() - k) / 2) * 2;
            if ((even.size() - k) % 2 != 0) {
                ans += 3;
            }
            out.println(ans);
        }

        private int f(int len) {
            if (len < 1) {
                return 0;
            }
            if (len == 1) {
                return 3;
            }
            if (len % 2 == 0) {
                return 2;
            }
            for (int d = 3; d * d <= len; d += 2) {
                if (len % d == 0) {
                    return 3;
                }
            }
            return 1;
        }

        private int matching(boolean[][] g) {
            int n = g.length;
            int m = n == 0 ? 0 : g[0].length;
            int[] pair = new int[m];
            Arrays.fill(pair, -1);
            int res = 0;
            boolean[] was = new boolean[n];
            for (int i = 0; i < n; i++) {
                Arrays.fill(was, false);
                if (dfs(i, g, was, pair)) {
                    ++res;
                }
            }
            return res;
        }

        private boolean dfs(int v, boolean[][] g, boolean[] was, int[] pair) {
            if (was[v]) {
                return false;
            }
            was[v] = true;
            for (int u = 0; u < g[v].length; u++) {
                if (!g[v][u]) {
                    continue;
                }
                if (pair[u] < 0 || dfs(pair[u], g, was, pair)) {
                    pair[u] = v;
                    return true;
                }
            }
            return false;
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