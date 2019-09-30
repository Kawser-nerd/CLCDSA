import java.io.IOException;
import java.io.InputStream;
import java.util.Arrays;
import java.util.Comparator;
import java.util.NoSuchElementException;

class Main {
	public static void main(String[] args) {
		// long time = System.currentTimeMillis();
		new Main().run();
		// System.err.println(System.currentTimeMillis() - time);
	}

	void run() {
		Scanner sc = new Scanner();
		int n = sc.nextInt();
		int m = sc.nextInt();
		int[][] a = new int[n][2];
		for (int i = 0; i < n; ++i) {
			a[i][0] = sc.nextInt() - 1;
			a[i][1] = sc.nextInt() - 1;
		}
		Arrays.sort(a, new Comparator<int[]>() {
			@Override
			public int compare(int[] o1, int[] o2) {
				return Integer.compare(o1[0], o2[0]);
			}
		});
		SegTree seg = new SegTree(n);
		for (int i = m - 1; i >= 0; --i) {
			seg.add(i, i + 1, -(m - 1 - i + 1));
		}
		int curL = -1;

		int ans = 0;
		{
			int l = -1, r = m;
			for (int i = 0; i < n; ++i) {
				l = Math.max(l, a[i][0]);
				r = Math.min(r, a[i][1]);
			}
			if (r - l > 1) {
				ans = Math.max(ans, n - (l + 1 + m - r));
			} else {
				ans = Math.max(ans, n - m);
			}

		}
		for (int i = 0; i < n; ++i) {
			while (curL < a[i][0]) {
				++curL;
				seg.add(0, m + 1, -1);
			}
			seg.add(0, a[i][1] + 1, 1);
			ans = Math.max(ans, seg.query(0, m + 1));
		}
		System.out.println(ans);
	}

	class SegTree {
		int n;
		int[] v;
		int[] lazy;

		public SegTree(int n_) {
			n = 1;
			while (n < n_)
				n *= 2;
			v = new int[2 * n - 1];
			lazy = new int[2 * n - 1];
		}

		int query(int a, int b) {
			return add(a, b, 0);
		}

		int add(int a, int b, int val) {
			return query(a, b, 0, n, 0, val);
		}

		int query(int a, int b, int l, int r, int k, int val) {
			if (r <= a || b <= l)
				return -Integer.MAX_VALUE / 3;
			put(k);
			if (a <= l && r <= b) {
				lazy[k] += val;
				put(k);
				return v[k];
			} else {
				int vl = query(a, b, l, (l + r) / 2, 2 * k + 1, val);
				int vr = query(a, b, (l + r) / 2, r, 2 * k + 2, val);
				v[k] = Math.max(v[2 * k + 1], v[2 * k + 2]);
				return Math.max(vl, vr);
			}
		}

		void put(int k) {
			if (lazy[k] == 0)
				return;
			v[k] += lazy[k];
			if (2 * k + 2 < v.length) {
				lazy[2 * k + 1] += lazy[k];
				lazy[2 * k + 2] += lazy[k];
			}
			lazy[k] = 0;
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
}