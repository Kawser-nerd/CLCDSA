import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    char[] cs;

    public static void main(String args[]) {
        new Main().run();
    }

    void run() {
        FastReader sc = new FastReader();
        cs = sc.next().toCharArray();
        solve();
    }

    void solve() {
        int[] nDigits = new int[cs.length];
        for (int i = 0; i < cs.length; i++) {
            nDigits[i] = Character.getNumericValue(cs[i]);
        }

        long[][][] dp = new long[10][2][10];
        dp[0][0][0] = 1;
        for (int i = 0; i < nDigits.length; i++) {
            for (int j = 0; j < 2; j++) {
                for (int k = 0; k < 10; k++) {
                    int limit = j > 0 ? 9 : nDigits[i];
                    for (int l = 0; l <= limit; l++) {
                        int jNum = j;
                        if (l < limit) {
                            jNum = 1;
                        }
                        int kNum = k + (l == 1 ? 1 : 0);
                        if (dp[i][j][k] == 0) {
                            continue;
                        }
                        dp[i + 1][jNum][kNum] += dp[i][j][k];
                    }
                }
            }
        }
        long count = 0;

        for (int j = 0 ; j < 2; j++) {
            for (int k = 1; k < 10; k++) {
                count = count + dp[nDigits.length][j][k] * k;
            }
        }
        System.out.println(count);
    }

    long pow(long x, int n) {
        long ans = 1;
        while (n > 0) {
            if ((n & 1) == 1) {
                ans = ans * x;
            }
            x = x * x;
            n >>= 1;
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