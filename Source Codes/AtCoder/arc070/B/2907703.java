import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {

    static int N;
    static int K;
    static int[] A;

    public static void main(String[] args) {
        FastScanner sc = new FastScanner(System.in);
        N = sc.nextInt();
        K = sc.nextInt();
        A = sc.nextIntArray(N);
        System.out.println(solve());
    }

    static boolean[][] dp;

    static long solve() {
        Arrays.sort(A);

        dp = new boolean[N+1][K+1];

        int lo = 0;
        int hi = N-1;

        while(lo <= hi) {
            int mid = (lo + hi) / 2;

            boolean r = runDp(mid);
            if( r ) {
                hi = mid-1;

            } else {
                lo = mid+1;
            }
        }
        return lo;
    }

    static boolean runDp(int x) {
        if( A[x] >= K ) return true;

        for (boolean[] each : dp) {
            Arrays.fill(each, false);
        }
        dp[0][0] = true;

        // x??????DP?????
        // -> x?copy?
        for (int i = 1; i <= N; i++) {
            if( i-1 == x ) {
                System.arraycopy(dp[i - 1], 0, dp[i], 0, K+1);

            } else {
                int a = A[i-1];
                for (int j = 0; j <= K; j++) {
                    dp[i][j] |= dp[i-1][j];
                    dp[i][Math.min(K, j+a)] |= dp[i-1][j];
                }
            }
        }

        for (int j = K - A[x]; j < K; j++) {
            if( dp[N][j] ) {
                return true;
            }
        }
        return false;
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