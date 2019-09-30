import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {

    static int N;
    static int M;
    static int[] F;

    static int MOD = 1_000_000_007;

    public static void main(String[] args) {
        FastScanner sc = new FastScanner(System.in);
        N = sc.nextInt();
        M = sc.nextInt();
        F = sc.nextIntArray(N);
        System.out.println(solve());
    }

    static int solve() {
        int[] dp = new int[N+1];
        int[] rui = new int[N+2];
        int[] next = new int[M+1];
        int div;
        Arrays.fill(next, -1);

        dp[N] = 1;
        div = N;
        rui[N] = 1;
        for (int i = N-1; i >= 0 ; i--) {
            int flavorNext = next[F[i]];
            if( flavorNext != -1 && flavorNext < div ) {
                div = flavorNext;
            }

            // div????????????????
            // -> [i, i], [i, i+1], [i, i+2]... [i, div-1]????????????
            // + ???[i, i+1] ??????, ??????dp[i+2]?????????
            // -> dp[i] = sigma(i+1, div){ x -> dp[x] }
            // ????????
            dp[i] = (rui[i+1] - rui[div+1] + MOD) % MOD;
            next[F[i]] = i;
            rui[i] = (dp[i] + rui[i+1]) % MOD;
        }
        return dp[0];
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