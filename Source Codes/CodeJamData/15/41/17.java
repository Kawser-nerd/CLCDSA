package gcj2015.round2;

import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class A {

    static int[] dx = new int[256];
    static int[] dy = new int[256];

    public static void main(String[] args) {
        dx['<'] = -1;
        dx['>'] = 1;
        dy['^'] = -1;
        dy['v'] = 1;

        Scanner in = new Scanner(System.in);
        PrintWriter out = new PrintWriter(System.out);

        int t = in.nextInt();
        for (int cs = 1 ; cs <= t ; cs++) {
            int r = in.nextInt();
            int c = in.nextInt();
            char[][] map = new char[r][c];
            for (int i = 0; i < r ; i++) {
                map[i] = in.next().toCharArray();
            }
            String ret = solve(map);
            out.println(String.format("Case #%d: %s", cs, ret));
        }

        out.flush();
    }

    private static String solve(char[][] map) {
        int n = map.length;
        int m = map[0].length;

        int[] graph = new int[n*m];
        Arrays.fill(graph, -1);

        int[] indeg = new int[n*m];

        int[] row = new int[n];
        int[] col = new int[m];

        boolean[] death = new boolean[n*m];
        UnionFind uf = new UnionFind(n*m);

        for (int i = 0; i < n ; i++) {
            for (int j = 0; j < m ; j++) {
                int id = i*m+j;
                if (map[i][j] != '.') {
                    row[i]++;
                    col[j]++;

                    int di = dy[map[i][j]];
                    int dj = dx[map[i][j]];
                    int ni = i;
                    int nj = j;
                    while (true) {
                        ni += di;
                        nj += dj;
                        if (ni < 0 || nj < 0 || ni >= n || nj >= m) {
                            death[id] = true;
                            break;
                        }
                        if (map[ni][nj] != '.') {
                            int tid = ni*m+nj;
                            graph[id] = tid;
                            indeg[tid]++;
                            uf.unite(id, tid);
                            break;
                        }
                    }
                }
            }
        }


        boolean[] done = new boolean[n*m];
        int need = 0;
        for (int i = 0; i < n ; i++) {
            for (int j = 0; j < m; j++) {
                int id = i*m+j;
                if (map[i][j] == '.') {
                    continue;
                }
                if (indeg[id] == 0) {
                    if (death[id]) {
                        if (row[i] == 1 && col[j] == 1) {
                            return "IMPOSSIBLE";
                        } else {
                            need++;
                        }
                        continue;
                    }
                    while (!done[id]) {
                        done[id] = true;
                        id = graph[id];
                        if (id == -1) {
                            need++;
                            break;
                        }
                    }

                }
            }
        }
        return String.format("%d", need);
    }

    static class UnionFind {
        int[] parent, rank;
        UnionFind(int n) {
            parent = new int[n];
            rank = new int[n];
            for (int i = 0 ; i < n ; i++) {
                parent[i] = i;
                rank[i] = 0;
            }
        }

        int find(int x) {
            if (parent[x] == x) {
                return x;
            }
            parent[x] = find(parent[x]);
            return parent[x];
        }

        void unite(int x, int y) {
            x = find(x);
            y = find(y);
            if (x == y) {
                return;
            }
            if (rank[x] < rank[y]) {
                parent[x] = y;
            } else {
                parent[y] = x;
                if (rank[x] == rank[y]) {
                    rank[x]++;
                }
            }
        }
        boolean issame(int x, int y) {
            return (find(x) == find(y));
        }
    }

    static void debug(Object... o) {
        System.err.println(Arrays.deepToString(o));
    }
}



