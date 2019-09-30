import java.io.*;

import java.awt.geom.Point2D;
import java.text.*;
import java.math.*;
import java.util.*;

public class Main implements Runnable {

	final String problem = "D";
//	final String filename = problem + "-sample";

//	 final String filename= problem+"-small-attempt0";
	// final String filename= problem+"-small-attempt1";
	 final String filename= problem+"-large";

	public void solve() throws Exception {
		long K = lread();
		int C = iread();
		int S = iread();

		long[] ans = new long[S];
		if (C * S < K) {
			out.write("IMPOSSIBLE");
			return;
		}
		int t = 0;
		long KK = 1;
		for (int i = 0; i < K; i++) {
			ans[t] += KK * i;
			KK *= K;
			if (i % C == C - 1 || i == K - 1) {
				t++;
				KK = 1;
			}
		}
		for (int i = 0; i < t; i++) {
			if (i > 0) {
				out.write(" ");
			}
			out.write("" + (ans[i] + 1));
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