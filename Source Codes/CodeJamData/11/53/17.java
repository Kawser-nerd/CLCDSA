import java.io.*;
import java.util.*;
import java.math.*;

public class Csmall implements Runnable {

	void solve() {
		int t = nextInt();
		for (int test = 0; test < t; test++) {
			int n = nextInt();
			int m = nextInt();
			char[][] c = new char[n][];
			for (int i = 0; i < n; i++) {
				c[i] = nextToken().toCharArray();
			}
			out.println("Case #" + (test + 1) + ": " + solve(n, m, c));
		}
	}

	static final char[] DIRS = { '-', '|', '\\', '/' };

	static final int[][] DX = { { 0, 0 }, { 1, -1 }, { 1, -1 }, { 1, -1 } };
	static final int[][] DY = { { 1, -1 }, { 0, 0 }, { 1, -1 }, { -1, 1 } };

	static int solve(int n, int m, char[][] c) {
		int all = (1 << n * m);
		boolean[][] was = new boolean[n][m];
		int ans = 0;
		int[][] w = new int[n][m];
		loop: for (int mask = 0; mask < all; mask++) {
			for (int j = 0; j < n; j++) {
				Arrays.fill(was[j], false);
			}
			for (int i = 0, q = mask; i < n; i++) {
				for (int j = 0; j < m; j++) {
					w[i][j] = q & 1;
					q >>= 1;
				}
			}
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++) {
					if (was[i][j]) {
						continue;
					}
					int x = i;
					int y = j;
					while (!was[x][y]) {
						was[x][y] = true;
						int dir = findDir(c[x][y]);
						int newX = (x + DX[dir][w[x][y]] + n) % n;
						int newY = (y + DY[dir][w[x][y]] + m) % m;
						x = newX;
						y = newY;
					}
					if (x != i || y != j) {
						continue loop;
					}
				}
			}
			ans++;
		}
		return ans;
	}

	static int findDir(char c) {
		for (int i = 0; i < DIRS.length; i++) {
			if (DIRS[i] == c) {
				return i;
			}
		}
		throw new AssertionError();
	}

	FastScanner sc;
	PrintWriter out;

	public void run() {
		try {
			sc = new FastScanner("csmall.in");
			out = new PrintWriter("csmall.out");
			solve();
			sc.close();
			out.close();
		} catch (Throwable e) {
			e.printStackTrace();
			System.exit(1);
		}
	}

	int nextInt() {
		return sc.nextInt();
	}

	String nextToken() {
		return sc.nextToken();
	}

	long nextLong() {
		return sc.nextLong();
	}

	double nextDouble() {
		return sc.nextDouble();
	}

	BigInteger nextBigInteger() {
		return sc.nextBigInteger();
	}

	class FastScanner extends BufferedReader {
		StringTokenizer st;
		boolean eof;
		String buf;
		String curLine;
		boolean createST;

		public FastScanner(String fileName) throws FileNotFoundException {
			this(fileName, true);
		}

		public FastScanner(String fileName, boolean createST)
				throws FileNotFoundException {
			super(new FileReader(fileName));
			this.createST = createST;
			nextToken();
		}

		public FastScanner(InputStream stream) {
			this(stream, true);
		}

		public FastScanner(InputStream stream, boolean createST) {
			super(new InputStreamReader(stream));
			this.createST = createST;
			nextToken();
		}

		String nextLine() {
			String ret = curLine;
			if (createST) {
				st = null;
			}
			nextToken();
			return ret;
		}

		String nextToken() {
			if (!createST) {
				try {
					curLine = readLine();
				} catch (Exception e) {
					eof = true;
				}
				return null;
			}
			while (st == null || !st.hasMoreTokens()) {
				try {
					curLine = readLine();
					st = new StringTokenizer(curLine);
				} catch (Exception e) {
					eof = true;
					break;
				}
			}
			String ret = buf;
			buf = eof ? "-1" : st.nextToken();
			return ret;
		}

		int nextInt() {
			return Integer.parseInt(nextToken());
		}

		long nextLong() {
			return Long.parseLong(nextToken());
		}

		double nextDouble() {
			return Double.parseDouble(nextToken());
		}

		BigInteger nextBigInteger() {
			return new BigInteger(nextToken());
		}

		public void close() {
			try {
				buf = null;
				st = null;
				curLine = null;
				super.close();
			} catch (Exception e) {

			}
		}

		boolean isEOF() {
			return eof;
		}
	}

	public static void main(String[] args) {
		new Csmall().run();
	}
}