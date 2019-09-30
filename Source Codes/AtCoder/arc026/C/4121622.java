import java.io.*;
import java.util.*;

public class Main {

    static int N, L;
    static Edge[] E;

    public static void main(String[] args) {
        FastScanner sc = new FastScanner(System.in);
        N = sc.nextInt();
        L = sc.nextInt();
        E = new Edge[N];
        for (int i = 0; i < N; i++) {
            E[i] = new Edge(sc.nextInt(), sc.nextInt(), sc.nextInt());
        }

        System.out.println(solve());
    }

    static long solve() {
        List<Edge> F = new ArrayList<>();
        Collections.addAll(F, E);
        for (int i = 1; i <= L; i++) {
            F.add( new Edge(i, i-1, 0) );
        }

        List<Edge>[] G = adjListD(L+1, F);
        PriorityQueue<State> q = new PriorityQueue<>();
        long[] dist = new long[L+1];
        Arrays.fill(dist, Long.MAX_VALUE/2);
        dist[0] = 0;
        q.add( new State(0, 0) );
        while(!q.isEmpty()) {
            State s = q.poll();
            if( dist[s.a] != s.d ) continue;

            for (Edge e : G[s.a]) {
                int next = e.a == s.a ? e.b : e.a;
                long nextDist = dist[s.a] + e.c;
                if( dist[next] > nextDist) {
                    dist[next] = nextDist;
                    q.add( new State(next, nextDist) );
                }
            }
        }
        return dist[L];
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

    static List<Edge>[] adjListD(int n, List<Edge> es) {
        List<Edge>[] adj = new List[n];
        for (int i = 0; i < n; i++) {
            adj[i] = new ArrayList<>();
        }
        for (Edge e : es) {
            adj[e.a].add( e );
        }
        return adj;
    }

    static class Edge {
        int a, b, c;

        public Edge(int a, int b, int c) {
            this.a = a;
            this.b = b;
            this.c = c;
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
            for (int i = 0; i < n; i++) a[i] = nextInt();
            return a;
        }

        int[] nextIntArray(int n, int delta) {
            int[] a = new int[n];
            for (int i = 0; i < n; i++) a[i] = nextInt() + delta;
            return a;
        }

        long[] nextLongArray(int n) {
            long[] a = new long[n];
            for (int i = 0; i < n; i++) a[i] = nextLong();
            return a;
        }
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

    static void writeSingleLine(int[] as) {
        PrintWriter pw = new PrintWriter(System.out);
        for (int i = 0; i < as.length; i++) {
            if (i != 0) pw.print(" ");
            pw.print(as[i]);
        }
        pw.println();
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
            if (arg == null) j.add("null");
            else if (arg instanceof int[]) j.add(Arrays.toString((int[]) arg));
            else if (arg instanceof long[]) j.add(Arrays.toString((long[]) arg));
            else if (arg instanceof double[]) j.add(Arrays.toString((double[]) arg));
            else if (arg instanceof Object[]) j.add(Arrays.toString((Object[]) arg));
            else j.add(arg.toString());
        }
        System.err.println(j.toString());
    }

    static void printSingleLine(int[] array) {
        PrintWriter pw = new PrintWriter(System.out);
        for (int i = 0; i < array.length; i++) {
            if (i != 0) pw.print(" ");
            pw.print(array[i]);
        }
        pw.println();
        pw.flush();
    }

    static int lowerBound(int[] array, int value) {
        int lo = 0, hi = array.length, mid;
        while (lo < hi) {
            mid = (hi + lo) / 2;
            if (array[mid] < value) lo = mid + 1;
            else hi = mid;
        }
        return lo;
    }

    static int upperBound(int[] array, int value) {
        int lo = 0, hi = array.length, mid;
        while (lo < hi) {
            mid = (hi + lo) / 2;
            if (array[mid] <= value) lo = mid + 1;
            else hi = mid;
        }
        return lo;
    }
} Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.