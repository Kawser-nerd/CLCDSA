import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.stream.LongStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.UncheckedIOException;
import java.util.OptionalLong;
import java.util.StringTokenizer;
import java.io.BufferedReader;
import java.util.NoSuchElementException;
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
        AIceTeaStore solver = new AIceTeaStore();
        solver.solve(1, in, out);
        out.close();
    }

    static class AIceTeaStore {
        public void solve(int testNumber, LightScanner in, PrintWriter out) {
            long q = in.ints(), h = in.ints(), s = in.ints(), d = in.ints();
            int n = in.ints();
            long min2 = IntMath.min(8 * q, 4 * h, 2 * s, d);
            long min1 = IntMath.min(4 * q, 2 * h, s);
            out.println(n / 2 * min2 + n % 2 * min1);
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

    }

    static final class IntMath {
        private IntMath() {
        }

        public static long min(long... v) {
            return Arrays.stream(v).min().orElseThrow(NoSuchElementException::new);
        }

    }
}