import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Locale;
import java.util.StringTokenizer;

public class C implements Runnable {
    BufferedReader in;
    StringTokenizer st;
    PrintWriter out;
    String filename = C.class.getName().substring(0, 1);

    void preSolve() {

    }

    boolean dfs(boolean[] used, boolean[][] g, int source, int target) {
        used[source] = true;
        if (source == target) {
            return true;
        }
        for (int i = 0; i < g.length; ++i) {
            if (g[source][i] && !used[i] && dfs(used, g, i, target)) {
                g[source][i] = false;
                g[i][source] = true;
                return true;
            }
        }
        return false;
    }

    int flow(boolean[][] graph, int source, int target) {
        int ans = 0;
        while (dfs(new boolean[graph.length], graph, source, target)) {
            ++ans;
        }
        return ans;
    }

    void solve(int testNumber) throws IOException {
        int n = nextInt();
        int k = nextInt();
        int[][] p = new int[n][k];
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < k; ++j) {
                p[i][j] = nextInt();
            }
        }

        boolean[][] less = new boolean[2 * n + 2][2 * n + 2];

        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                boolean isect = false;
                for (int t = 0; t < k; ++t) {
                    isect |= (p[i][t] == p[j][t]);
                }
                for (int t = 1; t < k; ++t) {
                    isect |= (p[i][t - 1] > p[j][t - 1]) != (p[i][t] > p[j][t]);
                }
                if (!isect) {
//                    System.out.println(i + " " + j + " " + p[i][0] + " " + p[j][0]);
                    less[2 * i][2 * j + 1] = p[i][0] < p[j][0];
                    less[2 * j][2 * i + 1] = p[j][0] < p[i][0];
                }
            }
        }

        for (int i = 0; i < n; ++i) {
            less[2 * n][2 * i] = true;
            less[2 * i + 1][2 * n + 1] = true;
        }

        out.println("Case #" + testNumber + ": " + (n - flow(less, 2 * n, 2 * n + 1)));
    }

    public void run() {
        try {
            in = new BufferedReader(new FileReader(filename + ".in"));
            out = new PrintWriter(filename + ".out");
            eat(null);

            preSolve();
            int nt = nextInt();
            for (int i = 1; i <= nt; ++i) {
                long t0 = System.currentTimeMillis();
                solve(i);
                t0 = System.currentTimeMillis() - t0;
                System.out.println(i + "/" + nt + " done in " + t0 + " ms.");
            }

            out.close();
            in.close();
        } catch (IOException ex) {
            throw new RuntimeException(ex);
        }
    }

    void eat(String s) {
        st = s == null ? null : new StringTokenizer(s);
    }

    String next() throws IOException {
        while (st == null || !st.hasMoreTokens()) {
            String line = in.readLine();
            if (line == null) {
                return null;
            }
            eat(line);
        }
        return st.nextToken();
    }

    int nextInt() throws IOException {
        return Integer.parseInt(next());
    }

    int[] nextIntArray() throws IOException {
        int n = nextInt();
        int[] rv = new int[n];
        for (int i = 0; i < n; ++i) {
            rv[i] = nextInt();
        }
        return rv;
    }

    int[] nextIntArrayFromLine() throws IOException {
        StringTokenizer st = new StringTokenizer(nextLine());
        int[] rv = new int[st.countTokens()];
        for (int i = 0; i < rv.length; ++i) {
            rv[i] = Integer.parseInt(st.nextToken());
        }
        return rv;
    }

    long nextLong() throws IOException {
        return Long.parseLong(next());
    }

    double nextDouble() throws IOException {
        return Double.parseDouble(next());
    }

    String nextLine() throws IOException {
        eat(null);
        return in.readLine();
    }

    public static void main(String[] args) {
        Locale.setDefault(Locale.US);
        new Thread(new C()).start();
    }
}