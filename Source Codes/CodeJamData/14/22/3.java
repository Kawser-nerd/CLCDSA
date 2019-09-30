import static java.lang.Double.parseDouble;
import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.Math.max;
import static java.lang.System.exit;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class B {
	
	static BufferedReader in;
	static PrintWriter out;
	static StringTokenizer tok;
	static int test;
	
	static long prefixSolve(int pa, int ba, int pb, int bb, int k) {
		int bMax = max(ba, bb);
		int prefixMask = -1 << bMax;
//		int suffixMask = ~prefixMask;
		int and = pa & pb & prefixMask;
		if (and >= k) {
			return 0;
		}
		if (and < (k & prefixMask)) {
			return 1L << (ba + bb);
		}
		if (bMax == 0) {
			throw new AssertionError();
		}
		if (ba > bb) {
			return prefixSolve(pa, ba - 1, pb, bb, k) +
				prefixSolve(pa | (1 << (ba - 1)), ba - 1, pb, bb, k);
		} else if (bb > ba) {
			return prefixSolve(pa, ba, pb, bb - 1, k) +
				prefixSolve(pa, ba, pb | (1 << (bb - 1)), bb - 1, k);
		} else {
			return prefixSolve(pa, ba - 1, pb, bb - 1, k) +
				prefixSolve(pa | (1 << (ba - 1)), ba - 1, pb, bb - 1, k) +
				prefixSolve(pa, ba - 1, pb | (1 << (bb - 1)), bb - 1, k) +
				prefixSolve(pa | (1 << (ba - 1)), ba - 1, pb | (1 << (bb - 1)), bb - 1, k);
		}
	}
	
	static long solve(int a, int b, int k) {
		long ans = 0;
		int ca = a;
		for (int i = 0; i < 32; i++) {
			if ((ca & (1 << i)) == 0) {
				continue;
			}
			ca &= ~(1 << i);
			int cb = b;
			for (int j = 0; j < 32; j++) {
				if ((cb & (1 << j)) == 0) {
					continue;
				}
				cb &= ~(1 << j);
				ans += prefixSolve(ca, i, cb, j, k);
			}
		}
//		long ansDumb = 0;
//		for (int i = 0; i < a; i++) {
//			for (int j = 0; j < b; j++) {
//				if ((i & j) < k) {
//					++ansDumb;
//				}
//			}
//		}
//		if (ans != ansDumb) {
//			throw new AssertionError();
//		}
		return ans;
	}
	
	static void solve() throws Exception {
		int a = nextInt();
		int b = nextInt();
		int k = nextInt();
		printCase();
		out.println(solve(a, b, k));
	}
	
	static void printCase() {
		out.print("Case #" + test + ": ");
	}
	
	static void printlnCase() {
		out.println("Case #" + test + ":");
	}
	
	static int nextInt() throws IOException {
		return parseInt(next());
	}

	static long nextLong() throws IOException {
		return parseLong(next());
	}

	static double nextDouble() throws IOException {
		return parseDouble(next());
	}

	static String next() throws IOException {
		while (tok == null || !tok.hasMoreTokens()) {
			tok = new StringTokenizer(in.readLine());
		}
		return tok.nextToken();
	}

	public static void main(String[] args) {
		try {
			in = new BufferedReader(new InputStreamReader(System.in));
			out = new PrintWriter(new OutputStreamWriter(System.out));
			int tests = nextInt();
			for (test = 1; test <= tests; test++) {
				solve();
			}
			in.close();
			out.close();
		} catch (Throwable e) {
			e.printStackTrace();
			exit(1);
		}
	}
}