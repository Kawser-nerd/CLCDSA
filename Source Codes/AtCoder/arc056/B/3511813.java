import java.io.*;
import java.util.*;

public class Main {

    static int N, M, S;
    static int[] U, V;

    public static void main(String[] args) {
        FastScanner sc = new FastScanner(System.in);
        N = sc.nextInt();
        M = sc.nextInt();
        S = sc.nextInt() - 1;

        U = new int[M];
        V = new int[M];
        for (int i = 0; i < M; i++) {
            U[i] = sc.nextInt() - 1;
            V[i] = sc.nextInt() - 1;
        }

        PrintWriter pw = new PrintWriter(System.out);
        for (Integer i : solve()) {
            pw.println(i);
        }
        pw.flush();
    }

    static List<Integer> solve() {
        int[][] G = adjB(N, U, V);

        PriorityQueue<State> q = new PriorityQueue<>();
        int[] neck = new int[N];
        Arrays.fill(neck, -1);
        neck[S] = S;
        q.add( new State(S, S) );

        while(!q.isEmpty()) {
            State s = q.poll();

            for (int next : G[s.a]) {
                if( neck[next] == -1 ) {
                    neck[next] = s.neck;
                    q.add( new State(next, Math.min(s.neck, next)) );
                }
            }
        }

        List<Integer> ans = new ArrayList<>();
        for (int i = 0; i < N; i++) {
            if( neck[i] >= i ) {
                ans.add(i+1);
            }
        }
        return ans;
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

    static class State implements Comparable<State> {
        int a;
        int neck;

        public State(int a, int neck) {
            this.a = a;
            this.neck = neck;
        }

        @Override
        public int compareTo(State o) {
            return Integer.compare(o.neck, neck);
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