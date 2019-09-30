import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Random;
import java.util.StringTokenizer;

/**
 * @author Pavel Mavrin
 */
public class Main {

    private void solve() throws IOException {
        int n = nextInt();
        int m = nextInt();
        int[] x = new int[m];
        int[] y = new int[m];
        for (int i = 0; i < m; i++) {
            x[i] = nextInt() - 1;
            y[i] = nextInt() - 1;
        }
        out.println(solve(n, m, x, y));
//        Random random = new Random(1231231231);
//        while (true) {
//            int n = 5;
//            int m = random.nextInt(n * n);
//            int[] x = new int[m];
//            int[] y = new int[m];
//            for (int i = 0; i < m; i++) {
//                x[i] = random.nextInt(n);
//                y[i] = random.nextInt(n);
//            }
//            long s1 = solve(n, m, x, y);
//            long s2 = solve2(n, m, x, y);
//            if (s1 != s2) {
//                System.out.println("!!!");
//                System.out.println(Arrays.toString(x) + " " + Arrays.toString(y));
//            }
//        }
    }

    private long solve(int n, int m, int[] x, int[] y) {
        DFS dfs = new DFS();
        dfs.init(n, m);
        for (int i = 0; i < m; i++) {
            dfs.addEdge(x[i], y[i]);
        }
        long bp = 0;
        long nbp = 0;
        long u = 0;
        for (int i = 0; i < n; i++) {
            if (!dfs.z[i]) {
                dfs.s = 0;
                dfs.bp = true;
                dfs.dfs(i, 0);
                if (!dfs.bp) {
                    nbp++;
                } else if (dfs.s == 1) {
                    u++;
                } else {
                    bp++;
                }
            }
        }
        return (2 * u * n - u * u + nbp * bp * 2 + nbp * nbp + bp * bp * 2);
    }

    public class DFS {

        void init(int n, int m) {
            m *= 2;
            this.n = n;
            this.m = m;
            last = 0;
            head = new int[n];
            nx = new int[m];
            dst = new int[m];
            src = new int[m];
            Arrays.fill(head, -1);
            z = new boolean[n];
            c = new int[n];
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

        private void dfs(int x, int cc) {
            if (z[x]) {
                bp &= c[x] == cc;
                return;
            }
            c[x] = cc;
            z[x] = true;
            s++;
            int j = head[x];
            while (j >= 0) {
                int y = dst[j];
                dfs(y, 1 - cc);
                j = nx[j];
            }
        }

        boolean bp;
        int n, m;
        int[] head;
        int[] c;
        int s;
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