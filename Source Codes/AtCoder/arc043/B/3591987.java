import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {

    static int N;
    static int[] D;

    public static void main(String[] args) {
        FastScanner sc = new FastScanner(System.in);
        N = sc.nextInt();
        D = sc.nextIntArray(N);

        System.out.println(solve());
    }

    static int MOD = 1_000_000_007;

    static long solve() {
        Arrays.sort(D);
        int[][] dp = new int[N][3];
        long ans = 0;
        for (int i = 0; i < N; i++) {
            int d = D[i];

            if( i > 0 ) {
                dp[i][0] += dp[i-1][0];
                dp[i][0] %= MOD;

                dp[i][1] += dp[i-1][1];
                dp[i][1] %= MOD;

                dp[i][2] += dp[i-1][2];
                dp[i][2] %= MOD;
            }

            int idx = lowerBound(D, d*2);
            if( idx != N ) {
                // 1(??) -> 2
                dp[idx][0] += 1;
                dp[idx][0] %= MOD;

                // 2 -> 3
                dp[idx][1] += dp[i][0];
                dp[idx][1] %= MOD;

                // 3 -> 4(??)
                dp[idx][2] += dp[i][1];
                dp[idx][2] %= MOD;
            }

            ans += dp[i][2];
            ans %= MOD;
        }

        return ans;
    }

    static int lowerBound(int[] array, int value) {
        int low = 0;
        int high = array.length;
        int mid;
        while( low < high ) {
            mid = ((high - low) >>> 1) + low; // (high + low) / 2
            if( array[mid] < value ) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        return low;
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