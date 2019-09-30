import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    int n, q;
    int[][] dss;
    int[] ps;

    public static void main(String args[]) {
        new Main().run();
    }

    void run() {
        FastReader sc = new FastReader();
        n = sc.nextInt();
        dss = new int[n + 1][n + 1];
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                dss[i][j] = sc.nextInt();
            }
        }
        q = sc.nextInt();
        ps = new int[q];
        for (int i = 0; i < q; i++) {
            ps[i] = sc.nextInt();
        }
        solve();
    }

    void solve() {
        int[][] sumss = new int[n + 1][n + 1];
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                sumss[i][j] = sumss[i - 1][j] + sumss[i][j - 1] -
                        sumss[i - 1][j - 1] + dss[i][j];
            }
        }
        int[] ans = new int[(n + 1) * (n + 1)];
        for (int i = 1; i <= n; i++) {
            for (int j = i; j <= n; j++) {
                for (int k = 1; k <= n; k++) {
                    for (int l = k; l <= n; l++) {
                        int area = (l - k + 1) * (j - i + 1);
                        int sum = sumss[j][l] - sumss[i - 1][l] -
                                sumss[j][k - 1] + sumss[i - 1][k - 1];
                        ans[area] = Math.max(ans[area], sum);
                    }
                }
            }
        }
        for (int i = 1; i < ans.length; i++) {
            ans[i] = Math.max(ans[i], ans[i - 1]);
        }
        for (int i = 0; i < q; i++) {
            System.out.println(ans[ps[i]]);
        }
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