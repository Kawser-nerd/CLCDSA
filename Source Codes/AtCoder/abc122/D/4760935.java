import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class Main {
	private static final int MOD = 1000000007;
	InputStream is;
	PrintWriter out;
	String INPUT = "";

	void solve() {
		int n = ni();
		long dp[][][][] = new long[n + 1][4][4][4];
		dp[0][0][0][0] = 1;
		for (int i = 1; i <= n; i++)
			for (int i3 = 0; i3 < 4; i3++) {
				for (int i0 = 0; i0 < 4; i0++)
					for (int i1 = 0; i1 < 4; i1++)
						for (int i2 = 0; i2 < 4; i2++) {
							// 12?3, 1?23, 123, 213, 132

							if (i0 == 1 && i3 == 3 && (i1 == 2 || i2 == 2) || i1 * 100 + i2 * 10 + i3 == 123
									|| i1 * 100 + i2 * 10 + i3 == 213 || i1 * 100 + i2 * 10 + i3 == 132) {
//								tr(i0, i1, i2, i3);
								continue;
							}
							dp[i][i1][i2][i3] = (dp[i][i1][i2][i3] + dp[i - 1][i0][i1][i2]) % MOD;
						}
			}
//		tr(dp[1]);

		long ans = 0;

//	tr(dp[4]);
		for (int i0 = 0; i0 < 4; i0++)
			for (int i1 = 0; i1 < 4; i1++)
				for (int i2 = 0; i2 < 4; i2++)
					ans += dp[n][i0][i1][i2];

		System.out.println(ans % MOD);
	}

	StringBuffer sb = new StringBuffer();

	void run() throws Exception {
		is = INPUT.isEmpty() ? System.in : new ByteArrayInputStream(INPUT.getBytes());
		out = new PrintWriter(System.out);
		Thread t = new Thread(null, null, "~", Runtime.getRuntime().maxMemory()) {
			@Override
			public void run() {
				long s = System.currentTimeMillis();
				solve();
				out.flush();
				if (!INPUT.isEmpty())
					tr(System.currentTimeMillis() - s + "ms");
			}
		};
		t.start();
		t.join();
	}

	public static void main(String[] args) throws Exception {
		new Main().run();
	}

	private byte[] inbuf = new byte[1024];
	public int lenbuf = 0, ptrbuf = 0;

	private int readByte() {
		if (lenbuf == -1)
			throw new InputMismatchException();
		if (ptrbuf >= lenbuf) {
			ptrbuf = 0;
			try {
				lenbuf = is.read(inbuf);
			} catch (IOException e) {
				throw new InputMismatchException();
			}
			if (lenbuf <= 0)
				return -1;
		}
		return inbuf[ptrbuf++];
	}

	private boolean isSpaceChar(int c) {
		return !(c >= 33 && c <= 126);
	}

	private int skip() {
		int b;
		while ((b = readByte()) != -1 && isSpaceChar(b))
			;
		return b;
	}

	private double nd() {
		return Double.parseDouble(ns());
	}

	private char nc() {
		return (char) skip();
	}

	private String ns() {
		int b = skip();
		StringBuilder sb = new StringBuilder();
		while (!(isSpaceChar(b))) { // when nextLine, (isSpaceChar(b) && b != ' ')
			sb.appendCodePoint(b);
			b = readByte();
		}
		return sb.toString();
	}

	private char[] ns(int n) {
		char[] buf = new char[n];
		int b = skip(), p = 0;
		while (p < n && !(isSpaceChar(b))) {
			buf[p++] = (char) b;
			b = readByte();
		}
		return n == p ? buf : Arrays.copyOf(buf, p);
	}

	private char[][] nm(int n, int m) {
		char[][] map = new char[n][];
		for (int i = 0; i < n; i++)
			map[i] = ns(m);
		return map;
	}

	private int[] na(int n) {
		int[] a = new int[n];
		for (int i = 0; i < n; i++)
			a[i] = ni();
		return a;
	}

	private int[][] na(int n, int m) {
		int[][] a = new int[n][];
		for (int i = 0; i < n; i++)
			a[i] = na(m);
		return a;
	}

	private int ni() {
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

	private long nl() {
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

	private static void tr(Object... o) {
		System.out.println(Arrays.deepToString(o));
	}
}