import java.io.*;
import java.math.*;
import java.util.*;
import java.util.stream.*;

public class Main {

	int[][] g;

	int[] deltaOutpSubTree;

	int time;
	int[] tIn, tOut;

	int[] par;

	int time2;

	int[] fIn, fOut;

	int[] outp;

	void submit() {
		int n = nextInt();

		int[] deg = new int[n];
		int[] vs = new int[n - 1];
		int[] us = new int[n - 1];

		for (int i = 0; i < n - 1; i++) {
			vs[i] = nextInt() - 1;
			us[i] = nextInt() - 1;
			deg[vs[i]]++;
			deg[us[i]]++;
		}

		g = new int[n][];
		for (int i = 0; i < n; i++) {
			g[i] = new int[deg[i]];
		}

		tIn = new int[n];
		tOut = new int[n];
		par = new int[n];

		fIn = new int[n];
		fOut = new int[n];

		depth = new int[n];
		deltaOutpSubTree = new int[n];

		for (int i = 0; i < n - 1; i++) {
			int v = vs[i];
			int u = us[i];
			g[v][--deg[v]] = u;
			g[u][--deg[u]] = v;
		}

		outp = new int[n];

		dfs1(0, 0, 0);

		Collections.sort(qs);

		int current = 1;

		int[] ans = new int[n + 1];

		blocked = new boolean[n];
		nextBlock = new int[n];
		Arrays.fill(blocked, true);
		for (int i = 1; i < n; i++) {
			nextBlock[i] = par[i];
		}

		Collections.sort(qs);

		hld = new HLD(g);
		fens = new int[hld.pathSize.length][];
		for (int i = 0; i < fens.length; i++) {
			fens[i] = new int[hld.pathSize[i] + 1];
		}

		for (Query q : qs) {
			while (current < q.less) {
				unblock(current);
				current++;
			}

			int value = getHERE(q.root) * q.sign;

//			System.err.println(q.less + " " + q.root + " " + value * q.sign
//					+ " " + q.sign);

			ans[q.addFrom] += value;
			ans[q.addTo] -= value;
		}

		for (int i = 1; i < n; i++) {
			ans[i] += ans[i - 1];
		}
		
		dfs2(0, 0);

		for (int i = 1; i < n; i++) {
			outp[i] += ans[tIn[i]];
			outp[i] += depth[i];
			outp[i] += deltaOutpSubTree[i];
		}

		for (int i = 1; i < n; i++) {
			out.print(outp[i] + " ");
		}
	}
	
	void dfs2(int v, int p) {
		for (int u : g[v]) {
			if (u == p) {
				continue;
			}
			deltaOutpSubTree[u] += deltaOutpSubTree[v];
			dfs2(u, v);
		}
	}

	boolean[] blocked;
	int[] nextBlock;

	void unblock(int v) {
		getBlock(v);

		int valHere = getHERE(v) + 1;
		blocked[v] = false;
		addPath(par[v], nextBlock[v], valHere);
	}

	int[][] fens;

	void addPath(int v, int u, int delta) {
		List<Integer> paths = hld.getPath(u, v);
		for (int i = 0; i < paths.size(); i += 3) {
			int id = paths.get(i);
			int pos1 = paths.get(i + 1);
			int pos2 = paths.get(i + 2);
			addFen(fens[id], pos1, delta);
			addFen(fens[id], pos2 + 1, -delta);
		}
	}

	int getHERE(int v) {
		int id = hld.pathId[v];
		int pos = hld.pathPos[v];
		return getFen(fens[id], pos);
	}

	void addFen(int[] fen, int p, int d) {
		for (int i = p; i < fen.length; i |= i + 1) {
			fen[i] += d;
		}
	}

	int getFen(int[] fen, int p) {
		int ret = 0;
		for (int i = p; i >= 0; i = (i & (i + 1)) - 1) {
			ret += fen[i];
		}
		return ret;
	}

	HLD hld;

	static class HLD {
		final int[][] g;
		final int[] par;
		final int[] heavy;
		final int[] depth;
		final int[] pathPos;
		final int[] pathId;

		final int[] pathSize;
		final int[] pathRoot;

		public HLD(int[][] g) {
			this.g = g;
			int n = g.length;

			par = new int[n];
			heavy = new int[n];
			depth = new int[n];
			pathPos = new int[n];
			pathId = new int[n];
			pathRoot = new int[n];

			Arrays.fill(heavy, -1);
			par[0] = -1;
			depth[0] = 0;
			dfs(0);

			int pathCount = 0;

			for (int v = 0; v < n; v++) {
				if (par[v] == -1 || heavy[par[v]] != v) {
					pathCount++;
				}
			}

			pathSize = new int[pathCount];

			for (int v = 0, curPathId = 0; v < n; v++) {
				if (par[v] == -1 || heavy[par[v]] != v) {
					for (int u = v, pos = 0; u != -1; u = heavy[u], pos++) {
						pathRoot[u] = v;
						pathSize[curPathId]++;
						pathPos[u] = pos;
						pathId[u] = curPathId;
					}
					curPathId++;
				}
			}
		}

		private int dfs(int v) {
			int size = 1;
			int maxSubtree = 0;
			for (int u : g[v]) {
				if (u == par[v])
					continue;
				par[u] = v;
				depth[u] = depth[v] + 1;
				int subtree = dfs(u);
				if (maxSubtree < subtree) {
					maxSubtree = subtree;
					heavy[v] = u;
				}
				size += subtree;

			}
			return size;
		}

		/**
		 * @return list of triplets [pathId; pos1; pos2] in order corresponding
		 *         to path from v to u <br>
		 *         pos1 < pos2 = going down <br>
		 *         pos1 > pos2 = going up
		 */
		List<Integer> getPath(int v, int u) {
			List<Integer> head = new ArrayList<Integer>();
			List<Integer> tail = new ArrayList<Integer>();
			while (true) {
				int upV = pathRoot[v];
				int upU = pathRoot[u];
				if (upV == upU) {
					break;
				}
				if (depth[upV] > depth[upU]) {
					head.add(pathId[v]);
					head.add(pathPos[v]);
					head.add(0);
					v = par[upV];
				} else {
					tail.add(pathPos[u]);
					tail.add(0);
					tail.add(pathId[u]);
					u = par[upU];
				}
			}
			int pv = pathPos[v];
			int pu = pathPos[u];
			if (pv > pu) {
				head.add(pathId[v]);
				head.add(pv);
				head.add(pu);
			} else {
				tail.add(pu);
				tail.add(pv);
				tail.add(pathId[v]);
			}
			Collections.reverse(tail);
			head.addAll(tail);
			return head;
		}

	}

	int getBlock(int v) {
		if (blocked[nextBlock[v]]) {
			return nextBlock[v];
		} else {
			return nextBlock[v] = getBlock(nextBlock[v]);
		}
	}

	static class Query implements Comparable<Query> {
		int root, less;

		int addFrom, addTo;

		int sign;

		int value;

		public Query(int root, int less, int addFrom, int addTo, int sign) {
			this.root = root;
			this.less = less;
			this.addFrom = addFrom;
			this.addTo = addTo;
			this.sign = sign;
		}

		@Override
		public int compareTo(Query o) {
			return Integer.compare(less, o.less);
		}
	}

	ArrayList<Query> qs = new ArrayList<>();

	int[] depth;

	void dfs1(int v, int p, int max) {
		par[v] = p;
		tIn[v] = time++;

		fIn[v] = time2++;
		// max = Math.max(max, v);
		for (int u : g[v]) {
			if (u == p) {
				continue;
			}
			int timeBefore = time;
			depth[u] = depth[v] + 1;
			dfs1(u, v, Math.max(max, v));
			// qs.add(new Query(u, max, timeBefore, time, -1));
			if (u > max) {
				// do NOTHING
			} else {
				qs.add(new Query(u, max, timeBefore, time, -1));
				deltaOutpSubTree[u] -= 1;
			}
		}
		qs.add(new Query(v, max, tIn[v], time, 1)); // ????? + ???
		fOut[v] = time2++;
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
	static final int C = 5;

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