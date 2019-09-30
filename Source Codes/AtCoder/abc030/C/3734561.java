import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.stream.IntStream;
import java.io.UncheckedIOException;
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
        C solver = new C();
        solver.solve(1, in, out);
        out.close();
    }

    static class C {
        public void solve(int testNumber, LightScanner in, PrintWriter out) {
            int[] n = in.ints(2);
            int[] x = {in.ints(), in.ints()};
            int[][] a = {in.ints(n[0]), in.ints(n[1])};
            int[] c = {0, 0};
            int h = 0;
            long t = 0;
            int ans = 0;
            while (true) {
                while (c[h] < a[h].length && a[h][c[h]] < t) {
                    c[h]++;
                }
                if (c[h] == n[h]) {
                    break;
                }
                if (h == 1) {
                    ans++;
                }
                t = a[h][c[h]] + x[h];
                h ^= 1;
            }
            out.println(ans);
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