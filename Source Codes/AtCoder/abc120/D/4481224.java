import java.io.*;
import java.util.Scanner;

class Pair {
    final int x;
    final int y;
    Pair(int x, int y) {
        this.x = x;
        this.y = y;
    }
}

class DisjointSet {
    private static int[] parent, size;

    DisjointSet(int n) {
        parent = new int[n + 1];
        size = new int[n + 1];
        for (int i = 0; i < n + 1; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    private int find(int u) {
        if (u == parent[u]) return u;
        return parent[u] = find(parent[u]);
    }

    public long merge(int u, int v) {
        u = find(u); v = find(v);
        if (u == v) return -1L;
        long a = (long)size[u], b = (long)size[v];
        parent[u] = v;
        size[v] += size[u];
        size[u] = 0;
        return a * (a - 1L) / 2L + b * (b - 1L) / 2L;
    }

    public int get_size(int u) {
        u = find(u);
        return size[u];
    }
}

public class Main {

    public static void main(String[] args) throws IOException {
        Scanner s = new Scanner(System.in);

        int n = s.nextInt();
        int m = s.nextInt();

        Pair edges[] = new Pair[m];
        long ans[] = new long[m];

        for (int i = 0; i < m; i++) {
            int u = s.nextInt();
            int v = s.nextInt();
            edges[i] = new Pair(u, v);
        }

        long incon = (long)n * ((long)n - 1L) / 2L;
        DisjointSet dsu = new DisjointSet(n + 1);

        for (int i = 0; i < m; i++) {
            ans[m - i - 1] = incon;
            Pair edge = edges[m - i - 1];
            long tmp = (long)dsu.merge(edge.x, edge.y);
            if (tmp == -1L) continue;
            incon += tmp;
            long size = (long)dsu.get_size(edge.x);
            incon -= size * (size - 1L) / 2L;
        }

        for (int i = 0; i < m; i++) {
            System.out.println(ans[i]);
        }

    }
}