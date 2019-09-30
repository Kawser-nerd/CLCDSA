import java.io.*;
import java.util.*;

public class A {
	public static void main(String[] args) {
		new A().run();
	}

	BufferedReader br;
	StringTokenizer st;
	PrintWriter out;
	boolean eof = false;
	Random rand = new Random(12345);

	private void run() {
		Locale.setDefault(Locale.US);
		try {
			br = new BufferedReader(new FileReader(FNAME + ".in"));
			out = new PrintWriter(FNAME + ".out");
			solve();
			out.close();
		} catch (Throwable e) {
			e.printStackTrace();
			System.exit(566);
		}
	}

	String nextToken() {
		while (st == null || !st.hasMoreTokens()) {
			try {
				st = new StringTokenizer(br.readLine());
			} catch (Exception e) {
				eof = true;
				return "0";
			}
		}
		return st.nextToken();
	}

	int nextInt() {
		return Integer.parseInt(nextToken());
	}

	long nextLong() {
		return Long.parseLong(nextToken());
	}

	double nextDouble() {
		return Double.parseDouble(nextToken());
	}

	String FNAME = "a";

	private void solve() throws IOException {
		int tests = nextInt();
		for (int test = 1; test <= tests; test++) {
			out.print("Case #" + test + ": ");
			int n = nextInt();
			int m = nextInt();
			double[] p = new double[n];
			for (int i = 0; i < p.length; i++) {
				p[i] = nextDouble();
			}
			double ans = Double.POSITIVE_INFINITY;
			{
				double allRight = 1.0;
				for (int i = 0; i < p.length; i++) {
					allRight *= p[i];
				}
				ans = Math.min(ans, (m - n) + 1 + (1 - allRight) * (m + 1));
			}
			{
				ans = Math.min(ans, m + 2);
			}
			{
				for (int i = 1; i < p.length; i++) {
					p[i] *= p[i - 1];
				}
				for (int i = 0; i < p.length; i++) {
					ans = Math.min(ans, (n - i - 1) + (m - 1 - i) + 1
							+ (1 - p[i]) * (m + 1));
				}
			}
			out.println(ans);
		}
	}
}
