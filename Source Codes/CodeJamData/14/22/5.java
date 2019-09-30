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
		int A = iread(), B = iread(), T = iread();

		int n = 0;
		long p = 1;
		while (p <= A || p <= B || p <= T) {
			p *= 2;
			n++;
		}
		n--;

		long[][] d = new long[2][8];
		d[0][0] = 1;
		int step = 0;
		for (int i = n; i >= 0; i--) {
			Arrays.fill(d[step ^ 1], 0);
			for (int mask = 0; mask < 8; mask++) {
				int maskA = mask & 1;
				int maskB = (mask >> 1) & 1;
				int maskT = (mask >> 2) & 1;

				int A1 = (A >> i) & 1;
				int B1 = (B >> i) & 1;
				int T1 = (T >> i) & 1;

				int A2 = A1 | maskA;
				int B2 = B1 | maskB;
				int T2 = T1 | maskT;
				for (int t = 0; t < 2; t++) {
					for (int u = 0; u < 2; u++) {
						int tu = t & u;
						int mask2 = mask;
						if (t > A2)
							continue;
						if (u > B2)
							continue;
						if (tu > T2)
							continue;

						if (t < A1)
							mask2 |= 1;
						if (u < B1)
							mask2 |= 2;
						if (tu < T1)
							mask2 |= 4;
						d[step ^ 1][mask2] += d[step][mask];
					}
				}
			}
			step ^= 1;
		}
		out.write(d[step][7] + "");
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