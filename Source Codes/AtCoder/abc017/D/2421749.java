import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {
    int n, m;
    int[] fs;
    int MOD = 1000000007;

    public static void main(String args[]) {
        new Main().run();
    }

    void run() {
        FastReader sc = new FastReader();
        n = sc.nextInt();
        m = sc.nextInt();
        fs = new int[n];
        for (int i = 0; i < n; i++) {
            fs[i] = sc.nextInt() - 1;
        }
        solve();
    }

    void solve() {
        long[] dp = new long[n + 1];
        dp[0] = 1;
        int[] tastes = new int[m];
        int left = 0;
        long sum = dp[0];
        for (int i = 0; i < n; i++) {
            tastes[fs[i]]++;
            while (tastes[fs[i]] > 1) {
                tastes[fs[left]]--;
                sum -= dp[left++];
                sum = (sum + MOD) % MOD;
            }
            dp[i + 1] = sum;
            sum += dp[i + 1];
            sum %= MOD;
        }
        System.out.println(dp[n]);
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