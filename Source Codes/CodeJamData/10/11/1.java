import java.io.*;
import java.util.*;

public class Solution {
	
	final String f = "A-large";
	
	private BufferedReader in;
	private PrintWriter out;
	private StringTokenizer st;

	void solve() throws IOException {
		int n = nextInt();
		int k = nextInt();
		char[][] f = new char[n][n];
		for (int row = 0; row < n; ++row) {
			f[row] = next().toCharArray();
			char[] r = f[row];
			for (int i = n - 1, j = n - 1; i >= 0; --i) {
				if (r[i] != '.') {
					r[j] = r[i];
					if (j != i) {
						r[i] = '.';
					}
					--j;
				}
			}
//			System.out.println(r);
		}
		boolean red = false, blue = false;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				final int[] dx = {0, 1, 1, 1};
				final int[] dy = {1, 1, 0, -1};
				for (int d = 0; d < dx.length; ++d) {
					if (i + dx[d] * k >= -1 && i + dx[d] * k <= n &&
						j + dy[d] * k >= -1 && j + dy[d] * k <= n) {
						char c = ' ';
						for (int t = 0; t < k; ++t) {
							char cc = f[i + dx[d] * t][j + dy[d] * t];
							if (c == ' ' || c == cc) {
								c = cc;
							} else {
								c = '.';
							}
						}
						if (c == 'R') {
							red = true;
						}
						if (c == 'B') {
							blue = true;
						}
					}
				}
			}
		}
		if (red) {
			out.println(blue ? "Both" : "Red");
		} else {
			out.println(blue ? "Blue" : "Neither");
		}
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
