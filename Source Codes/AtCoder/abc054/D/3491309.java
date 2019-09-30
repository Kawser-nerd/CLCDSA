import java.util.*;

class Main {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int ma = sc.nextInt();
        int mb = sc.nextInt();

        int a[] = new int[n];
        int b[] = new int[n];
        int c[] = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = sc.nextInt();
            b[i] = sc.nextInt();
            c[i] = sc.nextInt();
        }
        int inf = 100000000;
        int dp[][][] = new int[n+1][n*10+1][n*10+1];
        for (int i = 0; i < n+1; i++){
            for (int j = 0; j<n*10+1;j++){
                for (int k=0;k<n*10+1;k++){
                    dp[i][j][k] = inf;
                }
            }
        }
        dp[0][0][0]=0;
        //DP
        for (int i=1;i<n+1;i++){
            for (int j=0;j<n*10+1;j++){
                for (int k=0;k<n*10+1;k++){
                    int x = j-a[i-1];
                    int y = k-b[i-1];
                    if (x>=0 && y>=0) {
                        dp[i][j][k] = Math.min(dp[i-1][j][k],dp[i-1][x][y]+c[i-1]);
                    } else {
                        dp[i][j][k] = dp[i-1][j][k];
                    }
                }
            }
        }
        int candA = ma;
        int candB = mb;
        int answer = inf;
        while (candA <=n*10 && candB <=n*10) {
            answer = Math.min(answer,dp[n][candA][candB]);
            candA += ma;
            candB += mb;
        }
        if (answer == inf){
            System.out.println(-1);
        } else {
            System.out.println(answer);
        }
    }
}