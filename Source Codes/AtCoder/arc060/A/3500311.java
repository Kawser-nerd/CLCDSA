import java.util.*;

class Main {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int a = sc.nextInt();
        int x[] = new int[n+1];
        x[0] = -1;
        for (int i=0;i<n;i++){
            x[i+1] = sc.nextInt();
        }
        //DP table
        long dp[][][] = new long[n+1][n+1][n*50+1];
        dp[0][0][0] = 1;
        for (int i=1;i<n+1;i++){
            for(int m=0;m<n+1;m++){
                for(int s=0;s<n*50+1;s++){
                    int diff = s - x[i];
                    if(diff >= 0 & m>=1){
                        dp[i][m][s] = dp[i-1][m][s] + dp[i-1][m-1][diff];
                    } else {
                        dp[i][m][s] = dp[i-1][m][s];
                    }
                }
            }
        }
        //Answer
        int num = 1;
        int summation = a;
        long answer = 0;
        while (num <= n & summation <= n*50){
            answer += dp[n][num][summation];
            num++;
            summation+=a;
        }
        System.out.println(answer);
    }
}