import java.util.Scanner;

public class Main {
    static int N, M, R;
    static int INF = 1<<29;
    static int[][] d = new int[201][201];
    static int[] r = new int[9];
    static int res;
    static boolean used[] = new boolean[9];

    public static void main(String[] args) {
        final Scanner sc = new Scanner(System.in);
        int A,B,C;
        N = sc.nextInt();
        M = sc.nextInt();
        R = sc.nextInt();
        for(int i = 1; i <= N; i++) {
            for(int j = 1; j <= N; j++) {
                if(i != j) d[i][j] = INF;
            }
        }
        for(int i = 1; i <= R; i++) {
            r[i] = sc.nextInt();
        }
        for(int i = 1; i <= M; i++) {
            A = sc.nextInt();
            B = sc.nextInt();
            C = sc.nextInt();
            if(d[A][B] > C) d[A][B] = d[B][A] = C;
        }
        //?????????
        for(int k = 1; k <= N; k++) {
            for(int i = 1; i <= N; i++) {
                for(int j = 1; j <= N; j++) {
                    if(d[i][j] > d[i][k] + d[k][j]) {
                        d[i][j] = d[i][k]+d[k][j];
                    }
                }
            }
        }
        res = INF;
        dfs(1, -1, 0);
        System.out.println(res);
    }
    public static void dfs(int c, int las, int dist) {
        if(c==R+1) {
            if(res > dist) res = dist;
            return;
        }
        for(int i = 1; i <= R; i++) {
            if(!used[i]) {
                used[i] = true;
                if(las==-1) dfs(c+1, i, 0);
                else dfs(c+1, i, dist+d[r[las]][r[i]]);
                used[i] = false;
            }
        }
    }
}