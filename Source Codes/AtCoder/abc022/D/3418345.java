import java.awt.geom.Point2D;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.math.BigDecimal;
import java.util.StringTokenizer;

public class Main {

    static int N;
    static Point2D[] A;
    static Point2D[] B;

    public static void main(String[] args) {
        FastScanner fc = new FastScanner(System.in);
        N = fc.nextInt();
        A = new Point2D[N];
        for (int i = 0; i < N; i++) {
            A[i] = new Point2D.Double(fc.nextInt(), fc.nextInt());
        }
        B = new Point2D[N];
        for (int i = 0; i < N; i++) {
            B[i] = new Point2D.Double(fc.nextInt(), fc.nextInt());
        }
        System.out.println(BigDecimal.valueOf(solve()).toPlainString());
    }

    static double solve() {
        double a = calc(A);
        double b = calc(B);
        if( a == 0.0 ) return 0.0;
        else return b / a;
    }

    // ???????
    static double calc(Point2D[] P) {
        double sumx = 0.0;
        double sumy = 0.0;
        for (Point2D p : P) {
            sumx += p.getX();
            sumy += p.getY();
        }
        Point2D c = new Point2D.Double(sumx/N, sumy/N);

        double max = Double.MIN_VALUE;
        for (Point2D p : P) {
            max = Math.max(p.distance(c), max);
        }
        return max;
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