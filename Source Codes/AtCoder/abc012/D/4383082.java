/*
* Author. Silviase(@silviasetitech)
* For AtCoder
*/

import java.util.*;
import java.lang.*;
import java.math.*;


public class Main {

    
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        int m = sc.nextInt();
        int[][] distance = new int[n+1][n+1];
        int[] maxes = new int[n+1] ;
        for (int i = 1; i < n+1; i++) {
            maxes[i] = 0;
        }
        int minmax = Integer.MAX_VALUE;
        for (int i = 0; i < n+1; i++) {
            for (int j = 0; j < n+1; j++) {
                if (i == j) {
                    distance[i][j] = 0;
                }else{
                    distance[i][j] = (int)1e7;
                }
            }
        }
        for (int i = 0; i < m; i++) {
            int a = sc.nextInt();
            int b = sc.nextInt();
            distance[a][b] = sc.nextInt();
            distance[b][a] = distance[a][b];
        }

        for (int k = 1; k < n+1; k++) {
            for (int i = 1; i < n+1; i++) {
                for (int j = 1; j < n+1; j++) {
                    distance[i][j] = Math.min( distance[i][j] , distance[i][k] + distance[k][j]);
                }
            }
        }

        for (int i = 1; i < n+1; i++) {
            for (int j = 1; j < n+1; j++) {
                maxes[i] = Math.max(maxes[i], distance[i][j]);
            }
        }
        for (int i = 1; i < n+1; i++) {
            minmax = Math.min(minmax , maxes[i]);
        }
        System.out.println(minmax);


        sc.close();
    }


    private static long gcd(Long m, long n) {
        if(m < n) {
            return gcd(n, m);
        }
        if(n == 0){
            return m;
        } 
        return gcd(n, m % n);
    }

    private static long[][] Combination_nCk(long n, long k) {
        n++; k++;
        long[][] ans = new long[(int)n][(int)k];
        for (int i = 0; i < n; i++) {
            ans[i][0] = 1;
        }
        for (int i = 0; i < n-1; i++) {
            for (int j = 0; j < k-1; j++) {
                if (i < j) {
                    ans[i][j] = 0;
                }else{
                    ans[i+1][j+1] = ans[i][j] + ans[i][j+1];
                }
            }
        }
        return ans;
    }
}