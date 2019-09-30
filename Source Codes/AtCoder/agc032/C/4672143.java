import java.io.*;
import java.math.*;
import java.util.*;
import java.util.stream.*;

public class Main {

	void submit() {
		int n = nextInt();
		int m = nextInt();
		int[] deg = new int[n];
		
		int[] data = new int[2 * m];
		
		for (int i = 0; i < m; i++) {
			int v = nextInt() - 1;
			int u = nextInt() - 1;
			deg[v]++;
			deg[u]++;
			data[2 * i] = v;
			data[2 * i + 1] = u;
		}
		
		for (int i = 0; i < n; i++) {
			if (deg[i] % 2 != 0) {
				out.println("No");
				return;
			}
		}

		int c4 = 0;
		
		int root = -1;
		
		for (int i = 0; i < n; i++) {
			if (deg[i] > 4) {
				out.println("Yes");
				return;
			}
			if (deg[i] == 4) {
				c4++;
				root = i;
			}
		}
		
		if (c4 <= 1) {
			out.println("No");
			return;
		}
		
		if (c4 > 2) {
			out.println("Yes");
			return;
		}
		
		
		g = buildUGraph(data, n, m);
		
		for (int v : g[root]) {
			int prev = root;
			while (deg[v] == 2) {
				int newPrev = v;
				if (g[v][0] == prev) {
					v = g[v][1];
				} else {
					v = g[v][0];
				}
				prev = newPrev;
			}
			if (v == root) {
				out.println("Yes");
				return;
			}
		}
		
		out.println("No");
	}
	
	int[][] g;
	
	int[][] buildUGraph(int[] a, int n, int m) {
		if (m == 0) {
			if (a.length == 0) {
				return new int[n][0];
			} else {
				throw new AssertionError();
			}
		}
		if (a.length % m != 0 || a.length < 2 * m) {
			throw new AssertionError("Bad array length");
		}

		int[] deg = new int[n];
		int s = a.length / m;
		for (int i = 0; i < a.length; i += s) {
			deg[a[i]]++;
			deg[a[i + 1]]++;
		}

		int[][] g = new int[n][];
		for (int i = 0; i < n; i++) {
			g[i] = new int[deg[i] * (s - 1)];
		}

		for (int i = s * (m - 1); i >= 0; i -= s) {
			int v = a[i];
			int u = a[i + 1];
			int pv = (--deg[v]) * (s - 1);
			g[v][pv] = u;
			System.arraycopy(a, i + 2, g[v], pv + 1, s - 2);

			int pu = (--deg[u]) * (s - 1);
			g[u][pu] = v;
			System.arraycopy(a, i + 2, g[u], pu + 1, s - 2);
		}

		return g;
	}


	void test() {

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
		// test();
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