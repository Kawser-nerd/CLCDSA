import java.io.*;
import java.util.*;
import java.math.*;

public class A implements Runnable {
	public static void main(String[] args) {
		new Thread(new A()).run();
	}
	final static int INF = 1111111;

	int eat(int x, int y) {
		return x + y >= INF ? INF : x + y;
	}

	public void run() {
		InputReader in = new InputReader(System.in);
		PrintWriter out = new PrintWriter(System.out);

		int testCases = in.nextInt();
		for (int index = 1; index <= testCases; ++index) {
			int m = in.nextInt(), n = in.nextInt();
			int[] a = new int[n];
			for (int i = 0; i < n; ++i)
				a[i] = in.nextInt();
			Arrays.sort(a);
			int[][] dp = new int[n + 1][n + 1];
			dp[0][0] = m;
			for (int i = 1; i <= n; ++i)
				dp[0][i] = eat(dp[0][i - 1], dp[0][i - 1] - 1);
			for (int i = 1; i <= n; ++i) {
				for (int j = 0; j <= n; ++j) {
					if (dp[i - 1][j] > a[i - 1])
						dp[i][j] = Math.max(dp[i][j], eat(dp[i - 1][j], a[i - 1]));
					if (j > 0)
						dp[i][j] = Math.max(dp[i][j], dp[i - 1][j - 1]);
				}
				for (int j = 1; j <= n; ++j)
					dp[i][j] = Math.max(dp[i][j], eat(dp[i][j - 1], dp[i][j - 1] - 1));
			}
			int ret = 0;
			for (int i = 0; i <= n; ++i)
				if (dp[n][i] > 0) {
					ret = i;
					break;
				}
			out.println("Case #" + index + ": " + ret);
		}

		out.close();
	}
}

class InputReader {
	BufferedReader buff;
	StringTokenizer tokenizer;

	InputReader(InputStream stream) {
		buff = new BufferedReader(new InputStreamReader(stream));
		tokenizer = null;
	}
	boolean hasNext() {
		while (tokenizer == null || !tokenizer.hasMoreTokens())
			try {
				tokenizer = new StringTokenizer(buff.readLine());
			}
			catch (Exception e) {
				return false;
			}
		return true;
	}
	String next() {
		if (!hasNext())
			throw new RuntimeException();
		return tokenizer.nextToken();
	}
	int nextInt() { return Integer.parseInt(next()); }
	long nextLong() { return Long.parseLong(next()); }
}

