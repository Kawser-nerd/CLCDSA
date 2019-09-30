import static java.lang.Double.parseDouble;
import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.Math.min;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.HashMap;
import java.util.Locale;
import java.util.Map;
import java.util.Set;
import java.util.StringTokenizer;

public class C {
	
	static BufferedReader in;
	static PrintWriter out;
	static StringTokenizer tok;
	
	static class Res {
		
		final int cnt1, cnt2, cnt3;

		public Res(int cnt1, int cnt2, int cnt3) {
			super();
			this.cnt1 = cnt1;
			this.cnt2 = cnt2;
			this.cnt3 = cnt3;
		}

		@Override
		public int hashCode() {
			final int prime = 31;
			int result = 1;
			result = prime * result + cnt1;
			result = prime * result + cnt2;
			result = prime * result + cnt3;
			return result;
		}

		@Override
		public boolean equals(Object obj) {
			if (this == obj)
				return true;
			if (obj == null)
				return false;
			if (getClass() != obj.getClass())
				return false;
			Res other = (Res) obj;
			if (cnt1 != other.cnt1)
				return false;
			if (cnt2 != other.cnt2)
				return false;
			if (cnt3 != other.cnt3)
				return false;
			return true;
		}
		
		
	}
	
	static Map<Res, Boolean> cache[] = new Map[21];
	static {
		for (int i = 0; i < cache.length; i++) {
			cache[i] = new HashMap<C.Res, Boolean>();
		}
	}
	
	static void solveTest() throws Exception {
		int k = nextInt();
		int c = nextInt();
		if (c == 1) {
			out.println(k);
			return;
		}
		if (c == 2) {
			out.println(k + (k + 1) / 2);
			return;
		}
		if (c != 3) {
			throw new AssertionError();
		}
		int ans = Integer.MAX_VALUE;
		for (int cnt1 = 0; cnt1 <= k; cnt1++) {
			for (int cnt2 = 0; cnt2 <= k; cnt2++) {
				for (int cnt3 = 0; cnt3 <= k; cnt3++) {
					if (good(k, cnt1, cnt2, cnt3)) {
						ans = min(ans, cnt1 + cnt2 + cnt3);
					}
				}
			}
		}
		out.println(ans);
	}
	
	static boolean good(int k, int cnt1, int cnt2, int cnt3) {
		Res res = new Res(cnt1, cnt2, cnt3);
		if (cache[k].containsKey(res)) {
			return cache[k].get(res);
		}
		boolean ans = doGood(k, cnt1, cnt2, cnt3);
		cache[k].put(res, ans);
		return ans;
	}
	
	static boolean doGood(int k, int cnt1, int cnt2, int cnt3) {
		if (k <= 0) {
			return true;
		}
		if (cnt1 < 1 || !good(k - 1, cnt1 - 1, cnt2, cnt3)) {
			return false;
		}
		if ((cnt2 < 1 || !good(k - 1, cnt1, cnt2 - 1, cnt3)) &&
			(cnt1 < 2 || !good(k - 1, cnt1 - 2, cnt2, cnt3))) {
			return false;
		}
		if ((cnt3 < 1 || !good(k - 1, cnt1, cnt2, cnt3 - 1)) &&
			(cnt2 < 1 || cnt1 < 1 || !good(k - 1, cnt1 - 1, cnt2 - 1, cnt3)) &&
			(cnt1 < 3 || !good(k - 1, cnt1 - 3, cnt2, cnt3))) {
			return false;
		}
		return true;
	}

	static void solve() throws Exception {
		int tests = nextInt();
		for (int test = 1; test <= tests; test++) {
			out.print("Case #" + test + ": ");
			solveTest();
			System.out.print('.');
		}
	}

	public static void main(String[] args) throws Exception {
		Locale.setDefault(Locale.US);
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
	
	static long nextLong() throws IOException {
		return parseLong(next());
	}
	
	static double nextDouble() throws IOException {
		return parseDouble(next());
	}
	
	static BigInteger nextBigInt() throws IOException {
		return new BigInteger(next());
	}
}