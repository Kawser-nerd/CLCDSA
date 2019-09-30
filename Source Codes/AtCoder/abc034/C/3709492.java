import java.io.*;
import java.util.*;
import java.util.function.Function;

public class Main {

    static int H, W;

    public static void main(String[] args) {
        FastScanner sc = new FastScanner(System.in);
        H = sc.nextInt();
        W = sc.nextInt();

        System.out.println( solve() );
    }

    static int MOD = 1_000_000_007;

    static int solve() {
        FermatCombination fc = new FermatCombination(H+W+10, MOD);
        return fc.comb(H+W-2, H-1);
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

        int[] nextIntArray(int n, int delta) {
            int[] a = new int[n];
            for (int i = 0; i < n; i++)
                a[i] = nextInt() + delta;
            return a;
        }

        long[] nextLongArray(int n) {
            long[] a = new long[n];
            for (int i = 0; i < n; i++)
                a[i] = nextLong();
            return a;
        }
    }

    static <A> void writeLines(A[] as, Function<A, String> f) {
        PrintWriter pw = new PrintWriter(System.out);
        for (A a : as) {
            pw.println(f.apply(a));
        }
        pw.flush();
    }

    static void writeLines(int[] as) {
        PrintWriter pw = new PrintWriter(System.out);
        for (int a : as) pw.println(a);
        pw.flush();
    }

    static void writeLines(long[] as) {
        PrintWriter pw = new PrintWriter(System.out);
        for (long a : as) pw.println(a);
        pw.flush();
    }

    static int max(int... as) {
        int max = Integer.MIN_VALUE;
        for (int a : as) max = Math.max(a, max);
        return max;
    }

    static int min(int... as) {
        int min = Integer.MAX_VALUE;
        for (int a : as) min = Math.min(a, min);
        return min;
    }

    static void debug(Object... args) {
        StringJoiner j = new StringJoiner(" ");
        for (Object arg : args) {
            if (arg instanceof int[]) j.add(Arrays.toString((int[]) arg));
            else if (arg instanceof long[]) j.add(Arrays.toString((long[]) arg));
            else if (arg instanceof double[]) j.add(Arrays.toString((double[]) arg));
            else if (arg instanceof Object[]) j.add(Arrays.toString((Object[]) arg));
            else j.add(arg.toString());
        }
        System.err.println(j.toString());
    }
}