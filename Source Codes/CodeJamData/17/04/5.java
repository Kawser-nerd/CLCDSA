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
 *
 * @author Chiaki.Hoshinomori
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        TaskD solver = new TaskD();
        int testCount = Integer.parseInt(in.next());
        for (int i = 1; i <= testCount; i++)
            solver.solve(i, in, out);
        out.close();
    }

    static class TaskD {
        int[] mate;
        boolean[] vis;
        boolean[][] g;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            int m = in.nextInt();
            char[] model = new char[m];
            int[] R = new int[m];
            int[] C = new int[m];
            for (int i = 0; i < m; i++) {
                model[i] = in.next().charAt(0);
                R[i] = in.nextInt() - 1;
                C[i] = in.nextInt() - 1;
            }
            int score = 0;
            int[][] ret = new int[n][];
            for (int i = 0; i < n; i++) {
                ret[i] = new int[n];
            }
            // put x
            boolean[] markR = new boolean[n];
            boolean[] markC = new boolean[n];
            mate = new int[n];
            Arrays.fill(mate, -1);
            for (int i = 0; i < m; i++) {
                if (model[i] != '+') {
                    mate[C[i]] = R[i];
                    markC[C[i]] = true;
                    markR[R[i]] = true;
                    ++score;
                }
            }
            g = new boolean[n][];
            vis = new boolean[n];
            for (int i = 0; i < n; i++) {
                g[i] = new boolean[n];
                for (int j = 0; j < n; j++) {
                    if (!markR[i] && !markC[j]) {
                        g[i][j] = true;
                    }
                }
            }
            for (int i = 0; i < n; i++) {
                Arrays.fill(vis, false);
                if (aug(i)) ++score;
            }
            for (int i = 0; i < n; i++) {
                if (mate[i] != -1) {
                    ret[mate[i]][i] = 1;
                }
            }
            // put +
            markR = new boolean[n * 2 - 1];
            markC = new boolean[n * 2 - 1];
            mate = new int[n * 2 - 1];
            vis = new boolean[n * 2 - 1];
            Arrays.fill(mate, -1);
            for (int i = 0; i < m; i++) {
                if (model[i] != 'x') {
                    markR[R[i] + C[i]] = true;
                    markC[R[i] - C[i] + n - 1] = true;
                    mate[R[i] - C[i] + n - 1] = R[i] + C[i];
                    ++score;
                }
            }
            g = new boolean[n * 2 - 1][];
            for (int i = 0; i < n * 2 - 1; ++i) {
                g[i] = new boolean[n * 2 - 1];
            }
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    int r = i + j, c = i - j + n - 1;
                    if (!markR[r] && !markC[c]) {
                        g[r][c] = true;
                    }
                }
            }
            for (int i = 0; i < n * 2 - 1; ++i) {
                Arrays.fill(vis, false);
                if (aug(i)) ++score;
            }
            for (int i = 0; i < n * 2 - 1; ++i) {
                if (mate[i] != -1) {
                    int x = (mate[i] + i - (n - 1)) / 2;
                    int y = mate[i] - x;
                    ret[x][y] |= 2;
                }
            }
            for (int i = 0; i < m; i++) {
                int mask = 0;
                if (model[i] == 'x') mask = 1;
                if (model[i] == '+') mask = 2;
                if (model[i] == 'o') mask = 3;
                if (mask == ret[R[i]][C[i]]) {
                    ret[R[i]][C[i]] = 0;
                }
            }
            int total = 0;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (ret[i][j] != 0) ++total;
                }
            }
            out.printf("Case #%d: %d %d\n", testNumber, score, total);
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (ret[i][j] == 0) continue;
                    if (ret[i][j] == 1) out.printf("x %d %d\n", i + 1, j + 1);
                    if (ret[i][j] == 2) out.printf("+ %d %d\n", i + 1, j + 1);
                    if (ret[i][j] == 3) out.printf("o %d %d\n", i + 1, j + 1);
                }
            }
        }

        private boolean aug(int u) {
            for (int v = 0; v < g.length; ++v) {
                if (vis[v] || !g[u][v]) continue;
                ;
                vis[v] = true;
                if (mate[v] == -1 || aug(mate[v])) {
                    mate[v] = u;
                    return true;
                }
            }
            return false;
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

