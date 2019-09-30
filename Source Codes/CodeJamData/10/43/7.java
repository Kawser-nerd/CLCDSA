import java.io.*;
import java.math.BigInteger;
import java.util.Arrays;
import java.util.HashSet;
import java.util.InputMismatchException;
import java.util.Set;

/**
 * @author Egor Kulikov (egor@egork.net)
 *         Created on 14.03.2010
 */
public class TaskC implements Runnable {
	private InputReader in;
	private PrintWriter out;
	private int[] m;
	private int[][] c;
	private long[][][] res;

	public static void main(String[] args) {
		new Thread(new TaskC()).start();
//		new Template().run();
	}

	public TaskC() {
		String id = getClass().getName().toLowerCase();
		try {
			System.setIn(new FileInputStream(id + ".in"));
			System.setOut(new PrintStream(new FileOutputStream(id + ".out")));
//			System.setIn(new FileInputStream("input.txt"));
//			System.setOut(new PrintStream(new FileOutputStream("output.txt")));
		} catch (FileNotFoundException e) {
			throw new RuntimeException();
		}
		in = new InputReader(System.in);
		out = new PrintWriter(System.out);
	}

	public void run() {
        int numTests = in.readInt();
        for (int testNumber = 0; testNumber < numTests; testNumber++) {
			System.err.println(testNumber);
			int r = in.readInt();
			int[] x1 = new int[r];
			int[] y1 = new int[r];
			int[] x2 = new int[r];
			int[] y2 = new int[r];
			for (int i = 0; i < r; i++) {
				x1[i] = in.readInt() - 1;
				y1[i] = in.readInt() - 1;
				x2[i] = in.readInt() - 1;
				y2[i] = in.readInt() - 1;
			}
			/*
			int ans = 0;
			Set<Integer> xs = new HashSet<Integer>();
			Set<Integer> ys = new HashSet<Integer>();
			for (int i = 0; i < r; i++) {
				xs.add(x1[i]);
				xs.add(x2[i]);
				ys.add(y1[i]);
				ys.add(y2[i]);
			}
			int[] x = new int[xs.size()];
			int[] y = new int[ys.size()];
			int c = 0;
			for (int xx : xs)
				x[c++] = xx;
			c = 0;
			for (int yy : ys)
				y[c++] = yy;
			Arrays.sort(x);
			Arrays.sort(y);
			int n = x.length - 1;
			int m = y.length - 1;
			boolean[][] w = new boolean[n][m];
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++) {
					if (i > 0 && j > 0 && w[i - 1][j] && w[i][j - 1])
						w[i][j] = true;
					else {
						for (int k = 0; k < r; k++) {
							if (x[i] >= x1[k] && x[i + 1] <= x2[k] && y[j] >= y1[k] && y[j + 1] <= y2[k]) {
								w[i][j] = true;
								break;
							}
						}
					}
				}
			}
			int[][] res = new int[n + 1][m + 1];
			for (int i = n; i >= 0; i--) {
				for (int j = m; j >= 0; j--) {
					if (i != n && j != m && (i == 0 || !w[i - 1][j]) && (j == 0 || !w[i][j - 1]))
						continue;
					if (j != m && (i != 0 && w[i - 1][j] || i != n && w[i][j]))
						res[i][j] = Math.max(res[i][j], res[i][j + 1] + y[j + 1] - y[j]);
					if (i != n && (j != 0 && w[i][j - 1] || j != m && w[i][j]))
						res[i][j] = Math.max(res[i][j], res[i + 1][j] + x[i + 1] - x[i]);
				}
			}
			for (int[] rr : res) {
				for (int rrr : rr)
					ans = Math.max(ans, rrr);
			}*/
			int ans;
			boolean[][] w = new boolean[100][100];
			for (int i = 0; i < r; i++) {
				for (int j = x1[i]; j <= x2[i]; j++) {
					for (int k = y1[i]; k <= y2[i]; k++)
						w[j][k] = true;
				}
			}
			for (ans = 1; ; ans++) {
				boolean[][] nw = new boolean[100][100];
				boolean finished = true;
				for (int i = 0; i < 100; i++) {
					for (int j = 0; j < 100; j++) {
						if (w[i][j]) {
							if (i != 0 && w[i - 1][j] || j != 0 && w[i][j - 1]) {
								nw[i][j] = true;
								finished = false;
							}
						} else {
							if (i != 0 && w[i - 1][j] && j != 0 && w[i][j - 1]) {
								nw[i][j] = true;
								finished = false;
							}
						}
					}
				}
				if (finished)
					break;
				w = nw;
			}
			out.println("Case #" + (testNumber + 1) + ": " + ans);
        }
		out.close();
	}

	private static class InputReader {
		private InputStream stream;
		private byte[] buf = new byte[1000];
		private int curChar, numChars;

		public InputReader(InputStream stream) {
			this.stream = stream;
		}

		private int read() {
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

		public int readInt() {
			int c = read();
			while (isSpaceChar(c))
				c = read();
			int sgn = 1;
			if (c == '-') {
				sgn = -1;
				c = read();
			}
			int res = 0;
			do {
				if (c < '0' || c > '9')
					throw new InputMismatchException();
				res *= 10;
				res += c - '0';
				c = read();
			} while (!isSpaceChar(c));
			return res * sgn;
		}

		public long readLong() {
			int c = read();
			while (isSpaceChar(c))
				c = read();
			int sgn = 1;
			if (c == '-') {
				sgn = -1;
				c = read();
			}
			long res = 0;
			do {
				if (c < '0' || c > '9')
					throw new InputMismatchException();
				res *= 10;
				res += c - '0';
				c = read();
			} while (!isSpaceChar(c));
			return res * sgn;
		}

		public String readString() {
			int c = read();
			while (isSpaceChar(c))
				c = read();
			StringBuffer res = new StringBuffer();
			do {
				res.appendCodePoint(c);
				c = read();
			} while (!isSpaceChar(c));
			return res.toString();
		}

		private boolean isSpaceChar(int c) {
			return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
		}

		private String readLine0() {
			StringBuffer buf = new StringBuffer();
			int c = read();
			while (c != '\n' && c != -1) {
				buf.appendCodePoint(c);
				c = read();
			}
			return buf.toString();
		}

		public String readLine() {
			String s = readLine0();
			while (s.trim().length() == 0)
				s = readLine0();
			return s;
		}

		public String readLine(boolean ignoreEmptyLines) {
			if (ignoreEmptyLines)
				return readLine();
			else
				return readLine0();
		}

		public BigInteger readBigInteger() {
			try {
				return new BigInteger(readString());
			} catch (NumberFormatException e) {
				throw new InputMismatchException();
			}
		}

		public char readCharacter() {
			int c = read();
			while (isSpaceChar(c))
				c = read();
			return (char) c;
		}

		public double readDouble() {
			int c = read();
			while (isSpaceChar(c))
				c = read();
			int sgn = 1;
			if (c == '-') {
				sgn = -1;
				c = read();
			}
			double res = 0;
			while (!isSpaceChar(c) && c != '.') {
				if (c < '0' || c > '9')
					throw new InputMismatchException();
				res *= 10;
				res += c - '0';
				c = read();
			}
			if (c == '.') {
				c = read();
				double m = 1;
				while (!isSpaceChar(c)) {
					if (c < '0' || c > '9')
						throw new InputMismatchException();
					m /= 10;
					res += (c - '0') * m;
					c = read();
				}
			}
			return res * sgn;
		}
	}
}
