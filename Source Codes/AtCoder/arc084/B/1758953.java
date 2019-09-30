import java.util.*;

public class Main {
    int n;
    ArrayList<ArrayList<Edge>> ns;
    public static void main(String[] args) {
        Main m = new Main();
        m.read();
        m.solve();
    }

    private void read() {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        ns = new ArrayList<>(n+1);
        for (int i = 0; i < n+1; i++)
            ns.add(new ArrayList<>());
    }

    private void solve() {
        for (int i = 0; i < n+1; i++) {
            int nxt = (i + 1) % n;
            int nxt2 = (i * 10) % n;
            ns.get(i).add(new Edge(i, nxt, 1));
            ns.get(i).add(new Edge(i, nxt2, 0));
        }
        int[] ds = new int[n+1];
        Arrays.fill(ds, n+1);
        Deque<Edge> deq = new ArrayDeque<>();
        ds[1] = 1;
        for (Edge e: ns.get(1))
            if (e.c == 0) deq.addFirst(e);
            else deq.addLast(e);
        while (!deq.isEmpty()) {
            Edge e = deq.pollFirst();
            int dist = ds[e.cur] + e.c;
            ds[e.to] = Math.min(dist, ds[e.to]);
            for (Edge nxt: ns.get(e.to)) {
                if (ds[nxt.to] > ds[e.to] + nxt.c) {
                    if (nxt.c == 0)
                        deq.addFirst(nxt);
                    else
                        deq.addLast(nxt);
                }
            }
        }
        System.out.println(ds[0]);
    }

    private class Edge {
        int cur;
        int to;
        int c;
        Edge (int cur, int to, int c) {
            this.cur = cur;
            this.to = to;
            this.c = c;
        }
    }
}