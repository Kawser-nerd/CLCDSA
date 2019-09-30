import java.lang.*;
import java.io.*;
import java.util.*;

public class Solution {
	public static BufferedReader br;
	public static PrintWriter out;
	public static StringTokenizer stk;

	// ///////////////// TO CHANGE ///////////////////////////
	public static boolean isServer = false;

	// ///////////////// TO CHANGE ///////////////////////////

	public static void main(String[] args) throws IOException {
		if (isServer) {
			br = new BufferedReader(new InputStreamReader(System.in));
			out = new PrintWriter(System.out);
		} else {
			br = new BufferedReader(new FileReader("in.txt"));
			out = new PrintWriter(new File("out.txt"));
		}

		(new Solution()).run();
	}

	public void loadLine() {
		try {
			stk = new StringTokenizer(br.readLine());
		} catch (IOException e) {
			e.printStackTrace();
		}
	}

	public String nextLine() {
		try {
			return br.readLine();
		} catch (IOException e) {
			e.printStackTrace();
			return "";
		}
	}

	public String nextWord() {
		while (stk == null || !stk.hasMoreTokens())
			loadLine();
		return stk.nextToken();
	}

	public Integer nextInt() {
		while (stk == null || !stk.hasMoreTokens())
			loadLine();
		return Integer.valueOf(stk.nextToken());
	}

	public Long nextLong() {
		while (stk == null || !stk.hasMoreTokens())
			loadLine();
		return Long.valueOf(stk.nextToken());
	}

	public Double nextDouble() {
		while (stk == null || !stk.hasMoreTokens())
			loadLine();
		return Double.valueOf(stk.nextToken());
	}

	public Float nextFloat() {
		while (stk == null || !stk.hasMoreTokens())
			loadLine();
		return Float.valueOf(stk.nextToken());
	}
	
	public void run() {
		int tt = nextInt();
		for (int t = 0; t < tt; t++) {
			int A = nextInt();
			int B = nextInt();
			int m = nextInt();
			int n = nextInt()+1;
			
			int[] arr = new int[n];
			for (int i = 1; i < n; i++) {
				arr[i] = nextInt();
			}
			arr[0] = 0;
			
			int[][] dp = new int[n][256]; // pos, val
			for (int i = 0; i < n; i++) Arrays.fill(dp[i], Integer.MAX_VALUE);
			
			for (int i = 0; i < 256; i++) {
				dp[0][i] = 0;
			}
			for (int i = 0; i < n-1; i++) {
				for (int j = 0; j < 256; j++) {
					if (dp[i][j] != Integer.MAX_VALUE) {
						
						// Delete
						for (int last = i+1; last < n; last++) {
							dp[last][j] = Math.min(dp[last][j], dp[i][j] + A*(last-i));
						}
						
						// Change next
						for (int nxt = 0; nxt < 256; nxt++) {
							if (Math.abs(j-nxt) <= m) dp[i+1][nxt] = Math.min(dp[i+1][nxt], dp[i][j] + Math.abs(arr[i+1]-nxt));
						}
						
						// Add and change
						for (int nxt = 0; nxt < 256; nxt++) {
							if (m != 0 && j != nxt) {
								int dif = Math.abs(j-nxt);
								int cnt = (dif-1)/m;
								dp[i+1][nxt] = Math.min(dp[i+1][nxt], dp[i][j] + cnt*B + Math.abs(arr[i+1]-nxt));
							}
						}
					}
				}
			}

			int ans = Integer.MAX_VALUE;
			for (int i = 0; i < 256; i++) {
				ans = Math.min(ans, dp[n-1][i]);
			}
			out.printf("Case #%d: %d\n", t+1, ans);
		}
		out.flush();
	}
}
