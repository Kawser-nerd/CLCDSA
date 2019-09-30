import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.math.BigDecimal;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {

    static int N;
    static int D;
    static int X;
    static int Y;

    public static void main(String[] args) {
        FastScanner fc = new FastScanner(System.in);
        N = fc.nextInt();
        D = fc.nextInt();
        X = Math.abs(fc.nextInt());
        Y = Math.abs(fc.nextInt());
        System.out.println( BigDecimal.valueOf(solve()).toPlainString() );
    }

    static double[][] P;

    static double solve() {
        if( X % D != 0 || Y % D != 0 ) return 0.0;

        int u = X / D;
        int r = Y / D;
        if( u + r > N ) {
            return 0.0;
        }

        int remain = N - (u + r);
        if( remain % 2 != 0 ) {
            return 0.0;
        }

        P = initP();

        if( remain == 0 ) {
            return calc(u, 0, 0, r);
        }

        double ans = 0;
        for (int ud = 0; ud <= remain/2; ud++) {
            int lr = remain/2 - ud;
            ans += calc(u+ud, ud, lr, r+lr);
        }
        return ans;
    }

    static double calc(int u, int d, int l, int r) {
        // P?1/2???????1/2??????????????????
        return P[N][u+d] * P[u+d][u] * P[l+r][r];
    }

    static double[][] initP() {
        double[][] dp = new double[N+1][N+1];
        dp[0][0] = 1.0;
        for (int i = 1; i <= N; i++) {
            for (int j = 0; j <= i; j++) {

                if( j == 0 ) {
                    dp[i][j] = dp[i-1][j] / 2;

                } else if( j == i ) {
                    dp[i][j] = dp[i-1][j-1] / 2;

                } else {
                    dp[i][j] = (dp[i-1][j] + dp[i-1][j-1]) / 2;
                }
            }
        }
        return dp;
    }

    @SuppressWarnings("unused")
    static class FastScanner {
        private BufferedReader reader;
        private StringTokenizer tokenizer;

        FastScanner(InputStream in) {
            reader = new BufferedReader(new InputStreamReader(in));
            tokenizer = null;
        }

        String next() {
            if (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    tokenizer = new StringTokenizer(reader.readLine());
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
            return tokenizer.nextToken();
        }

        String nextLine() {
            if (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    return reader.readLine();
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
            return tokenizer.nextToken("\n");
        }

        long nextLong() {
            return Long.parseLong(next());
        }

        int nextInt() {
            return Integer.parseInt(next());
        }

        int[] nextIntArray(int n) {
            int[] a = new int[n];
            for (int i = 0; i < n; i++)
                a[i] = nextInt();
            return a;
        }

        long[] nextLongArray(int n) {
            long[] a = new long[n];
            for (int i = 0; i < n; i++)
                a[i] = nextLong();
            return a;
        }
    }
}