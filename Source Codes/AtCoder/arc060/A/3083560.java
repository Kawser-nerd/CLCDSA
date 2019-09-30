import java.util.*;
import java.lang.*;
import java.io.*;


public class Main {
    public static int maxOfArray(int[] a){
    	int ans = a[0];
    	for(int i=1;i<a.length;i++){
    		if(a[i]>ans) ans=a[i];
    	}
    	return ans;
    }
    public static int minOfArray(int[] a){
    	int ans = a[0];
    	for(int i=1;i<a.length;i++){
    		if(a[i]<ans) ans=a[i];
    	}
    	return ans;
    }
    
    public static long solve(int[] x){
        //dp[i][j]:use i cards, the sum is (j-2500)
        long[][] dp = new long[x.length+1][5001];
        dp[0][2500]=1;
        for(int i=1;i<=x.length;i++){
        	for(int j=0;j<=5000;j++){
        	    dp[i][j] = dp[i-1][j] + ((j-x[i-1]>=0&&j-x[i-1]<=5000)?dp[i-1][j-x[i-1]]:0);
        	}
        }
        return dp[x.length][2500]-1;
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int A = sc.nextInt();
        int[] x = new int[N];
        for(int n=0;n<N;n++) x[n]=sc.nextInt()-A;
        System.out.println(solve(x));
    }
}