import java.io.*;
import java.util.*;

public class Main {

    static int N, M, S, T;
    static Edge[] E;

    public static void main(String[] args) throws IOException {
        FastScanner sc = new FastScanner(System.in);
        N = sc.nextInt();
        M = sc.nextInt();
        S = sc.nextInt()-1;
        T = sc.nextInt()-1;
        E = new Edge[M];
        for (int i = 0; i < M; i++) {
            E[i] = new Edge(sc.nextInt()-1, sc.nextInt()-1, sc.nextInt());
        }

        System.out.println(solve());
    }

    static class Edge {
        final int a, b, d;

        public Edge(int a, int b, int d) {
            this.a = a;
            this.b = b;
            this.d = d;
        }

        int opposite(int x) {
            return a == x ? b : a;
        }
    }

    static class State implements Comparable<State> {
        int a;
        long d;

        public State(int a, long d) {
            this.a = a;
            this.d = d;
        }

        @Override
        public int compareTo(State o) {
            return Long.compare(d, o.d);
        }
    }

    static int MOD = 1_000_000_007;
    static long INF = Long.MAX_VALUE / 2;

    static long solve() throws IOException {
        Edge[][] G = adjB(N, E);

        Result rs = calc(G, S);
        Result rt = calc(G, T);
        long dist = rs.dist[T];

        long collision = 0;
        int vcnt = 0;
        for (int i = 0; i < N; i++) {
            if( rs.dist[i] == dist / 2 && rt.dist[i] == dist / 2 ) {
                long ab = (long)rs.time[i] * rt.time[i] % MOD;
                collision += ab * ab;
                collision %= MOD;
                vcnt++;
            }
        }

        int ecnt = 0;
        for (Edge e : E) {
            int a = rs.dist[e.a] < rs.dist[e.b] ? e.a : e.b;
            int b = e.opposite(a);
            int d = e.d;
            if( rs.dist[a] + d == rs.dist[b]
                    && rs.dist[b] + rt.dist[b] == dist
                    // && rs.dist[a] + rt.dist[a] == dist ???????
                    && rs.dist[a] < rt.dist[a]
                    && rs.dist[b] > rt.dist[b] )
            {
                long ab = (long)rs.time[a] * rt.time[b] % MOD;
                collision += ab * ab;
                collision %= MOD;
                ecnt ++;
            }
        }

        int time = rs.time[T];
        return ((long)time * time - collision + MOD) % MOD;
    }

    static class Key {
        int a, b;

        public Key(int a, int b) {
            this.a = a;
            this.b = b;
        }

        @Override
        public boolean equals(Object o) {
            if (this == o) return true;
            if (o == null || getClass() != o.getClass()) return false;
            Key key = (Key) o;
            return a == key.a &&
                    b == key.b;
        }

        @Override
        public int hashCode() {
            return Objects.hash(a, b);
        }
    }

    // (v, w) intersect (x, y)
    static boolean isCross(long v, long w, long x, long y) {
        if( v <= x ) {
            return x < w;
        } else {
            return v < y;
        }
    }

    static class Result {
        long[] dist;
        int[] time;

        public Result(long[] dist, int[] time) {
            this.dist = dist;
            this.time = time;
        }
    }

    static Result calc(Edge[][] G, int from) {
        long[] dist = new long[N];
        int[] time = new int[N];
        Arrays.fill(dist, INF);
        Arrays.fill(time, -1);

        PriorityQueue<State> q = new PriorityQueue<>();
        q.add(new State(from, 0));
        dist[from] = 0;
        time[from] = 1;

        while( !q.isEmpty() ) {
            State s = q.poll();
            if( dist[s.a] != s.d ) continue;

            for (Edge e : G[s.a]) {
                int next = e.opposite(s.a);
                long nd = s.d + e.d;
                if( dist[next] > nd ) {
                    dist[next] = nd;
                    time[next] = time[s.a];
                    q.add( new State(next, nd) );

                } else if( dist[next] == nd ) {
                    time[next] += time[s.a];
                    time[next] %= MOD;
                }
            }
        }
        return new Result(dist, time);
    }

    static Edge[][] adjB(int n, Edge[] E) {
        Edge[][] adj = new Edge[n][];
        int[] cnt = new int[n];
        for (Edge e : E) {
            cnt[e.a]++;
            cnt[e.b]++;
        }
        for (int i = 0; i < n; i++) {
            adj[i] = new Edge[cnt[i]];
        }
        for (Edge e : E) {
            adj[e.a][--cnt[e.a]] = e;
            adj[e.b][--cnt[e.b]] = e;
        }
        return adj;
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
}