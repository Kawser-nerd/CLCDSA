import java.io.*;
import java.util.*;

class Main{
    public static void main(String[] args){
        solve();
    }

    public static void solve(){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] s = new int[n];
        for(int i=0;i<n;i++){
        	s[i] = sc.nextInt();
        }
        int[] dp = new int[10001];
        for(int i=0;i<n;i++){
        	for(int j=10000-s[i];j>=0;j--){
        		if(dp[j]!=0){
        			dp[j+s[i]] = 1; 
        		}
        	}
        	dp[s[i]] = 1;
        }

        for(int i=10000;i>=0;i--){
        	if(dp[i]!=0 && i%10!=0){
        		System.out.println(i);
        		break;
        	}
        	if(i==0){
        		System.out.println(i);
        	}
        }
    }
}