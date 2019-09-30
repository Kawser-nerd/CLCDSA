import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.HashSet;
import java.util.InputMismatchException;
import java.util.List;
import java.util.Set;
import java.util.Stack;

public class Main {
	InputStream is;

	int __t__ = 1;
	int __f__ = 0;
	int __FILE_DEBUG_FLAG__ = __f__;
	String __DEBUG_FILE_NAME__ = "src/E2";

	FastScanner in;
	PrintWriter out;
	
	int C, R;
	class Point implements Comparable<Point> {
		int x;
		int y;
		int id;

		Point(int x, int y, int id) {
			this.x = x;
			this.y = y;
			this.id = id;
		}

		int type() {
			if (x == 0) return 0;
			if (y == C) return 1;
			if (x == R) return 2;
			if (y == 0) return 3;
			throw new RuntimeException();
		}
		
		public int compareTo(Point s) {
			int t1 = type(), t2 = s.type();
			if (t1 != t2) {
				return t1 - t2;
			} else {
				if (t1 == 0) {
					return y - s.y;
				} else if (t1 == 1) {
					return x - s.x;
				} else if (t1 == 2) {
					return s.y - y;
				} else {
					return s.x - x;
				}
			}
		}

		public String toString() {
			return "(" + x + ", " + y + ", " + id + ")";
		}
	}
	
	public void solve() {
		R = in.nextInt();
		C = in.nextInt();
		int N = in.nextInt();
		List<Point> ps = new ArrayList<>();
		for (int i = 0; i < N; i++) {
			int x1 = in.nextInt(), y1 = in.nextInt();
			int x2 = in.nextInt(), y2 = in.nextInt();
			if (x1 != 0 && x1 != R && y1 != 0 && y1 != C) continue;
			if (x2 != 0 && x2 != R && y2 != 0 && y2 != C) continue;
			ps.add(new Point(x1, y1, i));
			ps.add(new Point(x2, y2, i));
		}
		Collections.sort(ps);
		
		Set<Integer> hash = new HashSet<>();
		Stack<Integer> stack = new Stack<>();
		boolean res = true;
		for (Point p : ps) {
			if (hash.contains(p.id)) {
				if (stack.pop() != p.id) {
					res = false;
					break;
				}
			} else {
				stack.push(p.id);
				hash.add(p.id);
			}
		}
		System.out.println(res ? "YES" : "NO");
	}
	
	public void run() {
		if (__FILE_DEBUG_FLAG__ == __t__) {
			try {
				is = new FileInputStream(__DEBUG_FILE_NAME__);
			} catch (FileNotFoundException e) {
				// TODO ??????? catch ????
				e.printStackTrace();
			}
			System.out.println("FILE_INPUT!");
		} else {
			is = System.in;
		}
		in = new FastScanner(is);
		out = new PrintWriter(System.out);

		solve();
	}

	public static void main(String[] args) {
		new Main().run();
	}

	public void mapDebug(int[][] a) {
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
			//stream = new FileInputStream(new File("dec.in"));

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
}