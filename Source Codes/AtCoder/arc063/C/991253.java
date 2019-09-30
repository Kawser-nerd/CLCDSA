import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Main {

    static BufferedReader in;
    static PrintWriter out;
    static StringTokenizer tok;

    void solve() throws IOException {
        int n = ni();
        int[] a = new int[n];
        int[] b = new int[n];
        for (int i = 0; i < n - 1; i++) {
            a[i] = ni() - 1;
            b[i] = ni() - 1;
        }
        int k = ni();
        int[] v = new int[k];
        int[] p = new int[k];
        for (int i = 0; i < k; i++) {
            v[i] = ni() - 1;
            p[i] = ni();
        }

        ArrayList<ArrayList<Edge>> G = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            G.add(new ArrayList<>());
        }

        for (int i = 0; i < n - 1; i++) {
            G.get(a[i]).add(new Edge(b[i], 1));
            G.get(b[i]).add(new Edge(a[i], 1));
        }

        G.add(new ArrayList<>());
        for (int i = 0; i < k; i++) {
            G.get(n).add(new Edge(v[i], p[i]));
        }

        Dijkstra d = new Dijkstra(G);
        int[] dist = d.getDist(n);

        boolean flg = true;
        for (int i = 0; i < n - 1; i++) {
            if (Math.abs(dist[a[i]] - dist[b[i]]) != 1) {
                flg = false;
                break;
            }
        }
        if (flg) {
            for (int i = 0; i < k; i++) {
                if (dist[v[i]] != p[i]) {
                    flg = false;
                    break;
                }
            }
        }

        if (flg) {
            out.println("Yes");
            for (int i = 0; i < n; i++) {
                out.println(dist[i]);
            }
        } else {
            out.println("No");
        }
    }

    class Dijkstra {
        int n;
        ArrayList<ArrayList<Edge>> G;

        int INF = Integer.MAX_VALUE / 3;

        public Dijkstra(ArrayList<ArrayList<Edge>> G) {
            n = G.size();
            this.G = G;
        }

        int[] getDist(int s) {
            PriorityQueue<Pair> Q = new PriorityQueue<>();
            Q.add(new Pair(s, 0));
            int[] dist = new int[n];
            Arrays.fill(dist, INF);
            boolean[] used = new boolean[n];
            while (!Q.isEmpty()) {
                Pair p = Q.poll();
                if (used[p.x]) continue;
                used[p.x] = true;
                dist[p.x] = p.y;

                for (Edge e : G.get(p.x)) {
                    Q.add(new Pair(e.to, p.y + e.cost));
                }
            }
            return dist;
        }

        public class Pair implements Comparable<Pair> {
            int x, y;

            public Pair(int x, int y) {
                this.x = x;
                this.y = y;
            }

            public int compareTo(Pair p) {
                return y - p.y;
            }
        }
    }

    class Edge implements Comparable<Edge> {
        int to;
        int cost;

        public Edge(int to, int cost) {
            this.to = to;
            this.cost = cost;
        }

        public int compareTo(Edge edge) {
            return cost - edge.cost;
        }
    }

    String ns() throws IOException {
        while (!tok.hasMoreTokens()) {
            tok = new StringTokenizer(in.readLine(), " ");
        }
        return tok.nextToken();
    }

    int ni() throws IOException {
        return Integer.parseInt(ns());
    }

    long nl() throws IOException {
        return Long.parseLong(ns());
    }

    double nd() throws IOException {
        return Double.parseDouble(ns());
    }

    String[] nsa(int n) throws IOException {
        String[] res = new String[n];
        for (int i = 0; i < n; i++) {
            res[i] = ns();
        }
        return res;
    }

    int[] nia(int n) throws IOException {
        int[] res = new int[n];
        for (int i = 0; i < n; i++) {
            res[i] = ni();
        }
        return res;
    }

    long[] nla(int n) throws IOException {
        long[] res = new long[n];
        for (int i = 0; i < n; i++) {
            res[i] = nl();
        }
        return res;
    }

    public static void main(String[] args) throws IOException {
        in = new BufferedReader(new InputStreamReader(System.in));
        out = new PrintWriter(System.out);
        tok = new StringTokenizer("");
        Main main = new Main();
        main.solve();
        out.close();
    }
}