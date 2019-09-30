import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.stream.IntStream;
import java.io.UncheckedIOException;
import java.util.Arrays;
import java.util.StringTokenizer;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
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
        CSnukeFestival solver = new CSnukeFestival();
        solver.solve(1, in, out);
        out.close();
    }

    static class CSnukeFestival {
        public void solve(int testNumber, LightScanner in, PrintWriter out) {
            int n = in.ints();
            int[] a = in.ints(n), b = in.ints(n), c = in.ints(n);
            Arrays.sort(a);
            Arrays.sort(b);
            Arrays.sort(c);
            long ans = 0;
            long[] v = new long[n + 1];
            for (int i = n - 1; i >= 0; i--) {
                v[i] = v[i + 1] + n - ArrayUtil.upperBound(c, b[i]);
            }
            for (int i = 0; i < n; i++) {
                ans += v[ArrayUtil.upperBound(b, a[i])];
            }
            out.println(ans);
        }

    }

    static final class ArrayUtil {
        private ArrayUtil() {
        }

        public static int upperBound(int[] a, int t, int min) {
            int max = a.length;
            while (min < max) {
                final int mid = (min + max) / 2;
                if (t >= a[mid]) {
                    min = mid + 1;
                } else {
                    max = mid;
                }
            }
            return min;
        }

        public static int upperBound(int[] a, int t) {
            return upperBound(a, t, 0);
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

        public int[] ints(int length) {
            return IntStream.range(0, length).map(x -> ints()).toArray();
        }

    }
}