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
        static final long MODULO = (int) (1e9 + 7);
        static final long INV2 = (MODULO + 1) / 2;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            int q = in.nextInt();
            int[] a = new int[n];
            for (int i = 0; i < n; ++i) a[i] = in.nextInt();
            int[][] ways = new int[n][n];
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    ways[i][j] = a[i] > a[j] ? 1 : 0;
                }
            }
            for (int qi = 0; qi < q; ++qi) {
                int u = in.nextInt() - 1;
                int v = in.nextInt() - 1;
                for (int i = 0; i < n; ++i)
                    if (i != u && i != v) {
                        ways[u][i] = ways[v][i] = (int) ((ways[u][i] + ways[v][i]) * INV2 % MODULO);
                        ways[i][u] = ways[i][v] = (int) ((ways[i][u] + ways[i][v]) * INV2 % MODULO);
                    }
                ways[u][v] = ways[v][u] = (int) ((ways[u][v] + ways[v][u]) * INV2 % MODULO);
            }
            long res = 0;
            for (int i = 0; i < n; ++i) {
                for (int j = i + 1; j < n; ++j) {
                    res = (res + ways[i][j]) % MODULO;
                }
            }
            for (int i = 0; i < q; ++i) res = res * 2 % MODULO;
            out.println(res);
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