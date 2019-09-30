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
        AMultipleArray solver = new AMultipleArray();
        solver.solve(1, in, out);
        out.close();
    }

    static class AMultipleArray {
        public void solve(int testNumber, LightScanner in, PrintWriter out) {
            int n = in.ints();
            int[] a = new int[n];
            int[] b = new int[n];
            in.ints(a, b);
            long d = 0;
            for (int i = n - 1; i >= 0; i--) {
                d += (b[i] - ((a[i] + d) % b[i])) % b[i];
            }
            out.println(d);
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

        public void ints(int[]... arrays) {
            int l = Arrays.stream(arrays).mapToInt(a -> a.length).min().orElse(0);
            for (int i = 0; i < l; i++) {
                for (int j = 0; j < arrays.length; j++) {
                    arrays[j][i] = ints();
                }
            }
        }

    }
}