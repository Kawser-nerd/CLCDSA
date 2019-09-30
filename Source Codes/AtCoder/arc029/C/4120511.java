import java.io.*;
import java.util.*;

public class Main {

    static int N, M;
    static int[] C;
    static Edge[] E;

    public static void main(String[] args) {
        FastScanner sc = new FastScanner(System.in);
        N = sc.nextInt();
        M = sc.nextInt();
        C = sc.nextIntArray(N);
        E = new Edge[M];
        for (int i = 0; i < M; i++) {
            E[i] = new Edge(sc.nextInt()-1, sc.nextInt()-1, sc.nextInt());
        }

        System.out.println(solve());
    }

    static long solve() {
        int x = N;
        List<Edge> F = new ArrayList<>();
        Collections.addAll(F, E);
        for (int i = 0; i < N; i++) {
            F.add( new Edge(i, x, C[i]) );
        }
        UnionFind uf = new UnionFind(N+1);
        F.sort(Comparator.comparingInt(e -> e.r));
        long ans = 0;
        for (Edge e : F) {
            if( !uf.isSame(e.a, e.b) ) {
                uf.unite(e.a, e.b);
                ans += e.r;
            }
        }
        return ans;
    }

    static class UnionFind {

        private final int[] parent;
        private final int[] rank;

        public UnionFind(int n) {
            parent = new int[n];
            rank = new int[n];
            for (int i = 0; i < n; i++) {
                parent[i] = i;
                rank[i] = 0;
            }
        }

        public int root(int i) {
            if( parent[i] == i ) {
                return i;
            } else {
                return parent[i] = root(parent[i]);
            }
        }

        public void unite(int i, int j) {
            int ri = root(i);
            int rj = root(j);
            if( ri == rj ) return;

            if( rank[ri] < rank[rj] ) {
                parent[ri] = rj;

            } else {
                parent[rj] = ri;
                if( rank[ri] == rank[rj] ) {
                    rank[ri]++;
                }
            }
        }

        public boolean isSame(int a, int b) {
            return root(a) == root(b);
        }
    }

    static class Edge {
        int a, b, r;

        public Edge(int a, int b, int r) {
            this.a = a;
            this.b = b;
            this.r = r;
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
}