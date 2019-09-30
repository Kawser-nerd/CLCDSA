import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.PriorityQueue;
import java.util.StringTokenizer;
import java.util.function.Predicate;

public class Main {

    static int N, M, R, T;
    static Edge[] E;

    public static void main(String[] args) {
        FastScanner sc = new FastScanner(System.in);
        N = sc.nextInt();
        M = sc.nextInt();
        R = sc.nextInt();
        T = sc.nextInt();
        E = new Edge[M];
        for (int i = 0; i < M; i++) {
            E[i] = new Edge(sc.nextInt()-1, sc.nextInt()-1, sc.nextInt());
        }

        System.out.println(solve());
    }

    static long solve() {
        Edge[][] G = adjB(N, E);
        State[] dist = new State[N];
        PriorityQueue<State> q = new PriorityQueue<>();

        long ans = 0;
        for (int i = 0; i < N; i++) {
            ans += count(i, G, dist, q);
        }
        return ans;
    }

    static long count(int goal, Edge[][] G, State[] dist, PriorityQueue<State> q) {
        Arrays.fill(dist, null);

        State start = new State(goal, 0);
        q.add( start );
        dist[goal] = start;

        while(!q.isEmpty()) {
            State s = q.poll();
            if( dist[s.a].d != s.d ) continue;

            for (Edge e : G[s.a]) {
                State next = new State(e.opposite(s.a), s.d + e.c);
                if( dist[next.a] == null || dist[next.a].d > next.d ) {
                    dist[next.a] = next;
                    q.add( next );
                }
            }
        }

        // td/T < rd/R ?????????
        Arrays.sort(dist);
        int cnt = 0;
        if( R >= T ) {
            for (int ti = 1; ti < N; ti++) {
                int td = dist[ti].d;

                // td/T < rd/R => td*R < rd*T
                int rLoseMin = findMinimum(dist, ti+1, N, r -> td * R < r.d * T );
                cnt += N - rLoseMin;
            }

        } else {
            for (int ri = 1; ri < N; ri++) {
                int rd = dist[ri].d;
                // ???????????????
                int tWinMax = findMaximum(dist, ri+1, N, t -> t.d * R < rd * T );
                int tLose = N - tWinMax - 1;
                int tWin = N - 2 - tLose;
                cnt += tWin;
            }
        }
        return cnt;
    }

    static <A> int findMaximum(A[] array, int lo, int hi, Predicate<A> p) {
        while( lo < hi ) {
            int mid = ((hi - lo) >>> 1) + lo;
            if( p.test(array[mid]) ) {
                lo = mid + 1;
            } else {
                hi = mid;
            }
        }
        return lo - 1;
    }

    static <A> int findMinimum(A[] array, int lo, int hi, Predicate<A> p) {
        while( lo < hi ) {
            int mid = ((hi - lo) >>> 1) + lo;
            if( p.test(array[mid]) ) {
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }
        return lo;
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

    static class State implements Comparable<State> {
        int a, d;

        public State(int a, int d) {
            this.a = a;
            this.d = d;
        }

        @Override
        public int compareTo(State o) {
            return Integer.compare(d, o.d);
        }
    }

    static class Edge {
        int a, b, c;

        public Edge(int a, int b, int c) {
            this.a = a;
            this.b = b;
            this.c = c;
        }

        public int opposite(int n) {
            return n == a ? b : a;
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