import java.io.*;
import java.util.*;

public class Main {
    private FastScanner in;
    private PrintWriter out;

    class Condition {
        int l, r, cnt;

        public Condition(int l, int r, int cnt) {
            this.l = l;
            this.r = r;
            this.cnt = cnt;
        }
    }

    private void solve() {
        final int mod = (int) 1e9 + 7;
        int n = in.nextInt();
        int m = in.nextInt();
        ArrayList<Condition>[] conditions = new ArrayList[n + 1];
        for (int i = 0; i < conditions.length; i++) {
            conditions[i] = new ArrayList<>();
        }
        for (int i = 0; i < m; i++) {
            int fr = in.nextInt(), to = in.nextInt(), cnt = in.nextInt();
            conditions[to].add(new Condition(fr, to, cnt));
        }
        long[][] dp = new long[n][n];
        long[][] ndp = new long[n][n];
        dp[0][0] = 1;
        for (int pos = 1; pos <= n; pos++) {
            for (int i = 0; i < n; i++) {
                Arrays.fill(ndp[i], 0);
            }
            for (int p1 = 0; p1 < n; p1++) {
                for (int p2 = 0; p2 < n; p2++) {
                    long v = dp[p1][p2];
                    if (v == 0) {
                        continue;
                    }
                    if (pos == 1) {
                        ndp[0][0] += v * 3;
                    } else {
                        if (p1 == 0 && p2 == 0) {
                            ndp[0][0] += v;
                            ndp[0][pos - 1] += v * 2;
                        } else {
                            ndp[p1][p2] += v;
                            ndp[p1][pos - 1] += v;
                            ndp[p2][pos - 1] += v;
                        }
                    }
                }
            }
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    while (ndp[i][j] > mod) {
                        ndp[i][j] -= mod;
                    }
                    if (ndp[i][j] != 0) {
                        for (Condition c : conditions[pos]) {
                            int realC = 1;
                            if (i >= c.l) {
                                realC++;
                            }
                            if (j >= c.l) {
                                realC++;
                            }
                            if (realC != c.cnt) {
                                ndp[i][j] = 0;
                                break;
                            }
                        }
                    }
                }
            }
            long[][] tmp = dp;
            dp = ndp;
            ndp = tmp;
        }
        long res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                res += dp[i][j];
            }
        }
        out.println(res % mod);
    }

    private void run() {
        try {
            in = new FastScanner(new File("Main.in"));
            out = new PrintWriter(new File("Main.out"));

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