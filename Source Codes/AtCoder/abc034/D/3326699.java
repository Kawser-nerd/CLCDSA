import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.math.BigDecimal;
import java.util.Arrays;
import java.util.HashSet;
import java.util.Set;
import java.util.StringTokenizer;
import java.util.function.DoublePredicate;

public class Main {

    static int N, K;
    static int[] W, P;

    public static void main(String[] args) {
        FastScanner sc = new FastScanner(System.in);
        N = sc.nextInt();
        K = sc.nextInt();
        W = new int[N];
        P = new int[N];
        for (int i = 0; i < N; i++) {
            W[i] = sc.nextInt();
            P[i] = sc.nextInt();
        }
        System.out.println(BigDecimal.valueOf(solve()).toPlainString());
    }

    static double solve() {
        return maximaize_d(0, 100, Main::calc);
    }

    static boolean calc(double p) {
        double[] reqs = new double[N];
        for (int i = 0; i < N; i++) {
            double actual = (double)W[i] / 100 * P[i];
            double expected = (double)W[i] / 100 * p;
            reqs[i] = expected - actual;
        }
        Arrays.sort(reqs);

        double sum = 0.0;
        for (int i = 0; i < K; i++) {
            sum += reqs[i];
        }
        return sum <= 0.0;
    }

    static double maximaize_d(double lo, double hi, DoublePredicate p) {
        int time = 0;
        while(time++ < 100) {
            double x = (hi + lo) / 2;
            if( p.test(x) ) {
                lo = x;
            } else {
                hi = x;
            }
        }
        return lo;
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