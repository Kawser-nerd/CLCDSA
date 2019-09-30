/*
* @Author Silviase(@silviasetitech)
* For ProCon
*/

import java.util.*;
import java.lang.*;
import java.math.*;

class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        
        int n = sc.nextInt();
        int a = sc.nextInt();
        int[] num = new int[n+1];
        long ans = 0;
        long[][][] dp = new long[n+1][n+1][n*a+1];


        num[0] = 1000000007;
        for (int i = 1; i <= n; i++) {
            num[i] = sc.nextInt();
        }

        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= i; j++) {
                for (int k = 0; k <= n*a; k++) {
                    if (i == 0 && j == 0 && k == 0) {
                        dp[i][j][k] = 1;
                    }else if(i >= 1 && k < num[i]){
                        dp[i][j][k] = dp[i-1][j][k];
                    }else if(i >= 1 && j >= 1 && k >= num[i]){
                        dp[i][j][k] = dp[i-1][j][k] + dp[i-1][j-1][k-num[i]];
                    }else{
                        dp[i][j][k] = 0;
                    }
                }
            }
        }

        for (int i = 1; i <= n; i++) {
            ans += dp[n][i][i*a];
        }
        System.out.println(ans);

        sc.close();
    }

}