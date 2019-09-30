import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.PriorityQueue;
import java.util.Queue;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        new Main().compute();
    }

    void compute() {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int M = sc.nextInt();
        long T = sc.nextLong();
        long[] A = new long[N];
        for (int i = 0; i < N; i++) {
            A[i] = sc.nextLong();
        }

        List<Edge>[] G = new List[N];
        List<Edge>[] R = new List[N];
        for (int i = 0; i < N; i++) {
            G[i] = new ArrayList<>();
            R[i] = new ArrayList<>();
        }
        for (int i = 0; i < M; i++) {
            int a = sc.nextInt() - 1;
            int b = sc.nextInt() - 1;
            long c = sc.nextLong();
            G[a].add(new Edge(b, c));
            R[b].add(new Edge(a, c));
        }

        long[] d = new long[N];
        long INF = (long) Math.pow(10, 15);
        Arrays.fill(d, INF);
        Queue<Pair> que = new PriorityQueue<>((o1, o2) -> (int) Math.signum(o1.value - o2.value));
        d[0] = 0L;
        que.add(new Pair(0, 0L));

        while (!que.isEmpty()) {
            Pair p = que.poll();
            int v = p.key;
            if (d[v] < p.value) {
                continue;
            }
            for (int i = 0; i < G[v].size(); i++) {
                Edge e = G[v].get(i);
                if (d[e.to] > d[v] + e.cost) {
                    d[e.to] = d[v] + e.cost;
                    que.add(new Pair(e.to, d[e.to]));
                }
            }
        }

        long[] r = new long[N];
        Arrays.fill(r, INF);
        que = new PriorityQueue<>((o1, o2) -> (int) Math.signum(o1.value - o2.value));
        r[0] = 0L;
        que.add(new Pair(0, 0L));

        while (!que.isEmpty()) {
            Pair p = que.poll();
            int v = p.key;
            if (r[v] < p.value) {
                continue;
            }
            for (int i = 0; i < R[v].size(); i++) {
                Edge e = R[v].get(i);
                if (r[e.to] > r[v] + e.cost) {
                    r[e.to] = r[v] + e.cost;
                    que.add(new Pair(e.to, r[e.to]));
                }
            }
        }

        long ans = 0;
        for (int i = 0; i < N; i++) {
            ans = Math.max(ans, Math.max(0, T - d[i] - r[i]) * A[i]);
        }
        System.out.println(ans);
    }

    class Edge {

        int to;
        long cost;

        Edge(int to, long cost) {
            this.to = to;
            this.cost = cost;
        }
    }

    class Pair {

        int key;
        long value;

        Pair(int key, long value) {
            this.key = key;
            this.value = value;
        }
    }
} Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.