import java.io.IOException;
import java.io.InputStream;
import java.util.Arrays;
import java.util.NoSuchElementException;
import java.util.PriorityQueue;

class Main {

	public static void main(String[] args) throws Exception {
		new Main().run();
	}

	void tr(Object... objects) {
		System.out.println(Arrays.deepToString(objects));
	}

	void run() throws Exception {
		Scanner sc = new Scanner();
		int N = sc.nextInt();
		long[] x = new long[N];
		long[] sum = new long[N];
		long X = sc.nextLong();
		for (int i = 0; i < N; ++i) {
			x[i] = sc.nextLong();
		}
		for (int i = 0; i < N; ++i) {
			sum[i] = (i - 1 >= 0 ? sum[i - 1] : 0) + x[i];
		}
		long ans = Long.MAX_VALUE;
		out: for (int i = 0; i < N; ++i) {
			int len = N - i;
			long cur = 0;
			cur += X * len;// ????????
			cur += 2 * (sum[N - 1] - (i - 1 >= 0 ? sum[i - 1] : 0));
			int cntK = 0;
			for (int j = N - 1; j >= 0; j -= len) {
				long range = sum[j] - (j - len >= 0 ? sum[j - len] : 0);
				cur += (2 * (cntK + 1) + 1) * range;
				++cntK;
				if (cur - X * len > 1e15)
					continue out;
				if (cur > ans)
					continue out;
			}
			ans = Math.min(ans, cur);
		}
		System.out.println(ans + X * N);// ????????????????
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
}