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
        TaskE solver = new TaskE();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskE {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            int h = in.nextInt();
            int[][] g = new int[2 * h + 1][2 * h + 1];
            for (int i = 0; i < n; ++i) {
                int a = in.nextInt();
                int b = in.nextInt();
                int c = in.nextInt();
                int d = in.nextInt();
                int left;
                if (c == 0) {
                    left = h - a;
                } else {
                    left = h + c;
                }
                int right;
                if (d == 0) {
                    right = h + b;
                } else {
                    right = h - d;
                }
                ++g[left][right];
            }
            int[] outdeg = new int[g.length];
            int[] indeg = new int[g.length];
            for (int i = 0; i < g.length; ++i) {
                for (int j = 0; j < g.length; ++j) {
                    outdeg[i] += g[i][j];
                    indeg[j] += g[i][j];
                }
            }
            for (int i = 0; i < h; ++i) {
                int delta = outdeg[i] - indeg[i];
                if (delta < 0) {
                    out.println("NO");
                    return;
                }
                g[0][i] += delta;
            }
            for (int i = h + 1; i < g.length; ++i) {
                int delta = indeg[i] - outdeg[i];
                if (delta < 0) {
                    out.println("NO");
                    return;
                }
                g[i][0] += delta;
            }
            boolean[] mark = new boolean[g.length];
            dfs(0, g, mark);
            for (int i = 0; i < g.length; ++i)
                if (!mark[i] && outdeg[i] + indeg[i] > 0) {
                    out.println("NO");
                    return;
                }
            out.println("YES");
        }

        private void dfs(int i, int[][] g, boolean[] mark) {
            if (mark[i]) return;
            mark[i] = true;
            for (int j = 0; j < g.length; ++j)
                if (g[i][j] != 0 || g[j][i] != 0) {
                    dfs(j, g, mark);
                }
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