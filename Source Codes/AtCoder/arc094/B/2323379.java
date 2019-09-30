import java.io.File;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.NoSuchElementException;

public class Main implements Runnable {
	public static void main(String[] args) {
		new Thread(null, new Main(), "", Runtime.getRuntime().maxMemory()).start();
	}

	public void run() {
		Scanner sc = new Scanner();
		int Q = sc.nextInt();
		long[] A = new long[Q];
		long[] B = new long[Q];
		for (int i = 0; i < Q; ++i) {
			A[i] = sc.nextLong();
			B[i] = sc.nextLong();
			if (A[i] > B[i]) {
				A[i] ^= B[i];
				B[i] ^= A[i];
				A[i] ^= B[i];
			}
			if (A[i] == B[i] || A[i] + 1 == B[i]) {
				System.out.println(2 * A[i] - 2);
				continue;
			}
			long prd = A[i] * B[i];
			long ok = 0, ng = Math.max(A[i], B[i]);
			while (ng - ok > 1) {
				long m = (ok + ng) / 2;
				if (m * m < prd) {
					ok = m;
				} else
					ng = m;
			}
			long x = ok;
			if (x * (x + 1) >= prd)
				System.out.println(2 * x - 2);
			else
				System.out.println(2 * x - 1);
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