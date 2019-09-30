import java.io.*;
import java.util.*;
import static java.lang.Math.*;

public class Solution {

	BufferedReader in;
	StringTokenizer st;
	PrintWriter out;

	private String filename = "large";

	int n, d;

	int[] x;
	int[] cnt;

	boolean can(double time) {
		double pred = 0.0;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < cnt[i]; ++j) {
				if (i == 0 && j == 0) {
					pred = x[i] - time;
					continue;
				}
				double need = pred + d;
				/*
				 * if (abs(need - x[i]) > time) return false;
				 */
				if (x[i] > need) {
					pred = max(need, x[i] - time);
				} else {
					if (abs(x[i] - need) > time)
						return false;
					pred = min(need, x[i] + time);
				}
			}
		}
		return true;
	}

	void solve() throws IOException {
		int tests = ni();
		for (int test = 1; test <= tests; ++test) {
			n = ni();
			d = ni();
			x = new int[n];
			cnt = new int[n];
			for (int i = 0; i < n; ++i) {
				x[i] = ni();
				cnt[i] = ni();
			}
			double l = 0.0, r = 1e+12 + 10;
			for (int it = 0; it < 105; ++it) {
				double m = (l + r) / 2.0;
				if (can(m))
					r = m;
				else
					l = m;
			}
			if (can(l) == false)
				l = r;
			out.print("Case #" + test + ": ");
			out.printf("%.9f\n", l);
		}
	}

	public Solution() throws IOException {
		Locale.setDefault(Locale.US);
		in = new BufferedReader(new FileReader(filename + ".in"));
		out = new PrintWriter(filename + ".out");
		solve();
		in.close();
		out.close();
	}

	String ns() throws IOException {
		while (st == null || !st.hasMoreTokens())
			st = new StringTokenizer(in.readLine());
		return st.nextToken();
	}

	int ni() throws IOException {
		return Integer.valueOf(ns());
	}

	long nl() throws IOException {
		return Long.valueOf(ns());
	}

	double nd() throws IOException {
		return Double.valueOf(ns());
	}

	public static void main(String[] args) throws IOException {
		new Solution();
	}
}
