import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.math.BigDecimal;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.StringTokenizer;

public class Main {

    static int N;
    static int G;
    static int E;
    static int[] P;
    static int[] A;
    static int[] B;

    public static void main(String[] args) {
        FastScanner sc = new FastScanner(System.in);
        N = sc.nextInt();
        G = sc.nextInt();
        E = sc.nextInt();
        if( G > 0 ) {
            P = sc.nextIntArray(G);
        } else {
            sc.nextLine(); // G==0???????????????????
            P = new int[0];
        }
        A = new int[E];
        B = new int[E];
        for (int i = 0; i < E; i++) {
            A[i] = sc.nextInt();
            B[i] = sc.nextInt();
        }
        System.out.println( solve() );
    }

    static int solve() {
        if( G == 0 ) return 0;

        FordFulkerson ff = new FordFulkerson(N+1);
        int t = N;
        for (int i = 0; i < E; i++) {
            ff.addEdge(A[i], B[i], 1);
            ff.addEdge(B[i], A[i], 1);
        }
        for (int p : P) {
            ff.addEdge(p, t, 1);
        }

        return ff.execute(0, t);
    }

    static class FordFulkerson {

        private final List<Edge>[] EDGE;
        private final boolean[] USED;

        public FordFulkerson(int n) {
            EDGE = new List[n];
            for (int i = 0; i < n; i++) {
                EDGE[i] = new ArrayList<>();
            }
            USED = new boolean[n];
        }

        void addEdge(int from, int to, int cap) {
            EDGE[from].add( new Edge(to, cap, EDGE[to].size()) );
            EDGE[to].add( new Edge(from, 0, EDGE[from].size()-1) );
        }

        int execute(int s, int t) {
            int flow = 0;
            int f;
            while(true) {
                Arrays.fill(USED, false);
                f = dfs(s, t, Integer.MAX_VALUE);
                if( f == 0 ) return flow;
                flow += f;
            }
        }

        private int dfs(int v, int t, int f) {
            if( v == t ) return f;
            USED[v] = true;
            for (int i = 0; i < EDGE[v].size(); i++) {
                Edge e = EDGE[v].get(i);
                if( USED[e.to] || e.cap <= 0 ) continue;

                int d = dfs(e.to, t, Math.min(f, e.cap) );
                if( d > 0 ) {
                    e.cap -= d;
                    EDGE[e.to].get(e.rev).cap += d;
                    return d;
                }
            }
            return 0;
        }
    }

    static class Edge {
        int to, cap, rev;

        public Edge(int to, int cap, int rev) {
            this.to = to;
            this.cap = cap;
            this.rev = rev;
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