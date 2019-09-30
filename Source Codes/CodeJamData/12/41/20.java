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
		int tt = Integer.parseInt(nextLine());
		for (int ttt = 0; ttt < tt; ttt++) {
			int n = nextInt();
			int[] d = new int[n];
			int[] l = new int[n];
			for (int i = 0; i < n; i++) {
				d[i] = nextInt();
				l[i] = nextInt();
			}
			int D = nextInt();
			
			boolean ans = false;
			int[] dp = new int[n];
			dp[0] = d[0];
			for (int i = 0; i < n; i++) {
				if (dp[i] > 0) {
					for (int j = i+1; j < n; j++) {
						if (d[j] - d[i] <= dp[i]) {
							dp[j] = Math.max(dp[j], Math.min(d[j]-d[i], l[j]));
						}
					}
					if (dp[i] + d[i] >= D) ans = true;
				}
			}
			out.printf("Case #%d: ", ttt+1);
			out.println(ans ? "YES" : "NO");
		}
		out.flush();
	}
}
