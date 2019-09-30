import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.StringTokenizer;

public class Main {

    static int W;
    static int N;
    static int K;
    static int[] A; // ?
    static int[] B; // ???

    public static void main(String[] args) {
        FastScanner sc = new FastScanner(System.in);
        W = sc.nextInt();
        N = sc.nextInt();
        K = sc.nextInt();
        A = new int[N];
        B = new int[N];
        for (int i = 0; i < N; i++) {
            A[i] = sc.nextInt();
            B[i] = sc.nextInt();
        }
        System.out.println( solve() );
    }

    static int solve() {
        // ??? -> ????
        int MAX_B = N*100;
        int INF = Integer.MAX_VALUE / 2;
        int[][] dp = new int[K+1][MAX_B + 1];
        for (int[] arr : dp) {
            Arrays.fill(arr, INF);
        }
        dp[0][0] = 0;

        for (int i = 0; i < N; i++) {
            for (int k = K; k >= 1; k--) {
                for (int b = MAX_B; b >= 0; b--) {
                    if( B[i] <= b && dp[k-1][b-B[i]] != INF ) {
                        dp[k][b] = Math.min(dp[k-1][b-B[i]] + A[i], dp[k][b]);
                    }
                }
            }
        }

        int ans = 0;
        for (int k = 1; k <= K; k++) {
            for (int b = MAX_B; b >= 0; b--) {
                if( dp[k][b] != INF && dp[k][b] <= W) {
                    ans = Math.max(b, ans);
                    break;
                }
            }
        }
        return ans;
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