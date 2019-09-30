import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.stream.IntStream;
import java.util.Arrays;
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
        D solver = new D();
        solver.solve(1, in, out);
        out.close();
    }

    static class D {
        public void solve(int testNumber, LightScanner in, PrintWriter out) {
            int n = in.ints();
            long[] h = new long[n], s = new long[n];
            in.longs(h, s);
            long min = 0, max = 100_001_000_000_000L;
            long[] mor = new long[n];
            outer:
            while (max - min > 1) {
                long mid = (min + max + 1) / 2;
                for (int i = 0; i < n; i++) {
                    if (mid < h[i]) {
                        min = mid;
                        continue outer;
                    }
                    mor[i] = (mid - h[i]) / s[i];
                }
                Arrays.sort(mor);
                for (int i = 0; i < n; i++) {
                    if (mor[i] < i) {
                        min = mid;
                        continue outer;
                    }
                }
                max = mid;
            }
            out.println(max);
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