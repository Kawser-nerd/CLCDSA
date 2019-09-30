import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
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
        BModerateDifferences solver = new BModerateDifferences();
        solver.solve(1, in, out);
        out.close();
    }

    static class BModerateDifferences {
        private static final String YES = "YES";
        private static final String NO = "NO";

        public void solve(int testNumber, LightScanner in, PrintWriter out) {
            int n = in.ints();
            long a = in.longs(), b = in.longs(), c = in.longs(), d = in.longs();
            for (int i = 0; i < n; i++) {
                long max = a + d * i - c * (n - 1 - i);
                long min = a + c * i - d * (n - 1 - i);
                if (min <= b && b <= max) {
                    out.println(YES);
                    return;
                }
            }
            out.println(NO);
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

    }
}