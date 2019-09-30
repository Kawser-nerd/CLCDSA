import java.io.IOException;
import java.io.InputStream;
import java.util.Arrays;
import java.util.NoSuchElementException;
 
public class Main implements Runnable {
	public static void main(String[] args) {
		// long t = System.currentTimeMillis();
		new Thread(null, new Main(), "", Runtime.getRuntime().maxMemory()).start();
		// System.err.println(System.currentTimeMillis() - t);
	}
 
	class BIT {
		int n;
		long[] v;
 
		public BIT(int n_) {
			n = n_;
			v = new long[n + 1];
		}
 
		void add(int k, int val) {
			++k;
			while (k <= n) {
				v[k] += val;
				k += k & -k;
			}
		}
 
		long sum(int k) {
			++k;
			long ret = 0;
			while (k > 0) {
				ret += v[k];
				k -= k & -k;
			}
			return ret;
		}
	}
 
	long inversions(int[] a, int[] b) {
		int n = a.length;
		int[] to = new int[n];
		int[] tob = new int[n];
		for (int i = 0; i < n; ++i) {
			to[a[i]] = i;
		}
		for (int i = 0; i < n; ++i) {
			tob[i] = to[b[i]];
		}
		return inversions(tob);
	}
 
	long inversions(int[] a) {
		int n = a.length;
		BIT bit = new BIT(n);
		long sum = 0;
		for (int i = 0; i < n; ++i) {
			sum += i - bit.sum(a[i]);
			bit.add(a[i], 1);
		}
		return sum;
	}
 
	@SuppressWarnings("unchecked")
	public void run() {
		Scanner sc = new Scanner();
		int n = sc.nextInt();
		int[] to = new int[n];
		int[] d = new int[n];
		int[] inv = new int[n];
		for (int i = 0; i < n; ++i) {
			int a = sc.nextInt();
			--a;
			to[a] = i;
			inv[i] = a;
		}
		for (int i = 0; i < n; ++i) {
			int b = sc.nextInt();
			--b;
			d[i] = to[b];
		}
 
		long invs = inversions(d);
		if (invs % 2 == 1) {
			System.out.println(-1);
			return;
		}
		BIT bit = new BIT(n);
		for (int i = 0; i < n; ++i) {
			bit.add(i, 1);
		}
		boolean[] exist = new boolean[n];
		Arrays.fill(exist, true);
		int[] ans = new int[n];
		int p = 0;
		out: for (int i = 0; i < n; ++i) {
			if (invs - 2 * bit.sum(d[i] - 1) >= 0) {
				invs -= 2 * bit.sum(d[i] - 1);
				bit.add(d[i], -1);
				exist[d[i]] = false;
				ans[p++] = inv[d[i]];
			} else {
				//
				for (int j = 0; j <= d[i] - 1; ++j) {
					if (!exist[j])
						continue;
					bit.add(j, -1);
					exist[j] = false;
					ans[p++] = inv[j];
					// j???d[i]???????
					if (invs - 2 * (bit.sum(d[i] - 1) - bit.sum(j)) == 0) {
						ans[p++] = inv[d[i]];
						exist[d[i]] = false;
						bit.add(d[i], -1);
						for (int k = j + 1; k < n; ++k) {
							if (exist[k]) {
								ans[p++] = inv[k];
							}
						}
						break out;
					}
				}
				throw new AssertionError();
			}
		}
		if (p != n) {
			throw new AssertionError();
		}
		StringBuilder sb = new StringBuilder("");
		for (int i = 0; i < p; ++i) {
			sb.append((ans[i] + 1) + (i == p - 1 ? "\n" : " "));
		}
		System.out.println(sb);
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
 
	static void tr(Object... objects) {
		System.out.println(Arrays.deepToString(objects));
	}
 
}