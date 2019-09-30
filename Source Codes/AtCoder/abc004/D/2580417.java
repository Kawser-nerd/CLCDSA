import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {
    int r, g, b;

    public static void main(String args[]) {
        new Main().run();
    }

    void run() {
        FastReader sc = new FastReader();
        r = sc.nextInt();
        g = sc.nextInt();
        b = sc.nextInt();
        solve();
    }

    void solve() {
        int[][] dp = new int[2000][1000];
        for (int i = 0; i < 2000; i++) {
            Arrays.fill(dp[i], 1 << 30);
        }
        for (int i = 0; i < 2000; i++) {
            dp[i][r + g + b] = 0;
        }
        for (int j = r + g + b - 1; j >= 0; j--) {
            for (int i = 1; i < 2000; i++) {
                if (j >= g + b) {
                    dp[i][j] = Math.min(dp[i - 1][j], Math.abs(i - 900) + dp[i - 1][j + 1]);
                } else if (j >= b) {
                    dp[i][j] = Math.min(dp[i - 1][j], Math.abs(i - 1000) + dp[i - 1][j + 1]);
                } else {
                    dp[i][j] = Math.min(dp[i - 1][j], Math.abs(i - 1100) + dp[i - 1][j + 1]);
                }
            }
        }
        int min = Integer.MAX_VALUE;
        for (int i = 0; i < 2000; i++) {
            if (dp[i][0] < min) {
                min = dp[i][0];
            }
        }
        System.out.println(min);
    }

    int solveOneTower(int n) {
        int ans = n / 2 * (n / 2 + 1);
        if (n % 2 == 1) {
            ans += n / 2 + 1;
        }
        return ans;
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