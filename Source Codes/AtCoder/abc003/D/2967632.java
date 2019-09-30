import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    static int H;
    static int W;
    static int X;
    static int Y;
    static int D;
    static int L;

    public static void main(String[] args) {
        FastScanner sc = new FastScanner(System.in);
        H = sc.nextInt();
        W = sc.nextInt();
        X = sc.nextInt();
        Y = sc.nextInt();
        D = sc.nextInt();
        L = sc.nextInt();

        System.out.println(solve());
    }

    static final int MOD = 1_000_000_007;
    static FermatCombination fc;

    static long solve() {
        fc = new FermatCombination(1000, MOD);

        int select_xy = (H - X + 1) * (W - Y + 1);

        long all = calc();

        long bad = sum(calc(Ex.T), calc(Ex.B), calc(Ex.L), calc(Ex.R));
        bad = sub(bad, calc(Ex.T, Ex.B), calc(Ex.T, Ex.L), calc(Ex.T, Ex.R), calc(Ex.B, Ex.L), calc(Ex.B, Ex.R), calc(Ex.L, Ex.R));
        bad = sum(bad, calc(Ex.T, Ex.B, Ex.L), calc(Ex.T, Ex.B, Ex.R), calc(Ex.T, Ex.L, Ex.R), calc(Ex.B, Ex.L, Ex.R));
        bad = sub(bad, calc(Ex.T, Ex.B, Ex.L, Ex.R));

        return sub(all, bad) * select_xy % MOD;
    }

    static long sub(long a, long... bs) {
        long ret = a;
        for (long b : bs) {
            ret = (ret - b + MOD) % MOD;
        }
        return ret;
    }

    static long sum(long... values) {
        long ret = 0;
        for (long value : values) {
            ret = (ret + value) % MOD;
        }
        return ret;
    }

    static long calc(Ex... exs) {
        int x = X;
        int y = Y;

        for (Ex ex : exs) {
            if( ex == Ex.T || ex == Ex.B ) {
                x--;
            } else {
                y--;
            }
        }

        if( x <= 0 || y <= 0 ) return 0;
        int xy = x * y;
        if( xy < D + L ) return 0;

        return (long)fc.comb(xy, D) * fc.comb(xy-D, L) % MOD;
    }

    enum Ex {
        T, B, L, R
    }

    static class FermatCombination {

        private final int size;
        private final int mod;
        private final int[] factorial; // n -> factorial(n)
        private final int[] inverse;   // n -> inverse(factorial(n))

        public FermatCombination(int size, int mod) {
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