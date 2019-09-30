import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {

    static int N;
    static int[] A;
    static int[] B;

    public static void main(String[] args) {
        FastScanner fc = new FastScanner(System.in);
        N = fc.nextInt();
        A = new int[N-1];
        B = new int[N-1];
        for (int i = 0; i < N-1; i++) {
            A[i] = fc.nextInt() - 1;
            B[i] = fc.nextInt() - 1;
        }
        System.out.println(solve());
    }

    static String solve() {
        int[][] G = adjB(N, A, B);
        Result dia = diameter(N, G);
        return (dia.a+1) + " " + (dia.b+1);
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

    static Result diameter(int N, int[][] G) {
        Result u = maxDistance(0, N, G);
        return maxDistance(u.b, N, G);
    }

    static Result maxDistance(int a, int N, int[][] G) {
        ArrayDeque<State> q = new ArrayDeque<>();
        int[] dist = new int[N];
        Arrays.fill(dist, -1);
        dist[a] = 0;
        q.add(new State(a, 0));
        while(!q.isEmpty()) {
            State s = q.poll();
            if( dist[s.a] != s.d ) continue;

            for (int b : G[s.a]) {
                if( dist[b] == -1 ) {
                    q.add( new State(b, s.d+1) );
                    dist[b] = s.d + 1;
                }
            }
        }

        int v = -1;
        int maxd = -1;
        for (int i = 0; i < N; i++) {
            if( dist[i] > maxd ) {
                v = i;
                maxd = dist[i];
            }
        }
        return new Result(a, v, maxd);
    }

    static class State {
        int a;
        int d;

        public State(int a, int d) {
            this.a = a;
            this.d = d;
        }
    }

    static class Result {
        int a;
        int b;
        int d;

        public Result(int a, int b, int d) {
            this.a = a;
            this.b = b;
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
}