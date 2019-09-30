
import java.io.*;
import java.util.*;

public class D {
	FastScanner in = new FastScanner(System.in);
	PrintWriter out = new PrintWriter(System.out);

	public void run() {
		int T = in.nextInt();
		for (int caseN = 1; caseN <= T; caseN++) {
			String res = "";
			int N = in.nextInt(), L = in.nextInt();
			String[] G = in.nextStringArray(N);
			String B = in.next();
			if (L == 1) {
				res = "0 ?";
			} else {
				for (String g : G) {
					if (g.matches(B)) {
						res = "IMPOSSIBLE";
					}
				}
				
				if (res.length() == 0) {
					for (int i = 0; i < L - 1; i++) {
						res += "?";
					}
					res += " ";
					for (int i = 0; i < 49; i++) {
						res += "10";
					}
					res += "?";
					while (res.length() + 2 <= 200) {
						res += "10";
					}
				}
			}
			out.println("Case #" + caseN + ": " + res);
		}
		out.close();
	}

	public static void main(String[] args) {
		new D().run();
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
			return nextIntArray(n, 0);
		}

		int[] nextIntArray(int n, int margin) {
			int[] array = new int[n + margin];
			for (int i = 0; i < n; i++)
				array[i + margin] = nextInt();

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
			return nextLongArray(n, 0);
		}

		long[] nextLongArray(int n, int margin) {
			long[] array = new long[n + margin];
			for (int i = 0; i < n; i++)
				array[i + margin] = nextLong();

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
			return nextDoubleArray(n, 0);
		}

		double[] nextDoubleArray(int n, int margin) {
			double[] array = new double[n + margin];
			for (int i = 0; i < n; i++)
				array[i + margin] = nextDouble();

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

