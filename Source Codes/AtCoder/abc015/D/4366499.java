import java.util.*;
import java.io.InputStreamReader;
import java.io.BufferedReader;
import java.util.Arrays;
import java.util.List;
import java.util.ArrayList;
import java.util.ArrayDeque;
import java.util.Deque;
import java.util.Collections;
import java.awt.Point;


public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        //String[] nd = br.readLine().split(" ");
        int W = Integer.parseInt(br.readLine());
        String[] nk = br.readLine().split(" ");
        int n = Integer.parseInt(nk[0]);
        int k = Integer.parseInt(nk[1]);
        int[] w = new int[n+1];
        int[] v = new int[n+1];
        
        for (int i = 0; i < n; i++) {
            String[] line = br.readLine().split(" ");
            w[i+1] = Integer.parseInt(line[0]);
            v[i+1] = Integer.parseInt(line[1]);
        }
        
        //n???????W??k???????????
        int[][][] dp = new int[n+1][W+1][k+1];
        dp[0][0][0] = 0;
        
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= W; j++) {
                for (int l = 1; l <= k; l++) {
                    if (j-w[i] >= 0) dp[i][j][l] = Math.max(dp[i-1][j-w[i]][l-1]+v[i], dp[i-1][j][l]);
                    else dp[i][j][l] = dp[i-1][j][l];
                }
            }
        }
        
        System.out.println(dp[n][W][k]);
    }
}