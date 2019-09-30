import java.io.IOException;
import java.io.InputStream;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.List;
import java.util.NoSuchElementException;

public class Main {

	public static void main(String[] args) {
		FastScanner sc = new FastScanner();
		long n = sc.nextLong();
		long s = sc.nextLong();

		long b = findB2(n, s);
		System.out.println(b);
	}

	public static List<Long> allFactors(long n) {
		if (n == 1) {
			return new ArrayList<Long>(Arrays.asList(1L));
		}
		long logN = (long) Math.sqrt(n) + 1;
		List<long[]> factors = new ArrayList<>();

		for (int i = 2; i < logN; i++) {
			if (n % i == 0) {
				long[] elem = new long[] { i, 0 };
				while (n % i == 0) {
					elem[1]++;
					n /= i;
				}
				factors.add(elem);
			}
		}
		if (n != 1) {
			factors.add(new long[] { n, 1 });
		}

		int[] count = new int[factors.size()];
		int factorsSize = factors.size();

		List<Long> list = new ArrayList<>();
		loop: while (true) {
			long x = 1;
			for (int i = 0; i < factorsSize; i++) {
				long[] v = factors.get(i);
				for (int j = 0; j < count[i]; j++) {
					x *= v[0];
				}
			}
			list.add(x);

			int idx = 0;
			while (count[idx] == factors.get(idx)[1]) {
				count[idx] = 0;
				idx++;
				if (idx == factorsSize) {
					break loop;
				}
			}
			count[idx]++;
		}
		return list;
	}

	private static long findB2(long n, long s) {
		if (n == s)
			return n + 1;
		List<Long> list = allFactors(n - s);
		Collections.sort(list);
		for (long x : list) {
			long b = x + 1;

			if (b >= 2 && f(b, n) == s) {
				return b;
			}
		}
		return -1;
	}

	private static long f(long b, long n) {
		if (n < b) {
			return n;
		} else {
			return f(b, n / b) + (n % b);
		}
	}

}

class FastScanner {
	public static String debug = null;

	private final InputStream in = System.in;
	private int ptr = 0;
	private int buflen = 0;
	private byte[] buffer = new byte[1024];
	private boolean eos = false;

	private boolean hasNextByte() {
		if (ptr < buflen) {
			return true;
		} else {
			ptr = 0;
			try {
				if (debug != null) {
					buflen = debug.length();
					buffer = debug.getBytes();
					debug = "";
					eos = true;
				} else {
					buflen = in.read(buffer);
				}
			} catch (IOException e) {
				e.printStackTrace();
			}
			if (buflen < 0) {
				eos = true;
				return false;
			} else if (buflen == 0) {
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

	private static boolean isPrintableChar(int c) {
		return 33 <= c && c <= 126;
	}

	private void skipUnprintable() {
		while (hasNextByte() && !isPrintableChar(buffer[ptr]))
			ptr++;
	}

	public boolean isEOS() {
		return this.eos;
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

	public int nextInt() {
		return (int) nextLong();
	}

	public long[] nextLongList(int n) {
		return nextLongTable(1, n)[0];
	}

	public int[] nextIntList(int n) {
		return nextIntTable(1, n)[0];
	}

	public long[][] nextLongTable(int n, int m) {
		long[][] ret = new long[n][m];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				ret[i][j] = nextLong();
			}
		}
		return ret;
	}

	public int[][] nextIntTable(int n, int m) {
		int[][] ret = new int[n][m];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				ret[i][j] = nextInt();
			}
		}
		return ret;
	}
}