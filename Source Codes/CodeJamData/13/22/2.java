import java.io.*;

import java.awt.geom.Point2D;
import java.text.*;
import java.math.*;
import java.util.*;

public class Main implements Runnable {

	final String problem = "B";
	// final String filename = problem + "-sample";

	// final String filename = problem + "-small-attempt0";

	// final String filename= problem+"-small-attempt1";
	final String filename = problem + "-large";

	public void solve() throws Exception {
		int N = iread(), X = iread(), Y = iread();
		int layer = (Math.abs(X) + Y) / 2;
		int k = 0;
		for (int l = 0; l < layer; l++) {
			N -= 2 * k + 1;
			k += 2;
		}
		double ans = 0.0;
		if (N <= 0) {
			ans = 0.0;
		} else if (N >= 2 * k + 1) {
			ans = 1.0;
		} else if (X == 0) {
			ans = 0.0;
		} else {
			double[][] p = new double[2][k + 1];
			p[0][0] = 1.0;
			int step = 0;
			for (int i = 0; i < N; i++) {
				Arrays.fill(p[step ^ 1], 0.0);
				for (int j = 0; j <= k && j <= i; j++) {
					int j2 = i - j;
					if (j2 > k)
						continue;
					if (j == k) {
						p[step ^ 1][j] += p[step][j];
					} else if (j2 == k) {
						p[step ^ 1][j + 1] += p[step][j];
					} else {
						p[step ^ 1][j] += 0.5 * p[step][j];
						p[step ^ 1][j + 1] += 0.5 * p[step][j];
					}
				}
				step ^= 1;
			}
			ans = 0.0;
			for (int i = Y + 1; i <= k; i++) {
				ans += p[step][i];
			}
		}
		DecimalFormat df = new DecimalFormat("0.0000000");
		out.write(df.format(ans));
	}

	public void solve_gcj() throws Exception {
		int tests = iread();
		for (int test = 1; test <= tests; test++) {
			out.write("Case #" + test + ": ");
			solve();
			out.write("\n");
		}
	}

	public void run() {
		try {
			// in = new BufferedReader(new InputStreamReader(System.in));
			// out = new BufferedWriter(new OutputStreamWriter(System.out));
			in = new BufferedReader(new FileReader(filename + ".in"));
			out = new BufferedWriter(new FileWriter(filename + ".out"));
			solve_gcj();
			out.flush();
		} catch (Exception e) {
			e.printStackTrace();
			System.exit(1);
		}
	}

	public int iread() throws Exception {
		return Integer.parseInt(readword());
	}

	public double dread() throws Exception {
		return Double.parseDouble(readword());
	}

	public long lread() throws Exception {
		return Long.parseLong(readword());
	}

	BufferedReader in;

	BufferedWriter out;

	public String readword() throws IOException {
		StringBuilder b = new StringBuilder();
		int c;
		c = in.read();
		while (c >= 0 && c <= ' ')
			c = in.read();
		if (c < 0)
			return "";
		while (c > ' ') {
			b.append((char) c);
			c = in.read();
		}
		return b.toString();
	}

	public static void main(String[] args) {
		try {
			Locale.setDefault(Locale.US);
		} catch (Exception e) {

		}
		new Thread(new Main()).start();
		// new Thread(null, new Main(), "1", 1<<25).start();
	}
}