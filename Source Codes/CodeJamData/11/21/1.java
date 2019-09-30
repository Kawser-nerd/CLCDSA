import java.io.*;

import java.awt.geom.Point2D;
import java.text.*;
import java.math.*;
import java.util.*;

public class Main implements Runnable {

	final String problem = "A";
//	final String filename = problem + "-sample";

//	 final String filename= problem+"-small-attempt0";
	// final String filename= problem+"-small-attempt1";
	 final String filename= problem+"-large";

	public void solve() throws Exception {
		int n = iread();
		int[][] table = new int[n][n];
		for (int i = 0; i < n; i++) {
			String s = readword();
			for (int j = 0; j < n; j++)
				if (s.charAt(j) == '1') {
					table[i][j] = 1;
				} else if (s.charAt(j) == '.')
					table[i][j] = -1;
		}
		int[] cnt = new int[n], wins = new int[n];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++)
				if (table[i][j] >= 0) {
					cnt[i]++;
					if (table[i][j] == 1)
						wins[i]++;
				}
		}
		double[] wp = new double[n];
		for (int i = 0; i < n; i++)
			wp[i] = wins[i] * 1.0 / cnt[i];

		double[] owp = new double[n];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++)
				if (table[i][j] >= 0) {
					owp[i] += (wins[j] - table[j][i]) * 1.0 / (cnt[j] - 1);
				}
			owp[i] /= cnt[i];
		}
		
		double[] oowp = new double[n];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++)
				if (table[i][j] >= 0) {
					oowp[i] += owp[j];
				}
			oowp[i] /= cnt[i];
		}

		DecimalFormat df = new DecimalFormat("0.0000000");
		for (int i = 0; i < n; i++) {
			double ans = 0.25 * wp[i];
			ans += 0.5 * owp[i];
			ans += 0.25 * oowp[i];
			out.write("\n" + df.format(ans));
		}
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