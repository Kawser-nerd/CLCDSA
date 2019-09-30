import java.util.*;

class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        
        int[][] link = new int[n+1][n+1];
        int inf = 1000000;
        for(int i=0;i<n+1;i++){
            for(int j=0;j<n+1;j++){
                link[i][j]=inf;
            }
        }
        int[][] edges = new int[m][3];
        for(int i=0;i<m;i++){
            int a=sc.nextInt();
            int b=sc.nextInt();
            int c=sc.nextInt();
            link[a][b] = c;
            link[b][a] = c;
            edges[i][0] = a;
            edges[i][1] = b;
            edges[i][2] = c;
        }
        //Warshall–Floyd Algorithm
        int dp[][][] = new int[n+1][n+1][n+1];
        for (int i=0;i<n+1;i++){
            for(int j=0;j<n+1;j++){
                if (i!=j) {
                    dp[0][i][j] = link[i][j];
                } else {
                    dp[0][i][j] = 0;
                }
            }
        }
        for (int k=1;k<n+1;k++){
            for(int i=1;i<n+1;i++){
                for(int j=1;j<n+1;j++){
                    dp[k][i][j]=Math.min(dp[k-1][i][j],dp[k-1][i][k]+dp[k-1][k][j]);
                }
            }
        }
        int answer = m;
        for(int e=0;e<m;e++){
            int a = edges[e][0];
            int b = edges[e][1];
            int c = edges[e][2];
            boolean shortest = false;
            for(int i=1;i<n+1;i++){
                if(shortest) break;
                for(int j=1;j<n+1;j++){
                    if(dp[n][i][a]+c+dp[n][b][j] == dp[n][i][j]){
                        shortest = true;
                    }
                    if(shortest) break;
                }
            }
            if(shortest) answer --;
        }
        System.out.println(answer);
        /*
        for (int i=1;i<n+1;i++){
            for (int j=1;j<n+1;j++){
                System.out.print(dp[n][i][j]);
                System.out.print(" ");
            }
            System.out.println("");
        }
        */
    }
}