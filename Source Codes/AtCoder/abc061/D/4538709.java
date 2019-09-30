import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        try (Scanner sc = new Scanner(System.in)) {
            new Main().solve(sc);
        }
    }

    void solve(Scanner sc) {
        int n = sc.nextInt();
        int m = sc.nextInt();
        Edge[] edges = new Edge[m];
        for (int i = 0; i < m; i++) {
            int a = sc.nextInt();
            int b = sc.nextInt();
            long c = sc.nextLong();
            edges[i] = new Edge(a - 1, b - 1, -c);
        }

        long[] distances = new long[n];
        long INF = Long.MAX_VALUE;
        for (int i = 0; i < n; i++) {
            distances[i] = INF;
        }
        distances[0] = 0;

        boolean hasClosedPath = false;
        for (int i = 0; i < n; i++) {
            for (Edge e : edges) {
                if (distances[e.from] != INF && distances[e.to] > distances[e.from] + e.cost) {
                    distances[e.to] = distances[e.from] + e.cost;

                    if (i == n - 1 && e.to == n - 1) {
                        hasClosedPath = true;
                    }
                }
            }
        }

        if (hasClosedPath) {
            System.out.println("inf");
        } else {
            System.out.println(-distances[n - 1]);
        }
    }
}

class Edge {
    int from;
    int to;
    long cost;

    Edge(int from, int to, long cost) {
        this.from = from;
        this.to = to;
        this.cost = cost;
    }
}