import java.io.IOException;
import java.io.InputStream;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.NoSuchElementException;
import java.util.concurrent.SynchronousQueue;

public class Main implements Runnable {
	public static void main(String[] args) {
		// long t = System.currentTimeMillis();
		new Thread(null, new Main(), "", Runtime.getRuntime().maxMemory()).start();
		// System.err.println(System.currentTimeMillis() - t);
	}

	String min(String a, String b) {
		if (a.compareTo(b) <= 0) {
			return a;
		} else {
			return b;
		}
	}

	String concat(String a, String b) {
		return min(a + b, b + a);
	}

	class DJSet {
		int n;
		int[] upper;

		public DJSet(int n_) {
			n = n_;
			upper = new int[n_];
			Arrays.fill(upper, -1);
		}

		int root(int x) {
			return upper[x] < 0 ? x : (upper[x] = root(upper[x]));
		}

		boolean equiv(int x, int y) {
			return root(x) == root(y);
		}

		void setUnion(int x, int y) {
			x = root(x);
			y = root(y);
			if (x == y)
				return;
			if (upper[x] < upper[y]) {
				x ^= y;
				y ^= x;
				x ^= y;
			}
			upper[y] += upper[x];
			upper[x] = y;
		}
	}

	int[] col;
	int color;
	int[] ord;
	int order;
	int[] low;
	ArrayDeque<Integer> pnd;

	void scc(ArrayList<Integer>[] g) {
		int n = g.length;
		color = 0;
		order = 0;
		col = new int[n];
		ord = new int[n];
		low = new int[n];
		Arrays.fill(col, -1);
		Arrays.fill(ord, -1);
		pnd = new ArrayDeque<>();
		for (int i = 0; i < n; ++i) {
			if (col[i] != -1) {
				continue;
			}
			scc_dfs(g, i, -1);
		}
	}

	void scc_dfs(ArrayList<Integer>[] g, int cur, int par) {
		ord[cur] = order;
		low[cur] = ord[cur];
		++order;
		pnd.addLast(cur);
		for (int dst : g[cur]) {
			if (col[dst] != -1)
				continue;
			if (ord[dst] == -1) {
				scc_dfs(g, dst, cur);
			}
			low[cur] = Math.min(low[cur], low[dst]);
		}
		if (ord[cur] == low[cur]) {
			int v = -1;
			while (v != cur) {
				v = pnd.pollLast();
				col[v] = color;
			}
			++color;
		}
	}

	int[] sort_ord;
	int[] sort_ref;
	int sort_order;

	void sort_dfs(int cur, ArrayList<Integer>[] g) {
		for (int dst : g[cur]) {
			if (sort_ord[dst] == -1) {
				sort_dfs(dst, g);
			}
		}
		sort_ord[cur] = sort_order++;
		sort_ref[sort_ord[cur]] = cur;
	}

	void sort(ArrayList<Integer>[] g) {
		int n = g.length;
		sort_ord = new int[n];
		sort_ref = new int[n];
		Arrays.fill(sort_ord, -1);
		sort_order = 0;
		for (int i = 0; i < g.length; ++i) {
			if (sort_ord[i] == -1) {
				sort_dfs(i, g);
			}
		}
	}

	String f(ArrayList<Integer>[] g, ArrayList<String> c, int k) {
		int n = g.length;
		scc(g);
		ArrayList<String>[] ss = new ArrayList[color];
		for (int i = 0; i < ss.length; ++i) {
			ss[i] = new ArrayList<>();
		}
		for (int i = 0; i < n; ++i) {
			ss[col[i]].add(c.get(i));
		}
		for (int i = 0; i < color; ++i)
			Collections.sort(ss[i]);
		ArrayList<Integer>[] g2 = new ArrayList[color];
		for (int i = 0; i < g2.length; ++i) {
			g2[i] = new ArrayList<>();
		}
		for (int i = 0; i < g.length; ++i) {
			for (int v : g[i]) {
				if (col[i] == col[v])
					continue;
				g2[col[i]].add(col[v]);
			}
		}

		sort(g2);

		String[][] cur = new String[color][k + 1];
		for (int i = 0; i < color; ++i) {
			for (int j = 0; j <= k; ++j) {
				cur[i][j] = "{";
			}
			cur[i][0] = "";
		}
		String[] ss2 = new String[color];
		for (int i = 0; i < color; ++i) {
			String s = "";
			for (String u : ss[i]) {
				s += u;
			}
			ss2[i] = s;
		}


		String[][] ret = new String[color][k + 1];
		for (int i = 0; i < ret.length; ++i) {
			for (int j = 0; j < ret[i].length; ++j) {
				ret[i][j] = "{";
			}
			ret[i][0] = "";
		}
		for (int i = 0; i < color; ++i) {
			String[] pre = new String[k + 1];
			for (int j = 0; j <= k; ++j)
				pre[j] = "{";
			pre[0] = "";
			for (int dst : g2[sort_ord[i]]) {
				for (int j = 0; j <= k; ++j) {
					pre[j] = min(pre[j], ret[dst][j]);
				}
			}
			for (int j = 0; j <= ss2[sort_ord[i]].length(); ++j) {
				for (int l = 0; j + l <= k; ++l) {
					if (pre[l].equals("{") || ss2[sort_ord[i]].equals("{"))
						continue;
					ret[sort_ord[i]][j + l] = min(ret[sort_ord[i]][j + l], ss2[sort_ord[i]].substring(0, j) + pre[l]);
				}
			}
		}
		String res = "{";
		for (int i = 0; i < color; ++i) {
			res = min(res, ret[i][k]);
		}
		return res;
	}

	String solve(int n, int m, int k, char[] c, int[] a, int[] b) {
		DJSet ds = new DJSet(n);
		for (int i = 0; i < m; ++i) {
			ds.setUnion(a[i], b[i]);
		}
		@SuppressWarnings("unchecked")
		ArrayList<Integer>[] vv = new ArrayList[n];
		ArrayList<Integer>[][] gg = new ArrayList[n][];
		ArrayList<String>[] cc = new ArrayList[n];
		for (int i = 0; i < n; ++i) {
			vv[i] = new ArrayList<>();
			cc[i] = new ArrayList<>();
		}
		for (int i = 0; i < n; ++i) {
			vv[ds.root(i)].add(i);
		}
		for (int i = 0; i < n; ++i) {
			Collections.sort(vv[i]);
			for (int v : vv[i]) {
				cc[i].add(c[v] + "");
			}
		}
		int[] id = new int[n];
		for (int i = 0; i < n; ++i) {
			int r = ds.root(i);
			id[i] = Collections.binarySearch(vv[r], i);
		}
		boolean[] vis = new boolean[n];
		for (int i = 0; i < n; ++i) {
			int r = ds.root(i);
			if (vis[r])
				continue;
			vis[r] = true;
			gg[r] = new ArrayList[vv[r].size()];
			for (int j = 0; j < gg[r].length; ++j)
				gg[r][j] = new ArrayList<>();
		}
		for (int i = 0; i < m; ++i) {
			int r = ds.root(a[i]);
			gg[r][id[a[i]]].add(id[b[i]]);
		}
		String ret = "{";
		for (int i = 0; i < n; ++i) {
			if (gg[i] == null)
				continue;
			ret = min(ret, f(gg[i], cc[i], k));
		}
		if (ret.equals("{")) {
			return "-1";
		} else {
			return ret;
		}
	}

	public void run() {
		Scanner sc = new Scanner();
		int n = sc.nextInt();
		int m = sc.nextInt();
		int k = sc.nextInt();
		char[] c = new char[n];
		for (int i = 0; i < n; ++i) {
			c[i] = sc.next().toCharArray()[0];
		}
		int[] a = new int[m];
		int[] b = new int[m];
		for (int i = 0; i < m; ++i) {
			a[i] = sc.nextInt();
			b[i] = sc.nextInt();
			--a[i];
			--b[i];
		}

		System.out.println(solve(n, m, k, c, a, b));
	}

	static void tr(Object... objects) {
		System.out.println(Arrays.deepToString(objects));
	}

	class Scanner {
		private final InputStream in = System.in;
		private final byte[] buffer = new byte[1024];
		private int ptr = 0;
		private int buflen = 0;

		private boolean hasNextByte() {
			if (ptr < buflen) {
				return true;
			} else {
				ptr = 0;
				try {
					buflen = in.read(buffer);
				} catch (IOException e) {
					e.printStackTrace();
				}
				if (buflen <= 0) {
					return false;
				}
			}
			return true;
		}

		private int readByte() {
			if (hasNextByte())
				return buffer[ptr++];
			else
				return -1;
		}

		private boolean isPrintableChar(int c) {
			return 33 <= c && c <= 126;
		}

		private void skipUnprintable() {
			while (hasNextByte() && !isPrintableChar(buffer[ptr]))
				ptr++;
		}

		public boolean hasNext() {
			skipUnprintable();
			return hasNextByte();
		}

		public String next() {
			if (!hasNext())
				throw new NoSuchElementException();
			StringBuilder sb = new StringBuilder();
			int b = readByte();
			while (isPrintableChar(b)) {
				sb.appendCodePoint(b);
				b = readByte();
			}
			return sb.toString();
		}

		public int nextInt() {
			if (!hasNext())
				throw new NoSuchElementException();
			int n = 0;
			boolean minus = false;
			int b = readByte();
			if (b == '-') {
				minus = true;
				b = readByte();
			}
			if (b < '0' || '9' < b) {
				throw new NumberFormatException();
			}
			while (true) {
				if ('0' <= b && b <= '9') {
					n *= 10;
					n += b - '0';
				} else if (b == -1 || !isPrintableChar(b)) {
					return minus ? -n : n;
				} else {
					throw new NumberFormatException();
				}
				b = readByte();
			}
		}

		public long nextLong() {
			if (!hasNext())
				throw new NoSuchElementException();
			long n = 0;
			boolean minus = false;
			int b = readByte();
			if (b == '-') {
				minus = true;
				b = readByte();
			}
			if (b < '0' || '9' < b) {
				throw new NumberFormatException();
			}
			while (true) {
				if ('0' <= b && b <= '9') {
					n *= 10;
					n += b - '0';
				} else if (b == -1 || !isPrintableChar(b)) {
					return minus ? -n : n;
				} else {
					throw new NumberFormatException();
				}
				b = readByte();
			}
		}
	}
} Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.