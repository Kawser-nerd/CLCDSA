import java.io.*;
import java.util.*;

public class Main {
    FastScanner in;
    PrintWriter out;

    void fillParent(int v, int par, boolean[][] g, int[] p) {
        p[v] = par;
        for (int to = 0; to < g.length; to++) {
            if (to != par && g[v][to]) {
                fillParent(to, v, g, p);
            }
        }
    }

    void solve() {
        int tc = in.nextInt();
        for (int t = 0; t < tc; t++) {
            int n = in.nextInt();
            boolean[][] g = new boolean[n][n];
            boolean[][] gTmp = new boolean[n][n];
            for (int i = 0; i + 1 < n; i++) {
                int fr = in.nextInt() - 1;
                int to = in.nextInt() - 1;
                gTmp[fr][to] = gTmp[to][fr] = true;
            }
            boolean[][] gNeed = new boolean[n][n];
            for (int i = 0; i + 1 < n; i++) {
                int fr = in.nextInt() - 1;
                int to = in.nextInt() - 1;
                gNeed[fr][to] = gNeed[to][fr] = true;
            }
            int ans = Integer.MAX_VALUE;
            int[] parent = new int[n];
            boolean[] ok = new boolean[n];
            int[] gSz = new int[n];
            for (int root = 0; root < n; root++) {
                for (int i = 0; i < n; i++) {
                    gSz[i] = 0;
                    for (int j = 0; j < n; j++) {
                        g[i][j] = gTmp[i][j];
                        if (g[i][j]) {
                            gSz[i]++;
                        }
                    }
                }
                fillParent(root, root, gNeed, parent);
                Arrays.fill(ok, false);
                ok[root] = true;
                int cost = 0;
                while (true) {
                    boolean ch = false;
                    for (int i = 0; i < n; i++) {
                        if (!ok[i] && ok[parent[i]] && g[i][parent[i]]) {
                            ok[i] = true;
                            ch = true;
                        }
                    }
                    if (ch) {
                        continue;
                    }
                    for (int i = 0; i < n; i++) {
                        if (!ok[i] && gSz[i] == 1 && ok[parent[i]]) {
                            int curEdge = -1;
                            for (int j = 0; j < n; j++) {
                                if (g[i][j]) {
                                    curEdge = j;
                                }
                            }
                            g[i][curEdge] = g[curEdge][i] = false;
                            g[i][parent[i]] = g[parent[i]][i] = true;
                            cost++;
                            ok[i] = true;
                            gSz[parent[i]]++;
                            gSz[curEdge]--;
                            ch = true;
                            break;
                        }
                    }
                    if (!ch) {
                        break;
                    }
                }
                boolean totalOk = true;
                for (boolean z : ok) {
                    totalOk &= z;
                }
                if (totalOk) {
                    ans = Math.min(ans, cost);
                }
            }




            for (int root = 0; root < n; root++) {
                for (int connectTo = 0; connectTo < n; connectTo++) {
                    if (root == connectTo || gTmp[root][connectTo]) {
                        continue;
                    }
                    for (int i = 0; i < n; i++) {
                        gSz[i] = 0;
                        for (int j = 0; j < n; j++) {
                            g[i][j] = gTmp[i][j];
                            if (g[i][j]) {
                                gSz[i]++;
                            }
                        }
                    }
                    fillParent(root, root, gNeed, parent);
                    Arrays.fill(ok, false);
                    ok[root] = true;
                    int cost = 1;
                    if (gSz[root] != 1) {
                        continue;
                    }
                    int edgeTo =0 ;
                    while (!g[root][edgeTo]) {
                        edgeTo++;
                    }
                    g[root][edgeTo] = g[edgeTo][root] = false;
                    g[root][connectTo] = g[connectTo][root] = true;
                    gSz[edgeTo]--;
                    gSz[connectTo]++;


                    while (true) {
                        boolean ch = false;
                        for (int i = 0; i < n; i++) {
                            if (!ok[i] && ok[parent[i]] && g[i][parent[i]]) {
                                ok[i] = true;
                                ch = true;
                            }
                        }
                        if (ch) {
                            continue;
                        }
                        for (int i = 0; i < n; i++) {
                            if (!ok[i] && gSz[i] == 1 && ok[parent[i]]) {
                                int curEdge = -1;
                                for (int j = 0; j < n; j++) {
                                    if (g[i][j]) {
                                        curEdge = j;
                                    }
                                }
                                g[i][curEdge] = g[curEdge][i] = false;
                                g[i][parent[i]] = g[parent[i]][i] = true;
                                cost++;
                                ok[i] = true;
                                gSz[parent[i]]++;
                                gSz[curEdge]--;
                                ch = true;
                                break;
                            }
                        }
                        if (!ch) {
                            break;
                        }
                    }
                    boolean totalOk = true;
                    for (boolean z : ok) {
                        totalOk &= z;
                    }
                    if (totalOk) {
                        ans = Math.min(ans, cost);
                    }
                }
            }




            out.println(ans == Integer.MAX_VALUE ? -1 : ans);
        }
    }


    void run() {
        try {
            in = new FastScanner(new File("Main.in"));
            out = new PrintWriter(new File("Main.out"));

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