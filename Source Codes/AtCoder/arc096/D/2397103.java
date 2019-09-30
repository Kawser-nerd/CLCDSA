import java.io.*;
import java.math.*;
import java.util.*;

public class Main {

	int greedy(int maxW, int d, int[] ms, int[] ps) {
		int n = ms.length;

		int[] cs = new int[n];
		long[] lws = new long[n];

		for (int i = n - 1; i >= 0; i--) {
			cs[i] += 1;
			lws[i] += ms[i];
			if (i > 0) {
				cs[ps[i]] += cs[i];
				lws[ps[i]] += lws[i];
			}
		}

		int[] ws = new int[n];
		for (int i = 0; i < n; i++) {
			ws[i] = (int) Math.min(lws[i], maxW + 1);
		}

		Integer[] order = new Integer[n];
		for (int i = 0; i < n; i++) {
			order[i] = i;
		}

		Arrays.sort(order, new Comparator<Integer>() {

			@Override
			public int compare(Integer o1, Integer o2) {
				if (o1.equals(o2)) {
					return 0;
				}

				long v1 = (long) ws[o1] * cs[o2];
				long v2 = (long) ws[o2] * cs[o1];

				if (v1 == v2) {
					return Integer.compare(cs[o1], cs[o2]);
				} else {
					return v1 < v2 ? -1 : 1;
				}
			}

		});

		int[] base = new int[n];

		int curW = 0;
		for (int i : order) {
			int use = (maxW - curW) / ws[i];
			if (i > 0) {
				use = Math.min(use, d);
			}
			curW += ws[i] * use;
			base[i] = use;
		}

		long ans = 0;
		for (int i = 0; i < n; i++) {
			ans += (long) base[i] * cs[i];
		}
		return (int) ans;
	}

	int solve(int maxW, int d, int[] ms, int[] ps) {
		int n = ms.length;

		int[] cs = new int[n];
		long[] lws = new long[n];

		for (int i = n - 1; i >= 0; i--) {
			cs[i] += 1;
			lws[i] += ms[i];
			if (i > 0) {
				cs[ps[i]] += cs[i];
				lws[ps[i]] += lws[i];
			}
		}
		

		int[] ws = new int[n];
		for (int i = 0; i < n; i++) {
			ws[i] = (int) Math.min(lws[i], maxW + 1);
		}

//		System.err.println(Arrays.toString(cs));
//		System.err.println(Arrays.toString(ws));
		
		Integer[] order = new Integer[n];
		for (int i = 0; i < n; i++) {
			order[i] = i;
		}

		Arrays.sort(order, new Comparator<Integer>() {

			@Override
			public int compare(Integer o1, Integer o2) {
				if (o1.equals(o2)) {
					return 0;
				}

				long v1 = (long) ws[o1] * cs[o2];
				long v2 = (long) ws[o2] * cs[o1];

				if (v1 == v2) {
					return Integer.compare(cs[o1], cs[o2]);
				} else {
					return v1 < v2 ? -1 : 1;
				}
			}

		});

		int[] base = new int[n];

		int curW = 0;
		for (int i : order) {
			int use = (maxW - curW) / ws[i];
			if (i > 0) {
				use = Math.min(use, d);
			}
			curW += ws[i] * use;
			base[i] = use;
		}

		long ans = 0;
		for (int i = 0; i < n; i++) {
			ans += (long) base[i] * cs[i];
		}
		// out.println(ans);

		long[] dp = new long[2 * C + 1];
		Arrays.fill(dp, INF);
		dp[C] = curW;

		for (int i = 0; i < n; i++) {
			long[] nxt = dp.clone();
			for (int j = 0; j <= 2 * C; j++) {
				if (dp[j] == INF) {
					continue;
				}
				int decr = base[i];
				for (int k = 1; k <= decr && j - k * cs[i] >= 0; k++) {
					nxt[j - k * cs[i]] = Math.min(nxt[j - k * cs[i]], dp[j] - (long)k
							* ws[i]);
				}
				int incr = i == 0 ? Integer.MAX_VALUE : d - base[i];
				for (int k = 1; k <= incr && j + k * cs[i] <= 2 * C; k++) {
					nxt[j + k * cs[i]] = Math.min(nxt[j + k * cs[i]], dp[j] + (long)k
							* ws[i]);
				}
			}
			dp = nxt;
		}

		for (int i = 2 * C;; i--) {
			if (dp[i] <= maxW) {
				return (int) (ans + (i - C));
			}
		}
	}

	void submit() {
		int n = nextInt();
		int maxW = nextInt();
		int d = nextInt();
		int[] ms = new int[n];
		int[] ps = new int[n];

		ms[0] = nextInt();
		for (int i = 1; i < n; i++) {
			ms[i] = nextInt();
			ps[i] = nextInt() - 1;
		}

		out.println(solve(maxW, d, ms, ps));
		// out.println(greedy(maxW, d, ms, ps));
	}

	static final long INF = Long.MAX_VALUE / 4;

	void test() {

	}

	static final int K = 4;

	void stress() {

		for (int tst = 0;; tst++) {
			int n = rand(2, K);
			int maxW = rand(1, K);
			int d = rand(0, K);
			int[] ws = new int[n];
			int[] ps = new int[n];
			ws[0] = rand(1, K);
			for (int i = 1; i < n; i++) {
				ws[i] = rand(1, K);
				ps[i] = rand(0, i - 1);
			}

			if (solve(maxW, d, ws, ps) != greedy(maxW, d, ws, ps)) {
				System.err.println(maxW + " " + d);
				System.err.println(Arrays.toString(ws));
				System.err.println(Arrays.toString(ps));
				System.err.println(solve(maxW, d, ws, ps));
				System.err.println(greedy(maxW, d, ws, ps));

				throw new AssertionError();
			}
			System.err.println(tst);
		}
	}

	Main() throws IOException {
		is = System.in;
		out = new PrintWriter(System.out);
		submit();
		// stress();
		// test();
		out.close();
	}

	static final Random rng = new Random();
	static final int C = 1000;

	static int rand(int l, int r) {
		return l + rng.nextInt(r - l + 1);
	}

	public static void main(String[] args) throws IOException {
		new Main();
	}

	private InputStream is;
	PrintWriter out;

	private byte[] buf = new byte[1 << 14];
	private int bufSz = 0, bufPtr = 0;

	private int readByte() {
		if (bufSz == -1)
			throw new RuntimeException("Reading past EOF");
		if (bufPtr >= bufSz) {
			bufPtr = 0;
			try {
				bufSz = is.read(buf);
			} catch (IOException e) {
				throw new RuntimeException(e);
			}
			if (bufSz <= 0)
				return -1;
		}
		return buf[bufPtr++];
	}

	private boolean isTrash(int c) {
		return c < 33 || c > 126;
	}

	private int skip() {
		int b;
		while ((b = readByte()) != -1 && isTrash(b))
			;
		return b;
	}

	String nextToken() {
		int b = skip();
		StringBuilder sb = new StringBuilder();
		while (!isTrash(b)) {
			sb.appendCodePoint(b);
			b = readByte();
		}
		return sb.toString();
	}

	String nextString() {
		int b = readByte();
		StringBuilder sb = new StringBuilder();
		while (!isTrash(b) || b == ' ') {
			sb.appendCodePoint(b);
			b = readByte();
		}
		return sb.toString();
	}

	double nextDouble() {
		return Double.parseDouble(nextToken());
	}

	char nextChar() {
		return (char) skip();
	}

	int nextInt() {
		int ret = 0;
		int b = skip();
		if (b != '-' && (b < '0' || b > '9')) {
			throw new InputMismatchException();
		}
		boolean neg = false;
		if (b == '-') {
			neg = true;
			b = readByte();
		}
		while (true) {
			if (b >= '0' && b <= '9') {
				ret = ret * 10 + (b - '0');
			} else {
				if (b != -1 && !isTrash(b)) {
					throw new InputMismatchException();
				}
				return neg ? -ret : ret;
			}
			b = readByte();
		}
	}

	long nextLong() {
		long ret = 0;
		int b = skip();
		if (b != '-' && (b < '0' || b > '9')) {
			throw new InputMismatchException();
		}
		boolean neg = false;
		if (b == '-') {
			neg = true;
			b = readByte();
		}
		while (true) {
			if (b >= '0' && b <= '9') {
				ret = ret * 10 + (b - '0');
			} else {
				if (b != -1 && !isTrash(b)) {
					throw new InputMismatchException();
				}
				return neg ? -ret : ret;
			}
			b = readByte();
		}
	}
}