import java.util.*;
import java.lang.*;
import java.io.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String S = sc.next();
        int N = S.length();
        boolean[] dp = new boolean[N];
        for(int n=0;n<N;n++){
        	if(n>=4 && S.substring(n-4,n+1).equals("dream"))   dp[n]=dp[n]||(n==4)||dp[n-5];
        	if(n>=6 && S.substring(n-6,n+1).equals("dreamer")) dp[n]=dp[n]||(n==6)||dp[n-7];
        	if(n>=4 && S.substring(n-4,n+1).equals("erase")) dp[n]=dp[n]||(n==4)||dp[n-5];
        	if(n>=5 && S.substring(n-5,n+1).equals("eraser")) dp[n]=dp[n]||(n==5)||dp[n-6];
        }
        System.out.println(dp[N-1] ? "YES" : "NO");
    }
}