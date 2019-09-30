import java.util.*;
public class Main {
    static int INF = 1000000000;
    static int res = INF;
    static int rLen;
    static boolean[] used = new boolean[9];
    static int[] r;
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        rLen = sc.nextInt();
        r = new int[rLen + 1];
        for (int i = 1; i <= rLen; i++) {
            r[i] = sc.nextInt();
        }

        int[][] d = new int[n + 1][n + 1];
        for (int x[] : d) {
            Arrays.fill(x, INF);
        }

        for (int i = 0; i < m; i++) {
            int a = sc.nextInt();
            int b = sc.nextInt();
            int c = sc.nextInt();
            d[a][b] = c;
            d[b][a] = c;
        }
        d = warshallFloyd(n, d);
        dfs(1, -1, 0, d);
        System.out.println(res);
    }
    public static void dfs(int c, int las, int dist, int[][] d) {
        // System.out.printf("c = %d,las = %d %n", c, las);
        // System.out.printf("used = %s %n", Arrays.toString(used));
        if (c == rLen + 1) {
            if (res > dist) {
                res = dist;
                return;
            }
        }
        for (int i = 1; i <= rLen; i++) {
            if (!used[i]) {
                used[i] = true;
                if (las == -1) {
                    dfs(c + 1, i, 0, d);
                } else {
                    dfs(c + 1, i, dist + d[r[las]][r[i]], d);
                }
                used[i] = false;
            }
        }
    }
    public static int[][] warshallFloyd(int n, int[][] d) {
        for (int k = 1; k <= n; k++) {
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= n; j++) {
                    if (d[i][j] > d[i][k] + d[k][j]) {
                        d[i][j] = d[i][k] + d[k][j];
                    }
                }
            }
        }
        return d;
    }
}