import java.io.IOException;
import java.io.InputStream;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.NoSuchElementException;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		new Main().run();
	}

	void run() {
		FastScanner sc = new FastScanner();
		int N = sc.nextInt();
		int M = sc.nextInt();
		int[] u = new int[M];
		int[] v = new int[M];
		ArrayList<Integer>[] g = new ArrayList[N];
		for (int i = 0; i < N; ++i) {
			g[i] = new ArrayList<>();
		}
		for (int i = 0; i < M; ++i) {
			u[i] = sc.nextInt();
			v[i] = sc.nextInt();
			--u[i];
			--v[i];
			g[u[i]].add(v[i]);
			g[v[i]].add(u[i]);
		}
		solver(N, M, u, v, g);

	}

	void solver(int N, int M, int[] u, int[] v, ArrayList<Integer>[] g) {
		DJSet ds = new DJSet(N);
		for (int i = 0; i < M; ++i) {
			ds.setUniont(u[i], v[i]);
		}
		boolean[] vis = new boolean[N];
		long[] cnt = new long[3];
		long sz = 0;
		int[] color = new int[N];
		Arrays.fill(color, -1);
		for (int i = 0; i < N; ++i) {
			if (vis[ds.root(i)])
				continue;
			int t = type(ds.root(i), g, color);
			vis[ds.root(i)] = true;
			++cnt[t];
			if (t != 0)
				sz += ds.size(i);
		}
		long ans = 0;
		ans += cnt[0] * sz;
		ans += sz * cnt[0];
		ans += cnt[0] * cnt[0];
		ans += cnt[1] * cnt[1] * 2;
		ans += cnt[2] * cnt[2];
		ans += cnt[1] * cnt[2];
		ans += cnt[2] * cnt[1];
		System.out.println(ans);

	}

	// 0:????
	// 1:?????
	// 2:??????
	int type(int rep, ArrayList<Integer>[] g, int[] color) {
		if (g[rep].size() == 0)
			return 0;
		if (isBipartite(rep, color, 0, g)) {
			return 1;
		} else
			return 2;
	}

	boolean isBipartite(int cur, int[] color, int curColor, ArrayList<Integer>[] g) {
		color[cur] = curColor;
		for (int dst : g[cur]) {
			if (color[dst] != -1) {
				if (color[dst] == curColor)
					return false;
				continue;
			}
			if (!isBipartite(dst, color, curColor ^ 1, g)) {
				return false;
			}
		}
		return true;
	}

	class DJSet {
		int n;
		int[] upper;

		public DJSet(int n) {
			this.n = n;
			upper = new int[n];
			Arrays.fill(upper, -1);
		}

		int root(int x) {
			return upper[x] < 0 ? x : (upper[x] = root(upper[x]));
		}

		boolean equiv(int x, int y) {
			return root(x) == root(y);
		}

		void setUniont(int x, int y) {
			x = root(x);
			y = root(y);

			if (x != y) {
				if (upper[x] < upper[y]) {
					int d = x;
					x = y;
					y = d;
				}
				upper[y] += upper[x];
				upper[x] = y;
			}
		}

		int size(int x) {
			return -upper[root(x)];
		}
	}

	static void tr(Object... objects) {
		System.out.println(Arrays.deepToString(objects));
	}

	class FastScanner {
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

		public int nextInt() {
			return (int) nextLong();
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
	}
} Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.