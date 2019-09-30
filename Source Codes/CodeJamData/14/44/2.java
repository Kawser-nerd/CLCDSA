import static java.lang.Double.parseDouble;
import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.Math.max;
import static java.lang.System.exit;
import static java.util.Arrays.fill;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.StringTokenizer;

public class D {
	
	static BufferedReader in;
	static PrintWriter out;
	static StringTokenizer tok;
	static int test;

	static final int MOD = 1000000007;
	
	static int add(int a, int b) {
		int res = a + b;
		if (res >= MOD) {
			res -= MOD;
		}
		return res;
	}
	
	static int mul(int a, int b) {
		return (int) ((long) a * b % MOD);
	}
	
	static int inv(int a) {
		return BigInteger.valueOf(a).modInverse(BigInteger.valueOf(MOD)).intValue();
	}
	
	static void solve() throws Exception {
//		System.err.println("== TEST " + test + " ==");
		int m = nextInt();
		int n = nextInt();
		int fact[] = new int[n + 1];
		int invFact[] = new int[n + 1];
		fact[0] = 1;
		for (int i = 1; i <= n; i++) {
			fact[i] = mul(fact[i - 1], i);
		}
		invFact[n] = inv(fact[n]);
		for (int i = n; i > 0; i--) {
			invFact[i - 1] = mul(invFact[i], i);
		}
		String s[] = new String[m];
		int totalLength = 0;
		for (int i = 0; i < m; i++) {
			s[i] = next();
			totalLength += s[i].length();
		}
		int nodes = 1;
		int counts[] = new int[totalLength + 1];
		int children[][] = new int[26][totalLength + 1];
		boolean here[] = new boolean[totalLength + 1];
		for (int a[]: children) {
			fill(a, -1);
		}
		for (String ss: s) {
			int curNode = 0;
			++counts[curNode];
			for (int i = 0; i < ss.length(); i++) {
				int c = ss.charAt(i) - 'A';
				int id = children[c][curNode];
				if (id < 0) {
					id = children[c][curNode] = nodes++;
				}
				curNode = id;
				++counts[curNode];
			}
			here[curNode] = true;
		}
		int ans1 = 0;
		int ans2 = 1;
		for (int i = 0; i < nodes; i++) {
			if (counts[i] < n) {
				ans1 += counts[i];
				continue;
			}
			ans1 += n;
			int maxChildSize = 0;
			int curSum = 1;
//			System.err.println("NODE " + counts[i]);
			for (int j = 0; j < 26; j++) {
				int child = children[j][i];
				if (child < 0) {
					continue;
				}
				int childSize = counts[child];
//				System.err.println("CHILD " + childSize);
				if (childSize >= n) {
					maxChildSize = n;
					continue;
				}
				maxChildSize = max(maxChildSize, childSize);
				curSum = mul(curSum, mul(fact[n], invFact[n - childSize]));
			}
			if (here[i]) {
//				System.err.println("SELF");
				maxChildSize = max(maxChildSize, 1);
				curSum = mul(curSum, n);
			}
//			System.err.println("INITMUL " + curSum);
			for (int j = n - 1; j >= maxChildSize; j--) {
				int curMul = (n - j) % 2 == 0 ? 1 : MOD - 1;
				curMul = mul(curMul, mul(mul(fact[n], invFact[j]), invFact[n - j]));
//				System.err.println("C(" + n + ", " + j + ") = " + mul(mul(fact[n], invFact[j]), invFact[n - j]));
				for (int k = 0; k < 26; k++) {
					int child = children[k][i];
					if (child < 0) {
						continue;
					}
					int childSize = counts[child];
					curMul = mul(curMul, mul(fact[j], invFact[j - childSize]));
				}
				if (here[i]) {
					curMul = mul(curMul, j);
				}
				curSum = add(curSum, curMul);
//				System.err.println("ADDING " + mul(curMul, (n - j) % 2 == 0 ? 1 : MOD - 1));
			}
//			System.err.println("MULBY " + curSum);
			ans2 = mul(ans2, curSum);
		}
		printCase();
		out.println(ans1 + " " + ans2);
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