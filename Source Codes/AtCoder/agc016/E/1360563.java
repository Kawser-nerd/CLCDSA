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

    private void solve() throws IOException {
        int n = nextInt();
        int m = nextInt();
        init(n, m);
        for (int i = 0; i < m; i++) {
            int x = nextInt() - 1;
            int y = nextInt() - 1;
            addEdge(x, y, i);
        }
        int[][] zz = new int[n][n];
        boolean[] g = new boolean[n];
        for (int i = 0; i < n; i++) {
            z = zz[i];
            Arrays.fill(z, -1);
            if (dfs(i, m)) {
                g[i] = true;
            }
        }
        int res = 0;
        for (int i = 0; i < n; i++) if (g[i]) {
            for (int j = i + 1; j < n; j++) if (g[j]) {
                boolean ok = true;
                for (int k = 0; k < n; k++) {
                    if (zz[i][k] >= 0 && zz[j][k] >= 0) {
                        ok = false;
                    }
                }
                if (ok) res++;
            }
        }
        out.println(res);
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
        tm = new int[m];
        Arrays.fill(head, -1);
    }

    void addEdge(int x, int y, int time) {
        nx[last] = head[x];
        src[last] = x;
        dst[last] = y;
        tm[last] = time;
        head[x] = last;
        last++;
        nx[last] = head[y];
        src[last] = y;
        dst[last] = x;
        tm[last] = time;
        head[y] = last;
        last++;
    }

    private boolean dfs(int x, int time) {
        if (z[x] != -1) return false;
        z[x] = time;
        int j = head[x];
        while (j >= 0) {
            int y = dst[j];
            if (tm[j] < time) {
                if (!dfs(y, tm[j])) {
                    return false;
                }
            }
            j = nx[j];
        }
        return true;
    }

    int n, m;
    int[] head;
    int[] nx;
    int[] src;
    int[] dst;
    int[] tm;
    int[] z;
    int last;


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