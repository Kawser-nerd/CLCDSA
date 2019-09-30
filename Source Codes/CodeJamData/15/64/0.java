
import java.io.*;
import java.util.Arrays;
import java.util.HashMap;
import java.util.StringTokenizer;

public class D {


    private int solveTest() throws IOException {
        int n = nextInt();
        int m = nextInt();
        int k = nextInt();
        boolean[][] a = new boolean[n][n];
        for (int i = 0; i < m; i++) {
            int x = nextInt();
            int y = nextInt();
            a[x][y] = true;
            a[y][x] = true;
        }
        boolean[] taken = new boolean[n];
//        k--;
//        taken[0] = true;
//        int c = 0;
        while (true) {
//            c++;
//            if (c > 2) throw new RuntimeException();
            int[] d = new int[n];
            boolean[] z = new boolean[n];
            for (int i = 0; i < n; i++) {
                d[i] = 1000000000;
            }
            d[0] = 0;
            while (true) {
                int x = -1;
                int min = 1000000000;
                for (int i = 0; i < n; i++) if (!z[i]) {
                    if (d[i] < min) {
                        x = i;
                        min = d[i];
                    }
                }
                if (min == 1000000000) break;
                z[x] = true;
                for (int i = 0; i < n; i++) if (a[x][i]) {
                    d[i] = Math.min(d[i], d[x] + 1 + (taken[x] ? 1 : 0));
                }
            }
//            System.out.println(d[n - 1]);
            init(2 * n, m + n);
            for (int i = 0; i < n; i++) {
                addEdge(i, i + n, taken[i] ? 1000 : 1, 0);
            }
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (a[i][j] && d[j] == d[i] + 1 + (taken[i] ? 1 : 0)){
                        addEdge(n + i, j, 1000, 0);
                    }
                }
            }
            long f = maxFlow(0, n - 1);
//            if (f == 0) {
//                return d[n - 1];
//            }
//            System.out.println(Arrays.toString(d) + " " + f);
            if (k >= f) {
                Arrays.fill(this.z, false);
                dfs(0, n - 1, 1);
                int q = 0;
                for (int i = 0; i < n; i++) {
                    if (this.z[i] && !this.z[i + n]) {
                        if (taken[i]) throw new RuntimeException();
                        taken[i] = true;
                        q++;
                    }
                }
                if (q != f) throw new RuntimeException(q + " " + f);
                k -= f;
            } else {
                return d[n - 1];
            }
        }
    }


    void init(int n, int m) {
        m *= 2;
        this.n = n;
        this.m = m;
        last = 0;
        head = new int[n];
        nx = new int[m];
        dst = new int[m];
        src = new int[m];
        cp = new int[m];
        fl = new int[m];
        Arrays.fill(head, -1);
        z = new boolean[n];
    }

    void addEdge(int x, int y, int c1, int c2) {
        nx[last] = head[x];
        src[last] = x;
        dst[last] = y;
        cp[last] = c1;
        head[x] = last;
        last++;
        nx[last] = head[y];
        src[last] = y;
        dst[last] = x;
        cp[last] = c2;
        head[y] = last;
        last++;
    }

    long maxFlow(int s, int t) {
        long res = 0;
        while (true) {
            Arrays.fill(z, false);
            int f = dfs(s, t, Integer.MAX_VALUE);
            if (f > 0) {
                res += f;
            } else {
                break;
            }
        }
        return res;
    }

    private int dfs(int x, int t, int f) {
        if (f == 0) return 0;
        if (x == t) return f;
        if (z[x]) return 0;
        z[x] = true;
        int j = head[x];
        while (j >= 0) {
            int y = dst[j];
            if (!z[y] && fl[j] < cp[j]) {
                int res = dfs(y, t, Math.min(f, cp[j] - fl[j]));
                if (res > 0) {
                    fl[j] += res;
                    fl[j ^ 1] -= res;
                    return res;
                }
            }
            j = nx[j];
        }
        return 0;
    }

    private static final long INF = Long.MAX_VALUE;

    int n, m;
    int[] head;
    int[] nx;
    int[] src;
    int[] dst;
    int[] cp;
    int[] fl;
    boolean[] z;
    int last;

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