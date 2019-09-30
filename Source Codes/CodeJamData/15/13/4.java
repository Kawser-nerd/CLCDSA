import java.io.*;

import java.awt.geom.Point2D;
import java.text.*;
import java.math.*;
import java.util.*;

public class Main implements Runnable {

	final String problem = "C";
	// final String filename = problem + "-sample";

//	final String filename = problem + "-small-attempt0";

//	 final String filename= problem+"-small-attempt1";
	 final String filename= problem+"-large";

	public void solve() throws Exception {
		int N = iread();
		int[] x = new int[N], y = new int[N];
		for (int i = 0; i < N; i++) {
			x[i] = iread();
			y[i] = iread();
		}
		int[] log = new int[N];
		Arrays.fill(log, N + 1);
		if (N==1) log[0] = 0;
		int[] side = new int[2];
		for (int i = 0; i < N; i++) {
			for (int j = i + 1; j < N; j++) {
				side[0] = side[1] = 0;
				long A = y[i] - y[j], B = x[j] - x[i], C = -(x[i] * A + y[i]
						* B);
				for (int k = 0; k < N; k++) {
					long T = A * x[k] + B * y[k] + C;
					if (T > 0)
						side[0]++;
					if (T < 0)
						side[1]++;
				}
				log[i] = Math.min(log[i], Math.min(side[0], side[1]));
				log[j] = Math.min(log[j], Math.min(side[0], side[1]));
			}
		}
		for (int i = 0; i < N; i++) {
			out.write("\n" + log[i]);
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