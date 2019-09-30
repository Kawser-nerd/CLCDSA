import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class Main {
	static InputStream is;
	static PrintWriter out;
	static String INPUT = "";

	void solve() {
		int n = ni(), x[] = na(n), l = ni(), q = ni();
		int dp[][] = new int[n][20];
		for (int i = 0; i < n; ++i) {
			int min = i, max = n;
			while (max - min > 1) {
				int mid = (max + min) / 2;
				if (x[i] + l >= x[mid]) {
					min = mid;
				} else {
					max = mid;
				}
			}
			Arrays.fill(dp[i], Integer.MAX_VALUE);
			dp[i][0] = min;
		}
		for (int j = 1; j < 20; ++j) {
			for (int i = 0; i < n; ++i) {
				if (dp[i][j - 1] >= n - 1) break;
				dp[i][j] = dp[dp[i][j - 1]][j - 1];
			}
		}
		for (int i = 0; i < q; ++i) {
			int a = ni() - 1, b = ni() - 1;
			if (a > b) {
				int t = a;
				a = b;
				b = t;
			}
			int res = 0;
			while (a < b) {
				for (int j = 0; j < 20; ++j) {
					if (dp[a][j + 1] > b) {
						res += 1 << j;
						a = dp[a][j];
						break;
					}
				}
			}
			out.println(res);
		}
	}

	public static void main(String[] args) throws Exception {
		long S = System.currentTimeMillis();
		is = INPUT.isEmpty() ? System.in : new ByteArrayInputStream(INPUT.getBytes());
		out = new PrintWriter(System.out);

		new Main().solve();
		out.flush();
		long G = System.currentTimeMillis();
		tr(G - S + "ms");
	}

	static boolean eof() {
		if (lenbuf == -1) return true;
		int lptr = ptrbuf;
		while (lptr < lenbuf)
			if (!isSpaceChar(inbuf[lptr++])) return false;

		try {
			is.mark(1000);
			while (true) {
				int b = is.read();
				if (b == -1) {
					is.reset();
					return true;
				} else if (!isSpaceChar(b)) {
					is.reset();
					return false;
				}
			}
		} catch (IOException e) {
			return true;
		}
	}

	private static byte[] inbuf = new byte[1024];
	static int lenbuf = 0, ptrbuf = 0;

	private static int readByte() {
		if (lenbuf == -1) throw new InputMismatchException();
		if (ptrbuf >= lenbuf) {
			ptrbuf = 0;
			try {
				lenbuf = is.read(inbuf);
			} catch (IOException e) {
				throw new InputMismatchException();
			}
			if (lenbuf <= 0) return -1;
		}
		return inbuf[ptrbuf++];
	}

	private static boolean isSpaceChar(int c) {
		return !(c >= 33 && c <= 126);
	}

	private static int skip() {
		int b;
		while ((b = readByte()) != -1 && isSpaceChar(b))
			;
		return b;
	}

	static double nd() {
		return Double.parseDouble(ns());
	}

	static char nc() {
		return (char) skip();
	}

	private static String ns() {
		int b = skip();
		StringBuilder sb = new StringBuilder();
		while (!(isSpaceChar(b))) { // when nextLine, (isSpaceChar(b) && b != ' ')
			sb.appendCodePoint(b);
			b = readByte();
		}
		return sb.toString();
	}

	private static char[] ns(int n) {
		char[] buf = new char[n];
		int b = skip(), p = 0;
		while (p < n && !(isSpaceChar(b))) {
			buf[p++] = (char) b;
			b = readByte();
		}
		return n == p ? buf : Arrays.copyOf(buf, p);
	}

	static char[][] nm(int n, int m) {
		char[][] map = new char[n][];
		for (int i = 0; i < n; i++)
			map[i] = ns(m);
		return map;
	}

	static int[] na(int n) {
		int[] a = new int[n];
		for (int i = 0; i < n; i++)
			a[i] = ni();
		return a;
	}

	private static int ni() {
		int num = 0, b;
		boolean minus = false;
		while ((b = readByte()) != -1 && !((b >= '0' && b <= '9') || b == '-'))
			;
		if (b == '-') {
			minus = true;
			b = readByte();
		}

		while (true) {
			if (b >= '0' && b <= '9') {
				num = num * 10 + (b - '0');
			} else {
				return minus ? -num : num;
			}
			b = readByte();
		}
	}

	static long nl() {
		long num = 0;
		int b;
		boolean minus = false;
		while ((b = readByte()) != -1 && !((b >= '0' && b <= '9') || b == '-'))
			;
		if (b == '-') {
			minus = true;
			b = readByte();
		}

		while (true) {
			if (b >= '0' && b <= '9') {
				num = num * 10 + (b - '0');
			} else {
				return minus ? -num : num;
			}
			b = readByte();
		}
	}

	static void tr(Object... o) {
		if (INPUT.length() != 0) System.out.println(Arrays.deepToString(o));
	}

	static void debug(Object... o) {
		System.out.println(Arrays.deepToString(o));
	}
}