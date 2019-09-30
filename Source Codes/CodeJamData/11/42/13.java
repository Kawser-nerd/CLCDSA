import java.io.*;
import java.util.*;

public class Solution implements Runnable {


	private StringTokenizer st;
	private BufferedReader in;
	private PrintWriter out;
	
	final String file = "B-large";

	public void solve(int test) throws IOException {
		out.print("Case #" + (test + 1) + ": ");
		int n = nextInt();
		int m = nextInt();
		nextInt();
		int[][] a = new int[n][m];
		for (int i = 0; i < n; ++i) {
			char[] tmp = next().toCharArray();
			for (int j = 0; j < m; ++j) {
				a[i][j] = tmp[j] - '0';
			}
		}
		int[][] sum = new int[n + 1][m + 1];
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				sum[i + 1][j + 1] = sum[i + 1][j] + sum[i][j + 1] - sum[i][j] + a[i][j];
			}
		}
		int[][] sumi = new int[n + 1][m + 1];
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				sumi[i + 1][j + 1] = sumi[i + 1][j] + sumi[i][j + 1] - sumi[i][j] + a[i][j] * i;
			}
		}
		int[][] sumj = new int[n + 1][m + 1];
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				sumj[i + 1][j + 1] = sumj[i + 1][j] + sumj[i][j + 1] - sumj[i][j] + a[i][j] * j;
			}
		}
		int ans = 0;
		loop: for (int d = 3; d <= n && d <= m; ++d) {
			for (int i = 0; i + d <= n; ++i) {
				for (int j = 0; j + d <= m; ++j) {
					int s = sum[i + d][j + d] - sum[i + d][j] - sum[i][j + d] + sum[i][j];
					int si = sumi[i + d][j + d] - sumi[i + d][j] - sumi[i][j + d] + sumi[i][j];
					int sj = sumj[i + d][j + d] - sumj[i + d][j] - sumj[i][j + d] + sumj[i][j];
					s -= a[i][j] + a[i + d - 1][j] + a[i][j + d - 1] + a[i + d - 1][j + d - 1];
					si -= a[i][j] * i + a[i + d - 1][j] * (i + d - 1) + a[i][j + d - 1] * i + a[i + d - 1][j + d - 1] * (i + d - 1);
					sj -= a[i][j] * j + a[i + d - 1][j] * j + a[i][j + d - 1] * (j + d - 1) + a[i + d - 1][j + d - 1] * (j + d - 1);
					if (2 * si == s * (2 * i + d - 1) && 2 * sj == s * (2 * j + d - 1)) {
						System.err.println(d + " " + i + " " + j);
						ans = d;
						continue loop;
					}
				}
			}
		}
		System.err.println();
		out.println(ans == 0 ? "IMPOSSIBLE" : ans);
	}

	public void run() {
		try {
			in = new BufferedReader(new FileReader(file + ".in"));
			out = new PrintWriter(file + ".out");
			eat("");
			
			int tests = nextInt();
			for (int test = 0; test < tests; ++test) {
				solve(test);
			}
			
			out.close();
		} catch (Exception e) {
			e.printStackTrace();
			failed = true;
		}
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
	
	static boolean failed = false;
	
	public static void main(String[] args) {
		Locale.setDefault(Locale.US);
		Thread th = new Thread(new Solution());
		th.start();
		try {
			th.join();
		} catch (InterruptedException iex) {
		}
		if (failed) {
			throw new RuntimeException();
		}
	}
	
}
