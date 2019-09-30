import java.io.*;
import java.util.*;

public class Packing {

	class Circle {
		int r, id;

		public Circle(int r, int id) {
			this.r = r;
			this.id = id;
		}

	}

	Circle[] c;
	double[] x, y;
	int n, w, l;
	Random rnd;

	final int MAX_COUNT = 50;
	final double EPS = 1e-8;

	boolean go(int k) {
		if (k == n) {
			return true;
		}
		for (int IT = 0; IT < MAX_COUNT; IT++) {
			double xx = rnd.nextDouble() * w;
			double yy = rnd.nextDouble() * l;
			int rr = c[k].r;
			boolean ok = true;
			for (int i = 0; i < k; i++) {
				double d = (xx - x[i]) * (xx - x[i]) + (yy - y[i])
						* (yy - y[i]);
				long dist = rr + c[i].r;
				dist *= dist;
				if (d < dist) {
					ok = false;
					break;
				}
			}
			if (ok) {
				x[k] = xx;
				y[k] = yy;
				if (go(k + 1)) {
					return true;
				}
			}
		}
		return false;
	}

	void solve() throws Exception {
		n = nextInt();
		w = nextInt();
		l = nextInt();
		rnd = new Random();
		c = new Circle[n];
		for (int i = 0; i < n; i++) {
			c[i] = new Circle(nextInt(), i);
		}
		Arrays.sort(c, new Comparator<Circle>() {
			@Override
			public int compare(Circle o1, Circle o2) {
				return o2.r - o1.r;
			}
		});
		x = new double[n];
		y = new double[n];
		if (!go(0)) {
			System.err.println("FAIL " + testN);
		}
		double[] ansx = new double[n], ansy = new double[n];
		for (int i = 0; i < n; i++) {
			ansx[c[i].id] = x[i];
			ansy[c[i].id] = y[i];
		}
		for (int i = 0; i < n; i++) {
//			out.print(ansx[i] + " " + ansy[i] + " ");
			out.printf(Locale.US, "%.9f %.9f ", ansx[i], ansy[i]);
		}
		out.println();
	}

	int testN;

	void run() {
		try {
			in = new BufferedReader(new FileReader("input.txt"));
			out = new PrintWriter("output.txt");
			int tests = nextInt();

			for (int i = 0; i < tests; i++) {
				testN = i + 1;
				long time = System.currentTimeMillis();
				out.print("Case #" + (i + 1) + ": ");
				solve();
				System.err.println("Solved case #" + (i + 1) + " in "
						+ (System.currentTimeMillis() - time) + " ms");
			}

			out.close();
		} catch (Exception e) {
			e.printStackTrace();
			System.exit(1);
		}
	}

	BufferedReader in;
	StringTokenizer st;
	PrintWriter out;
	final String filename = new String("Packing").toLowerCase();

	String nextToken() throws Exception {
		while (st == null || !st.hasMoreTokens())
			st = new StringTokenizer(in.readLine());
		return st.nextToken();
	}

	int nextInt() throws Exception {
		return Integer.parseInt(nextToken());
	}

	long nextLong() throws Exception {
		return Long.parseLong(nextToken());
	}

	double nextDouble() throws Exception {
		return Double.parseDouble(nextToken());
	}

	public static void main(String[] args) {
		new Packing().run();
	}

}
