import java.io.IOException;
import java.io.InputStream;
import java.util.ArrayDeque;
import java.util.Arrays;
import java.util.NoSuchElementException;

public class Main implements Runnable {
	public static void main(String[] args) {
		// long t = System.currentTimeMillis();
		new Thread(null, new Main(), "", Runtime.getRuntime().maxMemory()).start();
		// System.err.println(System.currentTimeMillis() - t);
	}

	public void run() {
		Scanner sc = new Scanner();
		int K = sc.nextInt();
		int N = sc.nextInt();
		solve(K, N);
	}

	void solve(int K, int N) {
		if (K % 2 == 0) {
			int[] ans = new int[N];
			ans[0] = K / 2;
			for (int i = 1; i < N; ++i)
				ans[i] = K;
			for (int i = 0; i < N; ++i) {
				System.out.print(ans[i] + (i == N - 1 ? "\n" : " "));
			}
		} else {
			int[] cur = new int[N];
			Arrays.fill(cur, (K + 1) / 2);
			int p = N - 1;
			for (int q = 0; q < N / 2; ++q) {
				if (cur[p] == 1)
					--p;
				else if (p == N - 1)
					--cur[p];
				else {
					--cur[p];
					while (p + 1 < N) {
						++p;
						cur[p] = K;
					}
				}
			}

			for (int i = 0; i <= p; ++i) {
				System.out.print(cur[i] + (i == N - 1 ? "\n" : " "));
			}
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

	static void tr(Object... objects) {
		System.out.println(Arrays.deepToString(objects));
	}

}