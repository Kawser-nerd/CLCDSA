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
        init(n);
        for (int i = 0; i < n - 1; i++) {
            int x = nextInt() - 1;
            int y = nextInt() - 1;
            int z = nextInt();
            addEdge(x, y, z);
        }
        dfs(0, -1);
//        System.out.println(res);
        if (!ok) {
            int min = Integer.MAX_VALUE;
            int j = head[centr];
            while (j >= 0) {
                min = Math.min(min, cost[j]);
                j = nx[j];
            }
            res -= min;
        }
        out.println(res);
    }


    void init(int n) {
        this.n = n;
        this.m = (n - 1) * 2;
        last = 0;
        head = new int[n];
        nx = new int[m];
        dst = new int[m];
        cost = new int[m];
        Arrays.fill(head, -1);
    }


    void addEdge(int x, int y, int c) {
        nx[last] = head[x];
        dst[last] = y;
        cost[last] = c;
        head[x] = last;
        last++;
        nx[last] = head[y];
        dst[last] = x;
        cost[last] = c;
        head[y] = last;
        last++;
    }

    long res = 0;
    int centr = -1;
    boolean ok = false;

    private int dfs(int x, int p) {
        int j = head[x];
        int s = 1;
        boolean cc = true;
        while (j >= 0) {
            int y = dst[j];
            if (y != p) {
                int z = dfs(y, x);
                if (2 * z > n) cc = false;
                int xx = z;
                int yy = n - xx;
//                System.out.println(cost[j] + " " + xx + " " + yy);
                if (xx == yy) {
                    res += 1l * cost[j] * (xx * 2 - 1);
                    ok = true;
                } else {
                    res += 1l * cost[j] * Math.min(xx, yy) * 2;
                }
                s += z;
            }
            j = nx[j];
        }
        if (2 * s <= n) {
            cc = false;
        }
        if (cc) {
            centr = x;
        }
        return s;
    }

    int n, m;
    int[] head;
    int[] nx;
    int[] dst;
    int[] cost;
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