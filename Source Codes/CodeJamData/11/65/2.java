import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.Math.max;
import static java.lang.Math.min;
import static java.util.Arrays.fill;

import java.io.*;
import java.math.BigInteger;
import java.util.StringTokenizer;

public class E {
	
	static BufferedReader in;
	static PrintWriter out;
	static StringTokenizer tok;
	
	static void solveTest() throws Exception {
		int a = nextInt();
		int m = nextInt();
		int v = nextInt();
		double prob[] = new double[v + 1];
		fill(prob, 0.5);
		prob[0] = 0;
		prob[v] = 1;
		double nprob[] = new double[v + 1];
		for (int iter = 0; iter < 20000; iter++) {
			for (int i = 0; i <= v; i++) {
				double ans;
				if (i == 0) {
					ans = 0;
				} else if (i == v) {
					ans = 1;
				} else {
					ans = 0;
					for (int bet = 1; bet <= min(i, m); bet++) {
						for (int cnt = 1; bet << (cnt - 1) <= m; cnt++) {
							int resGood = i + bet;
							int resBad = i - ((bet << cnt) - bet);
							double probGood = resGood > v ? 1 : prob[resGood];
							double probBad = resBad < 0 ? 0 : prob[resBad];
							double nans = probGood + (probBad - probGood) / (1 << cnt);
							ans = max(ans, nans);
						}
					}
				}
				nprob[i] = ans;
			}
			double t[] = prob;
			prob = nprob;
			nprob = t;
		}
		int maxbet[] = new int[v + 1];
		for (int i = 0; i <= v; i++) {
			double ans;
			if (i == 0) {
				ans = 0;
			} else if (i == v) {
				ans = 1;
			} else {
				ans = 0;
				for (int bet = 1; bet <= min(i, m); bet++) {
					for (int cnt = 1; bet << (cnt - 1) <= m; cnt++) {
						int resGood = i + bet;
						int resBad = i - ((bet << cnt) - bet);
						double probGood = resGood > v ? 1 : prob[resGood];
						double probBad = resBad < 0 ? 0 : prob[resBad];
						double nans = probGood + (probBad - probGood) / (1 << cnt);
						if (ans <= nans + 1e-8) {
							ans = nans;
							maxbet[i] = bet;
						}
					}
				}
			}
			nprob[i] = ans;
		}
		out.printf("%.9f %d\n", prob[a], maxbet[a]);
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