import java.io.*;
import java.util.*;

public class Solution {
	
	final String f = "A-large";
	
	private BufferedReader in;
	private PrintWriter out;
	private StringTokenizer st;

	void solve() throws IOException {
		int n = nextInt();
		int[][] a = new int[n][n];
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j <= i; ++j) {
				a[i - j][j] = nextInt();
			}
		}
		for (int i = n; i < 2 * n - 1; ++i) {
			for (int j = 0; j < 2 * n - i - 1; ++j) {
				a[n - 1 - j][i - n + j + 1] = nextInt();
			}
		}
		final int inf = 1000000000;
		int ans = inf;
		for (int a1 = -n * 2; a1 <= n * 2; ++a1) {
			loop: for (int a2 = -n * 2; a2 <= n * 2; ++a2) {
				for (int i = 0; i < n; ++i) {
					for (int j = 0; j < n; ++j) {
						int x =  a1 + j;
						int y = -a1 + i;
						if (0 <= x && x < n && 0 <= y && y < n && a[i][j] != a[x][y]) {
							continue loop;
						}
						x = a2 - j;
						y = a2 - i;
						if (0 <= x && x < n && 0 <= y && y < n && a[i][j] != a[x][y]) {
							continue loop;
						}
					}
				}
				int k = (a1 + a2) % 2 == 0 ? 1 : 2;
				int t = (k + 1) % 2;
				int minx = (a1 + a2 - t) / 2, maxx = (a1 + a2 + t) / 2;
				int miny = (-a1 + a2 - t) / 2, maxy = (-a1 + a2 + t) / 2;
				while (minx > 0 || maxx < n - 1 || miny > 0 || maxy < n - 1) {
					k += 2;
					minx--; maxx++;
					miny--; maxy++;
				}
				ans = Math.min(ans, k * k - n * n);
			}
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
