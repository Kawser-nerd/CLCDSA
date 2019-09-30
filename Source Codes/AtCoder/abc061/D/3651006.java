import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.List;
import java.util.Arrays;
import java.util.Scanner;
import java.util.ArrayList;

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
        DScoreAttack solver = new DScoreAttack();
        solver.solve(1, in, out);
        out.close();
    }

    static class DScoreAttack {
        public void solve(int testNumber, Scanner in, PrintWriter out) {
            int n = in.nextInt(), m = in.nextInt();
            BellmanFord bf = new BellmanFord(n);
            for (int i = 0; i < m; i++) {
                bf.addEdge(in.nextInt() - 1, in.nextInt() - 1, -in.nextInt());
            }
            try {
                out.println(-bf.shortestPath(0, n - 1));
            } catch (RuntimeException ex) {
                out.println("inf");
            }
        }

    }

    static class BellmanFord {
        int nodes;
        List<BellmanFord.Edge> edges;
        long[] distance;

        public BellmanFord(int n) {
            nodes = n;
            edges = new ArrayList<>();
            distance = new long[n];
        }

        public void addEdge(int from, int to, int cost) {
            edges.add(new BellmanFord.Edge(from, to, cost));
        }

        public long shortestPath(int src, int dst) {
            Arrays.fill(distance, Long.MAX_VALUE);
            distance[src] = 0;
            for (int i = 0; i < 2 * nodes; i++) {
            	boolean updated = false;
                for (BellmanFord.Edge e : edges) {
                    updated = true;
                    if (distance[e.from] < Long.MAX_VALUE && distance[e.to] > distance[e.from] + e.cost) {
                        distance[e.to] = distance[e.from] + e.cost;
                        if (i == nodes - 1 && e.to == dst) {
                            throw new RuntimeException("negative loop");
                        }
                    }
                }
                if (!updated) {
                    break;
                }
            }
            return distance[dst];
        }

        private static class Edge {
            int from;
            int to;
            long cost;

            public Edge(int from, int to, long cost) {
                this.from = from;
                this.to = to;
                this.cost = cost;
            }

        }

    }
}