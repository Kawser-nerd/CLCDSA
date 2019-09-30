import java.util.*;
import java.io.*;

public class B {
    public void run() throws IOException {
        in = new FastScanner(new FileInputStream("B-large.in"));
        out = new PrintWriter(new FileOutputStream("B-large.out"));

        int tn = in.nextInt();
        for (int test = 1; test <= tn; test++) {
            int n = in.nextInt();
            int x = in.nextInt();
            int y = in.nextInt();
            if (x < 0) {
                x = -x;
            }

            int v = 1;
            int m = 0;
            while (m + v + v - 1 <= n) {
                m = m + v + v - 1;
                v += 2;
            }

            double[][] dp = new double[v + 1][v + 1];
            dp[0][0] = 1.0;
            for (int s = 0; s < n - m; s++) {
                for (int i = 0; i < v && i <= s; i++) {
                    int j = s - i;
                    if (!(i >= 0 && j >= 0 && i < v && j < v)) {
                        continue;
                    }
                    if (i < v - 1 && j < v - 1) {
                        dp[i + 1][j] += 0.5 * dp[i][j];
                        dp[i][j + 1] += 0.5 * dp[i][j];
                    } else if (i < v - 1) {
                        dp[i + 1][j] += dp[i][j];
                    } else if (j < v - 1) {
                        dp[i][j + 1] += dp[i][j];
                    } else {
                        throw new AssertionError();
                    }
                    dp[i][j] = 0;
                }
            }

//            System.out.println(v);
//            System.out.println(n - m);
//            System.out.println(Arrays.deepToString(dp));

            double ans = 0;
            if ((x + y) / 2 < (v - 1) / 2) {
                System.out.println("A");
                ans = 1.0;
            } else if ((x + y) / 2 > (v - 1) / 2) {
                System.out.println("B");
                ans = 0.0;
            } else {
                System.out.println("C");
                int p = (y - x) / 2 + (v - 1) / 2;
                System.out.println(x + " " + y + " " + (v - 1) / 2 + " " + p);
                for (int i = 0; i <= v; i++) {
                    int j = n- m - i;
                    if (i >= 0 && j >= 0 && i > p && i <= v && j <= v) {
                        System.out.println(i + " " + j);
                        ans += dp[i][j];
                    }
                }

            }
            out.println("Case #" + test + ": " + ans);
        }

        out.close();
    }

    FastScanner in;
    PrintWriter out;

    public static void main(String[] args) throws IOException {
        Locale.setDefault(Locale.US);
        new B().run();
    }

    static class FastScanner {
        BufferedReader br;
        StringTokenizer st;

        FastScanner(InputStream in) throws IOException {
            br = new BufferedReader(new InputStreamReader(in));
        }

        String next() {
            try {
                while (st == null || !st.hasMoreTokens()) {
                    st = new StringTokenizer(br.readLine());
                }
            } catch (IOException e) {
                System.err.println(e);
                System.exit(1);
            }
            return st.nextToken();
        }

        int nextInt() {
            return Integer.parseInt(next());
        }
    }
}