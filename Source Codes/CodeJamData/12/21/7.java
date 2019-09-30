import java.util.*;
import java.math.*;
import java.io.*;

public class A {
	
	int n;
	int[] scores;
	int sum;

	private void solve() throws Exception {
		n = nextInt();
		scores = new int[n];
		sum = 0;
		for (int i = 0; i < n; ++i) {
			scores[i] = nextInt();
			sum += scores[i];
		}
		for (int i = 0; i < n; ++i) {
			double lo = 0, hi = 1;
			for (int it = 0; it < 500; ++it) {
				double mid = (lo + hi) / 2.;
				double value = scores[i] + mid * sum;
				
				double left = 1 - mid;
				for (int j = 0; j < n; ++j) {
					if (i == j || scores[j] >= value) {
						continue;
					}
					double toReach = (value - scores[j]) / sum;
					left -= toReach;
				}
				if (left < 0) {
					hi = mid;
				} else {
					lo = mid;
				}
			}
			out.printf("%.15f ", 100. * (lo + hi) / 2.);
		}
		out.println();
	}

	public void run() {
		try {
			int tc = nextInt();
			for (int it = 1; it <= tc; ++it) {
				System.err.println(it);
				out.print("Case #" + it + ": ");
				solve();
			}
		} catch (Exception e) {
			NOO(e);
		} finally {
			out.close();
		}
	}

	PrintWriter out;
	BufferedReader in;
	StringTokenizer St;

	void NOO(Exception e) {
		e.printStackTrace();
		System.exit(42);
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

	String nextToken() {
		while (!St.hasMoreTokens()) {
			try {
				String line = in.readLine();
				if (line == null)
					return null;
				St = new StringTokenizer(line);
			} catch (Exception e) {
				NOO(e);
			}
		}
		return St.nextToken();
	}

	private A(String name) {
		try {
			in = new BufferedReader(new FileReader("input.txt"));
			St = new StringTokenizer("");
			out = new PrintWriter(new FileWriter("output.txt"));
		} catch (Exception e) {
			NOO(e);
		}
	}

	public static void main(String[] args) {
		Locale.setDefault(Locale.US);
		new A("a").run();
	}
}
