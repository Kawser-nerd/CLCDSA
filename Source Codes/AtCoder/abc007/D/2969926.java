import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {

    static long A;
    static long B;

    public static void main(String[] args) {
        FastScanner sc = new FastScanner(System.in);
        A = sc.nextLong();
        B = sc.nextLong();

        System.out.println(solve());
    }

    static long solve() {
        long[] dp = new long[19];

        dp[1] = 2;
        for (int k = 2; k <= 18; k++) {
            long n = (long)Math.pow(10, k-1); // 2???10

            // [0, 1, 2, 3, 5, 6, 7, 8] * dp[k-1]
            // [4, 9] * n
            dp[k] = dp[k-1] * 8 + n * 2;
        }

        long b = calc(B, dp);
        long a1 = calc(A-1, dp);
        return b - a1;
    }

    static long calc(long a, long[] dp) {
        long ret = 0;
        for (int k = 19; k >= 1; k--) {
            long n = (long)Math.pow(10, k-1);

            long d = a / n;
            a = a % n;

            if( d == 0 ) {
                continue;

            } else if ( d == 1 || d == 2 || d == 3 ) {
                // 232
                // [0, 99], [100, 199] = dp[2] * 2
                // 200 = 0
                // 32 => ??????
                ret += dp[k-1] * d;

            } else if( d == 4 ) {
                //?432
                // [0, 99], [100, 199], [200, 299], [300, 399] = dp[2] * 4
                // [400 - 432] = 32 + 1
                ret += dp[k-1] * 4;
                ret += a + 1;
                return ret;

            } else if( d == 5 || d == 6 || d == 7 || d == 8 ) {
                // 632
                // [0, 99], [100, 199], [200, 299], [300, 399], [500, 599] = dp[2] * 5
                // [400-499] = 100
                // 600 = 0
                // 32 => ??????
                ret += dp[k-1] * (d-1);
                ret += n;

            } else if( d == 9 ) {
                ret += dp[k-1] * 8; // [0, 1, 2, 3, 5, 6, 7, 8]
                ret += n; // 4
                ret += a + 1;
                return ret;
            }
        }

        if( a == 9 ) ret++;
        if( a >= 4 ) ret++;
        return ret;
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