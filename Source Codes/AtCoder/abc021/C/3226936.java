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
        int[][] G = adjB(N, X, Y);

        int[] dist = new int[N];
        int[] time = new int[N];
        Arrays.fill(dist, INF);
        Arrays.fill(time, INF);

        ArrayDeque<State> q = new ArrayDeque<>();
        q.add(new State(A, 0));
        dist[A] = 0;
        time[A] = 1;

        while( !q.isEmpty() ) {
            State s = q.poll();

            for (int next : G[s.a]) {
                int nd = s.d + 1;
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
        return time[B];
    }

    static class State {
        int a, d;

        public State(int a, int d) {
            this.a = a;
            this.d = d;
        }
    }

    static int[][] adjB(int n, int[] from, int[] to) {
        int[][] adj = new int[n][];
        int[] cnt = new int[n];
        for (int f : from) {
            cnt[f]++;
        }
        for (int t : to) {
            cnt[t]++;
        }
        for (int i = 0; i < n; i++) {
            adj[i] = new int[cnt[i]];
        }
        for (int i = 0; i < from.length; i++) {
            adj[from[i]][--cnt[from[i]]] = to[i];
            adj[to[i]][--cnt[to[i]]] = from[i];
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