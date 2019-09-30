import java.io.IOException;
import java.io.InputStream;
import java.util.Arrays;
import java.util.Comparator;
import java.util.NoSuchElementException;

public class Main {
	public static void main(String[] args) {
		// long t = System.currentTimeMillis();
		new Main().run();
		// System.err.println(System.currentTimeMillis() - t);
	}

	void solve(int W, int H, int Q, int[][] q) {
		long[] w = new long[W];
		long[] h = new long[H];
		final long INF = Long.MAX_VALUE / 3;
		for (int i = 0; i < Q; ++i) {
			int j = i;
			while (j + 1 < Q && q[i][0] == q[j + 1][0] && q[i][1] == q[j + 1][1] && q[j][2] == q[j + 1][2] - 1) {
				++j;
			}
			int l = q[i][2];
			int r = q[j][2];
			if (q[i][1] == 0)
				for (int k = l; k <= r; ++k) {
					if (l - 1 >= 0)
						w[l - 1] = Math.min(w[l - 1], w[k] + k - (l - 1));
					if (r + 1 < w.length)
						w[r + 1] = Math.min(w[r + 1], w[k] + (r + 1) - k);
					w[k] = INF;
				}
			else
				for (int k = l; k <= r; ++k) {
					if (l - 1 >= 0)
						h[l - 1] = Math.min(h[l - 1], h[k] + k - (l - 1));
					if (r + 1 < h.length)
						h[r + 1] = Math.min(h[r + 1], h[k] + (r + 1) - k);
					h[k] = INF;
				}

			i = j;
		}

		long minW = INF;
		long minH = INF;
		for (long v : w)
			minW = Math.min(minW, v);
		for (long v : h)
			minH = Math.min(minH, v);

		if (minH + minW >= INF)
			System.out.println(-1);
		else
			System.out.println(minW + minH);
	}

	public void run() {
		Scanner sc = new Scanner();
		int W = sc.nextInt();
		int H = sc.nextInt();
		int Q = sc.nextInt();
		int[][] q = new int[Q][];
		for (int i = 0; i < Q; ++i) {
			q[i] = new int[] { sc.nextInt(), sc.nextInt(), sc.nextInt() - 1 };
		}
		Arrays.sort(q, new Comparator<int[]>() {
			@Override
			public int compare(int[] o1, int[] o2) {
				if (o1[0] != o2[0])
					return Integer.compare(o1[0], o2[0]);
				else if (o1[1] != o2[1])
					return Integer.compare(o1[1], o2[1]);
				else
					return Integer.compare(o1[2], o2[2]);
			}
		});

		solve(W, H, Q, q);
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

		public int nextInt() {
			if (!hasNext())
				throw new NoSuchElementException();
			int n = 0;
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

	static void tr(Object... objects) {
		System.out.println(Arrays.deepToString(objects));
	}

}