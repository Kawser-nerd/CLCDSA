import java.io.*;
import java.util.*;

public class Main {

	int[] next;
	int[] head;
	int[] to;

	static final int P = 1_000_000_007;

	int[] p;
	int[] deg;
	int[] depth;

	Comparator<Integer> byDepth = (o1, o2) -> -Integer.compare(depth[o1],
			depth[o2]);

	void submit() {
		int n = nextInt();
		int[] inp = new int[n];
		for (int i = 0; i < n; i++) {
			inp[i] = nextInt();
		}
		out.println(solve(inp));
		// out.println(slow(inp));
	}

	void remove(int v) {
		dead[v] = true;
		int z = p[v];
		if (z == 0) {
			return;
		}
		deg[z]--;
		if (deg[z] > 1) {
			return;
		}
		int alive = -1;
		for (int e = head[z]; e >= 0; e = next[e]) {
			int u = get(to[e]);
			if (!dead[u]) {
				if (alive != -1) {
					throw new AssertionError();
				}
				alive = u;
			}
		}
		if (alive == -1) {
			throw new AssertionError();
		}
		repr[z] = alive;
		p[alive] = p[z];
	}

	int[] one;
	int[] zero;
	int[] tot;
	boolean[] inQ;

	int goDp(int[] arr, int from, int to) {
		int[] que = new int[2 * (to - from)];
		PriorityQueue<Integer> pq = new PriorityQueue<>(byDepth);
		int sz = 0;
		for (int i = from; i < to; i++) {
			int v = arr[i];
			one[v] = 1;
			zero[v] = 1;
			tot[v] = 2;
			inQ[v] = true;
			pq.add(v);
		}

		while (!pq.isEmpty()) {
			int v = pq.poll();
			que[sz++] = v;
			if (v == 0) {
				continue;
			}
			zero[v] = tot[v] - one[v];
			if (zero[v] < 0) {
				zero[v] += P;
			}
			int u = p[v];
			long tmp = (long) one[u] * zero[v] + (long) one[v] * zero[u];
			one[u] = (int) Math.floorMod(tmp, P);
			zero[u] = (int) ((long) zero[u] * zero[v] % P);
			tot[u] = (int)((long)tot[u] * tot[v] % P);
			if (!inQ[u]) {
				pq.add(u);
				inQ[u] = true;
			}
		}

		int ret = one[0];
		for (int i = 0; i < sz; i++) {
			int v = que[i];
			one[v] = 0;
			zero[v] = 1;
			tot[v] = 1;
			inQ[v] = false;
		}
		return ret;
	}

	int[] repr;
	boolean[] dead;

	int get(int v) {
		return repr[v] == v ? v : (repr[v] = get(repr[v]));
	}

	int slow(int[] inp) {
		int n = inp.length + 1;
		next = new int[n - 1];
		head = new int[n];
		Arrays.fill(head, -1);
		to = new int[n - 1];

		depth = new int[n];

		int maxD = 0;

		for (int i = 1; i < n; i++) {
			int par = inp[i - 1];
			deg[par]++;
			to[i - 1] = i;
			next[i - 1] = head[par];
			head[par] = i - 1;
			depth[i] = depth[par] + 1;
			maxD = Math.max(maxD, depth[i]);
		}

		int ans = 0;

		for (int i = 0; i <= maxD; i++) {
			int[] res = dfs(0, i);
			// one, total, number of actual depth
			int delta = res[0];
			for (int j = 0; j < n - res[2]; j++) {
				delta = delta * 2 % P;
			}
			ans += delta;
			if (ans >= P) {
				ans -= P;
			}
		}

		return ans;
	}

	int[] combine(int[] ret, int[] add) {
		long tmp = (long) ret[0] * add[1] + (long) ret[1] * add[0] - 2L
				* ret[0] * add[0];
		int x = (int) Math.floorMod(tmp, P);
		int y = (int) ((long) ret[1] * add[1] % P);
		int z = ret[2] + add[2];
		return new int[] { x, y, z };
	}

	int[] dfs(int v, int rest) {
		if (rest == 0) {
			return new int[] { 1, 2, 1 };
		}
		int[] ret = { 0, 1, 0 };
		for (int e = head[v]; e >= 0; e = next[e]) {
			int[] add = dfs(to[e], rest - 1);
			ret = combine(ret, add);
		}
		return ret;
	}

	int solve(int[] inp) {
		int n = inp.length + 1;

		one = new int[n];
		zero = new int[n];
		tot = new int[n];
		inQ = new boolean[n];

		Arrays.fill(zero, 1);
		Arrays.fill(tot, 1);
		
		next = new int[n - 1];
		head = new int[n];
		Arrays.fill(head, -1);
		to = new int[n - 1];

		deg = new int[n];
		dead = new boolean[n];
		depth = new int[n];

		repr = new int[n];
		for (int i = 0; i < n; i++) {
			repr[i] = i;
		}

		for (int i = 1; i < n; i++) {
			int par = inp[i - 1];
			deg[par]++;
			to[i - 1] = i;
			next[i - 1] = head[par];
			head[par] = i - 1;
			depth[i] = depth[par] + 1;
		}

		int[] p2 = new int[n + 1];
		p2[0] = 1;
		for (int i = 1; i < p2.length; i++) {
			p2[i] = p2[i - 1] * 2 % P;
		}

		p = new int[n];
		int[] q = new int[n];
		int qh = 0, qt = 0;
		q[qt++] = 0;

		int ans = 0;

		while (qh < n) {
			ans += (int) ((long) goDp(q, qh, qt) * p2[n - (qt - qh)] % P);
			if (ans >= P) {
				ans -= P;
			}

			int remT = qt;
			for (int i = qh; i < remT; i++) {
				int v = q[i];
				if (deg[v] == 0) {
					remove(v);
				} else if (deg[v] == 1) {
					int u = to[head[v]];
					p[u] = p[v];
					repr[v] = u;
					q[qt++] = u;
				} else {
					for (int e = head[v]; e >= 0; e = next[e]) {
						int u = to[e];
						q[qt++] = u;
						p[u] = v;
					}
				}
			}
			qh = remT;
		}
		return ans;
	}

	void preCalc() {

	}

	static final int C = 100;

	void stress() {
		for (int tst = 0;; tst++) {
			int n = rand(1, C);
			int[] p = new int[n];
			for (int i = 0; i < n; i++) {
				p[i] = rand(0, i);
			}
			int fast = solve(p);
			int slow = slow(p);

			if (fast != slow) {
				System.err.println(Arrays.toString(p));
				System.err.println(fast);
				System.err.println(slow);
				throw new AssertionError();
			}

			System.err.println(tst);
		}
	}

	void test() {
		System.err.println(solve(new int[] { 0, 1, 1, 0, 4 }));
	}

	Main() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		preCalc();
		submit();
		// stress();
//		 test();
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