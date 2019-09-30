import java.io.IOException;
import java.io.InputStream;
import java.util.Arrays;
import java.util.NoSuchElementException;

public class Main {
	public static void main(String[] args) {
		// long t = System.currentTimeMillis();
		new Main().run();
		// System.err.println(System.currentTimeMillis() - t);
	}

	int N, K;

	public void run() {
		Scanner sc = new Scanner();
		N = sc.nextInt();
		K = sc.nextInt();

		double[][] f = new double[N][K + 1];
		double[][] ma = new double[N + 1][K + 1];
		for (int i = N - 1; i >= 0; --i) {
			for (int j = 1; j <= K; ++j) {
				if (i + 1 < N)
					f[i][j] += f[i + 1][j] * i / (i + 1);
				f[i][j] += 1.0 / N;
				f[i][j] += ma[i + 1][j - 1] / (i + 1);
				ma[i][j] = Math.max(ma[i + 1][j], f[i][j]);
			}
		}
		double ans = 0;
		for (int i = 0; i < N; ++i) {
			ans = Math.max(ans, f[i][K]);
		}
		System.out.println(ans);
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