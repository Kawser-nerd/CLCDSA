import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        TaskD solver = new TaskD();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskD {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            String s = in.next();
            int k = in.nextInt();
            int[][][] best = new int[s.length() + 1][s.length() + 1][k + 1];
            for (int pos = s.length() - 1; pos >= 0; --pos) {
                Arrays.fill(best[pos][1], 1);
                for (int len = 2; pos + len <= s.length(); ++len) {
                    if (s.charAt(pos) == s.charAt(pos + len - 1)) {
                        for (int i = 0; i <= k; ++i) {
                            best[pos][len][i] = 2 + best[pos + 1][len - 2][i];
                        }
                    } else {
                        for (int i = 0; i <= k; ++i) {
                            best[pos][len][i] = Math.max(best[pos + 1][len - 1][i], best[pos][len - 1][i]);
                            if (i > 0) {
                                best[pos][len][i] = Math.max(best[pos][len][i], 2 + best[pos + 1][len - 2][i - 1]);
                            }
                        }
                    }
                }
            }
            out.println(best[0][s.length()][k]);
        }

    }

    static class InputReader {
        public BufferedReader reader;
        public StringTokenizer tokenizer;

        public InputReader(InputStream stream) {
            reader = new BufferedReader(new InputStreamReader(stream), 32768);
            tokenizer = null;
        }

        public String next() {
            while (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    tokenizer = new StringTokenizer(reader.readLine());
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
            return tokenizer.nextToken();
        }

        public int nextInt() {
            return Integer.parseInt(next());
        }

    }
}