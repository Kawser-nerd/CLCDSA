import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.stream.IntStream;
import java.util.Arrays;
import java.util.stream.LongStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.OptionalInt;
import java.io.UncheckedIOException;
import java.util.stream.Stream;
import java.util.StringTokenizer;
import java.io.BufferedReader;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 *
 * @author mikit
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        LightScanner in = new LightScanner(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        DBigBang solver = new DBigBang();
        solver.solve(1, in, out);
        out.close();
    }

    static class DBigBang {
        public void solve(int testNumber, LightScanner in, PrintWriter out) {
            int n = in.ints();
            long[] ax = new long[n], ay = new long[n];
            long[] bx = new long[n], by = new long[n];
            in.longs(ax, ay);
            in.longs(bx, by);
            out.println(Math.sqrt(rad(bx, by) / rad(ax, ay)));
        }

        private static double d(double x1, double y1, long x2, long y2) {
            return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
        }

        private static double rad(long[] x, long[] y) {
            double xs = LongStream.of(x).sum();
            double ys = LongStream.of(y).sum();
            double m = 0;
            xs /= x.length;
            ys /= y.length;
            for (int i = 0; i < x.length; i++) {
                double t = d(xs, ys, x[i], y[i]);
                if (t > m) {
                    m = t;
                }
            }
            return m;
        }

    }

    static class LightScanner {
        private BufferedReader reader = null;
        private StringTokenizer tokenizer = null;

        public LightScanner(InputStream in) {
            reader = new BufferedReader(new InputStreamReader(in));
        }

        public String string() {
            if (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    tokenizer = new StringTokenizer(reader.readLine());
                } catch (IOException e) {
                    throw new UncheckedIOException(e);
                }
            }
            return tokenizer.nextToken();
        }

        public int ints() {
            return Integer.parseInt(string());
        }

        public long longs() {
            return Long.parseLong(string());
        }

        public void longs(long[]... arrays) {
            int l = Arrays.stream(arrays).mapToInt(a -> a.length).min().orElse(0);
            for (int i = 0; i < l; i++) {
                for (int j = 0; j < arrays.length; j++) {
                    arrays[j][i] = longs();
                }
            }
        }

    }
}