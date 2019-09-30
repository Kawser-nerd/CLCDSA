import java.awt.geom.Rectangle2D;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.math.BigDecimal;
import java.util.StringTokenizer;
import java.util.function.DoublePredicate;

public class Main {

    static int N;
    static int[] X, Y, C;

    public static void main(String[] args) {
        FastScanner fc = new FastScanner(System.in);
        N = fc.nextInt();

        X = new int[N];
        Y = new int[N];
        C = new int[N];
        for (int i = 0; i < N; i++) {
            X[i] = fc.nextInt();
            Y[i] = fc.nextInt();
            C[i] = fc.nextInt();
        }
        System.out.println(BigDecimal.valueOf(solve()).toPlainString());
    }

    static double solve() {
        return minimize_d(0, 10e10, Main::calc);
    }

    static boolean calc(double t) {
        Rectangle2D all = null;
        for (int i = 0; i < N; i++) {
            int x = X[i];
            int y = Y[i];
            int c = C[i];
            double s = t / c;
            Rectangle2D r = new Rectangle2D.Double(x - s, y - s, s*2, s*2);

            if( all == null ) {
                all = r;
            } else {
                all = all.createIntersection(r);
                if( all.isEmpty() ) return false;
            }
        }
        return !all.isEmpty();
    }

    static double minimize_d(double lo, double hi, DoublePredicate p) {
        int time = 0;
        while(time++ < 100) {
            double x = (hi + lo) / 2;
            if( p.test(x) ) {
                hi = x;
            } else {
                lo = x;
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