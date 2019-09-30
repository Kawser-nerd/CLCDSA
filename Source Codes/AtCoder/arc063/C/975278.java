import java.io.IOException;
import java.io.InputStream;
import java.util.Arrays;
import java.util.NoSuchElementException;

public class Main {

	private static int[] low;
	private static int[] high;
	private static int[][] g;
	private static int N;

	public static void main(String[] args) {
		FastScanner sc = new FastScanner();
		N = sc.nextInt();
		int[] from = new int[N - 1];
		int[] to = new int[N - 1];
		for (int i = 0; i < N - 1; i++) {
			from[i] = sc.nextInt() - 1;
			to[i] = sc.nextInt() - 1;
		}
		g = packU(N, from, to);
		low = new int[N];
		high = new int[N];
		Arrays.fill(low, 0);
		Arrays.fill(high, 1000000);

		int K = sc.nextInt();
		int s = -1;
		for (int i = 0; i < K; i++) {
			int v = sc.nextInt() - 1;
			int p = sc.nextInt();
			low[v] = p;
			high[v] = p;
			
			if (s < 0) s = v;
		}

		boolean ret = dfs(-1, s, low[s] % 2);
		if (ret) {
			dfs2(-1, s);
			System.out.println("Yes");
			for (int v : high) {
				System.out.println(v);
			}
		} else {
			System.out.println("No");
		}
		
	}

	private static boolean dfs(int before, int now, int parity) {
		if (low[now] == high[now] && low[now] % 2 != parity) {
			return false;
		}

		for (int p : g[now]) {
			if (p != before) {
				if (!dfs(now, p, (parity + 1) % 2)) return false;

				low[now] = Math.max(low[now], low[p] - 1);
				high[now] = Math.min(high[now], high[p] + 1);
				
				if (low[now] > high[now]) return false;
			}
		}
		return true;
	}

	private static void dfs2(int before, int now) {
		if (before >= 0) {
			low[now] = Math.max(low[now], low[before] - 1);
			high[now] = Math.min(high[now], high[before] + 1);
		}

		for (int p : g[now]) {
			if (p != before) {
				dfs2(now, p);
			}
		}
	}

	public static int[][] packU(int n, int[] from, int[] to) {
		int[][] g = new int[n][];
		int[] p = new int[n];
		for (int f : from)
			p[f]++;
		for (int t : to)
			p[t]++;
		for (int i = 0; i < n; i++)
			g[i] = new int[p[i]];
		for (int i = 0; i < from.length; i++) {
			g[from[i]][--p[from[i]]] = to[i];
			g[to[i]][--p[to[i]]] = from[i];
		}
		return g;
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