import java.io.*;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {
    private FastScanner in;
    private PrintWriter out;

    static final long mod = (long) 1e9 + 7;

    int calcSize(int v, ArrayList<Integer>[] g, int[] sz, int p) {
        sz[v] = 1;
        for (int to : g[v]) {
            if (to == p) {
                continue;
            }
            sz[v] += calcSize(to, g, sz, v);
        }
        return sz[v];
    }

    int findCentroid(int v, ArrayList<Integer>[] g, int[] sz, int p) {
        int result = v;
        int maxSize = sz[0] / 2;
        int next = -1;
        for (int to : g[v]) {
            if (to == p) {
                continue;
            }
            if (sz[to] > maxSize) {
                next = to;
            }
        }
        if (next != -1) {
            result = findCentroid(next, g, sz, v);
        }
        return result;
    }

    long[] fact(int n) {
        long[] res = new long[n];
        res[0] = 1;
        for (int i = 1; i < n; i++) {
            res[i] = res[i - 1] * i % mod;
        }
        return res;
    }

    int[][] c(int n) {
        int[][] c = new int[n][n];
        for (int i = 0; i < n; i++) {
            c[i][0] = 1;
            if (i == 0) {
                continue;
            }
            for (int j = 1; j < n; j++) {
                c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
                if (c[i][j] >= mod) {
                    c[i][j] -= mod;
                }
            }
        }
        return c;
    }

    int countWays(int[] sizes) {
        int n = 1;
        for (int x : sizes) {
            n += x;
        }
        int[][] c = c(n + 1);
        long[] fact = fact(n + 1);
        long[] dp = new long[n + 1]; // [stay]
        long[] ndp = new long[n + 1];
        int sum = 0;
        dp[0] = 1;
        for (int curSize : sizes) {
            Arrays.fill(ndp, 0);
            for (int stay = 0; stay <= sum; stay++) {
                long cur = dp[stay];
                if (cur == 0) {
                    continue;
                }
                for (int stayHere = 0; stayHere <= curSize; stayHere++) {
                    int next = stay + stayHere;
                    long ways = cur * c[curSize][stayHere] % mod;
                    ndp[next] += ways;
                    if (ndp[next] >= mod) {
                        ndp[next] -= mod;
                    }
                    cur = (cur * (curSize - stayHere)) % mod;
                }
            }
            sum += curSize;
            long[] tmp = dp;
            dp = ndp;
            ndp = tmp;
        }
        long result = 0;
        for (int stay = 0; stay < n; stay++) {
            long cur = dp[stay];
            if (cur == 0) {
                continue;
            }
            if (stay % 2 == 1) {
                cur = mod - cur;
            }
            cur = cur * fact[n - stay] % mod;
            result += cur;
        }
        return (int) (result % mod);
    }

    private void solve() {
        int n = in.nextInt();
        ArrayList<Integer>[] g = new ArrayList[n];
        for (int i = 0; i < n; i++) {
            g[i] = new ArrayList<>();
        }
        for (int i = 0; i + 1 < n; i++) {
            int fr = in.nextInt() - 1;
            int to = in.nextInt() - 1;
            g[fr].add(to);
            g[to].add(fr);
        }
        int[] sz = new int[n];
        calcSize(0, g, sz, -1);
        int root = findCentroid(0, g, sz, -1);
        Arrays.fill(sz, 0);
        calcSize(root, g, sz, -1);
        int[] sizes = new int[g[root].size()];
        for (int i = 0; i < sizes.length; i++) {
            sizes[i] = sz[g[root].get(i)];
        }
        for (int size : sizes) {
            if (size * 2 == n) {
                long res = fact(size + 1)[size];
                res = res * res % mod;
                out.println(res);
                return;
            }
        }
        int result = countWays(sizes);
        out.println(result);
    }

    private void run() {
        try {
            in = new FastScanner(new File("ARC_087_D.in"));
            out = new PrintWriter(new File("ARC_087_D.out"));

            solve();

            out.close();
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }
    }

    private void runIO() {
        in = new FastScanner(System.in);
        out = new PrintWriter(System.out);

        solve();

        out.close();
    }

    private class FastScanner {
        BufferedReader br;
        StringTokenizer st;

        FastScanner(File f) {
            try {
                br = new BufferedReader(new FileReader(f));
            } catch (FileNotFoundException e) {
                e.printStackTrace();
            }
        }

        FastScanner(InputStream f) {
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
} Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.