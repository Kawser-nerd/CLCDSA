import java.io.*;
import java.util.ArrayDeque;
import java.util.Arrays;
import java.util.StringJoiner;
import java.util.StringTokenizer;
import java.util.function.Function;

public class Main {

    static int N, M;
    static int[] A, B;
    static int Q;
    static int[] V, D, C;

    public static void main(String[] args) {
        FastScanner sc = new FastScanner(System.in);
        N = sc.nextInt();
        M = sc.nextInt();
        A = new int[M];
        B = new int[M];
        for (int i = 0; i < M; i++) {
            A[i] = sc.nextInt()-1;
            B[i] = sc.nextInt()-1;
        }
        Q = sc.nextInt();
        V = new int[Q];
        D = new int[Q];
        C = new int[Q];
        for (int i = 0; i < Q; i++) {
            V[i] = sc.nextInt()-1;
            D[i] = sc.nextInt();
            C[i] = sc.nextInt();
        }

        writeLines( solve() );
    }

    static int[] solve() {
        int[] color = new int[N];
        int[] depth = new int[N];
        Arrays.fill(depth, -1);

        int[][] G = adjB(N, A, B);

        for (int i = Q-1; i >= 0; i--) {
            calc(i, G, color, depth);
            // debug(color, depth);
        }
        return color;
    }

    static void calc(int qi, int[][] G, int[] color, int[] depth) {
        if( depth[V[qi]] >= D[qi] ) return;

        ArrayDeque<State> q = new ArrayDeque<>();
        depth[V[qi]] = D[qi];
        q.add(new State(V[qi], D[qi]));
        // ??????????
        if( color[V[qi]] == 0 ) color[V[qi]] = C[qi];

        while(!q.isEmpty()) {
            State s = q.poll();
            if( s.d == 0 ) continue;

            for (int next : G[s.a]) {
                // ??????????
                if( color[next] == 0 ) color[next] = C[qi];

                // ???????????????????
                if( depth[next] < s.d-1 ) {
                    depth[next] = s.d-1;
                    q.add( new State(next, s.d-1) );
                }
            }
        }
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

        int[] nextIntArray(int n, int delta) {
            int[] a = new int[n];
            for (int i = 0; i < n; i++)
                a[i] = nextInt() + delta;
            return a;
        }

        long[] nextLongArray(int n) {
            long[] a = new long[n];
            for (int i = 0; i < n; i++)
                a[i] = nextLong();
            return a;
        }
    }

    static <A> void writeLines(A[] as, Function<A, String> f) {
        PrintWriter pw = new PrintWriter(System.out);
        for (A a : as) {
            pw.println(f.apply(a));
        }
        pw.flush();
    }

    static void writeLines(int[] as) {
        PrintWriter pw = new PrintWriter(System.out);
        for (int a : as) pw.println(a);
        pw.flush();
    }

    static void writeLines(long[] as) {
        PrintWriter pw = new PrintWriter(System.out);
        for (long a : as) pw.println(a);
        pw.flush();
    }

    static int max(int... as) {
        int max = Integer.MIN_VALUE;
        for (int a : as) max = Math.max(a, max);
        return max;
    }

    static int min(int... as) {
        int min = Integer.MAX_VALUE;
        for (int a : as) min = Math.min(a, min);
        return min;
    }

    static void debug(Object... args) {
        StringJoiner j = new StringJoiner(" ");
        for (Object arg : args) {
            if (arg instanceof int[]) j.add(Arrays.toString((int[]) arg));
            else if (arg instanceof long[]) j.add(Arrays.toString((long[]) arg));
            else if (arg instanceof double[]) j.add(Arrays.toString((double[]) arg));
            else if (arg instanceof Object[]) j.add(Arrays.toString((Object[]) arg));
            else j.add(arg.toString());
        }
        System.err.println(j.toString());
    }
}