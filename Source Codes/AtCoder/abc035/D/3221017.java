import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.*;

public class Main {

    static int N, M, T;
    static int[] A;
    static Edge[] E;

    public static void main(String[] args) {
        FastScanner fc = new FastScanner(System.in);
        N = fc.nextInt();
        M = fc.nextInt();
        T = fc.nextInt();
        A = fc.nextIntArray(N);
        E = new Edge[M];
        for (int i = 0; i < M; i++) {
            E[i] = new Edge(fc.nextInt()-1, fc.nextInt()-1, fc.nextInt());
        }
        System.out.println(solve());
    }

    static long solve() {
        long[] forward = dijk(false);
        long[] back = dijk(true);

        long ans = (long)A[0] * T; // fuck!
        for (int i = 1; i < N; i++) {
            if( forward[i] == INF || back[i] == INF ) continue;
            long t = T - forward[i] - back[i];
            if( t <= 0 ) continue;

            ans = Math.max(t * A[i], ans);
        }
        return ans;
    }

    static long INF = Long.MAX_VALUE / 3;

    static long[] dijk(boolean reverse) {
        List<Edge>[] G = adjListD(N, E, reverse);

        PriorityQueue<State> q = new PriorityQueue<>();
        long[] cost = new long[N];
        Arrays.fill(cost, INF);

        cost[0] = 0;
        q.add( new State(0, 0) );

        while(!q.isEmpty()) {
            State s = q.poll();
            if( cost[s.a] != s.c ) continue;

            for (Edge e : G[s.a]) {
                int next = e.opposite(s.a);
                long nextCost = s.c + e.c;

                if( cost[next] > nextCost ) {
                    q.add( new State(next, nextCost) );
                    cost[next] = nextCost;
                }
            }
        }
        return cost;
    }

    static List<Edge>[] adjListD(int n, Edge[] es, boolean reverse) {
        List<Edge>[] adj = new List[n];
        for (int i = 0; i < n; i++) {
            adj[i] = new ArrayList<>();
        }
        for (Edge e : es) {
            if( reverse ) {
                adj[e.y].add(e);
            } else {
                adj[e.x].add(e);
            }
        }
        return adj;
    }

    static class Edge {
        int x, y;
        long c;

        public Edge(int x, int y, long c) {
            this.x = x;
            this.y = y;
            this.c = c;
        }

        public int opposite(int a) {
            return a == x ? y : x;
        }
    }

    static class State implements Comparable<State> {
        private int a;
        private long c;

        public State(int a, long c) {
            this.a = a;
            this.c = c;
        }

        @Override
        public int compareTo(State o) {
            return Long.compare(c, o.c);
        }
    }

    @SuppressWarnings("unused")
    static class FastScanner {
        private BufferedReader reader;
        private StringTokenizer tokenizer;

        FastScanner(InputStream in) {
            reader = new BufferedReader(new InputStreamReader(in));
            tokenizer = null;
        }

        String next() {
            if (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    tokenizer = new StringTokenizer(reader.readLine());
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
            return tokenizer.nextToken();
        }

        String nextLine() {
            if (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    return reader.readLine();
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
            return tokenizer.nextToken("\n");
        }

        long nextLong() {
            return Long.parseLong(next());
        }

        int nextInt() {
            return Integer.parseInt(next());
        }

        int[] nextIntArray(int n) {
            int[] a = new int[n];
            for (int i = 0; i < n; i++)
                a[i] = nextInt();
            return a;
        }

        long[] nextLongArray(int n) {
            long[] a = new long[n];
            for (int i = 0; i < n; i++)
                a[i] = nextLong();
            return a;
        }
    }
} Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.