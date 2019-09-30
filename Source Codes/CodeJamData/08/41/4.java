import java.io.*;
import java.util.*;

public class Solution implements Runnable {

	private BufferedReader in;
	private StringTokenizer st;
	private PrintWriter out;
	
	private void solve() throws IOException {
		int tests = nextInt();
		for (int test = 1; test <= tests; ++test) {
			int n = nextInt();
			int V = nextInt();
			int[] g = new int[n];
			int[] c = new int[n];
			int[] v = new int[n];
			for (int i = 0; i < (n - 1) / 2; ++i) {
				g[i] = nextInt();
				c[i] = nextInt();
			}
			int[][] d = new int[n][2];
			for (int[] ar : d) {
				Arrays.fill(ar, 1000000000);
			}
			for (int i = (n - 1) / 2; i < n; ++i) {
				v[i] = nextInt();
				d[i][v[i]] = 0;
			}
			for (int i = (n - 1) / 2 - 1; i >= 0; --i) {
				if (g[i] == 0 || c[i] == 1) {
					d[i][0] = Math.min(d[i][0], d[i * 2 + 1][0] + d[i * 2 + 2][0] + g[i]);
					d[i][1] = Math.min(d[i][1], Math.min(d[i * 2 + 1][1], d[i * 2 + 2][1]) + g[i]);
				}
				if (g[i] == 1 || c[i] == 1) {
					d[i][0] = Math.min(d[i][0], Math.min(d[i * 2 + 1][0], d[i * 2 + 2][0]) + 1 - g[i]);
					d[i][1] = Math.min(d[i][1], d[i * 2 + 1][1] + d[i * 2 + 2][1] + 1 - g[i]);
				}
			}
			int ans = d[0][V];
			out.println("Case #" + test + ": " + (ans == 1000000000 ? "IMPOSSIBLE" : ans));
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