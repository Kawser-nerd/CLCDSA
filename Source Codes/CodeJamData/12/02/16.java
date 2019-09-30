import java.io.*;
import java.util.*;

public class Solution {


	private StringTokenizer st;
	private BufferedReader in;
	private PrintWriter out;
	
//	final String file = "sample";
	final String file = "B-large";

	public void solve() throws IOException {
		int tests = nextInt();
		for (int test = 0; test < tests; ++test) {
			int n = nextInt();
			int k = nextInt();
			int p = nextInt();
			int[] d = new int[k + 1];
			Arrays.fill(d, -1000000000);
			d[0] = 0;
			for (int i = 0; i < n; ++i) {
				int[] d1 = new int[k + 1];
				int a = nextInt();
				int val0 = -1000000000, val1 = -1000000000;
				for (int u = 0; u <= 10 && 3 * u <= a; ++u) {
					for (int v = u; v <= 10 && v <= u + 2 && u + 2 * v <= a; ++v) {
						int w = a - u - v;
						if (w <= u + 2 && w >= 0 && w <= 10) {
							if (w - u <= 1) {
								val0 = Math.max(val0, w >= p ? 1 : 0);
							} else {
								val1 = Math.max(val1, w >= p ? 1 : 0);
							}
						}
					}
				}
				for (int j = 0; j <= k; ++j) {
					d1[j] = d[j] == -1000000000 ? -1000000000 : d[j] + val0;
				}
				for (int j = 0; j < k; ++j) {
					if (d[j] != -1000000000) {
						d1[j + 1] = Math.max(d1[j + 1], d[j] + val1);
					}
				}
				d = d1;
			}
			out.printf("Case #%d: %d%n", test + 1, d[k]);
		}
	}

	public void run() throws IOException {
		in = new BufferedReader(new FileReader(file + ".in"));
		out = new PrintWriter(file + ".out");
		eat("");
		
		solve();
		
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