import java.util.*;
import java.io.*;

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int[][] map = new int[2][N];
        for(int i=0; i<2; i++)
            for(int j=0; j<N; j++)
                map[i][j] = sc.nextInt();
        System.out.println(func(N,map));
    }

    public static int func(int N, int[][] ar){
        int[][] dp = new int[2][N];
        dp[0][0] = ar[0][0];
        for(int i=0; i<2; i++)
            for(int j=0; j<N; j++){
                if(i+1<2) dp[i+1][j] = Math.max(dp[i+1][j], dp[i][j] + ar[i+1][j]);
                if(j+1<N) dp[i][j+1] = Math.max(dp[i][j+1], dp[i][j]+ ar[i][j+1]);
            }
        return dp[1][N-1];
    }
}