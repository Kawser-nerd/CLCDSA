import java.io.*;
import java.math.*;
import java.util.*;
import java.util.stream.*;

public class Main {

	int root(int x) {
		if (x < 0) {
			return -1;
		}
		int y = (int) Math.sqrt(x);
		if (y * y == x) {
			return y;
		}
		return -1;
	}

	int[][] gen(int dist) {
		ArrayList<Integer> ret = new ArrayList<>();
		for (int i = 0; i * i <= dist; i++) {
			int j = root(dist - i * i);
			if (j == -1) {
				continue;
			}
			ret.add(i);
			ret.add(j);
			ret.add(i);
			ret.add(-j);
			ret.add(-i);
			ret.add(j);
			ret.add(-i);
			ret.add(-j);
		}
		int[][] a = new int[2][ret.size() / 2];
		for (int i = 0; i < ret.size(); i += 2) {
			a[0][i / 2] = ret.get(i);
			a[1][i / 2] = ret.get(i + 1);
		}
		return a;
	}

	int[] dx;
	int[] dy;

	void dfs(int x, int y, int n, int color, int[][] f) {
		f[x][y] = color;

		for (int i = 0; i < dx.length; i++) {
			int cx = x + dx[i];
			int cy = y + dy[i];
			if (cx < 0 || cy < 0 || cx >= n || cy >= n) {
				continue;
			}
			if (f[cx][cy] == color) {
				throw new AssertionError();
			}
			if (f[cx][cy] == 0) {
				dfs(cx, cy, n, 3 - color, f);
			}
		}
	}

	int[][] color(int n, int dist) {
		// delta = gen(dist);
		int[][] tmp = gen(dist);
		dx = tmp[0];
		dy = tmp[1];
		int[][] f = new int[n][n];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (f[i][j] == 0) {
					dfs(i, j, n, 1, f);
				}
			}
		}
		return f;
	}

	void solve(int n, int d1, int d2) {
		int[][] a = color(2 * n, d1);
		int[][] b = color(2 * n, d2);

		int[] cnt = new int[4];
		for (int i = 0; i < 2 * n; i++) {
			for (int j = 0; j < 2 * n; j++) {
				int val = (a[i][j] - 1) * 2 + (b[i][j] - 1);
				cnt[val]++;
			}
		}

		int pick = 0;
		while (cnt[pick] < n * n) {
			pick++;
		}

		int left = n * n;

		for (int i = 0; i < 2 * n; i++) {
			for (int j = 0; j < 2 * n; j++) {
				int val = (a[i][j] - 1) * 2 + (b[i][j] - 1);
				if (val == pick) {
					out.println(i + " " + j);
					left--;
					if (left == 0) {
						return;
					}
				}
			}
		}
	}

	void submit() {
		solve(nextInt(), nextInt(), nextInt());
	}

	void test() {
		for (int d = 1; d <= 1; d++) {
			out.println(d);
			solve(300, d, d);
		}
	}

	void stress() {
		for (int tst = 0;; tst++) {
			if (false) {
				throw new AssertionError();
			}
			System.err.println(tst);
		}
	}

	Main() throws IOException {
		is = System.in;
		out = new PrintWriter(System.out);
		 submit();
		// stress();
//		test();
		out.close();
	}

	static final Random rng = new Random();
	static final int C = 5;

	static int rand(int l, int r) {
		return l + rng.nextInt(r - l + 1);
	}

	public static void main(String[] args) throws IOException {
		new Main();
	}

	private InputStream is;
	PrintWriter out;

	private byte[] buf = new byte[1 << 14];
	private int bufSz = 0, bufPtr = 0;

	private int readByte() {
		if (bufSz == -1)
			throw new RuntimeException("Reading past EOF");
		if (bufPtr >= bufSz) {
			bufPtr = 0;
			try {
				bufSz = is.read(buf);
			} catch (IOException e) {
				throw new RuntimeException(e);
			}
			if (bufSz <= 0)
				return -1;
		}
		return buf[bufPtr++];
	}

	private boolean isTrash(int c) {
		return c < 33 || c > 126;
	}

	private int skip() {
		int b;
		while ((b = readByte()) != -1 && isTrash(b))
			;
		return b;
	}

	String nextToken() {
		int b = skip();
		StringBuilder sb = new StringBuilder();
		while (!isTrash(b)) {
			sb.appendCodePoint(b);
			b = readByte();
		}
		return sb.toString();
	}

	String nextString() {
		int b = readByte();
		StringBuilder sb = new StringBuilder();
		while (!isTrash(b) || b == ' ') {
			sb.appendCodePoint(b);
			b = readByte();
		}
		return sb.toString();
	}

	double nextDouble() {
		return Double.parseDouble(nextToken());
	}

	char nextChar() {
		return (char) skip();
	}

	int nextInt() {
		int ret = 0;
		int b = skip();
		if (b != '-' && (b < '0' || b > '9')) {
			throw new InputMismatchException();
		}
		boolean neg = false;
		if (b == '-') {
			neg = true;
			b = readByte();
		}
		while (true) {
			if (b >= '0' && b <= '9') {
				ret = ret * 10 + (b - '0');
			} else {
				if (b != -1 && !isTrash(b)) {
					throw new InputMismatchException();
				}
				return neg ? -ret : ret;
			}
			b = readByte();
		}
	}

	long nextLong() {
		long ret = 0;
		int b = skip();
		if (b != '-' && (b < '0' || b > '9')) {
			throw new InputMismatchException();
		}
		boolean neg = false;
		if (b == '-') {
			neg = true;
			b = readByte();
		}
		while (true) {
			if (b >= '0' && b <= '9') {
				ret = ret * 10 + (b - '0');
			} else {
				if (b != -1 && !isTrash(b)) {
					throw new InputMismatchException();
				}
				return neg ? -ret : ret;
			}
			b = readByte();
		}
	}
}