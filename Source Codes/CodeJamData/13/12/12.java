import java.io.*;
import java.util.*;

public class B {
    FastScanner in;
    PrintWriter out;

    Random rnd = new Random(123);

    void solve(int testId) throws IOException {
        int e = in.nextInt();
        int r = in.nextInt();
        int n = in.nextInt();
        int[] v = new int[n];
        int[] cntUsed = new int[n];
        for (int i = 0; i < n; i++) {
            v[i] = in.nextInt();
        }
        boolean[] used = new boolean[n];
        int[] next = new int[n];
        Arrays.fill(next, Integer.MAX_VALUE);
        long res = 0;
        for (int i = 0; i < n; i++) {
            int bestId = -1;
            int curV = -1;
            for (int j = 0; j < n; j++)
                if (!used[j] && v[j] > curV) {
                    curV = v[j];
                    bestId = j;
                }
            int add = e;
            for (int j = 0; j < bestId; j++) {
                add -= cntUsed[j] - r;
                if (add > e)
                    add = e;
            }
            int nextM = next[bestId] - bestId;
            long addM = Math.min(e, nextM * 1L * r);
            int need = (int) Math.max(0, e - addM);
            add -= need;
            if (add < 0)
                add = 0;
            res += add * 1L * curV;
            used[bestId] = true;
            cntUsed[bestId] = add;
            for (int j = bestId - 1; j >= 0; j--) {
                next[j] = Math.min(next[j], bestId);
            }
        }
        int xx = e;
        //long xxx = solve2(e, r, n, v);
        for (int i = 0; i < n; i++) {
            if (xx < cntUsed[i] ) {
                System.err.println(e + " " + r + " " + n);
                System.err.println(Arrays.toString(v));
                throw new AssertionError();
            }
            xx = Math.min((xx + r) - cntUsed[i], e);
        }
        out.println(res);
    }

    long solve2(int e, int r, int n, int[] v) throws IOException {
        long res = 0;
        long[][] dp = new long[n + 1][e + 1];
        dp[0][e] = 0;
        for (int i = 0; i < n; i++)
            for (int have = 0; have <= e; have++)
                for (int use = 0; use <= have; use++) {
                    int nn = Math.min((have - use + r), e);
                    dp[i + 1][nn] = Math.max(dp[i + 1][nn], dp[i][have] + use
                            * v[i]);
                }
        for (int h = 0; h <= e; h++)
            res = Math.max(res, dp[n][h]);
        return res;
    }

    void run() throws IOException {
        try {
            in = new FastScanner(new File("B.in"));
            out = new PrintWriter(new File("B.out"));

            int testNumber = in.nextInt();
            for (int test = 1; test <= testNumber; test++) {
                out.print("Case #" + (test) + ": ");
                solve(test);
                System.out.println(test);
            }

            out.close();
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }
    }

    // void runIO() {
    //
    // in = new FastScanner(System.in);
    // out = new PrintWriter(System.out);
    //
    // try {
    // solve();
    // } catch (IOException e) {
    // // TODO Auto-generated catch block
    // e.printStackTrace();
    // }
    //
    // out.close();
    // }

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