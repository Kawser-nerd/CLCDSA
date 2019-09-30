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
	static final int ATTEMPT_NUMBER = 0;
	
	double go(double[] ps) {
		int k = ps.length;
		
		if (k % 2 != 0) {
			throw new AssertionError();
		}
		
		double[] dp = new double[k / 2 + 1];
		dp[0] = 1;
		
		for (double p : ps) {
			double[] nxt = new double[k / 2 + 1];
			for (int i = 0; i <= k / 2; i++) {
				nxt[i] += dp[i] * (1 - p);
				if (i != k / 2) {
					nxt[i + 1] += dp[i] * p;
				}
			}
			dp = nxt;
		}
		
		return dp[k / 2];
	}

	void solve() throws IOException {
		int n = nextInt();
		int k = nextInt();

		double[] p = new double[n];
		for (int i = 0; i < n; i++) {
			p[i] = nextDouble();
		}
		
		
		double ans = -1;
		Arrays.sort(p);
		for (int i = 0; i <= k; i++) {
			double[] tmp = new double[k];
			for (int j = 0; j < i; j++) {
				tmp[j] = p[j];
			}
			int tail = k - i;
			for (int j = 1; j <= tail; j++) {
				tmp[k - j] = p[n - j];
			}
			ans = Math.max(ans, go(tmp));
		}
		
		out.println(ans);
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