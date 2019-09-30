import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.NoSuchElementException;
import java.util.Scanner;

class Main {

	public static void main(String[] args) throws FileNotFoundException {
		new Main().run();
	}

	final long MOD = (long) (1e9 + 7);
	long[] inv = new long[100002];
	{
		inv[0] = inv[1] = 1;
		for (int i = 2; i < inv.length; ++i) {
			inv[i] = MOD - inv[(int) MOD % i] * (MOD / i) % MOD;
		}
	}

	void run() {
		PrintWriter pw = new PrintWriter(System.out);
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		long[] A = new long[N];
		for (int i = 0; i < N; ++i) {
			A[i] = sc.nextLong();
		}
		long sum = 0;
		for (int i = 1; i <= N; ++i) {
			sum = (sum + inv[i]) % MOD;
		}
		long ans = 0;
		for (int i = 0; i < N; ++i) {
			ans = (ans + sum * A[i] % MOD) % MOD;
			sum = (sum - inv[N - i] + inv[i + 2] + MOD) % MOD;
		}
		for (int i = 1; i <= N; ++i)
			ans = ans * i % MOD;
		System.out.println(ans);

	}

	long pow(long a, long n) {
		long ret = 1;
		for (; n > 0; n >>= 1, a = a * a % MOD) {
			if (n % 2 == 1) {
				ret = ret * a % MOD;
			}
		}
		return ret;
	}

	void tr(Object... objects) {
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