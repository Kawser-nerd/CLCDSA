import java.util.*;
import static java.lang.Math.*;

public class C {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int T = in.nextInt();
        for (int zz = 1; zz <= T; zz++) {
            int N = in.nextInt();
            HashMap<String, Integer> F = new HashMap<String, Integer>();
            HashMap<String, Integer> S = new HashMap<String, Integer>();
            int[] e1 = new int[N];
            int[] e2 = new int[N];
            for (int i = 0; i < N; i++) {
                String A = in.next();
                if (!F.containsKey(A))
                    F.put(A, F.size());
                int a = F.get(A);
                String B = in.next();
                if (!S.containsKey(B))
                    S.put(B, S.size());
                int b = S.get(B);
                e1[i] = a;
                e2[i] = b;
            }
            int[][] graph = new int[2*N+2][2*N+2];
            int start = graph.length-2;
            int end = graph.length-1;
            for (int i = 0; i < N; i++) {
                graph[e1[i]][e2[i] + N] = 1;
                graph[start][i] = 1;
                graph[i+N][end] = 1;
            }

            int f = flow(graph, start, end);
            int toCover = F.size() + S.size() - 2 * f;
            int usedToCover = toCover + f;
            int ans = N - usedToCover;
            System.out.format("Case #%d: %d\n", zz, ans);
        }
    }
    static int flow(int[][] G, int st, int en) {
        int ans = 0;
        while (true) {
            boolean[] V = new boolean[G.length];
            int f = dfs(G, V, st, en);
            if (f == 0)
                break;
            ans += f;
        }
        return ans;
    }
    static int dfs(int[][] G, boolean[] V, int at, int en) {
        if (at == en)
            return 1;
        if (V[at])
            return 0;
        V[at] = true;
        for (int i = 0; i < G.length; i++) {
            if (G[at][i] == 0)
                continue;
            int f = dfs(G, V, i, en);
            if (f == 1) {
                G[at][i]--;
                G[i][at]++;
                return 1;
            }
        }
        return 0;
    }
}
