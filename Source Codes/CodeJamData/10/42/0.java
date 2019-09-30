import java.io.*;
import java.util.*;

public class Solution {
	
	final String f = "B-large";
	
	private BufferedReader in;
	private PrintWriter out;
	private StringTokenizer st;

	void solve() throws IOException {
		int n = nextInt();
		int[] c = new int[1 << n];
		for (int i = 0; i < 1 << n; ++i) {
			c[i] = nextInt();
		}
		long[][] a = new long[n][];
		for (int it = 0; it < n; ++it) {
			a[it] = new long[1 << (n - it - 1)];
			for (int i = 0; i < a[it].length; ++i) {
				a[it][i] = nextLong();
			}
		}
		long[][] d = new long[1 << n][n + 1];
		for (int i = 0; i < 1 << n; ++i) {
			for (int j = 0; j <= n; ++j) {
				d[i][j] = j <= c[i] ? 0 : 1000000000000000000L;
			}
		}
		for (int l = 0; l < n; ++l) {
			long[][] t = new long[1 << (n - l - 1)][n + 1];
			for (int i = 0; i < t.length; ++i) {
				for (int j = 0; j <= n; ++j) {
					t[i][j] = a[l][i] + d[2 * i][j] + d[2 * i + 1][j];
					if (j < n) {
						t[i][j] = Math.min(t[i][j], d[2 * i][j + 1] + d[2 * i + 1][j + 1]);
					}
					t[i][j] = Math.min(t[i][j], 1000000000000000000L);
				}
			}
			d = t;
		}
		long ans = 1000000000000000000L;
		for (int i = 0; i <= n; ++i) {
			ans = Math.min(ans, d[0][i]);
		}
		out.println(ans);
	}

	Solution() throws IOException {
		in = new BufferedReader(new FileReader(f + ".in"));
		out = new PrintWriter(f + ".out");
		
		eat("");
		
		int tests = nextInt();
		for (int test = 0; test < tests; ++test) {
			System.out.println("Test #" + (test + 1));
			out.print("Case #" + (test + 1) + ": ");
			solve();
		}
		
		in.close();
		out.close();
	}
	
	private void eat(String str) {
		st = new StringTokenizer(str);
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
		new Solution();
	}
}
