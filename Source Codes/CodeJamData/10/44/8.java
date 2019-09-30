import java.io.*;
import java.util.*;
import java.math.*;

public class SolD implements Runnable {
	public static void main(String[] args) {
		new Thread(new SolD()).start();
	}

	@Override
	public void run() {
		try {
			Locale.setDefault(Locale.US);
			br = new BufferedReader(new FileReader(FNAME + ".in"));
			out = new PrintWriter(FNAME + ".out");
			solve();
			out.close();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}

	BufferedReader br;
	StringTokenizer st;
	PrintWriter out;
	boolean eof;
	Random random = new Random(43965743875L);

	String nextToken() {
		while (st == null || !st.hasMoreTokens()) {
			try {
				st = new StringTokenizer(br.readLine());
			} catch (Exception e) {
				eof = true;
				return "0";
			}
		}
		return st.nextToken();
	}

	int nextInt() {
		return Integer.parseInt(nextToken());
	}

	long nextLong() {
		return Long.parseLong(nextToken());
	}

	double nextDouble() {
		return Double.parseDouble(nextToken());
	}

	String FNAME = "D-small-attempt2";

	void solve() {
		int tests = nextInt();
		for (int test = 1; test <= tests; test++) {
			int n = nextInt();
			int m = nextInt();
			double[] x = new double[n];
			double[] y = new double[n];
			for (int i = 0; i < n; i++) {
				x[i] = nextInt();
				y[i] = nextInt();
			}
			double[] xq = new double[m];
			double[] yq = new double[m];
			for (int i = 0; i < m; i++) {
				xq[i] = nextInt();
				yq[i] = nextInt();
			}
			out.print("Case #" + test + ":");
			for (int t = 0; t < m; t++) {
				double[] r = new double[n];
				for (int i = 0; i < n; i++) {
					r[i] = (xq[t] - x[i]) * (xq[t] - x[i]) + (yq[t] - y[i]) * (yq[t] - y[i]);
				}
				double d = (x[0] - x[1]) * (x[0] - x[1]) + (y[0] - y[1]) * (y[0] - y[1]);
				double ans = 0;
				for (int i = 0; i < 2; i++) {
					double a = d + r[i] - r[1 - i];
					a /= 2 * Math.sqrt(d);
					double b = Math.sqrt(r[i] - a * a);
					ans += r[i] * Math.atan2(b, a);
					ans -= a * b;
				}
//				ans -= 0.5 * Math.sqrt((Math.sqrt(d) + r[0] + r[1]) * (-Math.sqrt(d) + r[0] + r[1]) * (Math.sqrt(d) - r[0] + r[1]) * (Math.sqrt(d) + r[0] - r[1]));
//				ans = Math.abs(ans);
				out.printf(" %.12f", ans);
			}
			out.println();
		}
	}
}
