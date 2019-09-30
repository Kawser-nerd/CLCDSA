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
        BMedianPyramidEasy solver = new BMedianPyramidEasy();
        solver.solve(1, in, out);
        out.close();
    }

    static class BMedianPyramidEasy {
        private static final String YES = "Yes";
        private static final String NO = "No";

        public void solve(int testNumber, LightScanner in, PrintWriter out) {
            int n = in.ints(), x = in.ints();
            if (x == 1 || x == 2 * n - 1) {
                out.println(NO);
                return;
            }
            out.println(YES);
            int[] ans = new int[2 * n - 1];
            if (x == 2 * n - 2 && n > 2) {
                ans[n - 2] = x - 2;
                ans[n - 1] = x + 1;
                ans[n] = x;
                ans[n + 1] = x - 1;
                int m = 1;
                for (int i = 0; i < 2 * n - 1; i++) {
                    if (i == n - 2) {
                        i = n + 2;
                        if (i >= 2 * n - 1) {
                            break;
                        }
                    }
                    if (m == x - 2) {
                        m = x + 2;
                    }
                    ans[i] = m;
                    m++;
                }
            } else {
                ans[n - 2] = x + 1;
                ans[n - 1] = x;
                ans[n] = x - 1;
                if (n > 2) {
                    ans[n + 1] = x + 2;
                }
                int m = 1;
                for (int i = 0; i < 2 * n - 1; i++) {
                    if (i == n - 2) {
                        i = n + 2;
                        if (i >= 2 * n - 1) {
                            break;
                        }
                    }
                    if (m == x - 1) {
                        m = x + 3;
                    }
                    ans[i] = m;
                    m++;
                }
            }
            Arrays.stream(ans).forEach(out::println);
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
}