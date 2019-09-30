/*
 * ?????N ????????????? i?(1?i?N) ??????????? xi ?????????
 * ???????????????? 1 ??????? ????????????????????? A ???????????? ???????????????????????????
 */

import java.util.*;
	public class Main{
		public static void main(String[] args){
            Scanner sc = new Scanner(System.in);
            // ??
            int n = Integer.parseInt(sc.next());
            int a = Integer.parseInt(sc.next());
            int[] nums = new int[n];
            int max = 1;

            for(int i=0; i<n; i++){
            	nums[i] = Integer.parseInt(sc.next());
            	if(max<nums[i]){
            		max = nums[i];
            	}
            }
            
            // a?????????b???????c??????????? = dp[a][b][c]
            long[][][] dp = new long[n+1][n+1][n*max+1];
            
            for(int i=0; i<n+1; i++){
            	for(int j=0; j<n*max+1; j++){
            		dp[0][i][j] = 0;
            		dp[i][0][j] = 0;
            	}
            }
            for(int i=0; i<n+1; i++){
            	dp[i][0][0] = 1;
            }
            
            for(int k=0; k<n*max+1; k++){
            	for(int j=1; j<n+1; j++){
            		for(int i=1; i<n+1; i++){
            			if(i<j){
            				dp[i][j][k] = 0;
            			}else{
            				dp[i][j][k] = dp[i-1][j][k];
            				if(k-nums[i-1] >= 0){
            					dp[i][j][k] += dp[i-1][j-1][k-nums[i-1]];
            				}
            			}
            		}
            	}
            }
            
            long ret = 0;
            
            for(int i=1; i<n+1 && i*a<n*max+1; i++){
            	ret += dp[n][i][i*a];
            }
            
            // ??
            System.out.println(ret);

            sc.close();
        }
    }