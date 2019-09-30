import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.stream.IntStream;
import java.util.HashSet;
import java.util.stream.Stream;
import java.util.Scanner;
import java.util.Set;

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
        private static D.Node[] nodes;

        public void solve(int testNumber, Scanner in, PrintWriter out) {
            // 1. INPUT GRAPH
            int n = in.nextInt();
            nodes = IntStream.range(0, n).mapToObj(D.Node::new).toArray(D.Node[]::new);
            for (int i = 1; i < n; i++) {
                int x = in.nextInt() - 1, y = in.nextInt() - 1;
                nodes[x].rel.add(nodes[y]);
                nodes[y].rel.add(nodes[x]);
            }

            // 2. ORGANIZE TREE
            nodes[0].setParent(0, null);

            // 3. CACHE PARENTS
            for (int i = 1; i < 20; i++) {
                for (D.Node node : nodes) {
                    D.Node mid = node.parents[i - 1];
                    if (mid != null) {
                        node.parents[i] = node.parents[i - 1].parents[i - 1];
                    }
                }
            }

            // 4. OUTPUT
            int q = in.nextInt();
            for (int i = 0; i < q; i++) {
                out.println(calc(in.nextInt() - 1, in.nextInt() - 1));
            }
        }

        private int calc(int a, int b) {
            if (nodes[a].depth > nodes[b].depth) {
                a ^= b;
                b ^= a;
                a ^= b;
            }
            D.Node x = nodes[a], y = nodes[b];
            int d = y.depth - x.depth;
            for (int j = 0; d > 0; j++, d /= 2) {
                if (d % 2 != 0) {
                    y = y.parents[j];
                }
            }

            D.Node lca;
            if (x == y) {
                lca = x;
            } else {
                for (int j = 19; j >= 0; j--) {
                    if (x.parents[j] != y.parents[j]) {
                        x = x.parents[j];
                        y = y.parents[j];
                    }
                }
                lca = x.parents[0];
            }
            return nodes[a].depth + nodes[b].depth - lca.depth * 2 + 1;
        }

        private static class Node {
            private final int id;
            private D.Node[] parents = new D.Node[20];
            private int depth = 0;
            private final Set<D.Node> rel = new HashSet<>();

            public Node(int id) {
                this.id = id;
            }

            private void setParent(int depth, D.Node parent) {
                this.depth = depth;
                this.parents[0] = parent;
                for (D.Node child : rel) {
                    if (child != parent) {
                        child.setParent(depth + 1, this);
                    }
                }
            }

            public String toString() {
                return "(" + (id + 1) + ":" + depth + ")";
            }

        }

    }
}