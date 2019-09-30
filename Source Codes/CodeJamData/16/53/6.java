import java.util.*;
import java.io.*;

public class C {
	FastScanner in;
	PrintWriter out;

	class Point {
		int x, y, z;

		public Point(int x, int y, int z) {
			super();
			this.x = x;
			this.y = y;
			this.z = z;
		}
	}

	int dist(Point p, Point q) {
		int dx = p.x - q.x;
		int dy = p.y - q.y;
		int dz = p.z - q.z;
		return dx * dx + dy * dy + dz * dz;
	}

	public void solve() throws IOException {
		int n = in.nextInt();
		int s = in.nextInt();
		Point[] pts = new Point[n];
		Point[] vel = new Point[n];
		for (int i = 0; i < n; i++) {
			pts[i] = new Point(in.nextInt(), in.nextInt(), in.nextInt());
			vel[i] = new Point(in.nextInt(), in.nextInt(), in.nextInt());
		}
		int MAX_DIST = 5 * 1000 * 1000;
		int l = -1, r = MAX_DIST;
		while (r - l > 1) {
			int mid = (l + r) / 2;
			int[] q = new int[n];
			boolean[] was = new boolean[n];
			int st = 0, en = 0;
			q[en++] = 0;
			was[0] = true;
			while (st != en) {
				int v = q[st++];
				for (int u = 0; u < n; u++) {
					if (!was[u] && dist(pts[u], pts[v]) <= mid) {
						was[u] = true;
						q[en++] = u;
					}
				}
			}
			if (was[1]) {
				r = mid;
			} else {
				l = mid;
			}
		}
		out.println(Math.sqrt(r));
	}

	public void run() {
		try {
			in = new FastScanner(new File("a.in"));
			out = new PrintWriter(new File("a.out"));

			int tn = in.nextInt();
			for (int i = 0; i < tn; i++) {
				System.err.println(i);
				out.print("Case #" + (i + 1) + ": ");
				solve();
			}

			out.close();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}

	class FastScanner {
		BufferedReader br;
		StringTokenizer st;

		FastScanner(File f) {
			try {
				br = new BufferedReader(new FileReader(f));
			} catch (FileNotFoundException e) {
				e.printStackTrace();
			}
		}

		String next() {
			while (st == null || !st.hasMoreTokens()) {
				try {
					st = new StringTokenizer(br.readLine());
				} catch (IOException e) {
					e.printStackTrace();
				}
			}
			return st.nextToken();
		}

		int nextInt() {
			return Integer.parseInt(next());
		}

		long nextLong() {
			return Long.parseLong(next());
		}

		double nextDouble() {
			return Double.parseDouble(next());
		}
	}

	public static void main(String[] arg) {
		new C().run();
	}
}