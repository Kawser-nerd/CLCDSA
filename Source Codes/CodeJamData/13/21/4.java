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
	static final int ATTEMPT_NUMBER = 1;
	
	static final long INF = Long.MAX_VALUE / 5;
	static final long BIG_ENOUGH = 1_000_000_000_000L;

	void solve() throws IOException {
		int init = nextInt();
		int n = nextInt();
		int[] a = new int[n];
		for (int i = 0; i < n; i++)
			a[i] = nextInt();
		Arrays.sort(a);
		
		int ptr = 0;
		while (ptr < 0 && a[ptr] < init) {
			init += a[ptr];
			ptr++;
		}
		
		a = Arrays.copyOfRange(a, ptr, n);
		n = a.length;
		
		long[] dp = new long[n + 1];
		Arrays.fill(dp, -INF);
		dp[0] = init;
		
		for (int i = 0; i < n; i++) {
			long[] next = new long[n + 1];
			Arrays.fill(next, -INF);
			for (int j = 0; j <= n; j++)
				if (dp[j] != -INF) {
					// eat
					if (dp[j] > a[i]) {
						next[j] = Math.max(next[j], a[i] + dp[j]);
					}
					// skip
					if (j != n) {
						next[j + 1] = Math.max(next[j + 1], dp[j]);
					}
					// eat new
					if (j != n && dp[j] <= BIG_ENOUGH) {
						dp[j + 1] = Math.max(dp[j + 1], 2L * dp[j] - 1);
					}
				}
			dp = next;
		}
		
		for (int i = 0; i <= n; i++)
			if (dp[i] != -INF) {
				out.println(i);
				return;
			}
		throw new AssertionError();
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