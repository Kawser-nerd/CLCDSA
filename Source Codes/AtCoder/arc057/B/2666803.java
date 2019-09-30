import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {
    int n, k;
    int[] as;
    int daySum = 0;

    public static void main(String args[]) {
        new Main().run();
    }

    void run() {
        FastReader sc = new FastReader();
        n = sc.nextInt();
        k = sc.nextInt();
        as = new int[n];
        for (int i = 0; i < n; i++) {
            as[i] = sc.nextInt();
            daySum += as[i];
        }
        solve();
    }

    void solve() {
        if (k == 0) {
            System.out.println(0);
            return;
        }
        if (daySum == k) {
            System.out.println(1);
            return;
        }
        int[] ss = new int[n + 1];
        for (int i = 1; i <= n; i++) {
            ss[i] = as[i - 1] + ss[i - 1];
        }

        long[][] dp = new long[n + 1][n + 1];
        for (int i = 0; i <= n; i++) {
            Arrays.fill(dp[i], 1 << 30);
        }
        dp[1][1] = 1;
        dp[1][0] = 0;
        for (int i = 2; i <= n; i++) {
            for (int j = 1; j <= i; j++) {
                //int win = dp[i - 1][j - 1] * ss[i] / ss[i - 1] + 1
                //        - dp[i - 1][j - 1];
                long win = dp[i - 1][j - 1] * as[i - 1];
                win = (win / ss[i - 1]) + 1;
                if (win <= as[i - 1]) {
                    dp[i][j] = Math.min(dp[i - 1][j],
                            dp[i - 1][j - 1] + win);
                }
                dp[i][j - 1] = Math.min(dp[i][j - 1], dp[i - 1][j - 1]);
            }
        }
        int ans = 0;
        for (int i = 0; i <= n; i++) {
            if (dp[n][i] <= k) {
                ans = i;
            }
        }
        System.out.println(ans);
    }

    static class FastReader {
        BufferedReader br;
        StringTokenizer st;

        public FastReader() {
            br = new BufferedReader(new
                    InputStreamReader(System.in));
        }

        String next() {
            while (st == null || !st.hasMoreElements())
            {
                try
                {
                    st = new StringTokenizer(br.readLine());
                }
                catch (IOException e)
                {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }

        int nextInt()
        {
            return Integer.parseInt(next());
        }

        long nextLong()
        {
            return Long.parseLong(next());
        }

        double nextDouble()
        {
            return Double.parseDouble(next());
        }

        String nextLine() {
            String str = "";
            try
            {
                str = br.readLine();
            }
            catch (IOException e)
            {
                e.printStackTrace();
            }
            return str;
        }
    }
}