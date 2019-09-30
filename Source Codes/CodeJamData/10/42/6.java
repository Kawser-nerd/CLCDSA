import static java.lang.Integer.parseInt;
import static java.lang.Math.min;

import java.io.*;
import java.math.BigInteger;
import java.util.StringTokenizer;

public class B {
	
	static BufferedReader in;
	static PrintWriter out;
	static StringTokenizer tok;
	
	static void solveTest() throws Exception {
		int p = nextInt();
		int n = 1 << p;
		int s[] = new int[n];
		for (int i = 0; i < n; i++) {
			s[i] = p - nextInt();
		}
		int price[] = new int[n];
		for (int i = p - 1; i >= 0; i--) {
			for (int j = 0; j < 1 << i; j++) {
				price[(1 << i) + j] = nextInt();
			}
		}
		// First index: number of matches seen
		// Second index: ID
		int cur[][] = new int[p + 1][n];
		for (int i = 0; i <= p; i++) {
			for (int j = 0; j < n; j++) {
				cur[i][j] = (i >= s[j]) ? 0 : Integer.MAX_VALUE;
			}
		}
		for (int level = p - 1; level >= 0; --level) {
			int next[][] = new int[level + 1][1 << level];
			for (int i = 0; i <= level; i++) {
				for (int j = 0; j < 1 << level; j++) {
					next[i][j] = trim(min(
						(long) cur[i][j << 1] + cur[i][(j << 1) + 1],
						(long) cur[i + 1][j << 1] + cur[i + 1][(j << 1) + 1] + price[(1 << level) + j]
					));
				}
			}
			cur = next;
		}
		out.println(cur[0][0]);
	}
	
	private static int trim(long val) {
		return (int) min(val, Integer.MAX_VALUE);
	}

	static void solve() throws Exception {
		int tests = nextInt();
		for (int test = 1; test <= tests; test++) {
			out.print("Case #" + test + ": ");
			solveTest();
		}
	}

	public static void main(String[] args) throws Exception {
		System.out.print("Enter filename: ");
		System.out.flush();
		String filename = new BufferedReader(new InputStreamReader(System.in)).readLine();
		in = new BufferedReader(new InputStreamReader(
			new FileInputStream(new File(filename + ".in"))));
		out = new PrintWriter(new BufferedWriter(new OutputStreamWriter(
			new FileOutputStream(new File(filename + ".out")))));
		solve();
		in.close();
		out.close();
	}
	
	static String next() throws IOException {
		while (tok == null || !tok.hasMoreTokens()) {
			tok = new StringTokenizer(in.readLine());
		}
		return tok.nextToken();
	}
	
	static int nextInt() throws IOException {
		return parseInt(next());
	}
	
	static BigInteger nextBigInt() throws IOException {
		return new BigInteger(next());
	}
}