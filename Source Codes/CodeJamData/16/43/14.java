import java.io.*;
import java.util.*;

public class C {
	FastScanner in;
	PrintWriter out;

	class Vertex {
		ArrayList<Vertex> g;

		public Vertex() {
			g = new ArrayList<>();
		}

		void clear() {
			g.clear();
		}

		long last;

		void go(long cur) {
			if (last == cur) {
				return;
			}
			last = cur;
			if (realId != -1) {
				was[realId] = true;
			}
			for (Vertex to : g) {
				to.go(cur);
			}
		}

		int realId = -1;
	}

	Random rnd = new Random(123);

	class Cell {
		Vertex up, down, right, left;

		Cell() {
			up = new Vertex();
			down = new Vertex();
			right = new Vertex();
			left = new Vertex();
		}

		void clear() {
			up.clear();
			down.clear();
			left.clear();
			right.clear();
		}
	}

	void gr(Vertex v1, Vertex v2) {
		v1.g.add(v2);
		v2.g.add(v1);
	}

	boolean[] was;

	void solve() {
		int tc = in.nextInt();
		for (int t = 0; t < tc; t++) {
			out.println("Case #" + (t + 1) + ": ");
			int n = in.nextInt();
			int m = in.nextInt();
			int tot = 2 * (n + m);
			int[] a = new int[tot];
			for (int i = 0; i < tot; i++) {
				a[i] = in.nextInt() - 1;
			}
			Cell[][] o = new Cell[n][m];
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++) {
					o[i][j] = new Cell();
				}
			}
			int it = 0;
			ArrayList<Vertex> all = new ArrayList<>();
			for (int i = 0; i < m; i++) {
				o[0][i].up.realId = it++;
				all.add(o[0][i].up);
			}
			for (int i = 0; i < n; i++) {
				o[i][m - 1].right.realId = it++;
				all.add(o[i][m - 1].right);
			}
			for (int i = m - 1; i >= 0; i--) {
				o[n - 1][i].down.realId = it++;
				all.add(o[n - 1][i].down);
			}
			for (int i = n - 1; i >= 0; i--) {
				o[i][0].left.realId = it++;
				all.add(o[i][0].left);
			}
			was = new boolean[it];
			boolean found = false;
			for (int mask = 0; mask < 1 << (n * m); mask++) {
				char[][] s = new char[n][m];
				if (found) {
					break;
				}
				for (int i = 0; i < n; i++) {
					for (int j = 0; j < m; j++) {
						o[i][j].clear();
					}
				}
				it = 0;
				for (int i = 0; i < n; i++) {
					for (int j = 0; j < m; j++) {
						if (((1 << it) & mask) != 0) {
							s[i][j] = '/';
							gr(o[i][j].left, o[i][j].up);
							gr(o[i][j].right, o[i][j].down);
						} else {
							s[i][j] = '\\';
							gr(o[i][j].left, o[i][j].down);
							gr(o[i][j].right, o[i][j].up);
						}
						it++;
					}
				}
				for (int i = 0; i < n; i++) {
					for (int j = 0; j + 1 < m; j++) {
						gr(o[i][j].right, o[i][j + 1].left);
					}
				}
				for (int i = 0; i + 1 < n; i++) {
					for (int j = 0; j < m; j++) {
						gr(o[i][j].down, o[i + 1][j].up);
					}
				}
				boolean ok = true;
				for (int i = 0; i < a.length; i += 2) {
					Arrays.fill(was, false);
					all.get(a[i]).go(rnd.nextLong());
					if (!was[a[i + 1]]) {
						ok = false;
					}
					int cc = 0;
					for (boolean z : was) {
						cc += z ? 1 : 0;
					}
					if (cc != 2) {
						ok = false;
					}
				}
				if (ok) {
					found = true;
					for (int i = 0; i < n; i++) {
						for (int j = 0; j < m; j++) {
							out.print(s[i][j]);
						}
						out.println();
					}
				}
			}
			if (!found) {
				out.println("IMPOSSIBLE");
			}
			System.err.println((t + 1) + "/" + tc + " done");
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