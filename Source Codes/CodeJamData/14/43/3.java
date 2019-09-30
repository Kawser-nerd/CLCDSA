import java.io.*;
import java.util.*;

public class C {
	FastScanner in;
	PrintWriter out;

	class Building {
		int x1, y1, x2, y2;

		public Building(int x1, int y1, int x2, int y2) {
			super();
			this.x1 = x1;
			this.y1 = y1;
			this.x2 = x2;
			this.y2 = y2;
		}

	}

	int dx(int x1, int x2, int x3, int x4) {
		if (x3 >= x1 && x3 <= x2)
			return 0;
		if (x4 >= x1 && x4 <= x2)
			return 0;
		if (x1 >= x3 && x1 <= x4)
			return 0;
		if (x2 >= x3 && x2 <= x4)
			return 0;
		if (x2 < x3)
			return x3 - x2 - 1;
		return x1 - x4 - 1;
	}

	int dist(Building b1, Building b2) {
		return Math.max(dx(b1.x1, b1.x2, b2.x1, b2.x2),
				dx(b1.y1, b1.y2, b2.y1, b2.y2));
	}

	void solveTestCase() {
		int w = in.nextInt();
		int h = in.nextInt();
		int b = in.nextInt();
		Building[] a = new Building[b + 2];
		for (int i = 0; i < b; i++) {
			a[i + 1] = new Building(in.nextInt(), in.nextInt(), in.nextInt(),
					in.nextInt());
		}
		a[0] = new Building(-1, 0, -1, h - 1);
		a[a.length - 1] = new Building(w, 0, w, h - 1);
		long[][] d = new long[a.length][a.length];
		for (int i = 0; i < a.length; i++)
			for (int j = i + 1; j < a.length; j++)
				d[i][j] = d[j][i] = dist(a[i], a[j]);
		long[] di = new long[a.length];
		Arrays.fill(di, Long.MAX_VALUE);
		di[0] = 0;
		boolean[] was = new boolean[a.length];
		for (int i = 0; i < a.length; i++) {
			int best = -1;
			for (int j = 0; j < a.length; j++)
				if (!was[j])
					if (best == -1 || di[j] < di[best])
						best = j;
			if (best == -1 || di[best] == Long.MAX_VALUE)
				break;
			for (int j = 0; j < a.length; j++)
				di[j] = Math.min(di[j], di[best] + d[best][j]);
			was[best] = true;
		}
		out.println(di[di.length - 1]);
	}

	void solve() {
		int testNumber = in.nextInt();
		for (int test = 1; test <= testNumber; test++) {
			System.err.println(test);
			out.print("Case #" + test + ": ");
			solveTestCase();
		}
	}

	void run() {
		try {
			in = new FastScanner(new File("C.in"));
			out = new PrintWriter(new File("C.out"));

			solve();

			out.close();
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		}
	}

	void runIO() {

		in = new FastScanner(System.in);
		out = new PrintWriter(System.out);

		solve();

		out.close();
	}

	class FastScanner {
		BufferedReader br;
		StringTokenizer st;

		public FastScanner(File f) {
			try {
				br = new BufferedReader(new FileReader(f));
			} catch (FileNotFoundException e) {
				e.printStackTrace();
			}
		}

		public FastScanner(InputStream f) {
			br = new BufferedReader(new InputStreamReader(f));
		}

		String next() {
			while (st == null || !st.hasMoreTokens()) {
				String s = null;
				try {
					s = br.readLine();
				} catch (IOException e) {
					e.printStackTrace();
				}
				if (s == null)
					return null;
				st = new StringTokenizer(s);
			}
			return st.nextToken();
		}

		boolean hasMoreTokens() {
			while (st == null || !st.hasMoreTokens()) {
				String s = null;
				try {
					s = br.readLine();
				} catch (IOException e) {
					e.printStackTrace();
				}
				if (s == null)
					return false;
				st = new StringTokenizer(s);
			}
			return true;
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

	public static void main(String[] args) {
		new C().run();
	}
}
