import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.*;

public class Main {

    void solve() throws IOException {
        int n = ni(), k = ni();
        INA ina = new INA(n - 1, 2);
        int[] a = ina.get(0);
        int[] b = ina.get(1);

        Dijkstra dij = new Dijkstra(n, a, b);

        int ans = Integer.MAX_VALUE;

        if (k % 2 == 0) {
            for (int i = 0; i < n; i++) {
                int[] dist = dij.getDist(i);
                int cnt = 0;
                for (int j = 0; j < n; j++) {
                    if (dist[j] > k / 2) cnt++;
                }
                ans = Math.min(ans, cnt);
            }
        } else {
            for (int i = 0; i < n - 1; i++) {
                int[] dist1 = dij.getDist(a[i]);
                int[] dist2 = dij.getDist(b[i]);
                int cnt = 0;
                for (int j = 0; j < n; j++) {
                    if (Math.min(dist1[j], dist2[j]) > k / 2) cnt++;
                }
                ans = Math.min(ans, cnt);
            }
        }

        out.println(ans);
    }

    class Dijkstra {
        int n;
        ArrayList<ArrayList<Edge>> G;

        int INF = Integer.MAX_VALUE / 3;

        Dijkstra(ArrayList<ArrayList<Edge>> G) {
            n = G.size();
            this.G = G;
        }

        Dijkstra(int n, int[] a, int[] b) {
            this.n = n;
            G = new ArrayList<>();
            for (int i = 0; i < n; i++) {
                G.add(new ArrayList<>());
            }

            int k = a.length;
            for (int i = 0; i < k; i++) {
                G.get(a[i]).add(new Edge(b[i], 1));
                G.get(b[i]).add(new Edge(a[i], 1));
            }
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

        class Pair implements Comparable<Pair> {
            int x, y;

            Pair(int x, int y) {
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

        Edge(int to, int cost) {
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

    class INA {
        int[][] a;

        INA(int n, int m) throws IOException {
            this(n, m, -1);
        }

        INA(int n, int m, int t) throws IOException {
            a = new int[m][n];

            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    a[j][i] = ni() + t;
                }
            }
        }

        int[] get(int i) {
            return a[i];
        }
    }

    static BufferedReader in;
    static PrintWriter out;
    static StringTokenizer tok;

    public static void main(String[] args) throws IOException {
        in = new BufferedReader(new InputStreamReader(System.in));
        out = new PrintWriter(System.out);
        tok = new StringTokenizer("");
        Main main = new Main();
        main.solve();
        out.close();
    }
}