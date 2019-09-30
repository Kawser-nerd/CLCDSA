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
        BN solver = new BN();
        solver.solve(1, in, out);
        out.close();
    }

    static class BN {
        public void solve(int testNumber, LightScanner in, PrintWriter out) {
            int n = in.ints();
            int[] rs = in.ints(n);
            Arrays.sort(rs);
            ArrayUtil.reverse(rs, 0, n - 1);
            double size = 0;
            for (int i = 0; i < n; i++) {
                int r = rs[i];
                double s = Math.PI * r * r;
                if (i % 2 == 0) {
                    size += s;
                } else {
                    size -= s;
                }
            }
            out.println(size);
        }

    }

    static final class ArrayUtil {
        private ArrayUtil() {
        }

        public static void reverse(int[] a, int left, int right) {
            while (left < right) {
                int temp = a[left];
                a[left] = a[right];
                a[right] = temp;
                left++;
                right--;
            }
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