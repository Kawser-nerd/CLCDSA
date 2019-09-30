import java.io.*;
import java.math.*;
import java.util.*;
import java.util.stream.*;

public class Main {

	static class Jewel {
		int x, y;
		long val;

		public Jewel(int x, int y, long val) {
			this.x = x;
			this.y = y;
			this.val = val;
		}
	}

	void submit() {
		int n = nextInt();

		int bigN = n + 100;

		Jewel[] a = new Jewel[n];

		int[] allX = new int[n];
		int[] allY = new int[n];

		for (int i = 0; i < n; i++) {
			int x = nextInt();
			int y = nextInt();
			allX[i] = x;
			allY[i] = y;
			long v = nextLong();

			a[i] = new Jewel(x, y, v);
		}

		allX = unique(allX);
		allY = unique(allY);

		for (int i = 0; i < n; i++) {
			a[i].x = Arrays.binarySearch(allX, a[i].x);
			a[i].y = Arrays.binarySearch(allY, a[i].y);
		}

		int szX = allX.length;
		int szY = allY.length;

		int m = nextInt();

		int[] lowX = new int[szX + 1];
		int[] highX = new int[szX + 1];
		int[] lowY = new int[szY + 1];
		int[] highY = new int[szY + 1];

		Arrays.fill(lowX, -bigN);
		Arrays.fill(highX, bigN);
		Arrays.fill(lowY, -bigN);
		Arrays.fill(highY, bigN);

		for (int i = 0; i < m; i++) {
			char type = nextChar();
			int coord = nextInt();
			int val = nextInt();

			if (type == 'L') {
				int idx = Arrays.binarySearch(allX, coord);
				if (idx < 0) {
					idx = -idx - 2;
				}
				lowX[idx + 1] = Math.max(lowX[idx + 1], -val);
			} else if (type == 'R') {
				int idx = Arrays.binarySearch(allX, coord);
				if (idx < 0) {
					idx = -idx - 1;
				}
				highX[idx] = Math.min(highX[idx], val);
			} else if (type == 'D') {
				int idx = Arrays.binarySearch(allY, coord);
				if (idx < 0) {
					idx = -idx - 2;
				}
				lowY[idx + 1] = Math.max(lowY[idx + 1], -val);
			} else if (type == 'U') {
				int idx = Arrays.binarySearch(allY, coord);
				if (idx < 0) {
					idx = -idx - 1;
				}
				highY[idx] = Math.min(highY[idx], val);
			} else {
				throw new AssertionError();
			}
		}

		long ans = 0;

		int gN = 4 + szX + szY + 2 * n;

		outer: for (int pick = 1; pick <= n; pick++) {

			{
				int low = pick + lowX[szX];
				int high = highX[szX];
				if (!(low <= 0 && 0 <= high)) {
					continue;
				}
			}

			{
				int low = pick + lowY[szY];
				int high = highY[szY];
				if (!(low <= 0 && 0 <= high)) {
					continue;
				}
			}
			
			{
				int low = pick + lowX[0];
				int high = highX[0];
				if (!(low <= pick && pick <= high)) {
					continue;
				}
			}

			{
				int low = pick + lowY[0];
				int high = highY[0];
				if (!(low <= pick && pick <= high)) {
					continue;
				}
			}

			MinCostFlowGraph g = new MinCostFlowGraph(4 + szX + szY + 2 * n,
					gN - 4, gN - 3);

			int s = gN - 2;
			int t = gN - 1;

			g.addLowerBound(s, 2 * n, pick, pick);
			for (int i = 1; i < szX; i++) {
				int low = Math.max(pick + lowX[i], 0);
				int high = Math.min(highX[i], pick);
				if (low > high) {
					continue outer;
				}
				g.addLowerBound(2 * n + i - 1, 2 * n + i, low, high);
			}

			g.addLowerBound(2 * n + szX, t, pick, pick);
			for (int i = 1; i < szY; i++) {
				int low = Math.max(pick + lowY[i], 0);
				int high = Math.min(highY[i], pick);
				if (low > high) {
					continue outer;
				}
				g.addLowerBound(2 * n + szX + i, 2 * n + szX + i - 1, low, high);
			}

			for (int i = 0; i < n; i++) {
				// x >= ... -> jewel -> y >= ...
				g.addEdge(2 * n + a[i].x, i, 1, 0);
				g.addEdge(i + n, 2 * n + szX + a[i].y, 1, 0);

				// edge for jewel
				g.addEdge(i, i + n, 1, -a[i].val);
			}

			g.addEdge(t, s, pick + 100, 0);

			long[] flow = g.maxFlowMinCost();
			if (g.needFlow != flow[0]) {
				continue;
			}

			// System.err.println(pick + " " + (C * pick - flow[1]));

			ans = Math.max(ans, -flow[1]);
		}

		out.println(ans);
	}

	// !!!!!!!!! ADD LONG
	static class MinCostFlowGraph {

		int needFlow = 0;

		int N, S, T;
		static final long INF = Long.MAX_VALUE / 3;

		List<MinCostFlowEdge>[] g;
		final private long[] d;
		private MinCostFlowEdge[] from;

		public MinCostFlowGraph(int n, int s, int t) {
			N = n;
			S = s;
			T = t;
			g = new List[N];
			for (int i = 0; i < N; i++) {
				g[i] = new ArrayList<>();
			}
			d = new long[N];
			from = new MinCostFlowEdge[N];
		}

		void addLowerBound(int v1, int v2, int lowCap, int highCap) {

			needFlow += lowCap;

			if (lowCap > highCap) {
				throw new AssertionError();
			}

			addEdge(S, v2, lowCap, 0);
			addEdge(v1, T, lowCap, 0);
			addEdge(v1, v2, highCap - lowCap, 0);
		}

		void addEdge(int v1, int v2, int cap, long cost) {

			// System.err.println(v1 + " -> " + v2 + " " + cap + "/" + cost);

			MinCostFlowEdge e1 = new MinCostFlowEdge(v2, cap, cost);
			MinCostFlowEdge e2 = new MinCostFlowEdge(v1, 0, -cost);
			e1.rev = e2;
			e2.rev = e1;
			g[v1].add(e1);
			g[v2].add(e2);
		}

		long[] augmentFlowLevit() {
			ArrayDeque<Integer> que = new ArrayDeque<>();
			que.add(S);

			Arrays.fill(d, INF);
			d[S] = 0;

			boolean[] inQ = new boolean[N];
			inQ[S] = true;

			while (!que.isEmpty()) {
				int v = que.poll();
				inQ[v] = false;

				for (MinCostFlowEdge e : g[v]) {
					if (e.flow == e.cap) {
						continue;
					}

					if (d[e.to] > d[v] + e.cost) {
						d[e.to] = d[v] + e.cost;
						from[e.to] = e;

						if (!inQ[e.to]) {
							que.add(e.to);
							inQ[e.to] = true;
						}
					}
				}
			}

			if (d[T] == INF) {
				return null;
			}

			long addFlow = Long.MAX_VALUE;
			long costPerFlowUnit = 0;

			for (int v = T; v != S; v = from[v].rev.to) {
				MinCostFlowEdge e = from[v];
				addFlow = Math.min(addFlow, e.cap - e.flow);
				costPerFlowUnit += e.cost;
			}

			for (int v = T; v != S; v = from[v].rev.to) {
				MinCostFlowEdge e = from[v];
				e.flow += addFlow;
				e.rev.flow -= addFlow;
			}

			return new long[] { addFlow, costPerFlowUnit };
		}

		// long[] augmentFlow() {
		// // returns null if it can't be augmented
		// // throw new
		// // AssertionError("Uncomment one of findPath implementations");
		// if (d[T] == INF) {
		// return null;
		// }
		// for (int i = 0; i < N; i++) {
		// if (vis[i]) {
		// phi[i] += d[i] - d[T];
		// }
		// }
		//
		// long addFlow = flowLeft;
		// long costPerFlowUnit = 0;
		//
		// for (int v = T; v != S; v = from[v].rev.to) {
		// MinCostFlowEdge e = from[v];
		// addFlow = Math.min(addFlow, e.cap - e.flow);
		// costPerFlowUnit += e.cost;
		// }
		//
		// for (int v = T; v != S; v = from[v].rev.to) {
		// MinCostFlowEdge e = from[v];
		// e.flow += addFlow;
		// e.rev.flow -= addFlow;
		// }
		//
		// return new long[] { addFlow, costPerFlowUnit };
		// }

		long[] maxFlowMinCost() {
			long[] ret = new long[2];
			while (true) {
				long[] delta = augmentFlowLevit();
				if (delta == null)
					break;
				ret[0] += delta[0];
				ret[1] += delta[0] * delta[1];
			}
			return ret;
		}
	}

	static class MinCostFlowEdge {
		int to;
		int flow, cap;

		long cost;

		MinCostFlowEdge rev;

		public MinCostFlowEdge(int to, int cap, long cost) {
			this.to = to;
			this.cap = cap;
			this.cost = cost;
		}
	}

	int[] unique(int[] a) {
		a = a.clone();
		int sz = 0;
		Arrays.sort(a);
		for (int i = 0; i < a.length; i++) {
			if (sz == 0 || a[i] != a[sz - 1]) {
				a[sz++] = a[i];
			}
		}
		return Arrays.copyOf(a, sz);
	}

	void test() {

	}

	void stress() {
		for (int tst = 0;; tst++) {
			if (false) {
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
} Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.