import java.util.Scanner;

public class Main {
    static int a[];
    static int b[];
    static boolean move[][];
    static boolean vis[];
    static int m;
    static int n;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        m = sc.nextInt();
        a = new int[m];
        b = new int[m];
        move = new boolean[n + 1][n + 1];
        vis = new boolean[n + 1];
        for (int i = 0; i < n + 1; i++) {
            for (int j = 0; j < n + 1; j++) {
                move[i][j] = false;
            }
        }
        for (int i = 0; i < m; i++) {
            a[i] = sc.nextInt();
            b[i] = sc.nextInt();
            move[a[i]][b[i]] = true;
            move[b[i]][a[i]] = true;
        }
        // ???????????
        int ans = 0;
        boolean conected = true;
        for (int i = 0; i < m; i++) {
            move[a[i]][b[i]] = false;
            move[b[i]][a[i]] = false;
            // ?????
            for (int j = 0; j < n + 1; j++) {
                vis[j] = false;
            }
            conected = true;
            dfs(1);
            vis[0] = true;
            for (int j = 0; j < n + 1; j++) {
                if (!vis[j]) {
                    conected = false;
                }
            }
            if (!conected) {
                ans++;
            }
            move[a[i]][b[i]] = true;
            move[b[i]][a[i]] = true;

        }
        System.out.println(ans);

    }

    static void dfs(int x) {
        if (vis[x])
            return;
        vis[x] = true;
        for (int i = 1; i < n + 1; i++) {
            if (move[x][i]) {
                dfs(i);
            }
        }
    }
}