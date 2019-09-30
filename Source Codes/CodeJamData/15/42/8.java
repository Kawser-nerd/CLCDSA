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
		int N = iread();
		double V = (long) (dread() * 10000 + 0.5), X = (long) (dread() * 10000 + 0.5);
		Pair[] p = new Pair[N];
		for (int i = 0; i < N; i++)
			p[i] = new Pair((long) (dread() * 10000 + 0.5),
					(long) (dread() * 10000 + 0.5));
		Arrays.sort(p);
		if (p[0].x > X || p[N - 1].x < X) {
			out.write("IMPOSSIBLE");
			return;
		}
		long S = 0, sum = 0;
		for (int i = 0; i < N; i++) {
			S += p[i].x * p[i].v;
			sum += p[i].v;
		}
		double ansV = sum;
		int left = 0, right = N - 1;
		if (X * sum < S) {
			while (X * sum < S) {
				S -= p[right].x * p[right].v;
				sum -= p[right].v;
				if (X * sum - S < 0) {
					right--;
				} else {
					double a = (X * sum - S) * 1.0 / (p[right].x - X);
					ansV = sum + a;
					break;
				}
			}
		} else
			while (X * sum > S) {
				S -= p[left].x * p[left].v;
				sum -= p[left].v;
				if (X * sum - S > 0) {
					left++;
				} else {
					double a = (X * sum - S) * 1.0 / (p[left].x - X);
					ansV = sum + a;
					break;
				}
			}
		out.write(df.format(V / ansV) + "");
	}

	DecimalFormat df = new DecimalFormat("0.000000000");

	class Pair implements Comparable<Pair> {
		public Pair(long v, long x) {
			super();
			this.x = x;
			this.v = v;
		}

		long x, v;

		@Override
		public int compareTo(Pair o) {
			return Long.compare(x, o.x);
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