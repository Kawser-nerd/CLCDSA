package gcj.gcj2017.round1;

import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;

public class B {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        PrintWriter out = new PrintWriter(System.out);

        int t = in.nextInt();
        for (int cs = 1 ; cs <= t ; cs++) {
            int n = in.nextInt();
            int p = in.nextInt();
            int[] r = new int[n];
            for (int i = 0; i < n ; i++) {
                r[i] = in.nextInt();
            }
            int[][] ingredients = new int[n][p];
            for (int i = 0; i < n ; i++) {
                for (int j = 0; j < p ; j++) {
                    ingredients[i][j] = in.nextInt();
                }
            }
            out.println(String.format("Case #%d: %d", cs, solve(r, ingredients)));
        }
        out.flush();
    }

    static int[][][] range = new int[51][51][2];

    private static int solve(int[] kit, int[][] ingredients) {
        int n = kit.length;
        int p = ingredients[0].length;

        int source = n*p;
        int sink = source+1;

        MaxFlowDinic dinic = new MaxFlowDinic();
        dinic.init(sink+1);

        for (int i = 0; i < n ; i++) {
            for (int j = 0; j < p; j++) {
                range[i][j] = byRange(kit[i], ingredients[i][j]);
            }
        }

        for (int j = 0; j < p ; j++) {
            if (range[0][j][1]-range[0][j][0] >= 1) {
                dinic.edge(source, j, 1);
            }
            if (range[n-1][j][1]-range[n-1][j][0] >= 1) {
                dinic.edge((n - 1) * p + j, sink, 1);
            }
        }

        for (int i = 0; i+1 < n ; i++) {
            for (int j = 0; j < p ; j++) {
                for (int k = 0; k < p ; k++) {
                    int[] fromRange = range[i][j];
                    int[] toRange = range[i+1][k];
                    if (fromRange[1] <= toRange[0] || toRange[1] <= fromRange[0]) {
                    } else {
                        dinic.edge(i*p+j, (i+1)*p+k, 1);
                    }
                }
            }
        }

        return dinic.max_flow(source, sink);
    }

    private static int[] byRange(long kit, long base) {
        int wfrom = -1;
        {
            long min = 0;
            long max = 1000000000;
            while (max - min > 1) {
                long med = (max + min) / 2;
                long more = kit * med * 11 / 10;
                if (base <= more) {
                    max = med;
                } else {
                    min = med;
                }
            }
            wfrom = (int)max;
        }


        int wto = -1;
        {
            long min = 0;
            long max = 1000000000;
            while (max - min > 1) {
                long med = (max + min) / 2;
                long less = kit * med * 9 / 10;
                if (kit * med % 10 != 0) {
                    less++;
                }
                if (base < less) {
                    max = med;
                } else {
                    min = med;
                }
            }
            wto = (int)max;
        }
        return new int[]{wfrom, wto};
    }

    public static class MaxFlowDinic {
        public List<int[]>[] graph;
        public int[] deg;

        public int[] level;
        public int[] itr;

        public int[] que;

        @SuppressWarnings("unchecked")
        public void init(int size) {
            graph = new List[size];
            for (int i = 0; i < size ; i++) {
                graph[i] = new ArrayList<int[]>();
            }
            deg = new int[size];
            level = new int[size];
            itr = new int[size];
            que = new int[size+10];
        }
        public void edge(int from, int to, int cap) {
            int fdeg = deg[from];
            int tdeg = deg[to];
            graph[from].add(new int[]{to, cap, tdeg});
            graph[to].add(new int[]{from, 0, fdeg});
            deg[from]++;
            deg[to]++;
        }

        public int dfs(int v, int t, int f) {
            if (v == t) return f;
            for (int i = itr[v] ; i < graph[v].size() ; i++) {
                itr[v] = i;
                int[] e = graph[v].get(i);
                if (e[1] > 0 && level[v] < level[e[0]]) {
                    int d = dfs(e[0], t, Math.min(f, e[1]));
                    if (d > 0) {
                        e[1] -= d;
                        graph[e[0]].get(e[2])[1] += d;
                        return d;
                    }
                }
            }
            return 0;
        }

        public void bfs(int s) {
            Arrays.fill(level, -1);
            int qh = 0;
            int qt = 0;
            level[s] = 0;
            que[qh++] = s;
            while (qt < qh) {
                int v = que[qt++];
                for (int i = 0; i < graph[v].size() ; i++) {
                    int[] e = graph[v].get(i);
                    if (e[1] > 0 && level[e[0]] < 0) {
                        level[e[0]] = level[v] + 1;
                        que[qh++] = e[0];
                    }
                }
            }
        }

        public int max_flow(int s, int t) {
            int flow = 0;
            while (true) {
                bfs(s);
                if (level[t] < 0) {
                    return flow;
                }
                Arrays.fill(itr, 0);
                while (true) {
                    int f = dfs(s, t, Integer.MAX_VALUE);
                    if (f <= 0) {
                        break;
                    }
                    flow += f;
                }
            }
        }
    }

    static void debug(Object... o) {
        System.err.println(Arrays.deepToString(o));
    }
}



