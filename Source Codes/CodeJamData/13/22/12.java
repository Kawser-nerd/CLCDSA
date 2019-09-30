import java.io.*;
import java.util.*;
import java.math.*;

public class B implements Runnable {
	public static void main(String[] args) {
		new Thread(new B()).run();
	}
	public void run() {
		InputReader in = new InputReader(System.in);
		PrintWriter out = new PrintWriter(System.out);

		int testCases = in.nextInt();
		for (int index = 1; index <= testCases; ++index) {
			out.print("Case #" + index + ": ");
			int n = in.nextInt(), x = in.nextInt(), y = in.nextInt();
			int m = (Math.abs(x) + y) / 2;
			if (n >= (m + 1) * (m + m + 1)) {
				out.println("1.0");
			}
			else if (n <= m * (m + m - 1) + y) {
				out.println("0.0");
			}
			else {
				int limit = 2 * m;
				n -= m * (limit - 1);
				double[][] dp = new double[n + 1][limit + 1];
				dp[0][0] = 1;
				for (int i = 0; i < n; ++i) {
					for (int j = Math.max(i - limit + 1, 0); j < limit; ++j) {
						dp[i + 1][j] += dp[i][j] * .5;
						dp[i + 1][j + 1] += dp[i][j] * .5;
					}
					if (i >= limit)
						dp[i + 1][i + 1 - limit] += dp[i][i - limit];
					dp[i + 1][limit] += dp[i][limit];
				}
				double ret = 0;
				for (int i = y + 1; i <= limit; ++i)
					ret += dp[n][i];
				out.println(ret);
			}
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

