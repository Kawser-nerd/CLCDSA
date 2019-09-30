import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.PriorityQueue;
import java.io.IOException;
import java.util.InputMismatchException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.AbstractCollection;
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
            int m = in.nextInt();
            int t = in.nextInt();
            long[] a = in.nextLongArray(n);

            Dijkstra dijkstra1 = new Dijkstra(n);
            Dijkstra dijkstra2 = new Dijkstra(n);
            for (int i = 0; i < m; i++) {
                int from = in.nextInt() - 1;
                int to = in.nextInt() - 1;
                int cost = in.nextInt();

                dijkstra1.addDirectedEdge(from, to, cost);
                dijkstra2.addDirectedEdge(to, from, cost);
            }

            long[] dist1 = dijkstra1.getDist(0);
            long[] dist2 = dijkstra2.getDist(0);

            long ans = 0;
            for (int i = 0; i < n; i++) {
                if (t >= dist1[i] + dist2[i])
                    ans = Math.max(ans, a[i] * (t - (dist1[i] + dist2[i])));
            }

            out.println(ans);
        }

    }

    static class Dijkstra {
        int n;
        ArrayList<Pair>[] G;
        long INF = Long.MAX_VALUE / 3;

        public Dijkstra(int n) {
            this.n = n;
            G = new ArrayList[n];
            for (int i = 0; i < n; i++) {
                G[i] = new ArrayList<>();
            }
        }

        public void addDirectedEdge(int from, int to, int cost) {
            G[from].add(new Pair(to, cost));
        }

        public long[] getDist(int s) {
            PriorityQueue<Pair> Q = new PriorityQueue<>();
            Q.add(new Pair(s, 0));
            long[] dist = new long[n];
            Arrays.fill(dist, INF);
            boolean[] used = new boolean[n];
            while (!Q.isEmpty()) {
                Pair p = Q.poll();
                if (used[p.x]) continue;
                used[p.x] = true;
                dist[p.x] = p.y;

                for (Pair edge : G[p.x]) {
                    Q.add(new Pair(edge.x, p.y + edge.y));
                }
            }
            return dist;
        }

        class Pair implements Comparable<Pair> {
            int x;
            long y;

            Pair(int x, long y) {
                this.x = x;
                this.y = y;
            }

            public int compareTo(Pair p) {
                return Long.compare(y, p.y);
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

        public long nextLong() {
            return Long.parseLong(nextString());
        }

        public long[] nextLongArray(int n) {
            long[] res = new long[n];
            for (int i = 0; i < n; i++) {
                res[i] = nextLong();
            }
            return res;
        }

        public InputReader(InputStream inputStream) {
            in = new BufferedReader(new InputStreamReader(inputStream));
            tok = new StringTokenizer("");
        }

    }
} Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.