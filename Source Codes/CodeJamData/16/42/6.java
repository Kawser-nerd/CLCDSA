import java.io.*;

import java.awt.geom.Point2D;
import java.text.*;
import java.math.*;
import java.util.*;

public class Main implements Runnable {

	final String problem = "B";
//	 final String filename = problem + "-sample";

	// final String filename = problem + "-small-attempt0";

//	final String filename = problem + "-small-attempt3";

	 final String filename= problem+"-large";

	public void solve() throws Exception {
		int N = iread(), K = iread();
		double[] p = new double[N];
		for (int i = 0; i < N; i++) {
			p[i] = dread();
		}
		Arrays.sort(p);

		double[][] pp = new double[2][K + 1];
		double ans = 0.0;

		pp[0][0] = 1.0;
		int step = 0;
		for (int i = 0; i < K; i++) {
			double p1;
			if (i < K / 2) {
				p1 = p[i];
			} else {
				p1 = p[N - K + i];
			}
			for (int j = 0; j <= K; j++) {
				pp[step ^ 1][j] = pp[step][j] * (1 - p1);
				if (j > 0) {
					pp[step ^ 1][j] += pp[step][j - 1] * p1;
				}
			}
			step ^= 1;
		}
		ans = Math.max(ans, pp[step][K / 2]);
		for (int s = 0; s + K <= N; s++) {
			Arrays.fill(pp[0], 0.0);
			pp[0][0] = 1.0;
			step = 0;
			for (int i = 0; i < K; i++) {
				double p1 = p[i + s];
				for (int j = 0; j <= K; j++) {
					pp[step ^ 1][j] = pp[step][j] * (1 - p1);
					if (j > 0) {
						pp[step ^ 1][j] += pp[step][j - 1] * p1;
					}
				}
				step ^= 1;
			}
			if (ans + 1e-6 < pp[step][K / 2]) {
				System.out.println("better");
			}
			ans = Math.max(ans, pp[step][K / 2]);
		}
		for (int s = 0; s < K; s++) {
			Arrays.fill(pp[0], 0.0);
			pp[0][0] = 1.0;
			step = 0;
			for (int i = 0; i < K; i++) {
				double p1;
				if (i < s) {
					p1 = p[i];
				} else {
					p1 = p[N - K + i];
				}
				for (int j = 0; j <= K; j++) {
					pp[step ^ 1][j] = pp[step][j] * (1 - p1);
					if (j > 0) {
						pp[step ^ 1][j] += pp[step][j - 1] * p1;
					}
				}
				step ^= 1;
			}
			if (ans + 1e-6 < pp[step][K / 2]) {
				System.out.println("even better");
			}
			ans = Math.max(ans, pp[step][K / 2]);
		}
		
//		 for (int a = 1; a < K; a++) {
//		 int c = K - a;
//		 for (int b = 0; b <= a; b++) {
//		 int start = b;
//		 int end = N - a + b;
//		 for (int d = start; d + c <= end; d++) {
//		 Arrays.fill(pp[0], 0.0);
//		 pp[0][0] = 1.0;
//		 step = 0;
//		 for (int i = 0; i < K; i++) {
//		 double p1;
//		 if (i < b) {
//		 p1 = p[i];
//		 } else if (i < a) {
//		 p1 = p[N - (i - b) - 1];
//		 } else {
//		 p1 = p[d + (i - a)];
//		 }
//		 for (int j = 0; j <= K; j++) {
//		 pp[step ^ 1][j] = pp[step][j] * (1 - p1);
//		 if (j > 0) {
//		 pp[step ^ 1][j] += pp[step][j - 1] * p1;
//		 }
//		 }
//		 step ^= 1;
//		 }
//		 if (ans + 1e-6 < pp[step][K / 2]) {
//		 System.out.println("SUPER better");
//		 }
//		 ans = Math.max(ans, pp[step][K / 2]);
//		 }
//		 }
//		 }

		out.write(df.format(ans));
	}

	DecimalFormat df = new DecimalFormat("0.0000000");

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