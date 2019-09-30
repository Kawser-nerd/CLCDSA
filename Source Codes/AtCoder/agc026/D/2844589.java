import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.Math.min;
import static java.lang.System.exit;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class Main {

	static final int MOD = 1000000007;

	static int add(int a, int b) {
		int res = a + b;
		return res >= MOD ? res - MOD : res;
	}

	static int sub(int a, int b) {
		int res = a - b;
		return res < 0 ? res + MOD : res;
	}

	static int mul(int a, int b) {
		int res = (int) ((long) a * b % MOD);
		return res < 0 ? res + MOD : res;
	}

	static int pow(int a, int e) {
		if (e == 0) {
			return 1;
		}
		int r = a;
		for (int i = 30 - Integer.numberOfLeadingZeros(e); i >= 0; i--) {
			r = mul(r, r);
			if ((e & (1 << i)) != 0) {
				r = mul(r, a);
			}
		}
		return r;
	}

	static int h[];

	static void solve() throws Exception {
		int n = scanInt();
		h = new int[n];
		for (int i = 0; i < n; i++) {
			h[i] = scanInt();
		}
		out.print(solve(0, n, 0));
	}

	static int resAlt;
	static int solve(int from, int to, int level) {
		int nextLevel = Integer.MAX_VALUE;
		for (int i = from; i < to; i++) {
			nextLevel = min(nextLevel, h[i]);
		}
		int rTotal = 1, rAlt = 2;
		for (int i = from, j; i < to;) {
			if (h[i] == nextLevel) {
				rTotal = add(rTotal, rTotal);
				++i;
				continue;
			}
			for (j = i + 1; j < to && h[j] != nextLevel; j++) { }
			int curTotal = solve(i, j, nextLevel);
			int curAlt = resAlt;
			rTotal = mul(rTotal, add(curTotal, curAlt));
			rAlt = mul(rAlt, curAlt);
			i = j;
		}
		rTotal = sub(rTotal, rAlt);
		rAlt = mul(rAlt, pow(2, nextLevel - level - 1));
		rTotal = add(rTotal, rAlt);
		resAlt = rAlt;
		return rTotal;
	}

	static int scanInt() throws IOException {
		return parseInt(scanString());
	}

	static long scanLong() throws IOException {
		return parseLong(scanString());
	}

	static String scanString() throws IOException {
		while (tok == null || !tok.hasMoreTokens()) {
			tok = new StringTokenizer(in.readLine());
		}
		return tok.nextToken();
	}

	static BufferedReader in;
	static PrintWriter out;
	static StringTokenizer tok;

	public static void main(String[] args) {
		try {
			in = new BufferedReader(new InputStreamReader(System.in));
			out = new PrintWriter(System.out);
			solve();
			in.close();
			out.close();
		} catch (Throwable e) {
			e.printStackTrace();
			exit(1);
		}
	}
}