import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.StringTokenizer;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 *
 * @author wh1t3_r0s3
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
        ArrayList<Integer>[] g;
        int[] size;
        int[] level;
        int[] parent;

        void dfs(int u, int p, int curr) {
            size[u] = 1;
            level[u] = curr;
            parent[u] = p;
            for (int x : g[u]) {
                if (x != p) {
                    dfs(x, u, curr + 1);
                    size[u] += size[x];
                }
            }
        }

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            g = new ArrayList[n];
            for (int i = 0; i < n; i++) {
                g[i] = new ArrayList<Integer>();
            }
            for (int i = 1; i < n; i++) {
                int u = in.nextInt() - 1;
                int v = in.nextInt() - 1;
                g[u].add(v);
                g[v].add(u);
            }
            level = new int[n];
            size = new int[n];
            parent = new int[n];
            dfs(0, -1, 1);
            int dis = level[n - 1] - level[0] - 1;
            int now = dis / 2, curr = n - 1;
            while (now > 0) {
                curr = parent[curr];
                now--;
            }
            int v1 = size[curr], v2 = n - v1;
            out.println(v1 >= v2 ? "Snuke" : "Fennec");

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
} Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.