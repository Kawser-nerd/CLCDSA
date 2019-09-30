import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Scanner;

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
        Scanner in = new Scanner(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        D solver = new D();
        solver.solve(1, in, out);
        out.close();
    }

    static class D {
        public void solve(int testNumber, Scanner in, PrintWriter out) {
            int n = in.nextInt(), g = in.nextInt(), e = in.nextInt();
            int[][] r = new int[n + 1][n + 1];
            for (int i = 0; i < g; i++) {
                r[in.nextInt()][n] = 1;
            }
            for (int i = 0; i < e; i++) {
                int a = in.nextInt(), b = in.nextInt();
                r[a][b] = 1;
                r[b][a] = 1;
            }
            int ans = 0;
            int[] path;
            while ((path = dfs(r, 0, n, 0, new boolean[n + 1])) != null) {
                ans++;
                for (int i = 1; i < path.length; i++) {
                    r[path[i - 1]][path[i]]--;
                    r[path[i]][path[i - 1]]++;
                }
            }
            out.println(ans);
        }

        private int[] dfs(int[][] graph, int start, int goal, int depth, boolean[] searched) {
            if (start == goal) {
                int[] res = new int[depth + 1];
                res[depth] = goal;
                return res;
            }
            searched[start] = true;
            for (int i = 0; i < graph.length; i++) {
                if (!searched[i] && graph[start][i] > 0) {
                    int[] res = dfs(graph, i, goal, depth + 1, searched);
                    if (res != null) {
                        res[depth] = start;
                        return res;
                    }
                }
            }
            return null;
        }

    }
}