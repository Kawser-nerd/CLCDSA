import java.io.*;
import java.util.*;

public class Main {

	static final int P = 1_000_000_007;
	static final int N = 5001;

	int inv(int x) {
		return x == 1 ? 1 : (int) (P - (long) (P / x) * inv(P % x) % P);
	}

	int[] fact;
	int[] invFact;

	int[] head;
	int[] next;
	int[] to;

	int[] sz;

	void dfs(int v, int p) {
		sz[v] = 1;
		for (int e = head[v]; e >= 0; e = next[e]) {
			int u = to[e];
			if (u == p) {
				continue;
			}
			dfs(u, v);
			sz[v] += sz[u];
		}
	}

	void submit() {
		int n = nextInt();

		head = new int[n];
		Arrays.fill(head, -1);
		next = new int[2 * n - 2];
		to = new int[2 * n - 2];

		for (int i = 0; i < n - 1; i++) {
			int v = nextInt() - 1;
			int u = nextInt() - 1;
			to[2 * i] = u;
			next[2 * i] = head[v];
			head[v] = 2 * i;

			to[2 * i + 1] = v;
			next[2 * i + 1] = head[u];
			head[u] = 2 * i + 1;
		}

		sz = new int[n];
		dfs(0, -1);

		int root = 0;
		outer: while (true) {
			for (int e = head[root]; e >= 0; e = next[e]) {
				int u = to[e];
				if (sz[u] < sz[root] && sz[u] > n - sz[u]) {
					root = u;
					continue outer;
				}
			}
			break;
		}

		dfs(root, -1);
		ArrayList<Integer> ch = new ArrayList<>();
		for (int e = head[root]; e >= 0; e = next[e]) {
			ch.add(sz[to[e]]);
		}

		int ret = solve(ch);
		ch.add(1);
		ret += solve(ch);
		if (ret >= P) {
			ret -= P;
		}

		out.println(ret);
	}

	int[] makePoly(int n) {
		int[] p = new int[n + 1];
		for (int b = 0; b <= n; b++) {
			p[b] = (int) ((long) fact[n] * fact[n] % P * invFact[b] % P
					* invFact[n - b] % P * invFact[n - b] % P);
		}
		return p;
	}

	int solve(ArrayList<Integer> a) {
		int n = a.size();
		int[][] ps = new int[n][];

		PriorityQueue<int[]> pq = new PriorityQueue<>(new Comparator<int[]>() {

			@Override
			public int compare(int[] o1, int[] o2) {
				return Integer.compare(o1.length, o2.length);
			}

		});
		for (int i = 0; i < n; i++) {
			pq.add(makePoly(a.get(i)));
		}

		while (pq.size() > 1) {
			int[] p = pq.poll();
			int[] q = pq.poll();
			pq.add(mult(p, q));
		}

		int[] ret = pq.poll();

		int ans = 0;
		int sum = ret.length - 1;

		for (int i = 0; i <= sum; i++) {
			int delta = (int) ((long) ret[i] * fact[sum - i] % P);
			if (i % 2 == 0) {
				ans += delta;
				if (ans >= P) {
					ans -= P;
				}
			} else {
				ans -= delta;
				if (ans < 0) {
					ans += P;
				}
			}
		}

		return ans;
	}

	int[] mult(int[] a, int[] b) {
		int[] c = new int[a.length + b.length - 1];
		for (int i = 0; i < a.length; i++) {
			for (int j = 0; j < b.length; j++) {
				c[i + j] += (int) ((long) a[i] * b[j] % P);
				if (c[i + j] >= P) {
					c[i + j] -= P;
				}
			}
		}
		return c;
	}

	void preCalc() {
		fact = new int[N];
		invFact = new int[N];
		fact[0] = invFact[0] = 1;
		for (int i = 1; i < N; i++) {
			fact[i] = (int) ((long) i * fact[i - 1] % P);
			invFact[i] = (int) ((long) inv(i) * invFact[i - 1] % P);
		}
	}

	void stress() {

	}

	int val(int p, int q) {
		return (int) ((long) fact[p] * fact[p] % P * invFact[q] % P
				* invFact[p - q] % P * invFact[p - q] % P);
	}

	int slow(int x, int y) {
		long ret = 0;
		for (int a = 0; a <= x; a++) {
			for (int b = 0; b <= y; b++) {
				long delta = val(x, a) * val(y, b) % P * fact[x + y - a - b]
						% P;
				if ((a + b) % 2 == 0) {
					ret += delta;
				} else {
					ret -= delta;
				}
			}
		}
		return (int) Math.floorMod(ret, P);
	}

	int slow(int x, int y, int z) {
		long ret = 0;
		for (int a = 0; a <= x; a++) {
			for (int b = 0; b <= y; b++) {
				for (int c = 0; c <= z; c++) {
					long delta = val(x, a) * val(y, b) % P * val(z, c) % P
							* fact[x + y + z - a - b - c] % P;
					if ((a + b + c) % 2 == 0) {
						ret += delta;
					} else {
						ret -= delta;
					}
				}
			}
		}
		return (int) Math.floorMod(ret, P);
	}

	int sloow(int[] a) {
		int n = 0;
		for (int x : a) {
			n += x;
		}
		boolean[][] bad = new boolean[n][n];
		int s = 0;
		for (int x : a) {
			for (int i = s; i < s + x; i++) {
				for (int j = s; j < s + x; j++) {
					bad[i][j] = true;
				}
			}
			s += x;
		}

		int[] p = new int[n];
		for (int i = 0; i < n; i++) {
			p[i] = i;
		}

		int ret = 0;

		do {
			boolean badd = false;
			for (int i = 0; i < n; i++) {
				badd |= bad[i][p[i]];
			}
			ret += badd ? 0 : 1;
		} while (nextPermutation(p));

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