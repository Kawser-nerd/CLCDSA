import java.io.*;
import java.util.*;

public class Solution {
	
	final String f = "B-large";
	
	private BufferedReader in;
	private PrintWriter out;
	private StringTokenizer st;

	void solve() throws IOException {
		int D = nextInt();
		int I = nextInt();
		int m = nextInt();
		int n = nextInt();
		int[] a = new int[n];
		for (int i = 0; i < n; ++i) {
			a[i] = nextInt();
		}
		int[] d = new int[256];
		for (int i = 0; i < n; ++i) {
			int[] t = new int[256];
			Arrays.fill(t, Integer.MAX_VALUE);
			for (int u = 0; u < 256; ++u) {
				t[u] = Math.min(t[u], d[u] + D);
				for (int v = 0; v < 256; ++v) {
					if (Math.abs(u - v) <= m) {
						t[v] = Math.min(t[v], d[u] + Math.abs(v - a[i]));
					}
				}
			}
			if (m != 0) {
				for (int u = 0; u < 256; ++u) {
					for (int v = 0; v < 256; ++v) {
						t[v] = Math.min(t[v], t[u] + ((Math.abs(u - v) + m - 1) / m) * I);
					}
				}
			}
			d = t;
		}
		int ans = Integer.MAX_VALUE;
		for (int u = 0; u < 256; ++u) {
			ans = Math.min(ans, d[u]);
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
