import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.HashSet;
import java.util.Set;
import java.util.StringTokenizer;

public class Main {

    static int N;
    static String S1, S2;

    public static void main(String[] args) {
        FastScanner fc = new FastScanner(System.in);
        N = fc.nextInt();
        S1 = fc.next();
        S2 = fc.next();
        System.out.println(solve());
    }

    static long solve() {
        UnionFind uf = new UnionFind(26+10);

        for (int i = 0; i < N; i++) {
            char c1 = S1.charAt(i);
            char c2 = S2.charAt(i);
            uf.unite(toIndex(c1), toIndex(c2));
        }

        // ????????????????????????root?????
        char[] S = S1.toCharArray();
        Set<Character> group = new HashSet<>();
        loop: for (int i = 0; i < N; i++) {
            char c = S[i];

            if( Character.isDigit(c) ) continue;

            int idx = toIndex(c);
            for (int d = 0; d < 10; d++) {
                if( uf.isSame(d, idx) ) {
                    S[i] = (char)(d + '0');
                    continue loop;
                }
            }

            S[i] = (char)(uf.root(idx) + 'A' - 10);
            group.add(S[i]);
        }

        // ???????????????????
        // ??????0??????????
        if( group.isEmpty() ) {
            return 1;

        } else if( Character.isDigit(S[0]) ) {
            return (long)Math.pow(10, group.size());

        } else {
            return 9 * (long)Math.pow(10, group.size()-1);
        }
    }

    static int toIndex(char c) {
        if( Character.isAlphabetic(c) ) {
            // 0-9?????
            return c - 'A' + 10;
        } else {
            return c - '0';
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