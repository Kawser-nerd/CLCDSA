import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    static int N;
    static int[] A;

    public static void main(String[] args) {
        FastScanner fc = new FastScanner(System.in);
        N = fc.nextInt();
        A = fc.nextIntArray(N);
        System.out.println(solve());
    }

    static int MOD = 1_000_000_007;

    static int solve() {
        int ans = 1;
        int prev = A[0];
        int prevIdx = 0;
        for (int i = 1; i < N-1; i++) {
            if( A[i] != -1 ) {
                int curr = A[i];
                ans = mul(ans, calc(prev, curr, i-prevIdx));
                prev = curr;
                prevIdx = i;
            }
        }
        ans = mul(ans, calc(prev, A[N-1], N-1-prevIdx));
        return ans;
    }

    static int calc(int from, int to, int len) {
        // len?from??to???
        // to-from??increment?len-1?????????
        // comb(to-from+len-1, len-1)
        int n = to - from + len - 1;
        int k = len - 1;

        // comb(n, k)
        // = n! / k!(n-k)!
        // = n*n-1*... * inv(k!)

        int a = 1;
        for (int i = 0; i < k; i++) {
            a = mul(n-i, a);
        }
        int b = 1;
        for (int i = 1; i <= k; i++) {
            b = mul(i, b);
        }

        return mul(a, pow(b, MOD-2) );
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