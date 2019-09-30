import java.io.*;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.StringTokenizer;

public class Main {
    FastScanner in;
    PrintWriter out;

    int sum(int n) {
        return n < 10 ? n : (n % 10 + sum(n / 10));
    }

    int n;
    boolean[][] g;
    int[] color;
    int cnt0 = 0, cnt1 = 0;

    boolean go(int v, int col) {
        if (color[v] == -1) {
            color[v] = col;
            if (col == 0) {
                cnt0++;
            } else {
                cnt1++;
            }
            for (int i = 0; i < n; i++) {
                if (g[v][i] && !go(i, 1 - col)) {
                    return false;
                }
            }
            return true;
        } else {
            return color[v] == col;
        }
    }

    void solve() {
        n = in.nextInt();
        g = new boolean[n][n];
        for (int i = 0; i < n; i++) {
            Arrays.fill(g[i], true);
            g[i][i] = false;
        }
        int m = in.nextInt();
        for (int i = 0; i < m; i++) {
            int fr = in.nextInt() - 1;
            int to = in.nextInt() - 1;
            g[fr][to] = g[to][fr] = false;
        }
        color = new int[n];
        Arrays.fill(color, -1);
        List<Integer> sizes = new ArrayList<>();
        List<Integer> sizes2 = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            if (color[i] == -1) {
                cnt0 = 0;
                cnt1 = 0;
                if (!go(i, 0)) {
                    out.println(-1);
                    return;
                }
                sizes.add(cnt0);
                sizes2.add(cnt1);
            }
        }
        boolean[] v = new boolean[n + 1];
        v[0] = true;
        for (int it = 0; it < sizes.size(); it++) {
            int q = sizes.get(it);
            int w = sizes2.get(it);
            boolean[] nv = new boolean[n + 1];
            for (int i = n; i >= 0; i--) {
                if (v[i]) {
                    nv[i + q] = true;
                    nv[i + w] = true;
                }
            }
            v = nv;
        }
        int bestAns = 0;
        for (int firstPart = 0; firstPart <= n; firstPart++) {
            if (!v[firstPart]) {
                continue;
            }
            bestAns = Math.max(bestAns, m - f(firstPart) - f(n - firstPart));
        }
        out.println(m - bestAns);
    }

    int f(int x) {
        return x * (x - 1) / 2;
    }

    void solve123() {
        final int MAX = 10000000;
        double[] f = new double[MAX];
        for (int n = 1; n < MAX; n++) {
            f[n] = n / (double) sum(n);
        }
        double curMin = Double.MAX_VALUE;
        for (int i = MAX - 1; i >= 0; i--) {
            if (f[i] <= curMin + 1e-9) {
                if (i < 1000000) {
                    System.err.println(i);
                }
            }
            curMin = Math.min(curMin, f[i]);
        }
    }

    void run() {
        try {
            in = new FastScanner(new File("Main23.in"));
            out = new PrintWriter(new File("Main23.out"));

            solve();

            out.close();
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }
    }

    void runIO() {

        in = new FastScanner(System.in);
        out = new PrintWriter(System.out);

        solve();

        out.close();
    }

    class FastScanner {
        BufferedReader br;
        StringTokenizer st;

        public FastScanner(File f) {
            try {
                br = new BufferedReader(new FileReader(f));
            } catch (FileNotFoundException e) {
                e.printStackTrace();
            }
        }

        public FastScanner(InputStream f) {
            br = new BufferedReader(new InputStreamReader(f));
        }

        String next() {
            while (st == null || !st.hasMoreTokens()) {
                String s = null;
                try {
                    s = br.readLine();
                } catch (IOException e) {
                    e.printStackTrace();
                }
                if (s == null)
                    return null;
                st = new StringTokenizer(s);
            }
            return st.nextToken();
        }

        boolean hasMoreTokens() {
            while (st == null || !st.hasMoreTokens()) {
                String s = null;
                try {
                    s = br.readLine();
                } catch (IOException e) {
                    e.printStackTrace();
                }
                if (s == null)
                    return false;
                st = new StringTokenizer(s);
            }
            return true;
        }

        int nextInt() {
            return Integer.parseInt(next());
        }

        long nextLong() {
            return Long.parseLong(next());
        }

        double nextDouble() {
            return Double.parseDouble(next());
        }
    }

    public static void main(String[] args) {
        new Main().runIO();
    }
}