import java.util.*;
public class Main {
    static long INF = 100000000000000L;
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        List<Edge> edges = new ArrayList<>();
        for (int i = 0; i < m; i++) {
            int from = sc.nextInt();
            int to = sc.nextInt();
            long cost = -sc.nextLong();
            edges.add(new Edge(from, to, cost));
        }
        long[] d = new long[100000];
        d = bellmanFord(d, edges, 1, n, m);
        if (negativeLoop(d, edges, 1, n, m)) {
            System.out.println("inf");
            return;
        }
        // System.out.println(Arrays.toString(d));
        System.out.println(-d[n]);
    }

    public static long[] bellmanFord(long[] d, List<Edge> es, int s, int vl, int el) {
        for (int i = 0; i <= vl; i++) {
            d[i] = INF;
        }
        d[s] = 0;
        for (int j = 0; j < vl; j++) {
            for (int i = 0; i < el; i++) {
                Edge e = es.get(i);
                // System.out.println(e);
                // System.out.printf("d[%d] = %d d[%d] = %d e.cost = %d%n", e.to, d[e.to], e.from,
                //     d[e.from], e.cost);
                if (d[e.from] != INF && d[e.to] > d[e.from] + e.cost) {
                    d[e.to] = d[e.from] + e.cost;
                    //   System.out.printf("d[%d] = %d %n", e.to, d[e.to]);
                }
            }
        }
        return d;
    }

    public static boolean negativeLoop(long[] d, List<Edge> es, int s, int vl, int el) {
        boolean[] negative = new boolean[vl + 1];
        for (int i = 0; i < vl; i++) {
            for (int j = 0; j < el; j++) {
                Edge e = es.get(j);
                // System.out.println(e);
                // System.out.printf("d[%d] = %d d[%d] = %d e.cost = %d%n", e.to, d[e.to], e.from,
                //    d[e.from], e.cost);
                if (d[e.from] == INF) {
                    continue;
                }
                if (d[e.to] > d[e.from] + e.cost) {
                    d[e.to] = d[e.from] + e.cost;
                    // if (i == vl - 1) {
                    //    return true;
                    //}
                    negative[e.to] = true;
                }
                // System.out.printf("negative[%d] = %s %n", e.to, negative[e.to]);
                if (negative[e.from]) {
                    negative[e.to] = true;
                }
            }
        }
        // for (int i = 0; i <= vl; i++) {
        //    System.out.println(d[i]);
        //}
        return negative[vl];
    }
}
class Edge {
    int from;
    int to;
    long cost;
    public Edge(int from, int to, long cost) {
        this.from = from;
        this.to = to;
        this.cost = cost;
    }
    public String toString() {
        return String.format("from = %d to = %d cost = %d", this.from, this.to, this.cost);
    }
}