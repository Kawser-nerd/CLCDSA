import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    static int N;
    static int K;

    public static void main(String[] args) {
        FastScanner sc = new FastScanner(System.in);
        N = sc.nextInt();
        K = sc.nextInt();

        System.out.println(solve());
    }

    static int MOD = 1_000_000_007;

    static int solve() {
        FermatCombination fc = new FermatCombination(N+K+100, MOD);

        return fc.hcomb(N, K);
    }

    static class FermatCombination {

        private final int size;
        private final int mod;
        private final int[] factorial; // n -> factorial(n)
        private final int[] inverse;   // n -> inverse(factorial(n))

        FermatCombination(int size, int mod) {
            this.mod = mod;
            this.size = size;
            factorial = new int[size + 1];
            inverse = new int[size + 1];

            init();
        }

        private void init() {
            factorial[0] = 1;
            factorial[1] = 1;
            inverse[0] = 1;
            inverse[1] = 1;
            for (int i = 2; i <= size; i++) {
                factorial[i] = mul(factorial[i-1], i);
                inverse[i] = pow(factorial[i], mod - 2);
            }
        }

        private int pow(int base, int exp) {
            if( exp == 0 ) return 1;

            int ans = 1;
            base %= mod;
            while( exp > 0 ) {
                if( (exp & 1) == 1 ) {
                    ans = mul(ans, base);
                }

                base = mul(base, base);
                exp = exp >> 1;
            }
            return ans;
        }

        private int mul(int a, int b) {
            return (int)((long)a * b % mod);
        }

        int comb(int n, int k) {
            if( n > size ) throw new RuntimeException("wtf : size=" + size + " n=" + n);
            return mul(mul(factorial[n], inverse[k]), inverse[n - k]);
        }

        // ???????
        // k????n???????
        int hcomb(int k, int n) {
            return comb(k+n-1, n);
        }

        int group(int n, int g, int k) {
            // C(n, g) * C(n-g, g)... / k!
            // n! / (n-gk)! / g! ^ k / k!
            int ret = factorial[n];             // n!
            ret = mul(ret, inverse[n - g*k]);   // 1 / (n-gk)!
            ret = mul(ret, pow(inverse[g], k)); // 1 / (g! ^ k)
            ret = mul(ret, inverse[k]);         // 1 / k!
            return ret;
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