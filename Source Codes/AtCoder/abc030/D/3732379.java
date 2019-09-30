import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.stream.IntStream;
import java.io.UncheckedIOException;
import java.util.Arrays;
import java.util.StringTokenizer;
import java.math.BigInteger;
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
        D solver = new D();
        solver.solve(1, in, out);
        out.close();
    }

    static class D {
        public void solve(int testNumber, LightScanner in, PrintWriter out) {
            int n = in.ints(), a = in.ints();
            BigInteger k = in.bigints();
            int[] b = in.ints(n);
            int[] s = new int[n + 1];
            Arrays.fill(s, -1);
            s[a] = 0;
            int p = a;
            int c = 1;
            while (s[b[p - 1]] < 0) {
                if (k.equals(BigInteger.valueOf(c))) {
                    out.println(b[p - 1]);
                    return;
                }
                s[b[p - 1]] = c;
                p = b[p - 1];
                c++;
            }
            k = k.subtract(BigInteger.valueOf(s[b[p - 1]])).mod(BigInteger.valueOf(c - s[b[p - 1]]));
            c = 0;
            while (k.compareTo(BigInteger.valueOf(c)) > 0) {
                c++;
                p = b[p - 1];
            }
            out.println(b[p - 1]);
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

        public BigInteger bigints() {
            return new BigInteger(string());
        }

    }
}