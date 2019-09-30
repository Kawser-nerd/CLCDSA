import java.io.IOException;
import java.io.InputStream;
import java.util.Arrays;
import java.util.NoSuchElementException;
import java.util.Scanner;

public class Main {
	class BIT {
		int n;
		long[] v;

		public BIT(int n_) {
			n = n_;
			v = new long[n + 1];
		}

		void add(int k, int val) {
			if (k <= 0)
				throw new AssertionError();
			while (k <= n) {
				v[k] += val;
				k += k & -k;
			}
		}

		long sum(int k) {
			long ret = 0;
			while (k >= 1) {
				ret += v[k];
				k -= k & -k;
			}
			return ret;
		}

		long sum(int l, int r) {
			return sum(r - 1) - sum(l - 1);
		}
	}

	void run() {
		Scanner sc = new Scanner();
		int N = sc.nextInt();
		char[] c = new char[2 * N];
		int[] a = new int[2 * N];
		int[] posW = new int[N + 1];
		int[] posB = new int[N + 1];
		long ans = 0;
		for (int i = 0; i < 2 * N; ++i) {
			c[i] = sc.next().toCharArray()[0];
			a[i] = sc.nextInt();
			if (c[i] == 'W') {
				posW[a[i]] = i + 1;
			} else {
				posB[a[i]] = i + 1;
			}
		}
		long[][] smaller = new long[2 * N][2 * N];// ??i??????????????????[0,j]???????
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j <= i; ++j) {
				if (j > 0)
					smaller[i][j] += smaller[i][j - 1];
				if (c[i] == c[j] && a[j] <= a[i]) {
					smaller[i][j]++;
				}
			}
		}
		long[][] dp = new long[N + 1][N + 1];// w?i,b?j????????min
		for (int i = 0; i < dp.length; ++i) {
			for (int j = 0; j < dp[i].length; ++j) {
				dp[i][j] = Long.MAX_VALUE / 3;
			}
		}
		// dp[n][n]???
		dp[0][0] = 0;
		BIT bit1 = new BIT(2 * N + 1);
		for (int i = 0; i <= N; ++i) {// w
			if (i > 0)
				bit1.add(posW[i], 1);
			BIT bit2 = new BIT(2 * N + 1);
			for (int j = 0; j <= N; ++j) {
				if (j > 0) {
					bit2.add(posB[j], 1);
				}
				if (i + 1 <= N)
					dp[i + 1][j] = Math.min(dp[i + 1][j],
							dp[i][j] + (posW[i + 1] - 1) - bit1.sum(1, posW[i + 1]) - bit2.sum(1, posW[i + 1]));
				if (j + 1 <= N)
					dp[i][j + 1] = Math.min(dp[i][j + 1],
							dp[i][j] + (posB[j + 1] - 1) - bit1.sum(1, posB[j + 1]) - bit2.sum(1, posB[j + 1]));
			}
		}
		System.out.println(dp[N][N]);
	}

	public static void main(String[] args) {
		new Main().run();
	}

	void tr(Object... objects) {
		System.out.println(Arrays.deepToString(objects));
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

		int nextInt() {
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
}