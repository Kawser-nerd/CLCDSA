import static java.lang.Integer.parseInt;
import static java.lang.Math.max;

import java.io.*;
import java.math.BigInteger;
import java.util.StringTokenizer;

public class C {
	
	static BufferedReader in;
	static PrintWriter out;
	static StringTokenizer tok;
	
	static final int MOD = 100003;
	
	static final int c[][] = new int[500][];
	
	static {
		for (int i = 0; i < c.length; i++) {
			int cc[] = new int[i + 1];
			cc[0] = 1;
			if (i > 0) {
				int pcc[] = c[i - 1];
				for (int j = 1; j < i; j++) {
					cc[j] = (pcc[j - 1] + pcc[j]) % MOD;
				}
				cc[i] = 1;
			}
			c[i] = cc;
		}
	}
	
	static final int ans[][] = new int[501][];
	
	static {
		for (int max = 2; max < ans.length; max++) {
			int cans[] = new int[max];
			cans[1] = 1;
			for (int cnt = 2; cnt < max; cnt++) {
				int pans[] = ans[cnt];
				for (int pcnt = max(1, 2 * cnt - max); pcnt < cnt; pcnt++) {
					cans[cnt] = (cans[cnt] + (int) (
						(long) pans[pcnt] * c[max - cnt - 1][cnt - pcnt - 1] % MOD
					)) % MOD;
				}
			}
			ans[max] = cans;
		}
	}
	
	static void solveTest() throws Exception {
		int n = nextInt();
		int theans = 0;
		for (int k = 1; k < n; k++) {
			theans = (theans + ans[n][k]) % MOD;
		}
		out.println(theans);
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