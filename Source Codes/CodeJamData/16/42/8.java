import java.io.*;
import java.util.*;

public class RedTape {

    public void solve() {
        int n = in.nextInt(), k = in.nextInt();
        double[] a = new double[n];
        for (int i = 0; i < n; i++) {
            a[i] = in.nextDouble();
        }
        Arrays.sort(a);
        double best = fast(n, k, a);
        out.println(best);
    }

    double fast(int n, int k, double[] a) {
        double best = 0;
        for (int i = 0; i <= k; i++) {
            double[] b = new double[k];
            for (int j = 0, ptr = 0; j < n; j++) {
                if (j < i || j >= n - (k - i)) {
                    b[ptr++] = a[j];
                }
            }
            best = Math.max(best, get(b));
        }
        return best;
    }

    private double slow(int n, int k, double[] a) {
        double best = 0;
        int bestMask = 0;
        for (int mask = 0; mask < 1 << n; mask++) {
            if (Integer.bitCount(mask) == k) {
                double[] b = new double[k];
                for (int i = 0, ptr = 0; i < n; i++) {
                    if ((mask & (1 << i)) != 0) {
                        b[ptr++] = a[i];
                    }
                }
                double cur = get(b);
                if (cur > best) {
                    best = cur;
                    bestMask = mask;
                }
            }
        }
        System.err.println(Integer.toBinaryString(bestMask));
        return best;
    }

    private double get(double[] b) {
        int n = b.length;
        double[][] dp = new double[n + 1][n + 1];
        dp[0][0] = 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= i; j++) {
                dp[i + 1][j + 1] += dp[i][j] * b[i];
                dp[i + 1][j] += dp[i][j] * (1 - b[i]);
            }
        }
        return dp[n][n / 2];
    }

    public void run() {
        try {
            in = new FastScanner("input.txt");
            out = new PrintWriter("output.txt");
            int tests = in.nextInt();
            for (int i = 1; i <= tests; i++) {
                long time = System.currentTimeMillis();
                out.printf("Case #%d: ", i);
                solve();
                System.err.printf("Solved case #%d in %d ms\n", i, System.currentTimeMillis() - time);
            }
            out.close();
        } catch (FileNotFoundException e) {
        }
    }

    FastScanner in;
    PrintWriter out;

    class FastScanner {
        BufferedReader br;
        StringTokenizer st;

        public FastScanner(String fileName) {
            try {
                br = new BufferedReader(new FileReader(fileName));
            } catch (FileNotFoundException e) {
            }
        }

        String nextToken() {
            while (st == null || !st.hasMoreElements()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                }
            }
            return st.nextToken();
        }

        int nextInt() {
            return Integer.parseInt(nextToken());
        }

        long nextLong() {
            return Long.parseLong(nextToken());
        }

        double nextDouble() {
            return Double.parseDouble(nextToken());
        }
    }

    public static void main(String[] args) {
        new RedTape().run();
    }
}
