import java.io.*;
import java.util.*;

class Main{
    public static void main(String[] args){
        solve();
    }

    public static void solve(){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        long ans = 0;
        long etc = 1000000007;
        long[][][][] dp = new long[n+1][4][4][4];
        dp[0][3][3][3] = 1;

        for(int i=0;i<n;i++){

        	//3
        	for(int j=0;j<4;j++){

        		//2
        		for(int k=0;k<4;k++){

        			//1
        			for(int l=0;l<4;l++){

        				//new
        				for(int m=0;m<4;m++){
        					
        					if(m==1 && k==0 && l==2){
        						continue;
        					}
        					if(m==2 && j==0 && l==1){
        						continue;
        					}
        					if(m==2 && j==0 && k==1){
        						continue;
        					}
        					if(m==2 && k==1 && l==0){
        						continue;
        					}
        					if(m==2 && k==0 && l==1){
        						continue;
        					}

        					dp[i+1][k][l][m] += dp[i][j][k][l];
        					dp[i+1][k][l][m] %= etc;
        				}
        			}
        		}
        	}
        }

        for(int i=0;i<4;i++){
        	for(int j=0;j<4;j++){
        		for(int k=0;k<4;k++){
        			ans += dp[n][i][j][k];
        			ans %= etc;
        		}
        	}
        }

        System.out.println(ans);
    }
}