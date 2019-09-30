import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Comparator;
import java.util.StringTokenizer;

public class Main {
    int n, m;
    int[][] cond;
    int MOD = 1000000007;

    public static void main(String args[]) {
        new Main().run();
    }

    void run() {
        FastReader sc = new FastReader();
        n = sc.nextInt();
        m = sc.nextInt();
        cond = new int[m][3];
        for (int i = 0; i < m; i++) {
            cond[i][0] = sc.nextInt() - 1;
            cond[i][1] = sc.nextInt() - 1;
            cond[i][2] = sc.nextInt();
        }
        Arrays.sort(cond, new Comparator<int[]>() {
            @Override
            public int compare(int[] o1, int[] o2) {
                return o1[1] - o2[1];
            }
        });
        solve();
    }

    void solve() {
        long[][] dp = new long[n + 1][n + 1];
        dp[0][0] = 1;
        int p = 0;
        // i-th character
        for (int i = 0; i < n; i++) {
            long[][] ndp = new long[n + 1][n + 1];
            int[] maxs = new int[4];
            int[] mins = new int[4];
            Arrays.fill(maxs, -1);
            Arrays.fill(mins, 9999);
            while (p < m && cond[p][1] <= i) {
                maxs[cond[p][2]] = Math.max(maxs[cond[p][2]], cond[p][1] - cond[p][0] + 1);
                mins[cond[p][2]] = Math.min(mins[cond[p][2]], cond[p][1] - cond[p][0] + 1);
                p++;
            }
            for (int j = 0; j <= n; j++) {
                for (int k = j; k <= n; k++) {
                    if (dp[j][k] == 0) {
                        continue;
                    }
                    {
                        int nj = j + 1;
                        int nk = k + 1;
                        if (maxs[1] == -1 || maxs[1] <= nj) {
                            if (maxs[2] == -1 || nj < mins[2] && maxs[2] <= nk) {
                                if (maxs[3] == -1 || nk < mins[3]) {
                                    ndp[nj][nk] += dp[j][k];
                                    if (ndp[nj][nk] >= MOD) {
                                        ndp[nj][nk] -= MOD;
                                    }
                                }
                            }
                        }
                    }
                    {
                        int nj = 1;
                        int nk = k + 1;
                        if (maxs[1] == -1 || maxs[1] <= nj) {
                            if (maxs[2] == -1 || nj < mins[2] && maxs[2] <= nk) {
                                if (maxs[3] == -1 || nk < mins[3]) {
                                    ndp[nj][nk] += dp[j][k];
                                    if (ndp[nj][nk] >= MOD) {
                                        ndp[nj][nk] -= MOD;
                                    }
                                }
                            }
                        }
                    }
                    {
                        int nj = 1;
                        int nk = j + 1;
                        if (maxs[1] == -1 || maxs[1] <= nj) {
                            if (maxs[2] == -1 || nj < mins[2] && maxs[2] <= nk) {
                                if (maxs[3] == -1 || nk < mins[3]) {
                                    ndp[nj][nk] += dp[j][k];
                                    if (ndp[nj][nk] >= MOD) {
                                        ndp[nj][nk] -= MOD;
                                    }
                                }
                            }
                        }
                    }
                }
            }
            dp = ndp;
        }
        long ans = 0;
        for (int j = 0; j <= n; j++) {
            for (int k = j; k <= n; k++) {
                ans += dp[j][k];
            }
        }
        System.out.println(ans % MOD);
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