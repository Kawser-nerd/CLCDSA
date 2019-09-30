import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    static int H, W;
    static char[][] C;

    public static void main(String[] args) {
        FastScanner sc = new FastScanner(System.in);
        H = sc.nextInt();
        W = sc.nextInt();
        C = new char[H][];
        for (int i = 0; i < H; i++) {
            C[i] = sc.next().toCharArray();
        }
        System.out.println(solve());
    }

    static int AN = 12;
    static int BN = 16;
    static int CN = 11;

    static String solve() {
        UnionFind uf = new UnionFind(H*W);

        for (int h = 0; h < H; h++) {
            for (int w = 0; w < W; w++) {
                if( C[h][w] == '.' ) continue;

                if( C[h-1][w+1] == 'o' ) { //???
                    uf.unite(node(h, w), node(h-1, w+1) );
                }

                if( C[h][w+1] == 'o' ) { //??
                    uf.unite(node(h, w), node(h, w+1) );
                }

                if( C[h+1][w+1] == 'o' ) { //???
                    uf.unite(node(h, w), node(h+1, w+1) );
                }

                if( C[h+1][w] == 'o' ) { //??
                    uf.unite(node(h, w), node(h+1, w) );
                }
            }
        }

        int[] cnt = new int[H*W];
        for (int h = 0; h < H; h++) {
            for (int w = 0; w < W; w++) {
                if( C[h][w] == 'o' ) {
                    int root = uf.root(node(h, w));
                    cnt[root]++;
                }
            }
        }

        int a = 0;
        int b = 0;
        int c = 0;

        for (int n : cnt) {
            if( n == 0 ) continue;

            if (n % AN == 0 && isSquare(n/AN) ) {
                a++;

            } else if (n % CN == 0 && isSquare(n/CN)) {
                c++;
            } else {
                b++;
            }
        }

        return a + " " + b + " " + c;
    }

    static boolean isSquare(int n) {
        // ???????...
        int sqrt = (int)Math.sqrt(n);
        return n == sqrt * sqrt;
    }

    static int node(int h, int w) {
        return h*W + w;
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