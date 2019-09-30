import java.util.*;
import java.io.*;

public class Solution {

	final String filename = "D-small-attempt1";
	private BufferedReader in;
	private PrintWriter out;
	private StringTokenizer st;

	private void solve(int test) throws IOException {
		out.print("Case #" + test + ": ");
		int n = nextInt();
		int[] x = new int[n];
		int[] y = new int[n];
		int[] r = new int[n];
		int[] s = new int[n];
		for (int i = 0; i < n; ++i) {
			x[i] = nextInt();
			y[i] = nextInt();
			r[i] = nextInt();
			s[i] = nextInt();
		}
		boolean[][] g = new boolean[n][n];
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				int d = (x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]);
				if (d <= r[i] * r[i]) {
					g[i][j] = true;
				}
			}
		}
		for (int k = 0; k < n; ++k) {
			for (int i = 0; i < n; ++i) {
				for (int j = 0; j < n; ++j) {
					g[i][j] |= g[i][k] & g[k][j];
				}
			}
		}
		int totalAns = 0;
		int ans = 0;
		boolean[] col = new boolean[n];
		for (int i = 0; i < n; ++i) {
			int best = -1, bestVal = -1000000000;
			for (int j = 0; j < n; ++j) {
				if (col[j]) {
					continue;
				}
				int val = 0;
				for (int k = 0; k < n; ++k) {
					if (g[j][k] && !col[k]) {
						val += s[k];
					}
				}
				if (val > bestVal) {
					bestVal = val;
					best = j;
				}
			}
			if (best != -1) {
				ans += bestVal;
				for (int k = 0; k < n; ++k) {
					col[k] |= g[best][k];
				}
			}
			totalAns = Math.max(totalAns, ans);
		}
		loop: for (int i = 0; i < 1 << n; ++i) {
			int val = 0;
			for (int j = 0; j < n; ++j) {
				if ((i & (1 << j)) == 0) {
					continue;
				}
				val += s[j];
				for (int k = 0; k < n; ++k) {
					if (g[j][k] && (i & (1 << k)) == 0) {
						continue loop;
					}
				}
			}
			if (totalAns < val) {
				totalAns = Math.max(totalAns, val);
			}
		}
		out.println(totalAns);
	}
	
	Solution() {
		try {
			in = new BufferedReader(new FileReader(filename + ".in"));
			out = new PrintWriter(filename + ".out");
			eat("");
			
			int tests = nextInt();
			for (int test = 1; test <= tests; ++test) {
				solve(test);
			}
			
			in.close();
			out.close();
		} catch (Exception ex) {
			ex.printStackTrace();
			System.exit(-1);
		}
	}
	
	private void eat(String string) {
		st = new StringTokenizer(string);
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

	public static void main(String[] args) {
		new Solution();
	}
	
}
