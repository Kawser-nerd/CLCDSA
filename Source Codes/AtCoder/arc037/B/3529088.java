import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.HashSet;
import java.util.Set;
import java.util.StringTokenizer;

public class Main {

    static int N, M;
    static int[] U, V;

    public static void main(String[] args) {
        FastScanner sc = new FastScanner(System.in);
        N = sc.nextInt();
        M = sc.nextInt();
        U = new int[M];
        V = new int[M];

        for (int i = 0; i < M; i++) {
            U[i] = sc.nextInt() - 1;
            V[i] = sc.nextInt() - 1;
        }

        System.out.println(solve());
    }

    static int solve() {
        UnionFind uf = new UnionFind(N);

        for (int i = 0; i < M; i++) {
            uf.unite(U[i], V[i]);
        }

        Candidate[] C = new Candidate[N];
        for (int i = 0; i < N; i++) {

            int root = uf.root(i);

            if( C[root] == null ) {
                C[root] = new Candidate(root);
            }
            C[root].nodes.add(i);
        }

        for (int i = 0; i < M; i++) {
            int u = U[i];
            C[uf.root(u)].edge++;
        }

        int cnt = 0;
        for (Candidate c : C) {
            if( c != null && c.isTree() ) {
                cnt++;
            }
        }
        return cnt;
    }

    static class Candidate {
        int root;
        Set<Integer> nodes = new HashSet<>();
        int edge;

        public Candidate(int root) {
            this.root = root;
            this.nodes.add(root);
        }

        boolean isTree() {
            return edge == nodes.size() - 1;
        }
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