import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
import java.util.function.IntPredicate;
import java.util.function.LongPredicate;

public class Main {

    static int K, N;
    static int[] A, D;

    public static void main(String[] args) {
        FastScanner fc = new FastScanner(System.in);
        K = fc.nextInt();
        N = fc.nextInt();
        A = new int[N];
        D = new int[N];
        for (int i = 0; i < N; i++) {
            A[i] = fc.nextInt();
            D[i] = fc.nextInt();
        }
        System.out.println(solve());
    }

    static long solve() {
        long cost = minimize(0, Long.MAX_VALUE, Main::isOk);
        return calcTotalCost(cost);
    }

    static long calcTotalCost(long cost) {
        long total = 0;
        long under = 0;
        for (int i = 0; i < N; i++) {
            // n??? dn + a
            int a = A[i];
            int d = D[i];

            // cost????????????????
            // ?????????????????????
            long times = maximize(0, K+1, n -> d * n + a < cost) + 1;
            under += times;
            total += times*(times-1)/2 * d + times*a;
        }

        // cost?K?????
        total += (K-under)*cost;

        return total;
    }

    static boolean isOk(long cost) {
        long build = 0;

        for (int i = 0; i < N; i++) {
            // n??? dn + a
            int a = A[i];
            int d = D[i];

            // ?????????????????????
            long times = maximize(0, K+1, n -> d * n + a <= cost) + 1;
            build += times;
        }
        return build >= K;
    }

    static long maximize(long lo, long hi, LongPredicate p) {
        while(lo < hi) {
            long x = ((hi - lo) >>> 1) + lo;
            if( p.test(x) ) {
                lo = x + 1;
            } else {
                hi = x;
            }
        }
        return lo - 1;
    }

    static long minimize(long lo, long hi, LongPredicate p) {
        while(lo < hi) {
            long x = ((hi - lo) >>> 1) + lo;
            if( p.test(x) ) {
                hi = x;
            } else {
                lo = x + 1;
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