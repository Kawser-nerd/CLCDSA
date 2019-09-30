import java.util.*;
public class Main {

	public static void main(String[] args) {
		int INF = 100000000;
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int m = sc.nextInt();
		int[] dp = new int[n+1];
		int [] a = new int[m];
		for(int i = 0; i < m; i++) {
			a[i] = sc.nextInt();
		}
		int[] cost = {0, 2, 5, 5, 4, 5, 6, 3, 7, 6};
		Arrays.sort(a);
		Arrays.fill(dp, -INF);
		dp[0] = 0;
		for(int i = 1; i <= n; i++) {
			for(int j = m-1; j >= 0; j--) {
				if(i - cost[a[j]] < 0) continue;
				else
					dp[i] = Math.max(dp[i],dp[i-cost[a[j]]] + 1);
			}
		}
		StringBuilder ans = new StringBuilder();
		while(n != 0) {
			for(int j = m-1; j >= 0; j--) {
				if(cost[a[j]] > n)
					continue;
				if(dp[n-cost[a[j]]] == dp[n]-1) {
					ans.append(a[j]);
					n -= cost[a[j]];
					break;
				}
			}
		}
		System.out.println(ans);
	}

}