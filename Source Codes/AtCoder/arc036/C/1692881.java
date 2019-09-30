import java.io.IOException;
import java.io.InputStream;
import java.util.Arrays;
import java.util.NoSuchElementException;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		// long t = System.currentTimeMillis();
		new Main().run();
		// System.err.println(System.currentTimeMillis() - t);
	}

	int n;
	int k;
	char[] s;
	int[][][][] f;

	long MODULO = 1_000_000__000 + 7;

	public void run() {
		Scanner sc = new Scanner();
		n = sc.nextInt();
		k = sc.nextInt();
		s = sc.next().toCharArray();
		f = new int[2][2][n + 1][2 * n + 1];
		for (int max = 0; max <= n; ++max) {
			if (max == 0)
				f[0][1][max][n] = 1;
			else
				f[0][0][max][n] = 1;
		}

		int b = 0;
		for (int i = 0; i < n; ++i) {

			for (int max = 0; max <= n; ++max) {
				for (int balance = Math.max(-k, max - k - 1); balance <= Math.min(k, max + 1); ++balance) {
					if ((s[i] == '1' || s[i] == '?') && balance + 1 <= max && balance + 1 <= k) {
						f[b ^ 1][1][max][balance + n + 1] = add(f[b ^ 1][1][max][balance + n + 1],
								f[b][1][max][balance + n]);

						if (balance + 1 == max) {
							f[b ^ 1][1][max][balance + n + 1] = add(f[b ^ 1][1][max][balance + n + 1],
									f[b][0][max][balance + n]);
						}

						if (balance + 1 < max) {
							f[b ^ 1][0][max][balance + n + 1] = add(f[b ^ 1][0][max][balance + n + 1],
									f[b][0][max][balance + n]);
						}

					}
					if ((s[i] == '0' || s[i] == '?') && -k <= balance - 1 && max - (balance - 1) <= k) {
						f[b ^ 1][1][max][balance + n - 1] = add(f[b ^ 1][1][max][balance + n - 1],
								f[b][1][max][balance + n]);
						f[b ^ 1][0][max][balance + n - 1] = add(f[b ^ 1][0][max][balance + n - 1],
								f[b][0][max][balance + n]);

					}
					f[b][0][max][balance + n] = 0;
					f[b][1][max][balance + n] = 0;

				}

			}
			b ^= 1;
		}

		long ans = 0;

		for (int i = 0; i <= n; ++i) {
			for (int balance = -k; balance <= k; ++balance) {
				ans = add(ans, f[b][1][i][balance + n]);
			}
		}

		System.out.println(ans);

	}

	int add(long a, long b) {
		long ret = a + b;
		if (ret >= MODULO) {
			ret -= MODULO;
		}
		return (int) ret;
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