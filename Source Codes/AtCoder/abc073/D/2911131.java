import java.util.*;

class Main{
    static int[] r;
    static long[][] map;
    static long ans = Long.MAX_VALUE;
    static boolean[] visited;
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int M = sc.nextInt();
        int R = sc.nextInt();
        r = new int[R+1];
        for(int i=1;i<=R;i++) r[i] = sc.nextInt();
        int[] A = new int[M+1];
        int[] B = new int[M+1];
        int[] C = new int[M+1];
        for(int i=1;i<=M;i++){
            A[i] = sc.nextInt();
            B[i] = sc.nextInt();
            C[i] = sc.nextInt();
        }
        long[][] g = new long[N+1][N+1];
        for(int row=1;row<=N; row++){
            for(int col=1; col<=N; col++) {
                if(row==col) g[row][col]=0;
                else g[row][col] = Long.MAX_VALUE/64;
            }
        }
        for(int i=1;i<=M;i++){
            int a = A[i];
            int b = B[i];
            g[a][b] = (long) C[i];
            g[b][a] = (long) C[i];
        }
        for(int i=1;i<=N;i++){
            for(int j=1;j<=N;j++){
                for(int k=1;k<=N;k++){
                    if(g[j][k]>g[j][i]+g[i][k]) {
                        g[j][k]=g[j][i]+g[i][k];
                        g[k][j]=g[j][i]+g[i][k];
                    }
                    //g[j][k] = Math.min(g[j][k], g[j][i]+g[i][k]);
                }
            }
        }
        map = new long[R+1][R+1];
        for(int row=1; row<=R; row++){
            for(int col=1; col<=R; col++){
                map[row][col] = g[r[row]][r[col]];
            }
        }
        visited = new boolean[R+1];
        for(int i=1;i<=R;i++){
            visited[i] = true;
            dfs(i,0);
            visited[i] = false;
        }
        System.out.println(ans);
    }
    private static void dfs(int start, long sum){
        boolean flag = true;
        for(int i=1;i<visited.length;i++) flag = flag&visited[i];
        if(flag) {
            ans = Math.min(sum,ans);
            return;
        }
        for(int i=1;i<r.length;i++){
            if(!visited[i]){
                visited[i] = true;
                dfs(i,map[i][start]+sum);
                visited[i] = false;
            }
        }
    }
}