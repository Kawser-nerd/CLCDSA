import static java.lang.Double.parseDouble;
import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.Math.max;
import static java.lang.System.arraycopy;

import java.io.*;
import java.math.BigInteger;
import java.util.HashMap;
import java.util.Locale;
import java.util.Map;
import java.util.StringTokenizer;

public class D {
	
	static BufferedReader in;
	static PrintWriter out;
	static StringTokenizer tok;
	
	static final int MOD = 1000000007;
	
	static int mul(int a, int b) {
		return (int) (((long) a * b) % MOD);
	}
	
	static int add(int a, int b) {
		int res = a + b;
		if (res > MOD) {
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
	
	static int inv(int a) {
		return BigInteger.valueOf(a).modInverse(BigInteger.valueOf(MOD)).intValue();
	}
	
	static int facts[] = new int[] {1};
	static int fact(int n) {
		if (n >= facts.length) {
			int nlength = Integer.highestOneBit(max(n, 15)) << 1;
			int narr[] = new int[nlength];
			arraycopy(facts, 0, narr, 0, facts.length);
			for (int i = facts.length; i < narr.length; i++) {
				narr[i] = mul(narr[i - 1], i);
			}
			facts = narr;
		}
		return facts[n];
	}
	
	static final int sumsWithZero[][][];
	static {
		int b = 70;
		// [num of summands][all summands less than this][sum]
		sumsWithZero = new int[b + 1][b + 1][];
		for (int i = 0; i <= b; i++) {
			sumsWithZero[0][i] = new int[] {1};
		}
		for (int nsum = 1; nsum <= b; nsum++) {
			sumsWithZero[nsum][0] = new int[0];
			for (int lim = 1; lim <= b; lim++) {
				int prev1[] = sumsWithZero[nsum][lim - 1];
				int prev2[] = sumsWithZero[nsum - 1][lim - 1];
				int cur[] = new int[max(prev1.length, prev2.length + lim - 1)];
				for (int i = 0; i < cur.length; i++) {
					if (i < prev1.length) {
						cur[i] = add(cur[i], prev1[i]);
					}
					if (i >= lim - 1 && i < prev2.length + lim - 1) {
						cur[i] = add(cur[i], prev2[i - lim + 1]);
					}
				}
				sumsWithZero[nsum][lim] = cur;
			}
		}
	}

	static final int sumsWithoutZero[][][];
	static {
		int b = 70;
		// [num of summands][all summands less than this][sum]
		sumsWithoutZero = new int[b + 1][b + 1][];
		for (int i = 0; i <= b; i++) {
			sumsWithoutZero[0][i] = new int[] {1};
		}
		for (int nsum = 1; nsum <= b; nsum++) {
			sumsWithoutZero[nsum][0] = new int[0];
			sumsWithoutZero[nsum][1] = new int[0];
			for (int lim = 2; lim <= b; lim++) {
				int prev1[] = sumsWithoutZero[nsum][lim - 1];
				int prev2[] = sumsWithoutZero[nsum - 1][lim - 1];
				int cur[] = new int[max(prev1.length, prev2.length + lim - 1)];
				for (int i = 0; i < cur.length; i++) {
					if (i < prev1.length) {
						cur[i] = add(cur[i], prev1[i]);
					}
					if (i >= lim - 1 && i < prev2.length + lim - 1) {
						cur[i] = add(cur[i], prev2[i - lim + 1]);
					}
				}
				sumsWithoutZero[nsum][lim] = cur;
			}
		}
	}
	
	static {
		int b = 70;
		for (int i = 0; i <= b; i++) {
			for (int j = 0; j <= b; j++) {
				int arr1[] = sumsWithZero[i][j];
				int arr2[] = sumsWithoutZero[i][j];
				for (int k = 0; k < arr2.length; k++) {
					arr1[k] = sub(arr1[k], arr2[k]);
				}
			}
		}
	}

	static class Request {
		final long num;
		final int sums;
		
		public Request(long num, int sums) {
			this.num = num;
			this.sums = sums;
		}
		
		public boolean equals(Object o) {
			Request r = (Request) o;
			return num == r.num && sums == r.sums;
		}
		
		public int hashCode() {
			return (int) num + (int) (num >> 32) * 31 + sums * 1000000009;
		}
	}
	
	static int b;
	
	static int doQuery(long num, int sums) {
		if (num < 0) {
			return 0;
		}
		if (num == 0) {
			return sums == 0 ? 1 : 0;
		}
		int ans = 0;
		int arr1[] = sumsWithZero[sums][b];
		int arr2[] = sumsWithoutZero[sums][b];
		int dig = (int) (num % b);
		num /= b;
		for (; dig < arr1.length; dig += b, --num) {
			int cnt1 = arr1[dig];
//			System.out.println("WITH ZERO: Summands: " + sums + ", sum: " + dig + ", res: " + cnt1);
			if (cnt1 > 0) {
				for (int nsums = 1; nsums <= sums; ++nsums) {
					int nans = query(num, nsums);
					ans = add(ans, mul(mul(nans, cnt1), mul(mul(nsums, fact(sums - 1)), inv(fact(sums - nsums)))));
				}
			}
			if (dig < arr2.length) {
				int cnt2 = arr2[dig];
//				System.out.println("WITHOUT ZERO: Summands: " + sums + ", sum: " + dig + ", res: " + cnt2);
				if (cnt2 > 0) {
					for (int nsums = 0; nsums <= sums; ++nsums) {
						int nans = query(num, nsums);
						ans = add(ans, mul(mul(nans, cnt2), mul(fact(sums), inv(fact(sums - nsums)))));
					}
				}
			}
		}
		return ans;
	}
	
	static Map<Request, Integer> res;
	
	static int query(long num, int sums) {
		Request req = new Request(num, sums);
		if (res.containsKey(req)) {
			return res.get(req);
		}
		int ans = doQuery(num, sums);
		res.put(req, ans);
		return ans;
	}
	
	static void solveTest() throws Exception {
//		System.out.println("New test");
		long n = nextLong();
		b = nextInt();
		res = new HashMap<Request, Integer>();
		int ans = 0;
		for (int sums = 1; sums <= b; ++sums) {
			ans = add(ans, query(n, sums));
//			System.out.println("With " + sums + " summands: " + query(n, sums));
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