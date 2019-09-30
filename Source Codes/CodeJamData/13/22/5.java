import java.io.*;
import java.util.*;

public class B {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	enum InputType {
		EXAMPLE, SMALL, LARGE
	}

	static final InputType INPUT_TYPE = InputType.LARGE;
	static final int ATTEMPT_NUMBER = 1;

	void solve() throws IOException {
		int n = nextInt();
		int x = nextInt();
		x = Math.abs(x);
		int y = nextInt();
		System.err.println(n + " " + x + " " +y);

		int sum = (x + y) >> 1;

		int layer = 0;

		while (n > 4 * layer + 1) {
			n -= 4 * layer + 1;
			layer++;
		}
		
		System.err.println(layer);
		
		if (sum != layer) {
			out.println(sum > layer ? 0 : 1);
			return;
		}
		
		if (y == layer * 2) {
			out.println(n == 4 * layer + 1 ? 1 : 0);
			return;
		}
		
		int side = 2 * layer;
		
		int rolls = n;
		int need = y + 1;
		
		if (rolls == 2 * side + 1) {
			out.println(1);
			return;
		}
		
		double[][] dp = new double[side + 1][side + 1];
		dp[0][0] = 1;
		
//		System.err.println(side + " " + rolls + " " + need);
		
		double ans = 0;
		for (int s1 = 0; s1 <= side && s1 <= rolls; s1++)
			for (int s2 = 0; s2 <= side && s1 + s2 <= rolls; s2++) {
				if (s1 + s2 == rolls) {
					if (s1 >= need)
						ans += dp[s1][s2];
					continue;
				}
				if (s1 == side) {
					dp[s1][s2 + 1] += dp[s1][s2];
				} else 
				if (s2 == side) {
					dp[s1 + 1][s2] += dp[s1][s2];
				} else {
					dp[s1 + 1][s2] += dp[s1][s2] * 0.5;
					dp[s1][s2 + 1] += dp[s1][s2] * 0.5;
				}
			}
		
		out.printf(Locale.US, "%.12f\n", ans);
		
	}

	B() throws IOException {
		switch (INPUT_TYPE) {
		case EXAMPLE: {
			br = new BufferedReader(new InputStreamReader(System.in));
			out = new PrintWriter(System.out);
			break;
		}
		case SMALL: {
			br = new BufferedReader(new FileReader("B-small-attempt"
					+ ATTEMPT_NUMBER + ".in"));
			out = new PrintWriter("B-small-attempt" + ATTEMPT_NUMBER + ".out");
			break;
		}
		case LARGE: {
			br = new BufferedReader(new FileReader("B-large.in"));
			out = new PrintWriter("B-large.out");
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
		new B();
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