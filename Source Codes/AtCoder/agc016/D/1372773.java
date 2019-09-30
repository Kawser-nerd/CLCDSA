import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.InputStream;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;
import java.util.NoSuchElementException;

public class Main {
	public static void main(String[] args) throws FileNotFoundException {
		new Main().run();
	}

	void run() {
		Scanner sc = new Scanner();
		int n = sc.nextInt();
		int[] a = new int[n + 1];
		int[] b = new int[n + 1];
		int[][] tmp = new int[2][n + 1];
		for (int i = 0; i < n; ++i) {
			a[i] = sc.nextInt();
			tmp[0][i] = a[i];
			tmp[0][n] ^= a[i];
			a[n] ^= a[i];
		}
		for (int i = 0; i < n; ++i) {
			b[i] = sc.nextInt();
			tmp[1][i] = b[i];
			tmp[1][n] ^= b[i];
			b[n] ^= b[i];
		}
		Arrays.sort(tmp[0]);
		Arrays.sort(tmp[1]);
		boolean f = true;
		for (int i = 0; i < n + 1; ++i) {
			f &= tmp[0][i] == tmp[1][i];
		}
		if (!f) {
			System.out.println(-1);
			return;
		}
		ArrayList<Integer> A = new ArrayList<>();
		ArrayList<Integer> B = new ArrayList<>();
		for (int i = 0; i < n; ++i) {
			if (a[i] == b[i])
				continue;
			A.add(a[i]);
			B.add(b[i]);
		}
		A.add(a[n]);
		B.add(b[n]);
		a = new int[A.size()];
		b = new int[B.size()];
		n = A.size() - 1;
		for (int i = 0; i < n + 1; ++i) {
			a[i] = A.get(i);
			b[i] = B.get(i);
		}
		shrink(a);
		shrink(b);
		solve(a, b, n);
	}

	void shrink(int[] a) {
		int n = a.length;
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
		int c = 0;
		for (int i = 0; i < n; ++i) {
			if (i != 0 && b[i][0] != b[i - 1][0]) {
				++c;
			}
			a[b[i][1]] = c;
		}
	}

	void solve(int[] a, int[] b, int n) {
		int cnt = 0;
		ArrayList<Integer>[] g = new ArrayList[n + 1];
		DJSet ds = new DJSet(n + 1);
		DJSet ds2 = new DJSet(n + 1);
		for (int i = 0; i < n + 1; ++i) {
			g[i] = new ArrayList<>();
		}
		for (int i = 0; i < n; ++i) {
			g[b[i]].add(i);
			ds.setUnion(i, g[b[i]].get(0));
		}
		ds2.upper = Arrays.copyOf(ds.upper, ds.upper.length);
		// g[v]:=(v=bi)???i????i!=n
		for (int i = 0; i < n; ++i) {
			if (g[a[i]].size() == 0) {
				continue;
			}
			ds2.setUnion(i, g[a[i]].get(0));
		}
		boolean[] vis = new boolean[n + 1];
		for (int i = 0; i < n; ++i) {
			int rep = ds2.root(i);
			if (vis[rep])
				continue;
			cnt += ds2.sz(i) + 1;
			vis[rep] = true;
		}
		boolean f = false;
		for (int i = 0; i < n; ++i) {
			f |= b[i] == a[n];
		}
		if (f) {
			--cnt;
		}
		// ds:bi=bj (??i,j!=n)???i,j???????
		System.out.println(cnt);
	}

	class DJSet {
		int n;
		int[] upper;

		public DJSet(int n_) {
			n = n_;
			upper = new int[n];
			Arrays.fill(upper, -1);
		}

		int root(int x) {
			return upper[x] < 0 ? x : (upper[x] = root(upper[x]));
		}

		boolean equiv(int x, int y) {
			return root(x) == root(y);
		}

		void setUnion(int x, int y) {
			x = root(x);
			y = root(y);
			if (x == y) {
				return;
			}
			if (upper[x] < upper[y]) {
				int tmp = x;
				x = y;
				y = tmp;
			}
			upper[y] += upper[x];
			upper[x] = y;
		}

		int sz(int x) {
			return -upper[root(x)];
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

		public boolean hasNext() {
			while (hasNextByte() && !isPrintableChar(buffer[ptr]))
				ptr++;
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
			long nl = nextLong();
			if (nl < Integer.MIN_VALUE || nl > Integer.MAX_VALUE)
				throw new NumberFormatException();
			return (int) nl;
		}

		public double nextDouble() {
			return Double.parseDouble(next());
		}
	}

	void tr(Object... objects) {
		System.out.println(Arrays.deepToString(objects));
	}
} Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.