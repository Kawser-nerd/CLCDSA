import java.io.*;
import java.awt.geom.Point2D;
import java.text.*;
import java.math.*;
import java.util.*;

public class Main implements Runnable {

	final String problem = "B";
	// final String filename = problem + "-sample";

	// final String filename = problem + "-small-attempt0";
	// final String filename = problem + "-small-attempt2";
	final String filename = problem + "-large";

	int[] a;
	int N;
	long ans;
	long[] fact;

	void swap(int i, int j) {
		int t = a[j];
		a[j] = a[i];
		a[i] = t;
	}

	void doit(int step, int swaps) {
		if (step == N) {
			ans += fact[swaps];
			return;
		}
		int w1 = -1, w2 = -1;
		for (int i = 0; i < N; i += 2 * step) {
			if (a[i] + step != a[i + step] || a[i] % (step * 2) != 0) {
				if (w1 == -1) {
					w1 = i;
				} else if (w2 == -1) {
					w2 = i;
				} else
					return;
			}
		}
		if (w1 == -1 && w2 == -1)
			doit(step * 2, swaps);
		else if (w2 == -1) {
			if (a[w1 + step] + step == a[w1]) {
				swap(w1, w1 + step);
				doit(step * 2, swaps + 1);
				swap(w1, w1 + step);
			}
		} else {
			if (a[w2 + step] + step == a[w1 + step] && a[w2] + step == a[w1]) {
				swap(w2 + step, w1);
				doit(step * 2, swaps + 1);
				swap(w2 + step, w1);
			} else if (a[w1 + step] + step == a[w2 + step]
					&& a[w1] + step == a[w2]) {
				swap(w1 + step, w2);
				doit(step * 2, swaps + 1);
				swap(w1 + step, w2);
			} else if (a[w1] + step == a[w2 + step]
					&& a[w2] + step == a[w1 + step]) {
				swap(w1, w2);
				doit(step * 2, swaps + 1);
				swap(w1, w2);
				swap(w1 + step, w2 + step);
				doit(step * 2, swaps + 1);
				swap(w1 + step, w2 + step);
			}
		}
	}

	public void solve() throws Exception {
		fact = new long[14];
		fact[0] = 1;
		for (int i = 1; i < fact.length; i++)
			fact[i] = fact[i - 1] * i;

		N = iread();
		N = 1 << N;
		a = new int[N];
		for (int i = 0; i < N; i++) {
			a[i] = iread() - 1;
		}
		ans = 0;
		doit(1, 0);
		out.write(ans + "");
		// out.write(df.format(res));
	}

	DecimalFormat df = new DecimalFormat("0.0000000000");

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