import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.io.IOException;
import java.util.InputMismatchException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;
import java.io.BufferedReader;
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
            List<Integer>[] G = new ArrayList[n];
            for (int i = 0; i < n; i++) {
                G[i] = new ArrayList<>();
            }
            for (int i = 0; i < n - 1; i++) {
                int x = in.nextInt() - 1;
                int y = in.nextInt() - 1;

                G[x].add(y);
                G[y].add(x);
            }

            Lca lca = new Lca(G, 0);
            int[] depth = lca.getDepth();
            int q = in.nextInt();
            for (int i = 0; i < q; i++) {
                int a = in.nextInt() - 1;
                int b = in.nextInt() - 1;

                int c = lca.lca(a, b);
                out.println((depth[a] - depth[c]) + (depth[b] - depth[c]) + 1);
            }
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

    static class Lca {
        int[] depth;
        int[] dfs_order;
        int cnt;
        int[] first;
        int[] minPos;
        int n;

        public int[] getDepth() {
            return depth;
        }

        void dfs(List<Integer>[] tree, int u, int d) {
            depth[u] = d;
            dfs_order[cnt++] = u;
            for (int v : tree[u])
                if (depth[v] == -1) {
                    dfs(tree, v, d + 1);
                    dfs_order[cnt++] = u;
                }
        }

        void buildTree(int node, int left, int right) {
            if (left == right) {
                minPos[node] = dfs_order[left];
                return;
            }
            int mid = (left + right) >> 1;
            buildTree(2 * node + 1, left, mid);
            buildTree(2 * node + 2, mid + 1, right);
            minPos[node] = depth[minPos[2 * node + 1]] < depth[minPos[2 * node + 2]] ? minPos[2 * node + 1] : minPos[2 * node + 2];
        }

        public Lca(List<Integer>[] tree, int root) {
            int nodes = tree.length;
            depth = new int[nodes];
            Arrays.fill(depth, -1);

            n = 2 * nodes - 1;
            dfs_order = new int[n];
            cnt = 0;
            dfs(tree, root, 0);

            minPos = new int[4 * n];
            buildTree(0, 0, n - 1);

            first = new int[nodes];
            Arrays.fill(first, -1);
            for (int i = 0; i < dfs_order.length; i++)
                if (first[dfs_order[i]] == -1)
                    first[dfs_order[i]] = i;
        }

        public int lca(int a, int b) {
            return minPos(Math.min(first[a], first[b]), Math.max(first[a], first[b]), 0, 0, n - 1);
        }

        int minPos(int a, int b, int node, int left, int right) {
            if (a == left && right == b)
                return minPos[node];
            int mid = (left + right) >> 1;
            if (a <= mid && b > mid) {
                int p1 = minPos(a, Math.min(b, mid), 2 * node + 1, left, mid);
                int p2 = minPos(Math.max(a, mid + 1), b, 2 * node + 2, mid + 1, right);
                return depth[p1] < depth[p2] ? p1 : p2;
            } else if (a <= mid) {
                return minPos(a, Math.min(b, mid), 2 * node + 1, left, mid);
            } else if (b > mid) {
                return minPos(Math.max(a, mid + 1), b, 2 * node + 2, mid + 1, right);
            } else {
                throw new RuntimeException();
            }
        }

    }
} Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.