import java.io.*;
import java.util.*;

public class Solution {


	private StringTokenizer st;
	private BufferedReader in;
	private PrintWriter out;
	
	final String file = "A-large";

	public void solve(int test) throws IOException {
		out.print("Case #" + (test + 1) + ": ");
		int n = nextInt();
		int[] a = new int[n];
		int x = 0;
		for (int i = 0; i < n; ++i) {
			a[i] = nextInt();
			x += a[i];
		}
		for (int i = 0; i < n; ++i) {
			double l = 0.;
			double r = 1.;
			for (int it = 0; it < 100; ++it) {
				double mid = (l + r) / 2.;
				double sum = 0.;
				for (int j = 0; j < n; ++j) {
					sum += Math.max(0., (a[i] - a[j]) / (double)x + mid);
				}
				if (sum > 1.) {
					r = mid;
				} else {
					l = mid;
				}
			}
			out.print(100. * l + " ");
		}
		out.println();
	}

	public void run() throws IOException {
		in = new BufferedReader(new FileReader(file + ".in"));
		out = new PrintWriter(file + ".out");
		eat("");
		
		int tests = nextInt();
		for (int test = 0; test < tests; ++test) {
			solve(test);
		}
		
		out.close();
	}
	
	void eat(String s) {
		st = new StringTokenizer(s);
	}
	
	String next() throws IOException {
		while (!st.hasMoreTokens()) {
			String line = in.readLine();
			if (line == null) {
				return null;
			}
			eat(line);
		}
		return st.nextToken();
	}
	
	int nextInt() throws IOException {
		return Integer.parseInt(next());
	}
	
	long nextLong() throws IOException {
		return Long.parseLong(next());
	}
	
	double nextDouble() throws IOException {
		return Double.parseDouble(next());
	}
	
	public static void main(String[] args) throws IOException {
		Locale.setDefault(Locale.US);
		new Solution().run();
	}
	
}
