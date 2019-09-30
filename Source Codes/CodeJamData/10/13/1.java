import java.io.*;
import java.util.*;

public class Solution {
	
	final String f = "C-large";
	
	private BufferedReader in;
	private PrintWriter out;
	private StringTokenizer st;

	void solve() throws IOException {
		int a1 = nextInt();
		int a2 = nextInt();
		int b1 = nextInt();
		int b2 = nextInt();
		long ans = 0;
		double phi = (Math.sqrt(5.) + 1.) / 2.;
		for (int t = 1; t <= 1000000; ++t) {
			if (a1 <= t && t <= a2) {
				ans += Math.max(0, b2 - Math.max(b1, (int)(phi * t) + 1) + 1);
			}
			if (b1 <= t && t <= b2) {
				ans += Math.max(0, a2 - Math.max(a1, (int)(phi * t) + 1) + 1);
			}
		}
		out.println(ans);
//		for (int i = 1; i <= 30; ++i) {
//			for (int j = 2 * i; j <= 30; ++j) {
//				int f1 = i, f2 = j;
//				while (f2 <= 20) {
//					System.out.println(f1 + " " + f2);
//					int nf1 = f1 + f2;
//					int nf2 = nf1 + f2;
//					f1 = nf1;
//					f2 = nf2;
//				}
//			}
//		}
//		System.out.println(set);
//		ans = set.size();
//		out.println((long)(a2 - a1 + 1) * (b2 - b1 + 1) - ans);
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
