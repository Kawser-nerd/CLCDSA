import java.awt.List;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;
import java.util.NoSuchElementException;

public class Main {
	public static void main(String[] args) {
		new Main().run();
	}

	final long MOD = 1_000_000_000 + 7;

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

		void setUnion(int x, int y) {
			x = root(x);
			y = root(y);
			if (x == y)
				return;
			if (upper[x] < upper[y]) {
				x ^= y;
				y ^= x;
				x ^= y;
			}
			upper[y] += upper[x];
			upper[x] = y;
		}

		boolean equiv(int x, int y) {
			return root(x) == root(y);
		}
	}

	long f(long X, int N, int M, int[][] es) {
		DJSet ds_all = new DJSet(M);
		for (int i = 0; i < M; ++i) {
			long weight = es[i][2];
			DJSet ds = new DJSet(N);
			ArrayList<Integer> used = new ArrayList<>();
			ds.setUnion((int) es[i][0], (int) es[i][1]);
			used.add(i);
			for (int j = 0; j < M; ++j) {
				if (ds.equiv(es[j][0], es[j][1])) {
					continue;
				}
				ds.setUnion(es[j][0], es[j][1]);
				weight += es[j][2];
				used.add(j);
			}
			if (weight <= X) {
				for (int j = 1; j < used.size(); ++j) {
					ds_all.setUnion(used.get(0), used.get(j));
				}
			}
		}

		int ret = 0;
		for (int i = 0; i < M; ++i) {
			if (ds_all.upper[i] < 0)
				++ret;
		}
		return pow(2, ret);
	}

	void run() {
		Scanner sc = new Scanner();
		int N = sc.nextInt();
		int M = sc.nextInt();
		long X = sc.nextLong();
		int[][] es = new int[M][];
		for (int i = 0; i < M; ++i) {
			int U = sc.nextInt();
			int V = sc.nextInt();
			int W = sc.nextInt();
			--U;
			--V;
			es[i] = new int[] { U, V, W };
		}
		Arrays.sort(es, new Comparator<int[]>() {
			@Override
			public int compare(int[] arg0, int[] arg1) {
				return Integer.compare(arg0[2], arg1[2]);
			}
		});
		PrintWriter pw = new PrintWriter(System.out);
		pw.println((f(X - 1, N, M, es) - f(X, N, M, es) + MOD) % MOD);
		pw.close();
	}

	long pow(long a, long n) {
		long ret = 1;
		for (; n > 0; n >>= 1, a = a * a % MOD) {
			if (n % 2 == 1)
				ret = ret * a % MOD;
		}
		return ret;
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

	static void tr(Object... objects) {
		System.out.println(Arrays.deepToString(objects));
	}
}