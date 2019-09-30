import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.System.exit;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class Main {

	static void solve() throws Exception {
		int n = scanInt();
		long l = scanLong();
		long x[] = new long[n];
		for (int i = 0; i < n; i++) {
			x[i] = scanLong();
		}
		long t[] = new long[n];
		for (int i = 0; i < n; i++) {
			t[i] = scanLong();
		}
		long cost = (2 * x[n - 1] + t[n - 1] + 2 * l - 1) / (2 * l);
		int low = 0, pairs = 0;
		for (int i = 0; i < n - 1; i++) {
			long costMinus = (2 * x[i] + t[i] + 2 * l - 1) / (2 * l);
			long costKeep = (t[i] + 2 * l - 1) / (2 * l);
			long costPlus = (2 * (l - x[i]) + t[i] + 2 * l - 1) / (2 * l) - 1;
			cost += costKeep;
			if (costMinus == costKeep) {
				if (costPlus == costKeep) {
					// minus
					if (low != 0) {
						--low;
						--cost;
					} else if (pairs != 0) {
						--pairs;
						++low;
						--cost;
					}
				} else {
					// both
					if (low != 0) {
						--low;
						++pairs;
					} else {
						++low;
					}
				}
			} else {
				if (costPlus == costKeep) {
					// none
				} else {
					// plus
					++low;
				}
			}
		}
		cost -= pairs;
		out.print(cost * 2 * l);
//		long ans = solveDumb(n, l, x, t);
//		out.println(ans * 2 * l);
//		ans = solve(n, l, x, t);
//		out.print(ans * 2 * l);
	}

//	static int dumbN;
//	static long dumbL, dumbX[], dumbT[], dumbAns;
//	static boolean dumbHave[];
//	static List<Integer> dumbSeq;
//	static long solveDumb(int n, long l, long x[], long t[]) {
//		dumbN = n;
//		dumbL = l;
//		dumbX = x;
//		dumbT = t;
//		dumbHave = new boolean[n];
//		dumbAns = Long.MAX_VALUE;
//		dumbSeq = new ArrayList<>();
//		dumbGo(0, 0);
//		Collections.reverse(dumbSeq);
//		System.err.println(dumbSeq);
//		return dumbAns / (2 * l);
//	}
//
//	static long dumbGoTo(long x, long t, long dest) {
//		if (x == dest) {
//			return t;
//		}
//		long l = dumbL;
//		if (x < dest) {
//			return (t + (2 * l - x) + 2 * l - 1) / (2 * l) * (2 * l) - (2 * l - dest);
//		} else {
//			return (t + x + 2 * l - 1) / (2 * l) * (2 * l) - dest;
//		}
//	}
//
//	static boolean dumbGo(long x, long t) {
//		boolean end = true, res = false;
//		for (int i = 0; i < dumbN; i++) {
//			if (!dumbHave[i]) {
//				dumbHave[i] = true;
//				if (dumbGo(dumbX[i], dumbGoTo(x, t, dumbX[i]) + dumbT[i])) {
//					dumbSeq.add(i);
//					res = true;
//				}
//				dumbHave[i] = false;
//				end = false;
//			}
//		}
//		if (end && dumbAns > dumbGoTo(x, t, 0)) {
//			dumbAns = dumbGoTo(x, t, 0);
//			dumbSeq.clear();
//			res = true;
//		}
//		return res;
//	}
//
//	static long solve(int n, long l, long[] x, long[] t) {
//		long ans = (2 * x[n - 1] + t[n - 1] + 2 * l - 1) / (2 * l);
//		for (int i = 0; i < n - 1; i++) {
//			ans += (t[i] + 2 * l - 1) / (2 * l);
//		}
//		return ans;
//	}

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