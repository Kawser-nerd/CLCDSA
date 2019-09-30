import java.util.*;
public class Main{
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int[] c = new int[n];
		for(int i=0; i<n; i++){
			c[i] = sc.nextInt();
		}
		int[] dp = new int[n];
		int INF = 1000000;
		Arrays.fill(dp, INF);
		dp[0] = c[0];
		for(int i=1; i<n; i++){
			int idx = (Arrays.binarySearch(dp, c[i])) * (-1) -1;
			dp[idx] = c[i];
		}
		int lis = n;
		while(dp[lis-1]==INF){
			lis--;
		}
		System.out.println(n-lis);
	}
}