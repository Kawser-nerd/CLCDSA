import java.io.*;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {

    static int N, A, B;
    static long X[];

    public static void main(String[] args) {
        FastScanner fc = new FastScanner(System.in);
        N = fc.nextInt();
        A = fc.nextInt();
        B = fc.nextInt();

        X = new long[N];
        for (int i = 0; i < N; i++) {
            X[i] = fc.nextInt();
        }

        PrintWriter pw = new PrintWriter(System.out);
        for (long i : solve()) {
            pw.println(i);
        }
        pw.flush();
    }

    static int MOD = 1_000_000_007;

    static long[] solve() {
        if( A == 1 ) {
            Arrays.sort(X);
            return X;
        }

        int times = 0;
        int max = (int)Arrays.stream(X).max().getAsLong();
        int p = calcPow(max);
        int from = (int)Math.pow(A, p);
        int to = (int)Math.pow(A, p+1);

        // ??????????50*60?????????????
        while(B > 0) {
            long min = Long.MAX_VALUE;
            int minIdx = -1;
            for (int i = 0; i < N; i++) {
                if( X[i] < min ) {
                    min = X[i];
                    minIdx = i;
                }
            }

            if( min < from ) {
                X[minIdx] *= A;
                B--;
            } else {
                break;
            }
        }

        Arrays.sort(X);
        for (int i = 0; i < N; i++) {
            X[i] %= MOD;
        }

        if( B == 0 ) return X;

        // ???r?? q+1??????? q? *A ??
        // ?????doubling??
        int q = B/N;
        int r = B%N;
        long[] Y = new long[N];
        for (int i = 0; i < r; i++) {
            Y[i + N-r] = mul(X[i], pow(A, q+1));
        }
        for (int i = 0; i < N - r; i++) {
            Y[i] = mul(X[i+r], pow(A, q));
        }
        return Y;
    }

    static int mul(long a, int b) {
        return (int)(a * b % MOD);
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

    static int calcPow(int n) {
        int from = 1;
        int to = A;
        int p = 1;
        while(true) {
            if( from <= n && n < to ) {
                return p;
            } else {
                from *= A;
                to *= A;
                p++;
            }
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