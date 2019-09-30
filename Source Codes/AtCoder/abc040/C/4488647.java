import java.io.IOException;
import java.io.InputStream;
import java.util.AbstractMap;
import java.util.NoSuchElementException;

public class Main {

	public static void main(String[] args) {
		final long INF = Long.MAX_VALUE;
		long[] dp = new long[100010];
		long[] h = new long[100010];

		FastScanner fc = new FastScanner();
		int N = fc.nextInt();

		// ???
		for (int i = 0; i < 100010; i++) {
			dp[i] = INF;
		}
		for (int i = 0; i < N; i++) {
			h[i] = fc.nextLong();
		}

		// ???????
		dp[0] = 0;
		dp[1] = Math.abs(h[0] - h[1]);

		for (int i = 2; i < N; i++) {
			dp[i] = chmin(dp[i], dp[i-1] + Math.abs(h[i] - h[i-1]));
			dp[i] = chmin(dp[i], dp[i-2] + Math.abs(h[i] - h[i-2]));
		}

		System.out.println(dp[N-1]);
	}

	public static  long chmin(long a, long b) {
		if (a > b) {
			return b;
		}
		return a;
	}

	public static long chmax(long a, long b) {
		if (a < b) {
			return b;
		}
		return a;
	}

	static class FastScanner {
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
			if (hasNextByte()) {
				return buffer[ptr++];
			} else {
				return -1;
			}
		}

		private static boolean isPrintableChar(int c) {
			return 33 <= c && c <= 126;
		}

		public boolean hasNext() {
			while (hasNextByte() && !isPrintableChar(buffer[ptr])) {
				ptr++;
			}
			return hasNextByte();
		}

		public String next() {
			if (!hasNext()) {
				throw new NoSuchElementException();
			}

			StringBuilder sb = new StringBuilder();
			int b = readByte();
			while (isPrintableChar(b)) {
				sb.appendCodePoint(b);
				b = readByte();
			}
			return sb.toString();
		}

		/**
		 *
		 * @return ??Long
		 */
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

		/**
		 *
		 * @return ??Int
		 */
		public int nextInt() {
			long nl = nextLong();
			if (nl < Integer.MIN_VALUE || nl > Integer.MAX_VALUE)
				throw new NumberFormatException();
			return (int) nl;
		}

		/**
		 *
		 * @return ??Double
		 */
		public double nextDouble() {
			return Double.parseDouble(next());
		}
	}

	class Pair<K, V> extends AbstractMap.SimpleEntry<K, V> {
		/** serialVersionUID. */
		private static final long serialVersionUID = 6411527075103472113L;

		public Pair(final K key, final V value) {
			super(key, value);
		}
	}

}