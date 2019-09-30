import java.io.*;
import java.util.*;

public class Main {

    static int N, M, S;
    static Edge[] E;

    public static void main(String[] args) {
        FastScanner sc = new FastScanner(System.in);
        N = sc.nextInt();
        M = sc.nextInt();
        S = sc.nextInt() - 1;

        E = new Edge[M];
        for (int i = 0; i < M; i++) {
            E[i] = new Edge(sc.nextInt()-1, sc.nextInt()-1);
        }

        PrintWriter pw = new PrintWriter(System.out);
        for (Integer i : solve()) {
            pw.println(i);
        }
        pw.flush();
    }

    static List<Integer> solve() {
        Arrays.sort(E, Comparator.<Edge>comparingInt(e -> Math.min(e.u, e.v)).reversed());

        List<Integer> ans = new ArrayList<>();
        UnionFind uf = new UnionFind(N);
        int j = 0;
        for (int i = N-1; i >= 0; i--) {
            while( j < M ) {
                Edge e = E[j];
                if( Math.min(e.u, e.v) >= i ) {
                    uf.unite(e.u, e.v);
                    j++;
                } else {
                    break;
                }
            }

            if( uf.isSame(S, i) ) {
                ans.add(i+1);
            }
        }
        Collections.reverse(ans);
        return ans;
    }

    static class Edge {
        int u, v;

        public Edge(int u, int v) {
            this.u = u;
            this.v = v;
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