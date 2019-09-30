import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.math.BigDecimal;
import java.util.StringTokenizer;

public class Main {

    static int A, B, C;

    public static void main(String[] args) {
        FastScanner fc = new FastScanner(System.in);
        A = fc.nextInt();
        B = fc.nextInt();
        C = fc.nextInt();
        System.out.println(BigDecimal.valueOf(solve()).toPlainString());
    }

    static double solve() {
        double gosa = Math.pow(10, -6);

        // ??? C * ?
        double p_half_sec = 0.5 / C;

        double prev = 0.0;
        double prev_t = 0.0;
        double cur_t = 0.0;

        while(cur_t < 201) {
            cur_t += p_half_sec;
            double cur = f(cur_t);
            if( Math.abs(cur - 100) <= gosa ) {
                return cur_t;
            }

            if( cur < 100 && 100 < prev ) {
                return search(cur_t, prev_t);

            } else if( prev < 100 && 100 < cur ) {
                return search(prev_t, cur_t);

            } else {
                prev = cur;
                prev_t = cur_t;
            }
        }
        throw new RuntimeException("not expected");
    }

    static double search(double lo, double hi) {
        int times = 0;
        while(times++ < 200) { // ?????????????
            double x = (lo + hi) / 2;
            if( f(x) < 100 ) {
                lo = x;
            } else {
                hi = x;
            }
        }
        return lo;
    }

    static double f(double t) {
        return A * t + B * Math.sin(C * t * Math.PI);
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