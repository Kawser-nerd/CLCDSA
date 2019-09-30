import java.io.*;
import java.util.*;

public class Main {
    FastScanner in;
    PrintWriter out;

    int mod;

    int add(int x, int y) {
        x += y;
        return x >= mod ? (x -mod) : x;
    }

    int mul(int x, int y) {
        return (int) ((x * 1L * y % mod));
    }

    void solve() {
        int n = in.nextInt();
        int k = in.nextInt();
        mod = in.nextInt();
        int[][] c = new int[n + 1][n + 1];
        c[0][0] = 1;
        for (int i = 1; i < c.length; i++) {
            c[i][0] = 1;
            for (int j = 1; j < c[i].length; j++) {
                c[i][j] = add(c[i - 1][j - 1], c[i - 1][j]);
            }
        }
        // [len][last]
        int[][] dp = new int[n + 1][k + 1];
        Arrays.fill(dp[0], 1);
        for (int curLen = 1; curLen <= n; curLen++) {
            for (int pos = 0; pos < curLen; pos++) {
                int sum = 0;
                for (int nextValue = k; nextValue >= 0; nextValue--) {
                    dp[curLen][nextValue] = add(dp[curLen][nextValue], mul(sum, mul(c[curLen - 1][pos], dp[curLen - pos - 1][nextValue])));
                    sum = add(sum, dp[pos][nextValue]);
                }
            }
        }
        out.println(dp[n][0]);
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