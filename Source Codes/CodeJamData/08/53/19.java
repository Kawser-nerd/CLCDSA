import java.io.*;
import java.util.*;

public class Solution implements Runnable {

	private BufferedReader in;
	private StringTokenizer st;
	private PrintWriter out;
	
	private void solve() throws IOException {
		int tests = nextInt();
		for (int test = 0; test < tests; ++test) {
			int n = nextInt();
			int m = nextInt();
			int[] f = new int[n];
			for (int i = 0; i < n; ++i) {
				char[] tmp = next().toCharArray();
				for (int j = 0; j < m; ++j) {
					if (tmp[j] == 'x') {
						f[i] ^= 1 << j;
					}
				}
			}
			int[][] d = new int[n + 1][1 << m];
			d[0][0] = 0;
			for (int i = 0; i < n; ++i) {
				for (int j = 0; j < 1 << m; ++j) {
					for (int k = 0; k < 1 << m; ++k) {
						if (((j | k) & (k << 1)) != 0 || ((j | k) & (k >> 1)) != 0 || (k & f[i]) != 0) {
							continue;
						}
						d[i + 1][k] = Math.max(d[i + 1][k], d[i][j] + Integer.bitCount(k));
					}
				}
			}
			int ans = 0;
			for (int i = 0; i < 1 << m; ++i) {
				ans = Math.max(ans, d[n][i]);
			}
			out.println("Case #" + (test + 1) + ": " + ans);
		}
	}

	public void run() {
		try {
			in = new BufferedReader(new InputStreamReader(System.in));
			st = new StringTokenizer("");
			out = new PrintWriter(System.out);
			
			solve();
			
			out.close();
		} catch (Exception ex) {
			ex.printStackTrace();
			System.exit(-1);
		}
	}
	
	String next() throws IOException {
		while (!st.hasMoreTokens()) {
			String line = in.readLine();
			if (line == null) {
				return null;
			}
			st = new StringTokenizer(line);
		}
		return st.nextToken();
	}
	
	int nextInt() throws IOException {
		return Integer.parseInt(next());
	}
	
	double nextDouble() throws IOException {
		return Double.parseDouble(next());
	}
	
	long nextLong() throws IOException {
		return Long.parseLong(next());
	}
	
	public static void main(String[] args) {
		new Thread(new Solution()).start();
	}

	private void ass(boolean b) {
		if (!b) {
			throw new RuntimeException("Assertion failed");
		}
	}
	
	static final boolean Ъ = true;
}