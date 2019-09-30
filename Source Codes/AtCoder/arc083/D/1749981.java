import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.InputMismatchException;
import java.util.Scanner;

public class Main implements Runnable {
	static InputStream is;
	static PrintWriter out;
	static String INPUT = "";

	public static void main(String[] args) {
		new Thread(null, new Main(), "", Runtime.getRuntime().maxMemory()).start();
	}

	static final long MOD = 1_000_000_000 + 7;
	static final int N = 100000;
	static long[] fac = new long[2 * N + 1];
	static long[] invfac = new long[2 * N + 1];
	static long[] inv = new long[2 * N + 1];
	{
		fac[0] = 1;
		invfac[0] = 1;
		inv[1] = 1;
		for (int i = 1; i < fac.length; ++i)
			fac[i] = fac[i - 1] * i % MOD;
		for (int i = 2; i < inv.length; ++i) {
			inv[i] = MOD - inv[(int) (MOD % i)] * (MOD / i) % MOD;
		}
		for (int i = 1; i < invfac.length; ++i) {
			invfac[i] = invfac[i - 1] * inv[i] % MOD;
		}
	}

	static long c(int n, int k) {
		return fac[n] * invfac[k] % MOD * invfac[n - k] % MOD;
	}

	static class DJSet {
		int[] upper;
		int[] e_sz;
		int n;

		public DJSet(int n_) {
			n = n_;
			upper = new int[n];
			e_sz = new int[n];
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
			if (x == y) {
				++e_sz[x];
				return;
			}
			if (upper[x] < upper[y]) {
				x ^= y;
				y ^= x;
				x ^= y;
			}
			upper[y] += upper[x];
			upper[x] = y;
			e_sz[y] += e_sz[x] + 1;
			e_sz[x] = -1;
		}

		int sz(int x) {
			return -upper[root(x)];
		}
	}

	static void scc(ArrayList<Integer>[] g) {
		int n = g.length;
		for (int i = 0; i < n; ++i) {
			col[i] = -1;
			ord[i] = -1;
			col_sz[i] = 0;
		}
		ArrayDeque<Integer> pend = new ArrayDeque<>();
		order = 0;
		color = 0;
		for (int i = 0; i < n; ++i) {
			if (col[i] == -1)
				scc_dfs(i, -1, g, pend);
		}
	}

	static void scc_dfs(int cur, int par, ArrayList<Integer>[] g, ArrayDeque<Integer> pend) {
		pend.addLast(cur);
		ord[cur] = order++;
		low[cur] = ord[cur];
		for (int dst : g[cur]) {
			if (dst == par || col[dst] != -1)
				continue;
			if (ord[dst] != -1) {
				low[cur] = Math.min(low[cur], low[dst]);
			} else {
				scc_dfs(dst, cur, g, pend);
				low[cur] = Math.min(low[cur], low[dst]);
			}
		}
		if (ord[cur] == low[cur]) {
			int v = -1;
			while (v != cur) {
				v = pend.pollLast();
				col[v] = color;
				col_sz[color]++;
			}
			++color;
		}
	}

	static int[] col = new int[200000];
	static int[] col_sz = new int[200000];
	static int[] ord = new int[200000];
	static int[] low = new int[200000];

	static int color;
	static int order;

	static long[] dfs2(int cur, ArrayList<Integer>[] g, boolean[] vis) {
		long pat = 1;
		int sz = 0;
		vis[cur] = true;
		for (int dst : g[cur]) {
			long[] q = dfs2(dst, g, vis);
			sz += q[1];
			pat = pat * q[0] % MOD * c(sz, (int) q[1]) % MOD;
		}
		sz += 1;
		return new long[] { pat, sz };
	}

	static void dfs1(ArrayList<Integer>[] g, int cur, int par, int[] forward, ArrayList<Integer>[] backward) {
		boolean update = false;
		for (int v : g[cur]) {
			if (v == par)
				continue;
			if (backward[v].size() == 0) {
				if (col_sz[col[cur]] > 1 && col_sz[col[v]] > 1) {
					if (update)
						continue;
					else
						update = true;
				}
				forward[v] = cur;
				backward[cur].add(v);
				dfs1(g, v, cur, forward, backward);
			} else if (col_sz[col[cur]] > 1 && col_sz[col[v]] > 1 && !update) {
				forward[v] = cur;
				backward[cur].add(v);
				update = true;
			}
		}
	}

	static long f(ArrayList<Integer>[] g, ArrayList<Integer> v) {

		int n = g.length;
		ArrayList<Integer>[] g2 = new ArrayList[n];
		for (int i = 0; i < g2.length; ++i)
			g2[i] = new ArrayList<>(2);

		scc(g);

		long ret = 0;

		int[] forward = new int[n];
		ArrayList<Integer>[] backward = new ArrayList[n];
		for (int i = 0; i < n; ++i) {
			backward[i] = new ArrayList<>(2);
		}

		for (int i = 0; i < n; ++i) {
			if (col_sz[col[i]] > 1) {
				dfs1(g, i, -1, forward, backward);
				break;
			}
		}
		for (int t = 0; t < 2; ++t) {
			for (int i = 0; i < g2.length; ++i)
				g2[i].clear();
			Arrays.fill(ord, -1);
			for (int i = 0; i < n; ++i) {
				for (int b : backward[i]) {
					if (v.get(b) < v.get(forward[i])) {
						g2[i].add(b);
						ord[b] = i;
					}
				}
			}
			int sz = 0;
			long ans = 1;
			boolean[] vis = new boolean[n];
			for (int i = 0; i < n; ++i) {
				if (vis[i])
					continue;
				int j = i;
				while (ord[j] != -1) {
					j = ord[j];
				}
				long[] q = dfs2(j, g2, vis);
				sz += q[1];
				ans = ans * q[0] % MOD * c((int) sz, (int) q[1]) % MOD;
			}
			ret = ret + ans;
			if (ret >= MOD)
				ret -= MOD;
			if (t == 0) {
				int[] nf = new int[n];
				ArrayList<Integer>[] nb = new ArrayList[n];
				for (int i = 0; i < n; ++i) {
					nb[i] = new ArrayList<>(2);
				}
				for (int i = 0; i < n; ++i) {
					int u = forward[i];
					if (col_sz[col[i]] == 1) {
						nf[i] = u;
						nb[u].add(i);
					} else if (col_sz[col[i]] > 1 && col_sz[col[u]] > 1) {
						nf[u] = i;
						nb[i].add(u);
					}
				}
				backward = nb;
				forward = nf;
			}
		}
		return ret;

	}

	static long solve(int n, int[] x, int[] y) {
		int n2 = 2 * n;
		DJSet ds = new DJSet(n2);
		ArrayList<Integer>[] vv = new ArrayList[n2];
		ArrayList<Integer>[][] gg = new ArrayList[n2][];
		for (int i = 0; i < n2; ++i) {
			vv[i] = new ArrayList<>();
		}
		for (int i = 0; i < n2; ++i) {
			ds.setUnion(x[i], y[i] + n);
		}

		for (int i = 0; i < n2; ++i) {
			vv[ds.root(i)].add(i);
		}
		for (int i = 0; i < n2; ++i) {
			Collections.sort(vv[i]);
			for (int v : vv[i])
				col[v] = Collections.binarySearch(vv[i], v);
			int vvi_size = vv[i].size();
			gg[i] = new ArrayList[vvi_size];
			for (int j = 0; j < vvi_size; ++j)
				gg[i][j] = new ArrayList<>();
		}
		for (int i = 0; i < n2; ++i) {
			int r = ds.root(x[i]);
			int u = col[x[i]];
			int v = col[y[i] + n];
			gg[r][u].add(v);
			gg[r][v].add(u);
		}
		long ans = 1;
		int tot = 0;
		for (int i = 0; i < n2; ++i) {
			if (gg[i].length == 0)
				continue;
			if (ds.sz(i) != ds.e_sz[ds.root(i)]) {
				return 0;
			}
			tot += gg[i].length;
			ans = ans * f(gg[i], vv[i]) % MOD * c(tot, gg[i].length) % MOD;
		}
		return ans;
	}

	public void run() {
		is = INPUT.isEmpty() ? System.in : new ByteArrayInputStream(INPUT.getBytes());
		out = new PrintWriter(System.out);
		// long t = System.currentTimeMillis();
		int n = ni();
		int n2 = 2 * n;
		for (int i = 0; i < n2; ++i) {
			ord[i] = ni();
			low[i] = ni();
			--ord[i];
			--low[i];
		}
		out.println(solve(n, ord, low));
		out.flush();
		// System.err.println(System.currentTimeMillis() - t);
	}

	static void tr(Object... objects) {
		System.out.println(Arrays.deepToString(objects));
	}

	private static boolean eof() {
		if (lenbuf == -1)
			return true;
		int lptr = ptrbuf;
		while (lptr < lenbuf)
			if (!isSpaceChar(inbuf[lptr++]))
				return false;

		try {
			is.mark(1000);
			while (true) {
				int b = is.read();
				if (b == -1) {
					is.reset();
					return true;
				} else if (!isSpaceChar(b)) {
					is.reset();
					return false;
				}
			}
		} catch (IOException e) {
			return true;
		}
	}

	private static byte[] inbuf = new byte[1024];
	static int lenbuf = 0, ptrbuf = 0;

	private static int readByte() {
		if (lenbuf == -1)
			throw new InputMismatchException();
		if (ptrbuf >= lenbuf) {
			ptrbuf = 0;
			try {
				lenbuf = is.read(inbuf);
			} catch (IOException e) {
				throw new InputMismatchException();
			}
			if (lenbuf <= 0)
				return -1;
		}
		return inbuf[ptrbuf++];
	}

	private static boolean isSpaceChar(int c) {
		return !(c >= 33 && c <= 126);
	}

	// private static boolean isSpaceChar(int c) { return !(c >= 32 && c <=
	// 126); }
	private static int skip() {
		int b;
		while ((b = readByte()) != -1 && isSpaceChar(b))
			;
		return b;
	}

	private static double nd() {
		return Double.parseDouble(ns());
	}

	private static char nc() {
		return (char) skip();
	}

	private static String ns() {
		int b = skip();
		StringBuilder sb = new StringBuilder();
		while (!(isSpaceChar(b))) {
			sb.appendCodePoint(b);
			b = readByte();
		}
		return sb.toString();
	}

	private static char[] ns(int n) {
		char[] buf = new char[n];
		int b = skip(), p = 0;
		while (p < n && !(isSpaceChar(b))) {
			buf[p++] = (char) b;
			b = readByte();
		}
		return n == p ? buf : Arrays.copyOf(buf, p);
	}

	private static char[][] nm(int n, int m) {
		char[][] map = new char[n][];
		for (int i = 0; i < n; i++)
			map[i] = ns(m);
		return map;
	}

	private static int[] na(int n) {
		int[] a = new int[n];
		for (int i = 0; i < n; i++)
			a[i] = ni();
		return a;
	}

	private static int ni() {
		int num = 0, b;
		boolean minus = false;
		while ((b = readByte()) != -1 && !((b >= '0' && b <= '9') || b == '-'))
			;
		if (b == '-') {
			minus = true;
			b = readByte();
		}

		while (true) {
			if (b >= '0' && b <= '9') {
				num = num * 10 + (b - '0');
			} else {
				return minus ? -num : num;
			}
			b = readByte();
		}
	}

	private static long nl() {
		long num = 0;
		int b;
		boolean minus = false;
		while ((b = readByte()) != -1 && !((b >= '0' && b <= '9') || b == '-'))
			;
		if (b == '-') {
			minus = true;
			b = readByte();
		}

		while (true) {
			if (b >= '0' && b <= '9') {
				num = num * 10 + (b - '0');
			} else {
				return minus ? -num : num;
			}
			b = readByte();
		}
	}
} Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.