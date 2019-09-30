import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {

	public static void main(String args[]) throws IOException{
		Scanner sc = new Scanner(System.in);
		
		//BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		//StringTokenizer st = new StringTokenizer(br.readLine());
		
		//StringBuilder sb = new StringBuilder();
		
		char s[] = sc.next().toCharArray();
		
		int k = sc.nextInt();
		
		int dp[][][] = new int[s.length][s.length][k+1];
		
		for(int i=0;i<=k;i++){
			for(int r=0;r<s.length;r++){
				for(int l=r;l>=0;l--){
					if(l==r){
						dp[l][r][i] = 1;
						continue;
					}
					
					if(r==l+1){
						dp[l][r][i] = s[l] == s[r] || i>0 ? 2 : 1;
						continue;
					}
					
					if(s[l] == s[r]){
						dp[l][r][i] = dp[l+1][r-1][i]+2;
					}
					else{
						dp[l][r][i] = Math.max(dp[l+1][r][i], dp[l][r-1][i]);
					}
					
					if(i>0){
						dp[l][r][i] = Math.max(dp[l][r][i], dp[l+1][r-1][i-1]+2);
					}
				}
			}
		}
		
		System.out.println(dp[0][s.length-1][k]);
	}
}