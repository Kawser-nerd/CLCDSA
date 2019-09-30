import java.util.*;
import java.io.*;
import java.math.BigInteger;

public class Solution {

	final String filename = "A-large";
	private BufferedReader in;
	private PrintWriter out;
	private StringTokenizer st;
	private BigInteger N;

	static class Fraction {
		BigInteger a, b;

		Fraction(BigInteger a, BigInteger b) {
			BigInteger g = a.gcd(b);
			this.a = a.divide(g);
			this.b = b.divide(g);
		}

		Fraction mul(Fraction v) {
			return new Fraction(a.multiply(v.a), b.multiply(v.b));
		}

		Fraction div(Fraction v) {
			return new Fraction(a.multiply(v.b), b.multiply(v.a));
		}

		Fraction add(Fraction v) {
			return new Fraction(a.multiply(v.b).add(v.a.multiply(b)), b
					.multiply(v.b));
		}

		Fraction sub(Fraction v) {
			return new Fraction(a.multiply(v.b).subtract(v.a.multiply(b)), b
					.multiply(v.b));
		}

		public String toString() {
			return a.divide(b) + "+" + a.mod(b) + "/" + b;
		}

		static Fraction valueOf(long a) {
			return valueOf(a, 1);
		}

		static Fraction valueOf(long a, long b) {
			return new Fraction(BigInteger.valueOf(a), BigInteger.valueOf(b));
		}
	}
	
	Random rnd = new Random();

	private void solve(int test) throws IOException {
		System.out.println("Test: " + test);
		out.print("Case #" + test + ": ");
		int n = nextInt();
		int m = nextInt();
//		int n = 1000000000;
//		int m = 50;
		int[][] days = new int[m][];
		for (int i = 0; i < m; ++i) {
			int t = nextInt();
//			int t = 50;
			days[i] = new int[t];
			for (int j = 1; j < t; ++j) {
				days[i][j] = nextInt() - 1;
//				days[i][j] = j;
			}
		}
		N = BigInteger.valueOf(n);
		Fraction ans = Fraction.valueOf(0);
		ArrayList<Integer> ds = new ArrayList<Integer>();
		ds.add(n);
		for (int i = 0; i < m; ++i) {
			for (int j : days[i]) {
				if (j < n) {
					ds.add(j);
				}
			}
		}
		Collections.sort(ds);
		for (int it = 0; it < ds.size() - 1; ++it) {
			int i = ds.get(it);
			int len = ds.get(it + 1) - i;
			if (len == 0) {
				continue;
			}
//			System.out.println("it: " + i);
			int[] prob = new int[m];
			for (int j = 0; j < m; ++j) {
				for (int k = 0; k < days[j].length; ++k) {
					if (days[j][k] <= i) {
						prob[j]++;
					}
				}
			}
			Fraction a = solve(prob);
//			System.out.println(Arrays.toString(prob) + " " + a + " " + len + " " + i);
			ans = ans.add(a.mul(Fraction.valueOf(len)));
		}
//		System.out.println();
		ans = new Fraction(ans.a, N.pow(m));
		out.println(ans);
	}

	private Fraction solve(int[] prob) {
		int n = prob.length;
		BigInteger[] d = new BigInteger[n + 1];
		Arrays.fill(d, BigInteger.ZERO);
		d[0] = BigInteger.ONE;
		for (int i = 0; i < n; ++i) {
			BigInteger p = BigInteger.valueOf(prob[i]);
			for (int j = n; j >= 0; --j) {
				BigInteger val = d[j].multiply(N.subtract(p));
				if (j > 0) {
					val = val.add(d[j - 1].multiply(p));
				}
				d[j] = val;
			}
		}
		BigInteger ret = BigInteger.ZERO;
		for (int i = 0; i <= n; ++i) {
			ret = ret.add(BigInteger.valueOf(i * i).multiply(d[i]));
		}
		return new Fraction(ret, BigInteger.ONE);
	}

	Solution() {
		try {
			in = new BufferedReader(new FileReader(filename + ".in"));
			out = new PrintWriter(filename + ".out");
			eat("");

			int tests = nextInt();
			for (int test = 1; test <= tests; ++test) {
				solve(test);
			}

			in.close();
			out.close();
		} catch (Exception ex) {
			ex.printStackTrace();
			System.exit(-1);
		}
	}

	private void eat(String string) {
		st = new StringTokenizer(string);
	}

	String next() throws IOException {
		while (!st.hasMoreTokens()) {
			String line = in.readLine();
			if (line == null) {
				return null;
			}
			eat(line);
		}
		return st.nextToken();
	}

	int nextInt() throws IOException {
		return Integer.parseInt(next());
	}

	long nextLong() throws IOException {
		return Long.parseLong(next());
	}

	double nextDouble() throws IOException {
		return Double.parseDouble(next());
	}

	public static void main(String[] args) {
		new Solution();
	}

}
