import java.io.*;
import java.util.*;

public class SwingingWild {

	void solve() throws Exception {
		int n = nextInt();
		int[] d = new int[n], l = new int[n];
		for (int i = 0; i < n; i++) {
			d[i] = nextInt();
			l[i] = nextInt();
		}
		int D = nextInt();
		
		long[] dp = new long[n];
		dp[0] = d[0];
		for (int i = 0; i < n - 1; i++) {
			long max = d[i] + dp[i];
			for (int j = i + 1; j < n && d[j] <= max; j++) {
				dp[j] = Math.max(dp[j], Math.min(l[j], d[j] - d[i]));
			}
		}
		for (int i = 0; i < n; i++) {
			if (d[i] + dp[i] >= D) {
				out.println("YES");
				return;
			}
		}
		out.println("NO");
	}

	void run() {
		try {
			in = new BufferedReader(new FileReader("input.txt"));
			out = new PrintWriter("output.txt");
			int tests = nextInt();

			for (int i = 0; i < tests; i++) {
				long time = System.currentTimeMillis();
				out.print("Case #" + (i + 1) + ": ");
				solve();
				System.err.println("Solved case #" + (i + 1) + " in "
						+ (System.currentTimeMillis() - time) + " ms");
			}

			out.close();
		} catch (Exception e) {
			e.printStackTrace();
			System.exit(1);
		}
	}

	BufferedReader in;
	StringTokenizer st;
	PrintWriter out;
	final String filename = new String("SwingingWild").toLowerCase();

	String nextToken() throws Exception {
		while (st == null || !st.hasMoreTokens())
			st = new StringTokenizer(in.readLine());
		return st.nextToken();
	}

	int nextInt() throws Exception {
		return Integer.parseInt(nextToken());
	}

	long nextLong() throws Exception {
		return Long.parseLong(nextToken());
	}

	double nextDouble() throws Exception {
		return Double.parseDouble(nextToken());
	}

	public static void main(String[] args) {
		new SwingingWild().run();
	}

}
