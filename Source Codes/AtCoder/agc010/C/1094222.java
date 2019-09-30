import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.InputMismatchException;

public class Main {
	InputStream is;

	int __t__ = 1;
	int __f__ = 0;
	
	int __STACKSIZE_CHANGE_FLAG__ = __f__;
	int __FILE_DEBUG_FLAG__ = __f__;
	String __DEBUG_FILE_NAME__ = "src/C2";

	FastScanner in;
	PrintWriter out;

	int[] a;
	ArrayList<Integer>[] g;
	
	long dfs(int u, int par) {
		long res = 0;
		long max = -1, sum = 0;
		int cnt = 0;
		for (int v : g[u]) {
			if (v == par) continue;
			
			long next = dfs(v, u);
			if (next == -1) return -1;
			max = Math.max(max, next);
			sum += next;
			cnt++;
		}
		
		if (cnt == 0) {
			res = a[u];
		} else {
			if (max > a[u] || sum < a[u] || sum > a[u] * 2) 
				res = -1;
			else 
				res = a[u] * 2 - sum;
		}
		// System.out.println(u + " " + par + " : " + res);
		return res;
	}
	
	public void solve() {
		int n = in.nextInt();
		a = in.nextIntArray(n);
		g = new ArrayList[n];
		for (int i = 0; i < n; i++)
			g[i] = new ArrayList<Integer>();
		for (int i = 0; i < n - 1; i++) {
			int a = in.nextInt() - 1, b = in.nextInt() - 1;
			g[a].add(b);
			g[b].add(a);
		}
		if (n == 2) {
			System.out.println(a[0] == a[1] ? "YES" : "NO");
			return;
		}
		int root = -1;
		for (int i = 0; i < n; i++) {
			if (g[i].size() != 1) root = i;
		}
		System.out.println(dfs(root, -1) == 0 ? "YES" : "NO");
	}
	
	public void run() {
		if (__FILE_DEBUG_FLAG__ == __t__) {
			try {
				is = new FileInputStream(__DEBUG_FILE_NAME__);
			} catch (FileNotFoundException e) {
				e.printStackTrace();
			}
			System.out.println("FILE_INPUT!");
		} else {
			is = System.in;
		}
		in = new FastScanner(is);
		out = new PrintWriter(System.out);
		if (__STACKSIZE_CHANGE_FLAG__ == __t__)
			new Thread(null, new Runnable() {
				@Override
				public void run() {
					solve();
				}
			}, "main", 1 << 30).start();
		else
			solve();
	}

	public static void main(String[] args) {
		new Main().run();
	}

	public void mapDebug(long[][] a) {
		System.out.println("--------map display---------");

		for (int i = 0; i < a.length; i++) {
			for (int j = 0; j < a[i].length; j++) {
				System.out.printf("%3d ", a[i][j]);
			}
			System.out.println();
		}

		System.out.println("----------------------------");
		System.out.println();
	}

	public void debug(Object... obj) {
		System.out.println(Arrays.deepToString(obj));
	}

	class FastScanner {
		private InputStream stream;
		private byte[] buf = new byte[1024];
		private int curChar;
		private int numChars;

		public FastScanner(InputStream stream) {
			this.stream = stream;
			// stream = new FileInputStream(new File("dec.in"));

		}

		int read() {
			if (numChars == -1)
				throw new InputMismatchException();
			if (curChar >= numChars) {
				curChar = 0;
				try {
					numChars = stream.read(buf);
				} catch (IOException e) {
					throw new InputMismatchException();
				}
				if (numChars <= 0)
					return -1;
			}
			return buf[curChar++];
		}

		boolean isSpaceChar(int c) {
			return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
		}

		boolean isEndline(int c) {
			return c == '\n' || c == '\r' || c == -1;
		}

		int nextInt() {
			return Integer.parseInt(next());
		}

		int[] nextIntArray(int n) {
			int[] array = new int[n];
			for (int i = 0; i < n; i++)
				array[i] = nextInt();

			return array;
		}

		int[][] nextIntMap(int n, int m) {
			int[][] map = new int[n][m];
			for (int i = 0; i < n; i++) {
				map[i] = in.nextIntArray(m);
			}
			return map;
		}

		long nextLong() {
			return Long.parseLong(next());
		}

		long[] nextLongArray(int n) {
			long[] array = new long[n];
			for (int i = 0; i < n; i++)
				array[i] = nextLong();

			return array;
		}

		long[][] nextLongMap(int n, int m) {
			long[][] map = new long[n][m];
			for (int i = 0; i < n; i++) {
				map[i] = in.nextLongArray(m);
			}
			return map;
		}

		double nextDouble() {
			return Double.parseDouble(next());
		}

		double[] nextDoubleArray(int n) {
			double[] array = new double[n];
			for (int i = 0; i < n; i++)
				array[i] = nextDouble();

			return array;
		}

		double[][] nextDoubleMap(int n, int m) {
			double[][] map = new double[n][m];
			for (int i = 0; i < n; i++) {
				map[i] = in.nextDoubleArray(m);
			}
			return map;
		}

		String next() {
			int c = read();
			while (isSpaceChar(c))
				c = read();
			StringBuilder res = new StringBuilder();
			do {
				res.appendCodePoint(c);
				c = read();
			} while (!isSpaceChar(c));
			return res.toString();
		}

		String[] nextStringArray(int n) {
			String[] array = new String[n];
			for (int i = 0; i < n; i++)
				array[i] = next();

			return array;
		}

		String nextLine() {
			int c = read();
			while (isEndline(c))
				c = read();
			StringBuilder res = new StringBuilder();
			do {
				res.appendCodePoint(c);
				c = read();
			} while (!isEndline(c));
			return res.toString();
		}
	}
} Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.