import static java.lang.Double.parseDouble;
import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.System.exit;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.StringTokenizer;

public class B {

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

	static int sub(int a, int b) {
		int res = a - b;
		if (res < 0) {
			res += MOD;
		}
		return res;
	}

	static int mul(int a, int b) {
		return (int) ((long) a * b % MOD);
	}

	static int inv(int a) {
		return BigInteger.valueOf(a).modInverse(BigInteger.valueOf(MOD)).intValue();
	}

	static final int ans1Num[] = new int[10000001];
	static final int ans1Den[] = new int[10000001];
	static {
		ans1Den[0] = ans1Den[1] = 1;
		int sumNum = 0, sumDen = 1;
		for (int i = 2; i < ans1Num.length; i++) {
			ans1Num[i] = add(sumNum, sumDen);
			ans1Den[i] = mul(sumDen, i - 1);
			sumNum = add(mul(sumNum, ans1Den[i - 1]), mul(sumDen, ans1Num[i - 1]));
			sumDen = mul(ans1Den[i - 1], sumDen);
		}
	}

	static void solve() throws Exception {
		int n = nextInt();
		int k = nextInt() - 1;
		int ansNum = mul(sub(ans1Den[k + 1], ans1Num[k + 1]), sub(ans1Den[n - k], ans1Num[n - k]));
		int ansDen = mul(ans1Den[k + 1], ans1Den[n - k]);
		int ans = mul(sub(ansDen, ansNum), inv(ansDen));
		printCase();
		out.println(ans);
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