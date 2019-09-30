import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.Math.min;
import static java.util.Arrays.sort;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.StringTokenizer;

public class B {
	
	static BufferedReader in;
	static PrintWriter out;
	static StringTokenizer tok;
	
	static void solveTest() throws Exception {
		int n = nextInt();
		int a[] = new int[n];
		for (int i = 0; i < n; i++) {
			a[i] = nextInt();
		}
		sort(a);
		int i, j;
		List<Integer> lens = new ArrayList<Integer>();
		int prev = Integer.MIN_VALUE;
		int ans = Integer.MAX_VALUE;
		for (i = 0; i < n; i = j) {
			for (j = i + 1; j < n && a[i] == a[j]; j++) { }
//			System.err.println(i + " " + j + " " + a[i]);
			if (a[i] > prev + 1) {
				for (int len: lens) {
					ans = min(len, ans);
				}
				lens.clear();
			}
			int ccnt = j - i;
			if (ccnt > lens.size()) {
				for (int x = 0; x < lens.size(); x++) {
					lens.set(x, lens.get(x) + 1);
				}
				for (int x = lens.size(); x < ccnt; x++) {
					lens.add(1);
				}
			} else {
				Collections.sort(lens);
				for (int x = ccnt; x < lens.size(); x++) {
					ans = min(lens.get(x), ans);
				}
				lens.subList(ccnt, lens.size()).clear();
				for (int x = 0; x < lens.size(); x++) {
					lens.set(x, lens.get(x) + 1);
				}
			}
			prev = a[i];
//			System.err.println(lens + " " + ans);
		}
		for (int len: lens) {
			ans = min(len, ans);
		}
		if (ans == Integer.MAX_VALUE) {
			ans = 0;
		}
		out.println(ans);
	}
	
	static void solve() throws Exception {
		int tests = nextInt();
		for (int test = 1; test <= tests; test++) {
			out.print("Case #" + test + ": ");
			solveTest();
		}
	}

	public static void main(String[] args) throws Exception {
		in = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
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
	
	static char nextChar() throws IOException {
		String token = next();
		if (token.length() != 1) {
			throw new IllegalArgumentException("String \"" + token + "\" is not a single character");
		}
		return token.charAt(0);
	}
	
	static int nextInt() throws IOException {
		return parseInt(next());
	}
	
	static long nextLong() throws IOException {
		return parseLong(next());
	}
	
	static BigInteger nextBigInt() throws IOException {
		return new BigInteger(next());
	}
}