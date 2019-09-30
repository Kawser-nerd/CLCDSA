import java.io.*;
import java.util.*;
import java.math.*;

public class SolC implements Runnable {

	public static void main(String[] args) {
		new Thread(new SolC()).start();
	}

	BufferedReader br;
	StringTokenizer st;
	PrintWriter out;
	boolean eof = false;
	Random rand = new Random(this.hashCode());

	@Override
	public void run() {
		Locale.setDefault(Locale.US);
		try {
			br = new BufferedReader(new FileReader(FNAME + ".in"));
			out = new PrintWriter(FNAME + ".out");
			solve();
			out.close();
		} catch (Throwable e) {
			e.printStackTrace();
			System.exit(566);
		}
	}

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

	//String FNAME = "C-small";
	//String FNAME = "C-small-attempt0";
	String FNAME = "C-large";

	private void solve() throws IOException {
		int tt = nextInt();
		for (int nt = 1; nt <= tt; nt++) {
			System.out.println(nt);
			out.print("Case #" + nt + ": ");
			int m = nextInt();
			int n = nextInt();
			long[][] c = new long[m + 1][m + 1];
			for (int i = 0; i <= m; i++) {
				c[i][0] = 1;
				c[i][i] = 1;
			}
			for (int i = 0; i <= m; i++) {
				for (int j = 1; j < i; j++) {
					c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
				}
			}
			double[] d = new double[m + 1];
			d[0] = 1;
			double ans = 0;
			for (int iter = 1; iter <= 100000; iter++) {
				double[] dd = new double[m + 1];
				for (int k = 0; k <= m; k++) {
					for (int i = 0; i <= Math.min(m - k, n); i++) {
						if (m - k >= i && k >= n - i) {
							double t = 1.0 * c[m - k][i] / c[m][n] * c[k][n - i];
							dd[k + i] += d[k] * t;
						}
					}
				}
				d = dd;
				ans += d[m] * iter;
				d[m] = 0;
			}
			out.println(ans);
		}
	}

}
 