import java.util.Scanner;
import java.util.*;
public class Main {
    static int INF = 1000000000;
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        int[][] cost = new int[n][n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cost[i][j] = INF;
            }
        }

        int[] a = new int[m];
        int[] b = new int[m];
        int[] c = new int[m];
        for (int i = 0; i < m; i++) {
            a[i] = sc.nextInt() - 1;
            b[i] = sc.nextInt() - 1;
            c[i] = sc.nextInt();
            cost[a[i]][b[i]] = c[i];
            cost[b[i]][a[i]] = c[i];
        }

        int[][] dist = new int[n][n];
        for (int i = 0; i < n; i++) {
            int[] d = dijkstra(i, n, cost);
            for (int j = 0; j < n; j++) {
                dist[i][j] = d[j];
            }
        }
        int ans = solve(n, m, dist, a, b, c);
        System.out.println(ans);
    }
    public static int solve(int n, int m, int[][] dist, int[] a, int b[], int c[]) {
        int ans = m;
        for (int i = 0; i < m; i++) {
            boolean ok = false;
            for (int j = 0; j < n; j++) {
                if (dist[j][a[i]] + c[i] == dist[j][b[i]]) {
                    ok = true;
                }
            }
            if (ok) {
                ans--;
            }
        }
        return ans;
    }
    public static int[] dijkstra(int from, int n, int[][] cost) {
        int[] d = new int[n];
        d[from] = 0;
        for (int i = 0; i < n; i++) {
            if (i == from) {
                continue;
            }
            d[i] = INF;
        }

        boolean[] visited = new boolean[n];
        while (true) {
            int v = -1;
            for (int u = 0; u < n; u++) {
                if (!visited[u] && (v == -1 || d[u] < d[v])) {
                    v = u;
                }
            }
            if (v == -1) {
                break;
            }
            visited[v] = true;

            for (int u = 0; u < n; u++) {
                d[u] = Math.min(d[u], d[v] + cost[v][u]);
            }
        }
        return d;
    }
}