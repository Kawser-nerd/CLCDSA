import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {

    static int N, X, Y, Z;

    public static void main(String[] args) {
        FastScanner sc = new FastScanner(System.in);
        N = sc.nextInt();
        X = sc.nextInt();
        Y = sc.nextInt();
        Z = sc.nextInt();

        System.out.println(solve());
    }

    static int MOD = 1_000_000_007;

    static long solve() {
        int B = X+Y+Z;
        int BN = 1 << B;
        // bit, [1, 10] => bit \/ -1(XYZ??)
        int[][] MEMO = new int[BN][10];
        int OK = (1 << X+Y+Z-1) | (1 << Y+Z-1) | (1 << Z-1);
        int MASK = (1 << X+Y+Z) - 1;
        for (int i = 0; i < BN; i++) {
            for (int j = 0; j < 10; j++) {

                int next = (i << (j+1)) | (1 << j);
                next &= MASK;
                if( (OK & next) == OK ) {
                    MEMO[i][j] = -1;
                } else {
                    MEMO[i][j] = next;
                }
            }
        }

        long[] dp = new long[BN];
        long[] prev = new long[BN];
        dp[0] = 1;
        for (int i = 0; i < N; i++) {
            long[] temp = dp;
            dp = prev;
            prev = temp;

            Arrays.fill(dp, 0);

            for (int bit = 0; bit < BN; bit++) {
                if( prev[bit] == 0 ) continue;

                for (int n = 0; n < 10; n++) {
                    int next = MEMO[bit][n];
                    if( next != -1 ) {
                        dp[next] += prev[bit];
                        dp[next] %= MOD;
                    }
                }
            }
        }
        int sum = 0;
        for (int bit = 0; bit < BN; bit++) {
            sum += dp[bit];
            sum %= MOD;
        }
        return (pow(10, N) - sum + MOD) % MOD;
    }

    static int pow(int base, int exp) {
        if( exp == 0 ) return 1;

        int ans = 1;
        base %= MOD;
        while( exp > 0 ) {
            if( (exp & 1) == 1 ) {
                ans = mul(ans, base);
            }

            base = mul(base, base);
            exp = exp >> 1;
        }
        return ans;
    }

    static int mul(int a, int b) {
        return (int)((long)a * b % MOD);
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