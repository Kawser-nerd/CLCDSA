import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.*;

public class Main {

    static int N, A, B, M;
    static int[] X, Y;

    public static void main(String[] args) {
        FastScanner sc = new FastScanner(System.in);
        N = sc.nextInt();
        A = sc.nextInt()-1;
        B = sc.nextInt()-1;
        M = sc.nextInt();
        X = new int[M];
        Y = new int[M];
        for (int i = 0; i < M; i++) {
            X[i] = sc.nextInt()-1;
            Y[i] = sc.nextInt()-1;
        }

        System.out.println(solve());
    }

    static int MOD = 1_000_000_007;
    static int INF = Integer.MAX_VALUE / 2;

    static int solve() {
        MEMO = new int[N];
        Arrays.fill(MEMO, INF);

        int[][] dist = new int[N][N];
        for (int[] arr : dist) Arrays.fill(arr, INF);

        for (int i = 0; i < N; i++) {
            dist[i][i] = 0;
        }
        for (int i = 0; i < M; i++) {
            dist[X[i]][Y[i]] = 1;
            dist[Y[i]][X[i]] = 1;
        }

        for (int k = 0; k < N; k++) {
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    if( dist[i][k] == INF || dist[k][j] == INF ) continue;

                    if( dist[i][k] + dist[k][j] < dist[i][j] ) {
                        dist[i][j] = dist[i][k] + dist[k][j];
                    }
                }
            }
        }

        List<Edge> edges = new ArrayList<>();
        for (int i = 0; i < M; i++) {
            int ax = dist[A][X[i]];
            int ay = dist[A][Y[i]];

            if( ax + 1 == ay ) {
                edges.add( new Edge(X[i], Y[i]) );
            } else if( ay + 1 == ax ) {
                edges.add( new Edge(Y[i], X[i]) );
            }
        }

        int[][] G = adjD(N, edges);

        return dfs(A, G);
    }

    static int[] MEMO;

    static int dfs(int node, int[][] G) {
        if( node == B ) return 1;

        if( MEMO[node] != INF ) {
            return MEMO[node];
        }

        int ret = 0;
        for (int to : G[node]) {
            ret = (ret + dfs(to, G)) % MOD;
        }
        MEMO[node] = ret;
        return ret;
    }

    static int[][] adjD(int n, List<Edge> es) {
        int[][] adj = new int[n][];
        int[] cnt = new int[n];

        for (Edge e : es) {
            cnt[e.a]++;
        }
        for (int i = 0; i < n; i++) {
            adj[i] = new int[cnt[i]];
        }
        for (Edge e : es) {
            adj[e.a][--cnt[e.a]] = e.b;
        }
        return adj;
    }

    static class Edge {

        int a, b;

        public Edge(int a, int b) {
            this.a = a;
            this.b = b;
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
}