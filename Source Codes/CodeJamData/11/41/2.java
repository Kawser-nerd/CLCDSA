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
		int X = iread();
		int S = iread(), R = iread();
		double t = iread();
		int N = iread();
		Tuple3[] ww = new Tuple3[N];
		double Y = X;
		for (int i = 0; i < N; i++) {
			ww[i] = new Tuple3(iread(), iread(), iread());
			Y -= ww[i].b - ww[i].a;
		}
		Arrays.sort(ww);
		double t1 = Math.min(t, Y / R);
		t -= t1;
		double ans = t1 + (Y - t1 * R) / S;

		for (int i = 0; i < N; i++) {
			double L = ww[i].b - ww[i].a;
			double t2 = Math.min(t, L / (ww[i].w + R));
			t -= t2;
			ans += t2 + (L - t2 * (ww[i].w + R)) / (ww[i].w + S);
		}
		DecimalFormat df = new DecimalFormat("0.0000000");
		out.write(df.format(ans)+"");
	}

	class Tuple3 implements Comparable<Tuple3> {
		public Tuple3(int a, int b, int w) {
			super();
			this.a = a;
			this.b = b;
			this.w = w;
		}

		int a, b, w;

		@Override
		public int compareTo(Tuple3 o) {
			return w - o.w;
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