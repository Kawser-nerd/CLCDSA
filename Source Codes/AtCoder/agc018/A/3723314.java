import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.stream.IntStream;
import java.io.UncheckedIOException;
import java.util.StringTokenizer;
import java.io.IOException;
import java.io.BufferedReader;
import java.util.OptionalInt;
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
        AGettingDifference solver = new AGettingDifference();
        solver.solve(1, in, out);
        out.close();
    }

    static class AGettingDifference {
        public void solve(int testNumber, LightScanner in, PrintWriter out) {
            int n = in.ints(), k = in.ints();
            int[] a = in.ints(n);
            int max = IntStream.of(a).max().orElse(0);
            int gcm = -1;
            for (int x : a) {
                if (x == max) {
                } else if (gcm < 0) {
                    gcm = max - x;
                } else {
                    gcm = IntMath.gcd(gcm, max - x);
                }
            }
            if (k <= max && (max - k) % gcm == 0) {
                out.println("POSSIBLE");
            } else {
                out.println("IMPOSSIBLE");
            }
        }

    }

    static final class IntMath {
        private IntMath() {
        }

        public static int gcd(int a, int b) {
            int t;
            while (a % b > 0) {
                t = b;
                b = a % b;
                a = t;
            }
            return b;
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