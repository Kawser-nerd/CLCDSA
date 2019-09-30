import java.io.*;
import java.util.*;

public class A {
	FastScanner in;
	PrintWriter out;

	ArrayList<Integer>[] g;

	int[] state;
	int curCnt;

	void go(int v) {
		for (int i = 0; i < g[v].size(); i++) {
			int to = g[v].get(i);
			if (state[to] == 1) {
				curCnt++;
				state[to] = 2;
				go(to);
			}
		}
	}

	void go2(int v) {
		if (state[v] == 2) {
			curCnt--;
		}
		state[v] = 3;
		for (int i = 0; i < g[v].size(); i++) {
			int to = g[v].get(i);
			if (state[to] != 3) {
				go2(to);
			}
		}
	}

	void solve() {
		int tc = in.nextInt();
		for (int t = 0; t < tc; t++) {
			out.print("Case #" + (t + 1) + ": ");
			int n = in.nextInt();
			g = new ArrayList[n];
			for (int i = 0; i < n; i++) {
				g[i] = new ArrayList<>();
			}
			int d = in.nextInt();
			int s0 = in.nextInt(), as = in.nextInt(), cs = in.nextInt(), rs = in
					.nextInt();
			int m0 = in.nextInt(), am = in.nextInt(), cm = in.nextInt(), rm = in
					.nextInt();
			int[] s = new int[n];
			int[] m = new int[n];
			s[0] = s0;
			m[0] = m0;
			for (int i = 0; i + 1 < n; i++) {
				s[i + 1] = (s[i] * as + cs) % rs;
				m[i + 1] = (m[i] * am + cm) % rm;
			}
			for (int i = 1; i < n; i++) {
				m[i] %= i;
			}
			for (int i = 1; i < n; i++) {
				g[m[i]].add(i);
			}
			O[] a = new O[n];
			for (int i = 0; i < n; i++) {
				a[i] = new O(i, s[i]);
			}
			Arrays.sort(a);
			int it = 0;
			curCnt = 0;
			state = new int[n];
			int result = 0;
			for (O o : a) {
				// add o
				if (state[o.id] == 3) {
					continue;
				}
				if (o.id == 0) {
					state[o.id] = 2;
				} else {
					if (state[m[o.id]] == 2) {
						state[o.id] = 2;
					} else {
						state[o.id] = 1;
					}
				}
				if (state[o.id] == 2) {
					curCnt++;
					go(o.id);
				}
				while (o.sal - d > a[it].sal) {
					// remove a[it];
					go2(a[it].id);
					it++;
				}

				if (state[0] == 2) {
					result = Math.max(result, curCnt);
				}
			}
			out.println(result);
			System.err.println((t + 1) + "/" + tc + " done");
		}
	}

	class O implements Comparable<O> {
		int id;
		int sal;

		public O(int id, int sal) {
			super();
			this.id = id;
			this.sal = sal;
		}

		@Override
		public int compareTo(O o) {
			return Integer.compare(sal, o.sal);
		}

		@Override
		public String toString() {
			return "O [id=" + id + ", sal=" + sal + "]";
		}

	}

	void run() {
		try {
			in = new FastScanner(new File("A.in"));
			out = new PrintWriter(new File("A.out"));

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
		new A().run();
	}
}