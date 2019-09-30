import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.stream.IntStream;
import java.io.UncheckedIOException;
import java.util.Arrays;
import java.util.stream.Stream;
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
        D solver = new D();
        solver.solve(1, in, out);
        out.close();
    }

    static class D {
        public void solve(int testNumber, LightScanner in, PrintWriter out) {
            int k = in.ints(), n = in.ints();
            int patterns = 1;
            for (int i = 0; i < k; i++) {
                patterns *= 3;
            }
            int[][] v = new int[n][];
            String[] w = new String[n];
            for (int i = 0; i < n; i++) {
                v[i] = in.string().chars().map(c -> c - '1').toArray();
                w[i] = in.string();
            }
            String[] abbr = new String[k];
            int[] length = new int[k];
            outer:
            for (int i = 0; i < patterns; i++) {
                int t = i;
                for (int j = 0; j < k; j++) {
                    length[j] = 1 + t % 3;
                    t /= 3;
                }
                Arrays.fill(abbr, null);
                // System.out.println(Arrays.toString(length));

                for (int j = 0; j < n; j++) {
                    if (w[j].length() != Arrays.stream(v[j]).map(d -> length[d]).sum()) {
                        // System.out.println("SUM VALIDATION FAIL");
                        continue outer;
                    }
                    int index = 0;
                    for (int p = 0; p < v[j].length; p++) {
                        String s = w[j].substring(index, index + length[v[j][p]]);
                        if (abbr[v[j][p]] != null && !abbr[v[j][p]].equals(s)) {
                            // System.out.println("EQUAL VALIDATION FAIL: " + s);
                            continue outer;
                        }
                        abbr[v[j][p]] = s;
                        index += length[v[j][p]];
                    }
                }
                // System.out.println("VALIDATION THRU");
                break;
            }

            Arrays.stream(abbr).forEach(out::println);
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