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
        TaskF solver = new TaskF();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskF {
        static final int MODULO = (int) (1e9 + 7);

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            int[] a = new int[2 * n];
            for (int i = 0; i < a.length; ++i) a[i] = Math.max(-1, in.nextInt() - 1);
            int[] where = new int[2 * n];
            Arrays.fill(where, -1);
            for (int i = 0; i < a.length; ++i) if (a[i] >= 0) where[a[i]] = i;
            int doubles = 0;
            int singles = 0;
            for (int i = 0; i < n; ++i) {
                int cnt = 0;
                if (a[2 * i] < 0) ++cnt;
                if (a[2 * i + 1] < 0) ++cnt;
                if (cnt == 1) ++singles;
                if (cnt == 2) ++doubles;
            }
            int[][] ways = new int[singles + 1][doubles + 1];
            int[][] nways = new int[singles + 1][doubles + 1];
            ways[0][doubles] = 1;
            int totalExtra = 0;
            int totalSingles = 0;
            for (int val = 2 * n - 1; val >= 0; --val) {
                if (where[val] >= 0 && a[where[val] ^ 1] >= 0) continue;
                for (int[] x : nways) Arrays.fill(x, 0);
                for (int s = 0; s <= singles; ++s) {
                    for (int d = 0; d <= doubles; ++d) {
                        int old = ways[s][d];
                        if (old == 0) continue;
                        if (s > totalSingles) throw new RuntimeException();
                        int spent = 2 * (doubles - d) + (totalSingles - s);
                        if (spent > totalExtra) throw new RuntimeException();
                        if (where[val] >= 0) {
                            if (spent < totalExtra) {
                                nways[s][d] += old;
                                if (nways[s][d] >= MODULO) nways[s][d] -= MODULO;
                            }
                            nways[s + 1][d] += old;
                            if (nways[s + 1][d] >= MODULO) nways[s + 1][d] -= MODULO;
                        } else {
                            nways[s][d] += old;
                            if (nways[s][d] >= MODULO) nways[s][d] -= MODULO;
                            if (s > 0) {
                                nways[s - 1][d] = (int) ((nways[s - 1][d] + s * (long) old) % MODULO);
                            }
                            if (d > 0 && spent < totalExtra) {
                                nways[s][d - 1] = (int) ((nways[s][d - 1] + d * (long) old) % MODULO);
                            }
                        }
                    }
                }
                int[][] tmp = ways;
                ways = nways;
                nways = tmp;
                if (where[val] < 0) ++totalExtra;
                if (where[val] >= 0) ++totalSingles;
            }
            out.println(ways[0][0]);
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