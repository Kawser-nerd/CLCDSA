import java.io.*;
import java.util.*;

public class SpinningBlade {

	class Point {
		long x, y;
		long w;

		public Point(long l, long m, long w) {
			this.x = l;
			this.y = m;
			this.w = w;
		}

		Point sum(Point a) {
			return new Point(this.x + a.x, this.y + a.y, w + a.w);
		}

		Point subract(Point a) {
			return new Point(this.x - a.x, this.y - a.y, w - a.w);
		}

		Point copy() {
			return new Point(x, y, w);
		}

		@Override
		public String toString() {
			// TODO Auto-generated method stub
			return x + " " + y;
		}
	}

	Point[][] col;
	Point[][] row;
	Point[][] part;
	Point[][] a;

	Point get(int l1, int r1, int l2, int r2) {
		Point res = part[l2][r2].copy();
		if (l1 > 0)
			res = res.subract(part[l1 - 1][r2]);
		if (r1 > 0)
			res = res.subract(part[l2][r1 - 1]);
		if (l1 > 0 && r1 > 0)
			res = res.sum(part[l1 - 1][r1 - 1]);
		res = res.subract(a[l1][r1]);
		res = res.subract(a[l2][r1]);
		res = res.subract(a[l1][r2]);
		res = res.subract(a[l2][r2]);
		return res;
	}

	void solve() throws Exception {
		int r = nextInt();
		int c = nextInt();
		int d = nextInt();
		a = new Point[r][c];
		for (int i = 0; i < r; i++) {
			String s = nextToken();
			for (int j = 0; j < s.length(); j++)
				a[i][j] = new Point(i * (s.charAt(j) - '0' + d), j
						* (s.charAt(j) - '0' + d), (s.charAt(j) - '0' + d));
		}
		col = new Point[r][c];
		row = new Point[r][c];
		part = new Point[r][c];
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				if (j == 0)
					row[i][j] = a[i][j];
				else
					row[i][j] = a[i][j].sum(row[i][j - 1]);

				if (i == 0)
					col[i][j] = a[i][j];
				else
					col[i][j] = a[i][j].sum(col[i - 1][j]);

				if (j == 0) {
					part[i][j] = col[i][j];
				} else
					part[i][j] = part[i][j - 1].sum(col[i][j]);
			}
		}

		for (int res = Math.min(r, c); res >= 3; res--) {
			for (int i = 0; i + res - 1 < r; i++) {
				for (int j = 0; j + res - 1 < c; j++) {
					Point cur = get(i, j, i + res - 1, j + res - 1);
					if (cur.x * 2 == cur.w * (2 * i + res - 1)
							&& cur.y * 2 == cur.w * (2 * j + res - 1)) {
						out.println(res);
						return;
					}
				}
			}
		}
		out.println("IMPOSSIBLE");
	}

	void run() {
		try {
			in = new BufferedReader(new FileReader("input.txt"));
			out = new PrintWriter("output.txt");
			int tests = nextInt();
			for (int i = 0; i < tests; i++) {
				out.print("Case #" + (i + 1) + ": ");
				solve();
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
	final String filename = new String("SpinningBlade").toLowerCase();

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
		new SpinningBlade().run();
	}

}
