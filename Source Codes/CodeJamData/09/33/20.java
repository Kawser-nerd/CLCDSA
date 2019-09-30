import java.io.*;
import java.util.*;
import java.math.*;
import static java.lang.Math.*;

public class Main implements Runnable {

	public static void main(String[] args) throws IOException {
		br = new BufferedReader(new FileReader(fileName + ".in"));
		out = new PrintWriter(fileName + ".out");
		new Main().run();
		out.close();
	}

	static BufferedReader br;
	static PrintWriter out;
	static StringTokenizer st;
	static String fileName = "prison";

	String nline() {
		try {
			return br.readLine();
		} catch (Exception e) {
			return null;
		}
	}

	String ns() {
		try {
			while (st == null || !st.hasMoreTokens())
				st = new StringTokenizer(br.readLine());
			return st.nextToken();
		} catch (Exception e) {
			return null;
		}
	}

	int ni() {
		return Integer.valueOf(ns());
	}

	long nl() {
		return Long.valueOf(ns());
	}

	double nd() {
		return Double.valueOf(ns());
	}

	int[][] dp;

	int[] qc;
	int n, q;

	int dp(int i, int j) {
		if (i > j)
			return 0;
		if (dp[i][j] != -1) {
			return dp[i][j];
		}
		int ans = Integer.MAX_VALUE;
		int left = i > 0 ? qc[i - 1] + 1 : 0;
		int right = j < q - 1 ? qc[j + 1] - 1 : n - 1;
		int sc = right - left;

		for (int l = i; l <= j; l++) {
			ans = min(ans, dp(i, l - 1) + dp(l + 1, j) + sc);
		}
		return dp[i][j] = ans;
	}

	public void run() {
		int T = ni();
		for (int tNum = 1; tNum <= T; tNum++) {
			n = ni();
			q = ni();
			dp = new int[q][q];
			qc = new int[q];
			for (int i = 0; i < q; i++)
				qc[i] = ni() - 1;
			Arrays.sort(qc);
			for (int i = 0; i < q; i++)
				Arrays.fill(dp[i], -1);
			int ans = dp(0, q - 1);
			out.println("Case #" + tNum + ": " + ans);
		}
	}

}
