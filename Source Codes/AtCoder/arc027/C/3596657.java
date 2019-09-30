import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {

    static int X, Y;
    static int N;
    static int[] T, H;

    public static void main(String[] args) {
        FastScanner sc = new FastScanner(System.in);
        X = sc.nextInt();
        Y = sc.nextInt();
        N = sc.nextInt();
        T = new int[N];
        H = new int[N];
        for (int i = 0; i < N; i++) {
            T[i] = sc.nextInt();
            H[i] = sc.nextInt();
        }

        System.out.println(solve());
    }

    static int solve() {
        // i: item
        // j: ticket
        // dp[i][j]: happy
        int[][] dp = new int[maxItemAvailable() + 1][X+Y+1];
        for (int[] arr : dp) {
            Arrays.fill(arr, -1);
        }
        dp[0][0] = 0;

        for (int i = 0; i < N; i++) {
            calc(dp, T[i], H[i]);
        }

        int ans = -1;
        for (int i = 0; i <= maxItemAvailable(); i++) {
            for (int j = 0; j <= X+Y; j++) {
                ans = Math.max(dp[i][j], ans);
            }
        }
        return ans;
    }

    static int maxItemAvailable() {
        return Math.min(X, N);
    }

    static void calc(int[][] dp, int t, int h) {
        for (int i = maxItemAvailable()-1; i >= 0; i--) {
            for (int j = X+Y-1; j >= 0; j--) {
                if( dp[i][j] != -1 && j + t <= X+Y ) {
                    dp[i+1][j+t] = Math.max(dp[i][j] + h, dp[i+1][j+t]);
                }
            }
        }
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