import java.io.*;
import java.util.*;

public class B {
    FastScanner in;
    PrintWriter out;

    Random rnd = new Random(123);

    void go(ArrayList<Integer>[] g, int v, int p, int[] sz, int[] dp) {
        sz[v]++;
        int[] costAlive = new int[3];
        costAlive[1] = costAlive[2] = Integer.MAX_VALUE;
        for (int x : g[v]) {
            if (x != p) {
                go(g, x, v, sz, dp);
                sz[v] += sz[x];
                int[] ncostAlive = new int[3];
                Arrays.fill(ncostAlive, Integer.MAX_VALUE);
                ncostAlive[0] = costAlive[0] + sz[x];
                for (int was = 0; was < 3; was++)
                    for (int curAlive = 0; curAlive < 2; curAlive++) {
                        if (costAlive[was] != Integer.MAX_VALUE
                                && was + curAlive < 3) {
                            int addCost = curAlive == 0 ? sz[x] : dp[x];
                            ncostAlive[was + curAlive] = Math.min(
                                    ncostAlive[was + curAlive], costAlive[was]
                                            + addCost);
                        }
                    }
                costAlive = ncostAlive;
            }
        }
        dp[v] = Math.min(costAlive[2], costAlive[0]);
    }

    int getAns(ArrayList<Integer>[] g, int root) {
        int n = g.length;
        int[] sz = new int[n];
        int[] dp = new int[n];
        go(g, root, -1, sz, dp);
        return dp[root];
    }

    void solve() throws IOException {
        int n = in.nextInt();
        ArrayList<Integer>[] g = new ArrayList[n];
        for (int i = 0; i < n; i++) {
            g[i] = new ArrayList<>();
        }
        for (int i = 0; i < n - 1; i++) {
            int fr = in.nextInt() - 1;
            int to = in.nextInt() - 1;
            g[fr].add(to);
            g[to].add(fr);
        }
        int ans = Integer.MAX_VALUE;
        for (int root = 0; root < n; root++) {
            ans = Math.min(ans, getAns(g, root));
        }
        out.println(ans);
    }

    void run() throws IOException {
        try {
            in = new FastScanner(new File("B.in"));
            out = new PrintWriter(new File("B.out"));

            int testNumber = in.nextInt();
            for (int test = 1; test <= testNumber; test++) {
                out.print("Case #" + (test) + ": ");
                solve();
                System.out.println(test);
            }

            out.close();
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }
    }

    void runIO() {

        in = new FastScanner(System.in);
        out = new PrintWriter(System.out);

        try {
            solve();
        } catch (IOException e) {
            // TODO Auto-generated catch block
            e.printStackTrace();
        }

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
    }

    public static void main(String[] args) throws IOException {
        new B().run();
    }
}