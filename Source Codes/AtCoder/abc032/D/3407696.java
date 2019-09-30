import java.io.IOException;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;


/*
 *
 *
 * tc 1
 * https://beta.atcoder.jp/contests/abc032/submissions/1585209
 * https://beta.atcoder.jp/contests/abc032/submissions/1820674
 *
 *
 * tc 2 3
 * https://beta.atcoder.jp/contests/abc032/submissions/2177288
 *
 */



public class Main {

	static int n;	//????
	static int w;	//?????????????
	static Map<String,Long> dp;
	static int N;
	static long[][] items;
	public static void main(String[] args) throws IOException {

		Scanner sc = new Scanner(System.in);
		n = sc.nextInt();
		N=n;
		w = sc.nextInt();
		items=new long[n][2];
		//Item[] items = new Item[n];

		boolean isTest1 = true;
		boolean isTest2weight = true;
		boolean isTest3value = true;

		if (n > 30) {
			isTest1 = false;
		}
		else if(n<=30) {
			isTest2weight=false;
			isTest3value=false;
		}
		for (int i = 0; i < n; i++) {		//????
			int v = sc.nextInt();
			int w = sc.nextInt();
			items[i][0]=v;		//value
			items[i][1]=w;		//weight

			if (w > 1000) {
				isTest2weight = false;		//3???????????????????????
			}
			if (v > 1000) {
				isTest3value = false;
			}
		}

		// Restriction of weight

		if(isTest1) {
			dp = new HashMap<>();
			long ans = dfs(0,w);
			System.out.println(ans);
		}
		else if (isTest2weight) {		//???2???
			long[][] dp = new long[n+1][w+1];		//???????MAX?weight?1000????????DP?OK???????200???200000???TLE???????
			for (int i = 0; i < n; i++) {
				for (int j = 0; j <= w; j++) {
					if (j >= items[i][1]) {
						dp[i+1][j] = Math.max(dp[i][(int) (j-items[i][1])] + items[i][0], dp[i][j]);
					} else {
						dp[i+1][j] = dp[i][j];
					}
				}
			}
			System.out.println(dp[n][w]);
		}
		// Restriction of value
		else if (isTest3value) {		//???????value??????
			int vMax = 1000;
			long[][] dp = new long[n+1][n * vMax + 1];
			for (int i = 1; i < n * vMax + 1; i++) {
				dp[0][i] = Integer.MAX_VALUE;		//????????????????????????????????0
			}

			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n * vMax + 1; j++) {
					if (j>=items[i][0]) {
						dp[i+1][j] = Math.min(dp[i][j], dp[i][(int) (j-items[i][0])] + items[i][1]);		//value??????????????????weight
					} else {
						dp[i+1][j] = dp[i][j];
					}
				}
			}

			long ans = 0;
			for (int i = 0; i < n * vMax + 1; i++) {
				if (dp[n][i] <= w) {
					ans = Math.max(ans, i);
				}
			}
			System.out.println(ans);
		}

		// Restriction only size
		else {

		}
	}
	static long dfs(int n, long w) {
		if (dp.get(getKey(n,w))!=null) {
			return dp.get(getKey(n,w));
		}
		long res;
		if (n==N) {
			res=0;
		}else if(w<items[n][1]) {
			res = dfs(n+1, w);
		}else{
			res = Math.max( dfs(n+1, w), dfs(n+1, w-items[n][1])+items[n][0]);
		}
		dp.put(getKey(n,w), res);
		return res;
	}

	static String getKey(int n, long w){
		return String.format("%d.%d", n,w);
	}
}