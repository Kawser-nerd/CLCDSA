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
        C4Adjacent solver = new C4Adjacent();
        solver.solve(1, in, out);
        out.close();
    }

    static class C4Adjacent {
        private static final String YES = "Yes";
        private static final String NO = "No";

        public void solve(int testNumber, LightScanner in, PrintWriter out) {
            int n = in.ints();
            int[] a = in.ints(n);
            int x = 0, y = 0;
            for (int i = 0; i < n; i++) {
                if (a[i] % 4 == 0) {
                    x++;
                } else if (a[i] % 2 == 1) {
                    y++;
                }
            }
            if (y <= x || (y <= x + 1 && x + y == n)) {
                out.println(YES);
            } else {
                out.println(NO);
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