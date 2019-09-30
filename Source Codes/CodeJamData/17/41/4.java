import java.io.*;
import java.util.*;

public class A {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	enum InputType {
		EXAMPLE, SMALL, LARGE
	}

	static final InputType INPUT_TYPE = InputType.LARGE;
	static final int ATTEMPT_NUMBER = 0;

	void solve() throws IOException {
		int n = nextInt();
		int p = nextInt();
		int[] a = new int[4];
		for (int i = 0; i < n; i++) {
			int x = nextInt();
			a[x % p]++;
		}

		int[][][] dp = new int[a[1] + 1][a[2] + 1][a[3] + 1];
		dp[0][0][0] = a[0];
		for (int i = 0; i <= a[1]; i++) {
			for (int j = 0; j <= a[2]; j++) {
				for (int k = 0; k <= a[3]; k++) {
					int delta = (i + 2 * j + 3 * k) % p == 0 ? 1 : 0;
					if (i < a[1]) {
						dp[i + 1][j][k] = Math.max(dp[i + 1][j][k], dp[i][j][k]
								+ delta);
					}
					if (j < a[2]) {
						dp[i][j + 1][k] = Math.max(dp[i][j + 1][k], dp[i][j][k]
								+ delta);
					}
					if (k < a[3]) {
						dp[i][j][k + 1] = Math.max(dp[i][j][k + 1], dp[i][j][k]
								+ delta);
					}
				}
			}
		}

		out.println(dp[a[1]][a[2]][a[3]]);
	}

	A() throws IOException {
		switch (INPUT_TYPE) {
		case EXAMPLE: {
			br = new BufferedReader(new InputStreamReader(System.in));
			out = new PrintWriter(System.out);
			break;
		}
		case SMALL: {
			br = new BufferedReader(new FileReader("A-small-attempt"
					+ ATTEMPT_NUMBER + ".in"));
			out = new PrintWriter("A-small-attempt" + ATTEMPT_NUMBER + ".out");
			break;
		}
		case LARGE: {
			br = new BufferedReader(new FileReader("A-large.in"));
			out = new PrintWriter("A-large.out");
			break;
		}
		}
		int t = nextInt();
		for (int i = 1; i <= t; i++) {
			System.err.println("Test " + i);
			out.print("Case #" + i + ": ");
			solve();
		}
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new A();
	}

	String nextToken() {
		while (st == null || !st.hasMoreTokens()) {
			try {
				st = new StringTokenizer(br.readLine());
			} catch (Exception e) {
				eof = true;
				return null;
			}
		}
		return st.nextToken();
	}

	String nextString() {
		try {
			return br.readLine();
		} catch (IOException e) {
			eof = true;
			return null;
		}
	}

	int nextInt() throws IOException {
		return Integer.parseInt(nextToken());
	}

	long nextLong() throws IOException {
		return Long.parseLong(nextToken());
	}

	double nextDouble() throws IOException {
		return Double.parseDouble(nextToken());
	}
}