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
        TaskC solver = new TaskC();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskC {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            int[] a = new int[n];
            int[] b = new int[n];
            for (int i = 0; i < n; ++i) {
                a[i] = in.nextInt();
            }
            for (int i = 0; i < n; ++i) {
                b[i] = in.nextInt();
            }
            long res = (1L << 52) - 1;
            if (!possible(res, n, a, b)) {
                out.println(-1);
                return;
            }
            for (int k = 51; k >= 0; --k) {
                res ^= 1L << k;
                if (!possible(res, n, a, b)) {
                    res ^= 1L << k;
                }
            }
            out.println(res);
        }

        private boolean possible(long allowed, int n, int[] a, int[] b) {
            boolean[][] can = new boolean[51][51];
            for (int i = 0; i <= 50; ++i) can[i][i] = true;
            for (int k = 1; k <= 51; ++k)
                if ((allowed & (1L << k)) != 0) {
                    boolean[][] ncan = new boolean[51][51];
                    for (int old = 0; old <= 50; ++old) {
                        for (int nxt = 0; nxt <= 50; ++nxt) {
                            ncan[old][nxt] |= can[old][nxt];
                            ncan[old][nxt] |= can[old % k][nxt];
                        }
                    }
                    can = ncan;
                }
            for (int i = 0; i < n; ++i) if (!can[a[i]][b[i]]) return false;
            return true;
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