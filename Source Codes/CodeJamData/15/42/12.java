import java.io.*;
import java.util.*;

public class B_int {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	enum InputType {
		SAMPLE, SMALL, LARGE;
	}

	static final InputType currentInputType = InputType.LARGE;
	static final int attemptNumber = 2; // for small inputs only

	int nextInt4() throws IOException {
		String s = nextToken();
		s = s.replace(".", "");
		return Integer.parseInt(s);
	}

	static class Point implements Comparable<Point> {
		int x, slope;

		public Point(int x, int slope) {
			this.x = x;
			this.slope = slope;
		}

		@Override
		public int compareTo(Point o) {
			return Integer.compare(slope, o.slope);
		}

	}

	double go(long x1, long y1, long x2, long y2, long needX, long needSlope) {
		System.err.println(x1 + " " + y1 + " " + x2 + " " + y2 + " " + needX
				+ " " + needSlope);
		long dx = x2 - x1; // 10^6
		long dy = y2 - y1; // 10^10

		long num = needSlope * x1 - y1;
		long denom = dy - needSlope * dx;

		if (denom == 0) {
			if (num == 0) {
				return 1.0 * needX / Math.max(x1, x2);
			}
			return 1e100;
		}

		if (denom < 0) {
			denom = -denom;
			num = -num;
		}

		if (num < 0 || num > denom) {
			return 1e100;
		}

		double t = 1.0 * num / denom;
		double x = x1 + dx * t;
//		System.err.println(needX / x);
		return needX / x;
	}

	void solve() throws IOException {
		int n = nextInt();
		int needX = nextInt4();
		int needSlope = nextInt4();

		Point[] a = new Point[n];
		for (int i = 0; i < n; i++) {
			a[i] = new Point(nextInt4(), nextInt4());
		}
		Arrays.sort(a);
		if (needSlope < a[0].slope || a[n - 1].slope < needSlope) {
			out.println("IMPOSSIBLE");
			return;
		}

		double ans = 1e100;
		long sx = 0;
		long sy = 0;
		for (int i = 0; i < n; i++) {
			long nx = sx + a[i].x;
			long ny = sy + (long) a[i].x * a[i].slope;
			ans = Math.min(ans, go(sx, sy, nx, ny, needX, needSlope));
			sx = nx;
			sy = ny;
		}

		sx = sy = 0;
		for (int i = n - 1; i >= 0; i--) {
			long nx = sx + a[i].x;
			long ny = sy + (long) a[i].x * a[i].slope;
			ans = Math.min(ans, go(sx, sy, nx, ny, needX, needSlope));
			sx = nx;
			sy = ny;
		}
		out.printf(Locale.US, "%.10f\n", ans);
	}

	void inp() throws IOException {
		switch (currentInputType) {
		case SAMPLE:
			br = new BufferedReader(new InputStreamReader(System.in));
			out = new PrintWriter(System.out);
			break;
		case SMALL:
			String fileName = "B_int-small-attempt" + attemptNumber;
			br = new BufferedReader(new FileReader(fileName + ".in"));
			out = new PrintWriter(fileName + ".out");
			break;
		case LARGE:
			fileName = "B-large";
			br = new BufferedReader(new FileReader(fileName + ".in"));
			out = new PrintWriter(fileName + ".out");
			break;
		}
		int test = nextInt();
		for (int i = 1; i <= test; i++) {
			System.err.println("Running test " + i);
			out.print("Case #" + i + ": ");
			solve();
		}
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new B_int().inp();
	}

	String nextToken() {
		while (st == null || !st.hasMoreTokens()) {
			try {
				st = new StringTokenizer(br.readLine());
			} catch (Exception e) {
				eof = true;
				return null;
			}
		}
		return st.nextToken();
	}

	String nextString() {
		try {
			return br.readLine();
		} catch (Exception e) {
			eof = true;
			return null;
		}
	}

	int nextInt() throws IOException {
		return Integer.parseInt(nextToken());
	}

	long nextLong() throws IOException {
		return Long.parseLong(nextToken());
	}

	double nextDouble() throws IOException {
		return Double.parseDouble(nextToken());
	}
}
