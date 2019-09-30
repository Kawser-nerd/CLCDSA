import java.io.*;
import java.util.*;

public class Main {

	static final int INF = Integer.MAX_VALUE / 3;

	int[] head;
	int[] next;
	int[] to;
	int[] cost;

	void addEdge(int v, int u, int c, int idx) {
		to[idx] = u;
		cost[idx] = c;
		next[idx] = head[v];
		head[v] = idx;
	}

	int[] sz;
	boolean[] isCenter;

	int n;

	long sum;

	int[] par;

	void dfs1(int v, int pEdge) {
		sz[v] = 1;
		par[v] = pEdge;

		int maxC = -1;

		for (int e = head[v]; e >= 0; e = next[e]) {
			int u = to[e];
			if ((e ^ pEdge) != 1) {
				dfs1(u, e);
				sz[v] += sz[u];
				maxC = Math.max(maxC, sz[u]);

				sum += (long) cost[e] * 2 * Math.min(sz[u], n - sz[u]);
			}
		}

		maxC = Math.max(maxC, n - sz[v]);
		isCenter[v] = maxC <= n - maxC;
	}

	long fast(int[] vs, int[] us, int[] cs) {
		n = vs.length + 1;
		head = new int[n];
		next = new int[2 * n - 2];
		to = new int[2 * n - 2];
		cost = new int[2 * n - 2];
		Arrays.fill(head, -1);

		for (int i = 0; i < n - 1; i++) {
			int v = vs[i];
			int u = us[i];
			int c = cs[i];
			addEdge(v, u, c, 2 * i);
			addEdge(u, v, c, 2 * i + 1);
		}

		sz = new int[n];
		isCenter = new boolean[n];
		par = new int[n];
		sum = 0;
		dfs1(0, -1);

		for (int i = 0; i < n; i++) {
			if (sz[i] * 2 == n) {
				return sum - cost[par[i]];
			}
		}

		long minSub = Long.MAX_VALUE;

		for (int v = 0; v < n; v++) {
			if (isCenter[v]) {
				for (int e = head[v]; e >= 0; e = next[e]) {
					minSub = Math.min(minSub, cost[e]);
				}
			}
		}

		return sum - minSub;
	}

	long slow(int[] vs, int[] us, int[] cs) {
		int n = vs.length + 1;
		int[][] g = new int[n][n];
		for (int i = 0; i < n; i++) {
			Arrays.fill(g[i], INF);
			g[i][i] = 0;
		}

		for (int i = 0; i < n - 1; i++) {
			int v = vs[i];
			int u = us[i];
			g[v][u] = g[u][v] = cs[i];
		}

		for (int k = 0; k < n; k++) {
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					g[i][j] = Math.min(g[i][j], g[i][k] + g[k][j]);
				}
			}
		}

		int[] p = new int[n];
		for (int i = 0; i < n; i++) {
			p[i] = i;
		}

		int ret = -1;

		int[] cert = null;

		do {
			int cur = 0;
			for (int i = 0; i < n - 1; i++) {
				cur += g[p[i]][p[i + 1]];
			}
			if (cur > ret) {
				ret = cur;
				cert = p.clone();
			}
		} while (nextPermutation(p));

		// System.err.println(Arrays.toString(cert));
		return ret;
	}

	static boolean nextPermutation(int[] a) {
		int n = a.length;
		int ptr = n - 1;
		while (ptr > 0 && a[ptr - 1] >= a[ptr]) {
			ptr--;
		}

		for (int i = ptr, j = n - 1; i < j; i++, j--) {
			int tmp = a[i];
			a[i] = a[j];
			a[j] = tmp;
		}

		if (ptr == 0) {
			return false;
		}

		for (int i = ptr;; i++) {
			if (a[ptr - 1] < a[i]) {
				int tmp = a[ptr - 1];
				a[ptr - 1] = a[i];
				a[i] = tmp;
				return true;
			}
		}
	}

	void submit() {
		int n = nextInt();
		int[] vs = new int[n - 1];
		int[] us = new int[n - 1];
		int[] cs = new int[n - 1];

		for (int i = 0; i < n - 1; i++) {
			vs[i] = nextInt() - 1;
			us[i] = nextInt() - 1;
			cs[i] = nextInt();
		}

//		out.println(slow(vs, us, cs));
		out.println(fast(vs, us, cs));
	}

	void preCalc() {

	}

	static final int B = 10;

	void stress() {
		for (int tst = 0;; tst++) {
			int n = rand(2, B);
			int[] vs = new int[n - 1];
			int[] us = new int[n - 1];
			int[] cs = new int[n - 1];

			for (int i = 0; i < n - 1; i++) {
				vs[i] = i + 1;
				us[i] = rand(0, i);
				cs[i] = rand(1, B);
			}

			long fast = fast(vs, us, cs);
			long slow = slow(vs, us, cs);

			if (fast != slow) {
				System.err.println(n);
				for (int i = 0; i < n - 1; i++) {
					System.err.println((vs[i] + 1) + " " + (us[i] + 1) + " "
							+ cs[i]);
				}
				System.err.println(fast + " vs " + slow);
				throw new AssertionError();
			}

			System.err.println(tst);
		}
	}

	void test() {

	}

	Main() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		preCalc();
		submit();
		// stress();
		// test();
		out.close();
	}

	static final Random rng = new Random();

	static int rand(int l, int r) {
		return l + rng.nextInt(r - l + 1);
	}

	public static void main(String[] args) throws IOException {
		new Main();
	}

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;

	String nextToken() {
		while (st == null || !st.hasMoreTokens()) {
			try {
				st = new StringTokenizer(br.readLine());
			} catch (IOException e) {
				throw new RuntimeException(e);
			}
		}
		return st.nextToken();
	}

	String nextString() {
		try {
			return br.readLine();
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
	}

	int nextInt() {
		return Integer.parseInt(nextToken());
	}

	long nextLong() {
		return Long.parseLong(nextToken());
	}

	double nextDouble() {
		return Double.parseDouble(nextToken());
	}
}