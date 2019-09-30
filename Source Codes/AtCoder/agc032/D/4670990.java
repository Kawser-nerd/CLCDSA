import java.io.*;
import java.util.*;

public class Main {
    FastScanner in;
    PrintWriter out;

    void solve() {
        int n = in.nextInt();
        int a = in.nextInt();
        int b = in.nextInt();
        int[] nums = new int[n];
        for (int i = 0; i < n; i++) {
            nums[i] = in.nextInt();
        }
        long[] dp = new long[n + 1];
        long[] ndp = new long[n + 1];
        for (int v : nums) {
            Arrays.fill(ndp, Long.MAX_VALUE / 2);
            for (int curMax = 0; curMax <= n; curMax++) {
                long cost = dp[curMax];
                if (v < curMax) {
                    ndp[curMax] = Math.min(ndp[curMax], cost + b);
                } else {
                    ndp[curMax] = Math.min(ndp[curMax], cost + a);
                    ndp[v] = Math.min(ndp[v], cost);
                }
            }
            long[] tmp = dp;
            dp = ndp;
            ndp = tmp;
        }
        long res = Long.MAX_VALUE;
        for (long z : dp) {
            res = Math.min(res, z);
        }
        out.println(res);
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