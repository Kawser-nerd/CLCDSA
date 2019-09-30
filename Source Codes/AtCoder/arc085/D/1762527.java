import java.io.*;
import java.util.*;

public class Main {

	static final int INF = Integer.MAX_VALUE / 3;

	static class Node {
		int l, r;
		Node left, right;

		int min;
		int delta;

		public Node(int l, int r) {
			this.l = l;
			this.r = r;
			min = INF;
			if (r - l > 1) {
				int m = (l + r) >> 1;
				left = new Node(l, m);
				right = new Node(m, r);
			}
		}

		int getMin() {
			return min + delta;
		}

		void setMin(int pos, int val) {
			if (r - l == 1) {
				min = Math.min(getMin(), val);
				delta = 0;
				return;
			}
			left.delta += delta;
			right.delta += delta;
			delta = 0;
			(pos < left.r ? left : right).setMin(pos, val);
			min = Math.min(left.getMin(), right.getMin());
		}

		int get(int ql, int qr) {
			if (l >= qr || ql >= r) {
				return INF;
			}
			if (ql <= l && r <= qr) {
				return getMin();
			}
			return Math.min(left.get(ql, qr), right.get(ql, qr)) + delta;
		}

		void add(int ql, int qr, int val) {
			if (l >= qr || ql >= r) {
				return;
			}
			if (ql <= l && r <= qr) {
				delta += val;
				return;
			}
			left.add(ql, qr, val);
			right.add(ql, qr, val);
			min = Math.min(left.getMin(), right.getMin());
		}

	}

	int fast(int[] b, int[] ls, int[] rs) {
		int n = b.length;
		int q = ls.length;
		int[] head = new int[n];
		Arrays.fill(head, -1);
		int[] next = new int[q];
		int[] to = new int[q];
		for (int i = 0; i < q; i++) {
			to[i] = rs[i];
			next[i] = head[ls[i]];
			head[ls[i]] = i;
		}

		Node dp = new Node(0, n + 1);
		dp.setMin(0, 0);

		int[] memoVal = new int[q];

		for (int i = 0; i < n; i++) {

			int dpI = dp.get(i, i + 1);

			// skip
			// for (int k = i + 1; k <= n; k++) {
			// nxt[k] = Math.min(nxt[k], dp[k] + 1 - b[i]);
			// }

			for (int e = head[i]; e >= 0; e = next[e]) {
				int j = to[e];
				memoVal[e] = dp.get(i, j) + 1 - b[i];
			}

			dp.add(i + 1, n + 1, 1 - b[i]);

			for (int e = head[i]; e >= 0; e = next[e]) {
				dp.setMin(to[e], memoVal[e]);
			}

			dp.setMin(i + 1, dpI + b[i]);
		}
		return dp.get(n, n + 1);
	}

	int good(int[] b, int[] ls, int[] rs) {
		int n = b.length;
		int q = ls.length;
		int[] head = new int[n];
		Arrays.fill(head, -1);
		int[] next = new int[q];
		int[] to = new int[q];
		for (int i = 0; i < q; i++) {
			to[i] = rs[i];
			next[i] = head[ls[i]];
			head[ls[i]] = i;
		}

		int[] dp = new int[n + 1];
		Arrays.fill(dp, INF);
		dp[0] = 0;

		for (int i = 0; i < n; i++) {

			// skip
			int[] nxt = new int[n + 1];
			Arrays.fill(nxt, INF);
			nxt[i + 1] = Math.min(nxt[i + 1], dp[i] + b[i]);
			for (int k = i + 1; k <= n; k++) {
				nxt[k] = Math.min(nxt[k], dp[k] + 1 - b[i]);
			}

			for (int e = head[i]; e >= 0; e = next[e]) {
				int j = to[e];
				nxt[j] = Math.min(nxt[j], dp[i] + 1 - b[i]);
				for (int was = i + 1; was < j; was++) {
					nxt[j] = Math.min(nxt[j], dp[was] + 1 - b[i]);
				}
			}

			dp = nxt;
		}
		return dp[n];
	}

	int slow(int[] b, int[] ls, int[] rs) {
		int n = b.length;
		int q = ls.length;

		int ret = INF;

		for (int i = 0; i < (1 << q); i++) {
			int cur = 0;
			int[] a = new int[n];
			for (int j = 0; j < q; j++) {
				if (((i >> j) & 1) == 1) {
					Arrays.fill(a, ls[j], rs[j], 1);
				}
			}
			for (int j = 0; j < n; j++) {
				cur += (a[j] ^ b[j]);
			}
			ret = Math.min(ret, cur);
		}
		return ret;
	}

	void submit() {
		int n = nextInt();
		int[] b = new int[n];
		for (int i = 0; i < n; i++) {
			b[i] = nextInt();
		}
		int q = nextInt();
		int[] ls = new int[q];
		int[] rs = new int[q];
		for (int i = 0; i < q; i++) {
			ls[i] = nextInt() - 1;
			rs[i] = nextInt();
		}

		out.println(fast(b, ls, rs));
	}

	void preCalc() {

	}

	static final int C = 10;

	void stress() {
		for (int tst = 0;; tst++) {
			int n = rand(1, C);
			int q = rand(1, C);

			int[] b = new int[n];
			for (int i = 0; i < n; i++) {
				b[i] = rand(0, 1);
			}
			int[] ls = new int[q];
			int[] rs = new int[q];
			for (int i = 0; i < q; i++) {
				ls[i] = rand(0, n - 1);
				rs[i] = rand(ls[i] + 1, n);
			}
			if (fast(b, ls, rs) != slow(b, ls, rs)) {
				System.err.println(Arrays.toString(b));
				System.err.println(Arrays.toString(ls));
				System.err.println(Arrays.toString(rs));
				System.err.println(fast(b, ls, rs));
				System.err.println(slow(b, ls, rs));
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
//		stress();
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