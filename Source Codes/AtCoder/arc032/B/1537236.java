import java.util.Scanner;

public class Main {
    static Scanner sc = new Scanner(System.in);
    public static void main(String[] args) {
        int N = sc.nextInt();
        int M = sc.nextInt();
        UnionFind uf = new UnionFind(N);
        uf.init(N);
        for (int i = 0; i < M; i++) {
            int a = sc.nextInt() - 1;
            int b = sc.nextInt() - 1;
            uf.unite(a, b);
        }
        for (int i = 0; i < N; i++) {
            uf.find(i);
        }

        boolean[] used = new boolean[N];
        int ans = -1;
        for (int i = 0; i < N; i++) {
            if (!used[uf.parent[i]]) {
                used[uf.parent[i]] = true;
                ans++;
            }
        }

        System.out.println(ans);
    }
}

class UnionFind {
    public int[] parent;
    public int[] rank;

    public UnionFind(int MAX_SIZE) {
        parent = new int[MAX_SIZE];
        rank = new int[MAX_SIZE];
    }

    public void init(int n) {
        for (int i = 0; i < n; i++) {
            parent[i] = i;
            rank[i] = 0;
        }
    }

    public int find(int x) {
        if (parent[x] == x) {
            return x;
        }
        else {
            return parent[x] = find(parent[x]);
        }
    }

    public void unite(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) return;

        if (rank[x] < rank[y])
            parent[x] = y;
        else
            parent[y] = x;
        if (rank[x] == rank[y]) rank[x]++;
    }

    public boolean same(int x, int y) {
        return find(x) == find(y);
    }
}