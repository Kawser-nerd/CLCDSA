import java.io.File;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;
import java.util.HashMap;
import java.util.List;
import java.util.NoSuchElementException;

public class Main {
	public static void main(String[] args) throws FileNotFoundException {
		new Main().run();
	}

	HashMap<List<Integer>, Integer> f = new HashMap<>();
	int gen = 0;
	DJSet ds;

	int getid(int src, int dst, int col) {
		if (f.containsKey(Arrays.asList(src, col)) && f.containsKey(Arrays.asList(dst, col))) {
			ds.setUnion(f.get(Arrays.asList(src, col)), f.get(Arrays.asList(dst, col)));
			return ds.root(f.get(Arrays.asList(src, col)));
		}
		if (f.containsKey(Arrays.asList(src, col))) {
			f.put(Arrays.asList(dst, col), f.get(Arrays.asList(src, col)));
			return ds.root(f.get(Arrays.asList(src, col)));
		}
		if (f.containsKey(Arrays.asList(dst, col))) {
			f.put(Arrays.asList(src, col), f.get(Arrays.asList(dst, col)));
			return ds.root(f.get(Arrays.asList(dst, col)));
		}
		f.put(Arrays.asList(src, col), gen);
		f.put(Arrays.asList(dst, col), gen);
		return gen++;
	}

	public void run() throws FileNotFoundException {
		Scanner sc = new Scanner();
		int n = sc.nextInt();
		int m = sc.nextInt();
		int[] p = new int[m];
		int[] q = new int[m];
		int[] c = new int[m];
		ArrayList<Integer>[] g = new ArrayList[n + m];
		ds = new DJSet(m);
		for (int i = 0; i < n + m; ++i) {
			g[i] = new ArrayList<>();
		}
		for (int i = 0; i < m; ++i) {
			p[i] = sc.nextInt();
			q[i] = sc.nextInt();
			c[i] = sc.nextInt();
			--p[i];
			--q[i];
		}
		c = shrink(c);
		for (int i = 0; i < m; ++i) {
			getid(p[i], q[i], c[i]);
		}
		for (int i = 0; i < m; ++i) {
			int cid = getid(p[i], q[i], c[i]) + n;
			g[p[i]].add(cid);
			g[cid].add(p[i]);
			g[q[i]].add(cid);
			g[cid].add(q[i]);
		}
		f.clear();
		ArrayDeque<Integer> que = new ArrayDeque<>();
		int[] d = new int[n + m];
		Arrays.fill(d, Integer.MAX_VALUE / 10);
		que.add(0);
		d[0] = 0;
		while (!que.isEmpty()) {
			int v = que.pollFirst();
			for (int u : g[v]) {
				if (d[u] > d[v] + 1) {
					d[u] = d[v] + 1;
					que.addLast(u);
					if (u == n - 1) {
						if (d[n - 1] % 2 != 0) {
							throw new AssertionError();
						}
						System.out.println(d[n - 1] / 2);
						return;
					}
				}
			}
		}
		System.out.println(-1);
	}

	int[] shrink(int[] a) {
		int n = a.length;
		int[] ret = new int[n];
		int[][] b = new int[n][2];
		for (int i = 0; i < n; ++i) {
			b[i][0] = a[i];
			b[i][1] = i;
		}
		Arrays.sort(b, new Comparator<int[]>() {
			@Override
			public int compare(int[] o1, int[] o2) {
				return Integer.compare(o1[0], o2[0]);
			}
		});
		int p = 0;
		for (int i = 0; i < n; ++i) {
			if (i > 0 && b[i - 1][0] != b[i][0]) {
				++p;
			}
			ret[b[i][1]] = p;
		}
		return ret;
	}

	class DJSet {
		int n;
		int[] upper;

		public DJSet(int n_) {
			n = n_;
			upper = new int[n];
			Arrays.fill(upper, -1);
		}

		boolean equiv(int x, int y) {
			return root(x) == root(y);
		}

		int root(int x) {
			return upper[x] < 0 ? x : (upper[x] = root(upper[x]));
		}

		void setUnion(int x, int y) {
			x = root(x);
			y = root(y);
			if (x == y)
				return;
			if (upper[x] < upper[y]) {
				int d = x;
				x = y;
				y = d;
			}
			upper[y] += upper[x];
			upper[x] = y;
		}
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

		public int nextInt() {
			return (int) nextLong();
		}
	}

	void tr(Object... objects) {
		System.out.println(Arrays.deepToString(objects));
	}
} Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.