import java.io.*;
import java.util.*;

public class C {

	final static int MOD = 1000003;

	private void solve() throws IOException {
		int r = nextInt(), c = nextInt();
		char[][] f = new char[r][c];
		for (int i = 0; i < r; i++) {
			f[i] = nextToken().toCharArray();
		}
		int n = r * c;
		TreeSet<Integer> out[] = new TreeSet[r * c];
		final TreeSet<Integer> in[] = new TreeSet[r * c];
		for (int i = 0; i < r * c; i++) {
			out[i] = new TreeSet<Integer>();
			in[i] = new TreeSet<Integer>();
		}
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				char t = f[i][j];
				int u = i * c + j;
				switch (t) {
				case '|': {
					int j1 = j;
					for (int i1 : new int[] { (i + r - 1) % r, (i + 1) % r }) {
						int v = i1 * c + j1;
						out[u].add(v);
						in[v].add(u);
					}
					break;
				}
				case '-': {
					int i1 = i;
					for (int j1 : new int[] { (j + c - 1) % c, (j + 1) % c }) {
						int v = i1 * c + j1;
						out[u].add(v);
						in[v].add(u);
					}
					break;
				}
				case '/': {
					{
						int i1 = (i + r - 1) % r;
						int j1 = (j + 1) % c;
						int v = i1 * c + j1;
						out[u].add(v);
						in[v].add(u);
					}
					{
						int i1 = (i + 1) % r;
						int j1 = (j + c - 1) % c;
						int v = i1 * c + j1;
						out[u].add(v);
						in[v].add(u);
					}
					break;
				}
				case '\\': {
					{
						int i1 = (i + r - 1) % r;
						int j1 = (j + c - 1) % c;
						int v = i1 * c + j1;
						out[u].add(v);
						in[v].add(u);
					}
					{
						int i1 = (i + 1) % r;
						int j1 = (j + 1) % c;
						int v = i1 * c + j1;
						out[u].add(v);
						in[v].add(u);
					}
					break;
				}
				}
			}
		}
		TreeSet<Integer> ts = new TreeSet<Integer>(new Comparator<Integer>() {

			@Override
			public int compare(Integer o1, Integer o2) {
				int cmp = in[o1].size() - in[o2].size();
				if (cmp != 0)
					return cmp;
				else
					return o1 - o2;
			}
		});
		boolean[] havein = new boolean[n];
		boolean[] haveout = new boolean[n];

		for (int k = 0; k < n; k++) {
			ts.add(k);
		}
		while (!ts.isEmpty()) {
			int u = ts.first();
			// for (int j : ts) {
			// System.err.print(in[j].size() + " ");
			// }
			// System.err.println();
			if (in[u].isEmpty()) {
				this.out.println(0);
				return;
			}
			if (in[u].size() == 1) {
				int v = in[u].first();
				if (haveout[v]) {
					this.out.println(0);
					return;
				}
				haveout[v] = true;
				havein[u] = true;
				ts.remove(u);
				in[u].clear();
				out[v].remove(u);
				for (int j : out[v]) {
					ts.remove(j);
					in[j].remove(v);
					if (!havein[j]) {
						ts.add(j);
					} else {
						System.err.println("WTF");
					}
				}
				out[v].clear();
			} else {
				break;
			}
		}
		// for (int i = 0; i < n; i++) {
		// System.err.println(i + " " + in[i] + " " + out[i]);
		// System.err.println(havein[i]);
		// }
		ArrayList<Integer> e[] = new ArrayList[n];
		DisjointSets ds = new DisjointSets(n);
		int need = 0;
		for (int i = 0; i < n; i++) {
			// e[i] = new ArrayList<Integer>();
			if (in[i].size() != 0 && in[i].size() != 2) {
				System.err.println(in[i].size());
				throw new AssertionError();
			}
			if (!havein[i]) {
				need++;
			}
		}
		for (int i = 0; i < n; i++) {
			if (!havein[i]) {
				for (int j : in[i]) {
					for (int i2 : out[j]) {
						if (i2 != i) {
							ds.union(i, i2);
						}
					}
				}
			}
		}
		int ok = ds.size;
		ok += need - n;
		int res = modPow(2, ok, MOD);
		this.out.println(res);
	}

	int modPow(int a, int pow, int mod) {
		int res = 1;
		while (pow > 0) {
			if ((pow & 1) != 0) {
				res = (int) ((long) res * a % mod);
			}
			a = (int) ((long) a * a % mod);
			pow >>= 1;
		}
		return res;
	}

	public class DisjointSets {
		int[] r;
		int[] p;
		int size;

		public DisjointSets(int n) {
			r = new int[n];
			p = new int[n];
			for (int i = 0; i < n; i++) {
				p[i] = i;
			}
			size = n;
		}

		public int get(int i) {
			if (p[i] != i)
				p[i] = get(p[i]);
			return p[i];
		}

		public void union(int i, int j) {
			i = get(i);
			j = get(j);
			if (i == j)
				return;
			--size;
			if (r[i] < r[j]) {
				p[i] = j;
			} else {
				p[j] = i;
				if (r[i] == r[j])
					r[i]++;
			}
		}

		public void clear() {
			for (int i = 0; i < p.length; i++) {
				p[i] = i;
			}
			Arrays.fill(r, 0);
		}
	}

	public static void main(String[] args) {
		new C().run();
	}

	BufferedReader br;
	StringTokenizer st;
	PrintWriter out;

	static final boolean large = true;

	public void run() {
		try {
			String fileName = "C-" + (large ? "large" : "small");
			br = new BufferedReader(new FileReader(fileName + ".in"));
			out = new PrintWriter(fileName + ".out");
			st = new StringTokenizer("");
			int T = nextInt();
			for (int i = 1; i <= T; i++) {
				out.print("Case #" + i + ": ");
				solve();
			}
			out.close();
		} catch (Throwable e) {
			e.printStackTrace();
			System.exit(239);
		}
	}

	String nextToken() throws IOException {
		while (!st.hasMoreTokens()) {
			String line = br.readLine();
			if (line == null) {
				return null;
			}
			st = new StringTokenizer(line);
		}
		return st.nextToken();
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