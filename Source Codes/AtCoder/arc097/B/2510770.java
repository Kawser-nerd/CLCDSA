import java.util.Scanner;
import java.util.StringJoiner;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int N = sc.nextInt();
        int M = sc.nextInt();
        int[] ps = new int[N];
        for (int i = 0; i < N; i++) {
            ps[i] = sc.nextInt();
        }
        Path[] paths = new Path[M];
        for (int i = 0; i < M; i++) {
            paths[i] = new Path(sc.nextInt(), sc.nextInt());
        }

        System.out.println( solve(N, M, ps, paths) );
    }

    private static int solve(int N, int M, int[] ps, Path[] paths) {
        UnionFind uf = new UnionFind(N);
        for (Path path : paths) {
            uf.unite(path.x, path.y);
        }

        int result = 0;
        for (int i = 1; i <= N; i++) {
            int p = ps[i - 1];

            if( i == p || uf.isSame(i, p) ) {
                result++;
            }
        }
        return result;
    }

    // Union-Find
    // 1-origin
    private static class UnionFind {
        private final int[] par;

        public UnionFind(int size) {
            par = new int[size + 1];
            for (int i = 1; i <= size; i++) {
                par[i] = i;
            }
        }

        public int root(int n) {
            if( par[n] == n ) {
                return n;
            } else {
                par[n] = root(par[n]);
                return par[n];
            }
        }

        public void unite(int x, int y) {
            int rx = root(x);
            int ry = root(y);
            if( rx == ry ) return;

            par[rx] = ry;
        }

        public boolean isSame(int x, int y) {
            return root(x) == root(y);
        }
    }

    private static void show(int[] array) {
        StringJoiner j = new StringJoiner(" ");
        for (int i : array) {
            j.add("" + i);
        }
        System.err.println(j.toString());
    }

    static class Path {
        final int x;
        final int y;

        public Path(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }
}