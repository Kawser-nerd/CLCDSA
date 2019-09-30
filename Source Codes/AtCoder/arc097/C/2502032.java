import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.NoSuchElementException;

public class Main {

	static PrintWriter out;
	static InputReader ir;

	static void solve() {
		int n = ir.nextInt();
		int[][] p = new int[n][2];
		for (int i = 0; i < 2 * n; i++) {
			char c = ir.next().charAt(0);
			if (c == 'W')
				p[ir.nextInt() - 1][0] = i;
			else
				p[ir.nextInt() - 1][1] = i;
		}
		int[][] ct = new int[n][n + 1];
		int[][] ct2 = new int[n][n + 1];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (p[i][1] > p[j][0])
					ct[i][j + 1]++;
			}
			for (int j = 0; j < n; j++)
				ct[i][j + 1] += ct[i][j];
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (p[i][0] > p[j][1])
					ct2[i][j + 1]++;
			}
			for (int j = 0; j < n; j++)
				ct2[i][j + 1] += ct2[i][j];
		}
		long[][] dp = new long[2 * n + 1][n + 1];
		for (int i = 0; i <= 2 * n; i++)
			Arrays.fill(dp[i], (long) 1e9);
		dp[2 * n][n] = 0;
		for (int i = 2 * n - 1; i >= 0; i--) {
			for (int j = 0; j <= n; j++) {
				int k = i - j;
				if (k < 0 || k > n)
					continue;
				if (j == n)
					dp[i][j] = dp[i + 1][j] + n - ct[k][n];
				else if (k == n)
					dp[i][j] = dp[i + 1][j + 1] + n - ct2[j][n];
				else
					dp[i][j] = Math.min(dp[i + 1][j] + j - ct[k][j], dp[i + 1][j + 1] + k - ct2[j][k]);
			}
		}
		long ret = dp[0][0];
		for (int i = 0; i < n; i++)
			for (int j = i + 1; j < n; j++) {
				if (p[i][0] > p[j][0])
					ret++;
				if (p[i][1] > p[j][1])
					ret++;
			}
		out.println(ret);
	}

	static class UnionFindTree {

		private int[] par;
		private int[] rank;

		public UnionFindTree(int size) {
			par = new int[size];
			rank = new int[size];
			for (int i = 0; i < size; i++) {
				par[i] = i;
				rank[i] = 0;
			}
		}

		private int find(int x) {
			if (par[x] == x)
				return x;
			else
				return par[x] = find(par[x]);
		}

		public void unite(int x, int y) {
			x = find(x);
			y = find(y);
			if (x == y)
				return;
			else if (rank[x] > rank[y])
				par[y] = x;
			else {
				par[x] = y;
				if (rank[x] == rank[y])
					rank[y]++;
			}
		}

		public boolean same(int x, int y) {
			return find(x) == find(y);
		}
	}

	public static void main(String[] args) throws Exception {
		ir = new InputReader(System.in);
		out = new PrintWriter(System.out);
		solve();
		out.flush();
	}

	static class InputReader {

		private InputStream in;
		private byte[] buffer = new byte[1024];
		private int curbuf;
		private int lenbuf;

		public InputReader(InputStream in) {
			this.in = in;
			this.curbuf = this.lenbuf = 0;
		}

		public boolean hasNextByte() {
			if (curbuf >= lenbuf) {
				curbuf = 0;
				try {
					lenbuf = in.read(buffer);
				} catch (IOException e) {
					throw new InputMismatchException();
				}
				if (lenbuf <= 0)
					return false;
			}
			return true;
		}

		private int readByte() {
			if (hasNextByte())
				return buffer[curbuf++];
			else
				return -1;
		}

		private boolean isSpaceChar(int c) {
			return !(c >= 33 && c <= 126);
		}

		private void skip() {
			while (hasNextByte() && isSpaceChar(buffer[curbuf]))
				curbuf++;
		}

		public boolean hasNext() {
			skip();
			return hasNextByte();
		}

		public String next() {
			if (!hasNext())
				throw new NoSuchElementException();
			StringBuilder sb = new StringBuilder();
			int b = readByte();
			while (!isSpaceChar(b)) {
				sb.appendCodePoint(b);
				b = readByte();
			}
			return sb.toString();
		}

		public int nextInt() {
			if (!hasNext())
				throw new NoSuchElementException();
			int c = readByte();
			while (isSpaceChar(c))
				c = readByte();
			boolean minus = false;
			if (c == '-') {
				minus = true;
				c = readByte();
			}
			int res = 0;
			do {
				if (c < '0' || c > '9')
					throw new InputMismatchException();
				res = res * 10 + c - '0';
				c = readByte();
			} while (!isSpaceChar(c));
			return (minus) ? -res : res;
		}

		public long nextLong() {
			if (!hasNext())
				throw new NoSuchElementException();
			int c = readByte();
			while (isSpaceChar(c))
				c = readByte();
			boolean minus = false;
			if (c == '-') {
				minus = true;
				c = readByte();
			}
			long res = 0;
			do {
				if (c < '0' || c > '9')
					throw new InputMismatchException();
				res = res * 10 + c - '0';
				c = readByte();
			} while (!isSpaceChar(c));
			return (minus) ? -res : res;
		}

		public double nextDouble() {
			return Double.parseDouble(next());
		}

		public int[] nextIntArray(int n) {
			int[] a = new int[n];
			for (int i = 0; i < n; i++)
				a[i] = nextInt();
			return a;
		}

		public long[] nextLongArray(int n) {
			long[] a = new long[n];
			for (int i = 0; i < n; i++)
				a[i] = nextLong();
			return a;
		}

		public char[][] nextCharMap(int n, int m) {
			char[][] map = new char[n][m];
			for (int i = 0; i < n; i++)
				map[i] = next().toCharArray();
			return map;
		}
	}
}