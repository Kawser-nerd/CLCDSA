import java.io.*;
import java.util.Arrays;
import java.util.Comparator;
import java.util.StringTokenizer;

public class Main {

    static int N;
    static int M;
    static Route[] R;
    static int Q;
    static Citizen[] C;

    public static void main(String[] args) {
        FastScanner sc = new FastScanner(System.in);
        N = sc.nextInt();
        M = sc.nextInt();
        R = new Route[M];
        for (int i = 0; i < M; i++) {
            R[i] = new Route(sc.nextInt(), sc.nextInt(), sc.nextInt());
        }
        Q = sc.nextInt();
        C = new Citizen[Q];
        for (int i = 0; i < Q; i++) {
            C[i] = new Citizen(i, sc.nextInt(), sc.nextInt());
        }

        PrintWriter pw = new PrintWriter(System.out);
        for (int answer : solve()) {
            pw.println(answer);
        }
        pw.flush();
    }

    static class UnionFind {

        private final int[] parent;
        private final int[] rank;
        private final int[] cnt;

        public UnionFind(int n) {
            parent = new int[n];
            rank = new int[n];
            cnt = new int[n];
            for (int i = 0; i < n; i++) {
                parent[i] = i;
                rank[i] = 0;
                cnt[i] = 1;
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

            int ci = cnt[ri];
            int cj = cnt[rj];
            cnt[ri] += cj;
            cnt[rj] += ci;
        }

        public boolean isSame(int a, int b) {
            return root(a) == root(b);
        }

        public int count(int a) {
            int root = root(a);
            return cnt[root];
        }
    }

    static class Citizen {
        int index;
        int city;
        int y;

        public Citizen(int index, int city, int y) {
            this.index = index;
            this.city = city;
            this.y = y;
        }
    }

    static class Route {
        int a;
        int b;
        int y;

        public Route(int a, int b, int y) {
            this.a = a;
            this.b = b;
            this.y = y;
        }
    }

    static int[] solve() {
        int[] ans = new int[Q];
        Arrays.sort(R, Comparator.<Route>comparingInt(r -> r.y).reversed());
        Arrays.sort(C, Comparator.<Citizen>comparingInt(c -> c.y).reversed());

        UnionFind uf = new UnionFind(N+1);

        int ri = 0;
        for (int i = 0; i < Q; i++) {
            Citizen c = C[i];

            for (; ri < M; ri++) {
                Route r = R[ri];
                if( r.y > c.y ) {
                    uf.unite( r.a, r.b );
                } else {
                    break;
                }
            }

            ans[c.index] = uf.count(c.city);
        }

        return ans;
    }

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