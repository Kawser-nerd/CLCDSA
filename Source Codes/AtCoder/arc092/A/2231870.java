import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;
import java.io.IOException;
import java.util.InputMismatchException;
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
            int[] c = new int[n];
            int[] d = new int[n];

            for (int i = 0; i < n; i++) {
                a[i] = in.nextInt();
                b[i] = in.nextInt();
            }
            for (int i = 0; i < n; i++) {
                c[i] = in.nextInt();
                d[i] = in.nextInt();
            }

            boolean[][] graph = new boolean[2 * n][2 * n];
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (a[i] < c[j] && b[i] < d[j]) {
                        graph[i][j + n] = true;
                        graph[j + n][i] = true;
                    }
                }
            }

            out.println(MaxMatching2.maxMatching(graph) / 2);
        }

    }

    static class InputReader {
        BufferedReader in;
        StringTokenizer tok;

        public String nextString() {
            while (!tok.hasMoreTokens()) {
                try {
                    tok = new StringTokenizer(in.readLine(), " ");
                } catch (IOException e) {
                    throw new InputMismatchException();
                }
            }
            return tok.nextToken();
        }

        public int nextInt() {
            return Integer.parseInt(nextString());
        }

        public InputReader(InputStream inputStream) {
            in = new BufferedReader(new InputStreamReader(inputStream));
            tok = new StringTokenizer("");
        }

    }

    static class MaxMatching2 {
        public static int maxMatching(boolean[][] graph) {
            int n1 = graph.length;
            int n2 = n1 == 0 ? 0 : graph[0].length;
            int[] matching = new int[n2];
            Arrays.fill(matching, -1);
            int matches = 0;
            for (int u = 0; u < n1; u++)
                if (findPath(graph, u, matching, new boolean[n1]))
                    ++matches;
            return matches;
        }

        static boolean findPath(boolean[][] graph, int u1, int[] matching, boolean[] vis) {
            vis[u1] = true;
            for (int v = 0; v < matching.length; ++v) {
                int u2 = matching[v];
                if (graph[u1][v] && (u2 == -1 || !vis[u2] && findPath(graph, u2, matching, vis))) {
                    matching[v] = u1;
                    return true;
                }
            }
            return false;
        }

    }
}