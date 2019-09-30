import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.Locale;
import java.util.SortedSet;
import java.util.StringTokenizer;
import java.util.TreeSet;

public class A {
	
	static BufferedReader in;
	static PrintWriter out;
	static StringTokenizer tok;
	
	static void solveTest() throws Exception {
		int w = nextInt();
		int l = nextInt();
		int u = nextInt();
		int g = nextInt();
		int xl[] = new int[l];
		int yl[] = new int[l];
		for (int i = 0; i < l; i++) {
			xl[i] = nextInt();
			yl[i] = nextInt();
		}
		int xu[] = new int[u];
		int yu[] = new int[u];
		for (int i = 0; i < u; i++) {
			xu[i] = nextInt();
			yu[i] = nextInt();
		}
		SortedSet<Integer> xs = new TreeSet<Integer>();
		for (int i = 0; i < l; i++) {
			xs.add(xl[i]);
		}
		for (int i = 0; i < u; i++) {
			xs.add(xu[i]);
		}
		int nx[] = new int[xs.size()];
		{
			int i = 0;
			for (int xx: xs) {
				nx[i++] = xx;
			}
		}
		double ny[] = new double[nx.length];
		{
			int i = 0;
			int il = 0;
			int iu = 0;
			while (true) {
				double nyl = nx[i] > xl[il] ? yl[il] + (double)
					(yl[il + 1] - yl[il]) * (nx[i] - xl[il]) / (xl[il + 1] - xl[il]) : yl[il];
				double nyu = nx[i] > xu[iu] ? yu[iu] + (double)
					(yu[iu + 1] - yu[iu]) * (nx[i] - xu[iu]) / (xu[iu + 1] - xu[iu]) : yu[iu];
				ny[i] = nyu - nyl;
				++i;
				if (i >= nx.length) {
					break;
				}
				while (il < l - 1 && xl[il + 1] <= nx[i]) {
					++il;
				}
				while (iu < u - 1 && xu[iu + 1] <= nx[i]) {
					++iu;
				}
			}
		}
		double area = area(nx, ny, w);
		for (int pos = 1; pos < g; ++pos) {
			double narea = area / g * pos;
			double testl = 0;
			double testr = w;
			while (true) {
				double mid = (testl + testr) / 2;
				double testarea = area(nx, ny, mid);
				if (testarea < narea) {
					if (testl == mid) {
						break;
					}
					testl = mid;
				} else {
					if (testr == mid) {
						break;
					}
					testr = mid;
				}
			}
			out.printf(Locale.US, "%.9f\n", (testl + testr) / 2);
		}
	}
	
	static double area(int x[], double y[], double w) {
		double area = 0;
		for (int i = 0; i < x.length - 1; i++) {
			if (x[i + 1] < w) {
				area += (x[i + 1] - x[i]) * (y[i] + y[i + 1]);
			} else {
				area += (w - x[i]) * (y[i] + (y[i] + (y[i + 1] - y[i]) * (w - x[i]) / (x[i + 1] - x[i])));
				break;
			}
		}
		return area;
	}
	
	static void solve() throws Exception {
		int tests = nextInt();
		for (int test = 1; test <= tests; test++) {
			out.println("Case #" + test + ":");
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