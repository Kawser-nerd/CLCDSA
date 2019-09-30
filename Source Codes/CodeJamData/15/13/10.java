import java.io.*;
import java.util.*;

public class taskC {

	PrintWriter out;
	BufferedReader br;
	StringTokenizer st;

	String nextToken() throws IOException {
		while ((st == null) || (!st.hasMoreTokens()))
			st = new StringTokenizer(br.readLine());
		return st.nextToken();
	}

	public int nextInt() throws IOException {
		return Integer.parseInt(nextToken());
	}

	public long nextLong() throws IOException {
		return Long.parseLong(nextToken());
	}

	public double nextDouble() throws IOException {
		return Double.parseDouble(nextToken());
	}

	class Point {
		long x, y;

		public Point(long x, long y) {
			super();
			this.x = x;
			this.y = y;
		}

		@Override
		public String toString() {
			return "Point [x=" + x + ", y=" + y + "]";
		}	
	}

	class MyComparator implements Comparator<Point> {
		Point t;

		MyComparator(Point t) {
			this.t = t;
		}

		@Override
		public int compare(Point aa, Point bb) {
			Point a = new Point(aa.x - t.x, aa.y - t.y);
			Point b = new Point(bb.x - t.x, bb.y - t.y);

			int as = -1;
			if (a.x < 0 || a.x == 0 && a.y < 0) {
				as = 1;
			}

			int bs = -1;
			if (b.x < 0 || b.x == 0 && b.y < 0) {
				bs = 1;
			}

			if (as != bs) {
				return Integer.compare(as, bs);
			}

			return Long.compare(mult(aa, bb, t), 0);
		}
	}

	private long mult(Point aa, Point bb, Point t) {
		return (aa.x - t.x) * (bb.y - t.y) - (aa.y - t.y) * (bb.x - t.x);
	}

	public void solve() throws IOException {
		int n = nextInt();
		Point[] a = new Point[n];
		for (int i = 0; i < n; i++) {
			a[i] = new Point(nextLong(), nextLong());
		}

		for (int t = 0; t < n; t++) {
			ArrayList<Point> q = new ArrayList<>();
			for (int i = 0; i < n; i++) {
				if (i != t) {
					q.add(a[i]);
				}
			}
			Collections.sort(q, new MyComparator(a[t]));
//			System.err.println(a[t]);
			for (int i = 0; i < n - 1; i++) {
				q.add(q.get(i));
			}
//			System.err.println(q);
			
			int maxAns = 1;
			int r = 0;
			for (int l = 0; l < n - 1; l++) {
				while (r < l + n - 2 && mult(q.get(r + 1), q.get(l), a[t]) >= 0) {
					r++;
				}
				maxAns = Math.max(maxAns, 1 + r - l + 1);
			}
			out.println(n - maxAns);
		}
	}

	public void run() {
		try {
			br = new BufferedReader(new InputStreamReader(System.in));
			out = new PrintWriter(System.out);

			br = new BufferedReader(new FileReader("taskC.in"));
			out = new PrintWriter("taskC.out");
			int n = nextInt();
			for (int i = 0; i < n; i++) {
				System.err.println("Case #" + (i + 1));
				out.println("Case #" + (i + 1) + ":");
				solve();
			}
			out.close();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}

	public static void main(String[] args) {
		new taskC().run();
	}
}
