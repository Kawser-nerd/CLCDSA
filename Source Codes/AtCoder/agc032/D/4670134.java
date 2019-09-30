import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
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
            int n = in.nextInt();
            long a = in.nextLong();
            long b = in.nextLong();
            int[] p = new int[n];
            for (int i = 0; i < n; ++i) {
                p[i] = in.nextInt();
            }
            long[] best = new long[n + 2];
            for (int i = 0; i < n + 1; ++i) {
                best[i + 1] = Long.MAX_VALUE;
                long extra = 0;
                for (int j = i - 1; j >= -1; --j) {
                    if (i == n || j < 0 || p[j] < p[i]) {
                        best[i + 1] = Math.min(best[i + 1], best[j + 1] + extra);
                    }
                    if (j >= 0) {
                        if (i == n || p[j] < p[i]) {
                            extra += b;
                        } else {
                            extra += a;
                        }
                    }
                }
            }
            out.println(best[n + 1]);
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

        public long nextLong() {
            return Long.parseLong(next());
        }

    }
}