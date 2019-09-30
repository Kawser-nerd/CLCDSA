import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Arrays;

public class Main {
	static InputStream is;
	static PrintWriter out;
	static String INPUT = "";

	public static void main(String[] args) throws Exception {
		new Main().run();
	}

	void solver() {
		int N = ni();
		int A = ni();
		int[] x = new int[A];
		int[] y = new int[A];
		for (int i = 0; i < A; i++) {
			x[i] = ni() - 1;
			y[i] = ni() - 1;
		}
		int B = ni();
		int[] u = new int[B];
		int[] v = new int[B];
		for (int i = 0; i < B; i++) {
			u[i] = ni() - 1;
			v[i] = ni() - 1;
		}
		int max = 0;
		for (int mask = 0; mask < (1 << B); mask++) {
			ArrayList<Integer>[] g = new ArrayList[N];
			for (int i = 0; i < N; i++) {
				g[i] = new ArrayList<>();
			}
			NG = new boolean[N];
			for (int i = 0; i < A; i++) {
				g[y[i]].add(x[i]);
			}
			for (int i = 0; i < B; i++) {
				if (((mask >> i) & 1) == 1) {
					NG[u[i]] = true;
				} else {
					g[u[i]].add(v[i]);
				}
			}
			for (int i = 0; i < N; i++) {
				if (NG[i])
					dfs(i, -1, g);
			}
			int[] scc = stronglyConnectedComponents(g, NG);
			ArrayList<Integer>[] comp = new ArrayList[N];
			for (int i = 0; i < N; i++)
				comp[i] = new ArrayList<>();
			for (int i = 0; i < N; i++) {
				if (scc[i] == -1)
					continue;
				comp[scc[i]].add(i);
			}
			for (int i = 0; i < N; i++) {
				if (comp[i].size() > 1) {
					for (int element : comp[i]) {
						NG[element] = true;
					}
				}
			}
			for (int i = 0; i < N; i++) {
				if (NG[i])
					dfs(i, -1, g);
			}
			int ans = N;
			for (int i = 0; i < N; i++)
				if (NG[i])
					ans--;
			max = Math.max(max, ans);
		}
		out.println(max);
	}

	void dfs(int cur, int par, ArrayList<Integer>[] g) {
		NG[cur] = true;
		for (int to : g[cur]) {
			if (to != cur && !NG[to]) {
				dfs(to, cur, g);
			}
		}
	}

	int[] dfsnum;
	int[] low;
	ArrayDeque<Integer> S = new ArrayDeque<>();
	ArrayDeque<Integer> T = new ArrayDeque<>();
	int N;
	int NOW;
	boolean[] used;
	int[] ret;
	boolean[] NG;

	int[] stronglyConnectedComponents(ArrayList<Integer>[] g, boolean[] NG) {
		int n = g.length;
		dfsnum = new int[n];
		low = new int[n];
		used = new boolean[n];
		ret = new int[n];
		S.clear();
		T.clear();
		N = 0;
		NOW = 0;
		Arrays.fill(ret, -1);
		for (int i = 0; i < n; i++) {
			if (NG[i] || used[i])
				continue;
			if (dfsnum[i] == 0) {
				dfs(g, i, NG);
			}
		}
		return ret;
	}

	void dfs(ArrayList<Integer>[] g, int i, boolean[] NG) {
		S.addFirst(i);
		dfsnum[i] = N;
		N++;
		low[i] = dfsnum[i];
		for (int j : g[i]) {
			if (NG[j] || used[j])
				continue;
			if (!T.contains(j)) {
				T.add(j);
				dfs(g, j, NG);
				low[i] = Math.min(low[i], low[j]);
			} else {
				low[i] = Math.min(dfsnum[j], low[i]);
			}
		}
		if (low[i] == dfsnum[i]) {
			int v;
			do {
				v = S.removeFirst();
				ret[v] = NOW;
				used[v] = true;
			} while (v != i);
			NOW++;
		}
		return;
	}

	void run() {
		is = INPUT.isEmpty() ? System.in : new ByteArrayInputStream(INPUT.getBytes());
		out = new PrintWriter(System.out);
		solver();
		out.flush();

	}

	static long nl() {
		try {
			long num = 0;
			boolean minus = false;
			while ((num = is.read()) != -1 && !((num >= '0' && num <= '9') || num == '-'))
				;
			if (num == '-') {
				num = 0;
				minus = true;
			} else {
				num -= '0';
			}

			while (true) {
				int b = is.read();
				if (b >= '0' && b <= '9') {
					num = num * 10 + (b - '0');
				} else {
					return minus ? -num : num;
				}
			}
		} catch (IOException e) {
		}
		return -1;
	}

	static char nc() {
		try {
			int b = skip();
			if (b == -1)
				return 0;
			return (char) b;
		} catch (IOException e) {
		}
		return 0;
	}

	static double nd() {
		try {
			return Double.parseDouble(ns());
		} catch (Exception e) {
		}
		return 0;
	}

	static String ns() {
		try {
			int b = skip();
			StringBuilder sb = new StringBuilder();
			if (b == -1)
				return "";
			sb.append((char) b);
			while (true) {
				b = is.read();
				if (b == -1)
					return sb.toString();
				if (b <= ' ')
					return sb.toString();
				sb.append((char) b);
			}
		} catch (IOException e) {
		}
		return "";
	}

	public static char[] ns(int n) {
		char[] buf = new char[n];
		try {
			int b = skip(), p = 0;
			if (b == -1)
				return null;
			buf[p++] = (char) b;
			while (p < n) {
				b = is.read();
				if (b == -1 || b <= ' ')
					break;
				buf[p++] = (char) b;
			}
			return Arrays.copyOf(buf, p);
		} catch (IOException e) {
		}
		return null;
	}

	public static byte[] nse(int n) {
		byte[] buf = new byte[n];
		try {
			int b = skip();
			if (b == -1)
				return null;
			is.read(buf);
			return buf;
		} catch (IOException e) {
		}
		return null;
	}

	static int skip() throws IOException {
		int b;
		while ((b = is.read()) != -1 && !(b >= 33 && b <= 126))
			;
		return b;
	}

	static boolean eof() {
		try {
			is.mark(1000);
			int b = skip();
			is.reset();
			return b == -1;
		} catch (IOException e) {
			return true;
		}
	}

	static int ni() {
		try {
			int num = 0;
			boolean minus = false;
			while ((num = is.read()) != -1 && !((num >= '0' && num <= '9') || num == '-'))
				;
			if (num == '-') {
				num = 0;
				minus = true;
			} else {
				num -= '0';
			}

			while (true) {
				int b = is.read();
				if (b >= '0' && b <= '9') {
					num = num * 10 + (b - '0');
				} else {
					return minus ? -num : num;
				}
			}
		} catch (IOException e) {
		}
		return -1;
	}

	static void tr(Object... o) {
		System.out.println(Arrays.deepToString(o));
	}
} Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.