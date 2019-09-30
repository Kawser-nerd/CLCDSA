import static java.lang.Integer.parseInt;

import java.io.*;
import java.math.BigInteger;
import java.util.StringTokenizer;

public class B {
	
	static BufferedReader in;
	static PrintWriter out;
	static StringTokenizer tok;
	
	static void solveTest() throws Exception {
		int n = nextInt();
		int k = nextInt();
		int b = nextInt();
		int t = nextInt();
		int x[] = new int[n];
		for (int i = 0; i < n; i++) {
			x[i] = nextInt();
		}
		int v[] = new int[n];
		for (int i = 0; i < n; i++) {
			v[i] = nextInt();
		}
		int ans = 0;
		while (true) {
			if (k == 0) {
				out.println(ans);
				return;
			}
			if (n == 0) {
				out.println("IMPOSSIBLE");
				return;
			}
			--n;
			if (b - x[n] <= v[n] * t) {
				--k;
			} else {
				ans += k;
			}
		}
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