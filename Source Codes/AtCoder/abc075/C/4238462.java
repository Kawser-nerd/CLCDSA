import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        boolean[][] g = new boolean[n][n];
        int [] a = new int[m];
        int [] b = new int[m];
        for (int i = 0 ; i < m ; i++) {
            a[i] = sc.nextInt() - 1;
            b[i] = sc.nextInt() - 1;
            g[a[i]][b[i]] = true;
            g[b[i]][a[i]] = true;
        }

        int answer = 0;
        for (int i = 0 ; i < m ; i++) {
            g[a[i]][b[i]] = false;
            g[b[i]][a[i]] = false;
            boolean[] v = new boolean[n];
            dfs(0, n, g, v);
            boolean bridge = false;

            for (int j = 0; j < n ; j++) {
                if (!v[j]) {
                    bridge = true;
                    break;
                }
            }
            if (bridge) {
                answer++;
            }
            g[a[i]][b[i]] = true;
            g[b[i]][a[i]] = true;
        }
        System.out.println(answer);

    }

    private static void dfs (int i, int n, boolean[][] g, boolean[] v) {
        v[i] = true;
        for (int j = 0 ; j < n ; j++) {
            if (!g[i][j]) {
                continue;
            }
            if (v[j]) {
                continue;
            }
            dfs(j,n,g,v);
        }
        return;
    }

}