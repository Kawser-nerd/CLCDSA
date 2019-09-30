import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.*;

public class Main {

    static int N;
    static int K;
    static Edge[] E;

    public static void main(String[] args) {
        FastScanner sc = new FastScanner(System.in);
        N = sc.nextInt();
        K = sc.nextInt();
        E = new Edge[N-1];
        for (int i = 0; i < N-1; i++) {
            E[i] = new Edge(sc.nextInt() - 1, sc.nextInt() - 1);
        }

        System.out.println(solve());
    }

    static int solve() {
        List<Edge>[] G = new List[N];
        for (int i = 0; i < N; i++) {
            G[i] = new ArrayList<>();
        }
        for (Edge e : E) {
            G[e.x].add(e);
            G[e.y].add(e);
        }


        int ans = Integer.MAX_VALUE;
        if( K % 2 == 0 ) {
            int r = K / 2;
            for (int v = 0; v < N; v++) {
                ans = Math.min(countOutOfRange(v, r, G), ans);
            }
        } else {
            int r = K / 2;
            for (Edge e : E) {
                ans = Math.min(countOutOfRange(e, r, G), ans);
            }
        }
        return ans;
    }

    static int countOutOfRange(Edge c, int r, List<Edge>[] G) {
        return _count(c.x, r, G, c) + _count(c.y, r, G, c);
    }

    static int countOutOfRange(int c, int r, List<Edge>[] G) {
        return _count(c, r, G, null);
    }

    private static int _count(int c, int r, List<Edge>[] G, Edge ignore) {
        ArrayDeque<State> q = new ArrayDeque<>();
        int[] dist = new int[N];
        Arrays.fill(dist, -1);
        dist[c] = 0;
        q.add(new State(c, 0));
        while(!q.isEmpty()) {
            State s = q.poll();
            if( dist[s.a] != s.d ) continue;

            for (Edge e : G[s.a]) {
                if( ignore != null && e == ignore ) continue;

                int b = e.opposite(s.a);
                if( dist[b] == -1 ) {
                    q.add( new State(b, s.d+1) );
                    dist[b] = s.d + 1;
                }
            }
        }

        int cnt = 0;
        for (int i = 0; i < N; i++) {
            if(dist[i] > r ) cnt++;
        }
        return cnt;
    }

    static class Edge {
        int x;
        int y;

        public Edge(int x, int y) {
            this.x = x;
            this.y = y;
        }

        public int opposite(int a) {
            return a == x ? y : x;
        }
    }

    static class State {
        int a;
        int d;

        public State(int a, int d) {
            this.a = a;
            this.d = d;
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