import java.io.*;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.StringTokenizer;

public class Main {

    static int N;
    static int M;
    static int D;
    static int[] A;
    final static int MOD = 1_000_000_007;

    public static void main(String[] args) {
        FastScanner sc = new FastScanner(System.in);
        N = sc.nextInt();
        M = sc.nextInt();
        D = sc.nextInt();
        A = sc.nextIntArray(M);

        PrintWriter pw = new PrintWriter(System.out);
        for (int each : solve()) {
            pw.println(each);
        }
        pw.flush();
    }

    static int[] solve() {
        int[] B = new int[N];
        for (int i = 0; i < N; i++) {
            B[i] = i;
        }
        for (int a : A) {
            int t = B[a];
            B[a] = B[a-1];
            B[a-1] = t;
        }

        int[] REV = new int[N];
        for (int i = 0; i < N; i++) {
            int b = B[i];
            REV[b] = i;
        }

        int[] ANS = new int[N];
        Arrays.fill(ANS, -1);
        for (int i = 0; i < N; i++) {
            if( ANS[i] != -1 ) continue;

            List<Integer> group = new ArrayList<>();
            group.add(i);

            int cur = i;
            while(true) {
                cur = REV[cur];
                if( cur == i ) {
                    break;
                } else {
                    group.add(cur);
                }
            }

            // group?????????
            int r = D % group.size();
            for (int j = 0; j < group.size(); j++) {
                int x = group.get(j);
                int y = (j + r) % group.size();
                ANS[x] = group.get(y) + 1;
            }
        }
        return ANS;
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