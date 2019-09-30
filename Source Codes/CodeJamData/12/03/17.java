import java.io.*;
import java.util.*;

public class Solution {


	private StringTokenizer st;
	private BufferedReader in;
	private PrintWriter out;
	
	final String file = "C-large";

	public void solve() throws IOException {
		int tests = nextInt();
		int[] pows10 = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000};
		for (int test = 0; test < tests; ++test) {
			int a = nextInt();
			int b = nextInt();
			int[] o = new int[6];
			int pow10 = 0;
			int ans = 0;
			for (int i = a; i <= b; ++i) {
				int c = 0;
				while (pows10[pow10] <= i) {
					++pow10;
				}
				for (int sh = 1; sh < pow10; ++sh) {
					int val = i / pows10[sh] + (i % pows10[sh]) * pows10[pow10 - sh];
					if (i < val && val <= b) {
						o[c++] = val;
					}
				}
				Arrays.sort(o, 0, c);
				for (int j = 0; j < c; ++j) {
					if (j == 0 || o[j] != o[j - 1]) {
						ans++;
					}
				}
			}
			out.printf("Case #%d: %d%n", test + 1, ans);
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