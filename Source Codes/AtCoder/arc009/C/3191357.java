import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    static long N;
    static int K;
    static int MOD = 1_777_777_777;

    public static void main(String[] args) {
        FastScanner fc = new FastScanner(System.in);
        N = fc.nextLong();
        K = fc.nextInt();
        System.out.println(solve());
    }

    static int solve() {
        return (int)((long)comb(N, K) * montmort(K) % MOD);
    }

    static int comb(long n, int k) {
        if( k > n-k ) k = (int)n-k;
        if( k == 0 ) return 1;

        long a = 1;
        for (int i = 0; i < k; i++) {
            a = a * ((n-i) % MOD) % MOD;
        }
        long b = pow(fact(k), MOD-2);

        return (int)(a * b % MOD);
    }

    private static int fact(int n) {
        long ret = 1;
        for (int i = 2; i <= n; i++) {
            ret = ret * i % MOD;
        }
        return (int)ret;
    }

    // ??????
    // ????(????)??
    static int montmort(int n) {
        if( n == 1 ) return 0;
        if( n == 2 ) return 1;

        long m1 = 1; // ???
        long m2 = 0; // ???
        long m = -1;
        for (int i = 3; i <= n; i++) {
            m = (i-1) * (m1 + m2) % MOD;

            m2 = m1;
            m1 = m;
        }
        return (int)m;
    }

    // ??????pow
    // Primes???????
    private static int pow(int base, int exp) {
        if( exp == 0 ) return 1;

        long ans = 1;
        base %= MOD;
        while( exp > 0 ) {
            if( (exp & 1) == 1 ) {
                ans = ans * base % MOD;
            }

            base = (int)((long)base * base % MOD);
            exp = exp >> 1;
        }
        return (int)ans;
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