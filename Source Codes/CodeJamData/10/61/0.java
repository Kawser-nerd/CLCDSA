import java.io.*;
import java.math.BigInteger;
import java.util.Arrays;
import java.util.InputMismatchException;

/**
 * @author Egor Kulikov (egor@egork.net)
 *         Created on 14.03.2010
 */
public class TaskA implements Runnable {
	private InputReader in;
	private PrintWriter out;
	private static final int INF = 1000000000;

	public static void main(String[] args) {
		new Thread(new TaskA()).start();
	}

	public TaskA() {
		try {
			System.setIn(new FileInputStream("input.txt"));
			System.setOut(new PrintStream(new FileOutputStream("output.txt")));
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
			out.print("Case #" + (testNumber + 1) + ": ");
			char[] s = in.readString().toCharArray();
			int n = s.length;
			int[][] r = new int[2][n + 1];
			int[][] u = new int[2][n + 1];
			for (int[] rr : r) {
				Arrays.fill(rr, INF);
				rr[1] = 2;
			}
			int s1, s2;
			if (s[0] == 'A') {
				s1 = 'B';
				s2 = 'C';
			} else if (s[0] == 'B') {
				s1 = 'A';
				s2 = 'C';
			} else {
				s1 = 'A';
				s2 = 'B';
			}
			StringBuilder b1 = new StringBuilder();
			StringBuilder b2 = new StringBuilder();
			for (int i = 0; i <= n + 10; i++) {
				if (i % 3 == 0) {
					b1.append(s[0]);
					b2.append(s[0]);
				} else if (i % 3 == 1) {
					b1.append((char) s1);
					b2.append((char) s2);
				} else {
					b1.append((char) s2);
					b2.append((char) s1);
				}
			}
			char[][] t = new char[2][];
			t[0] = b1.toString().toCharArray();
			t[1] = b2.toString().toCharArray();
			for (int i = 0; i < n - 1; i++) {
				for (int[] rr : u)
					Arrays.fill(rr, INF);
				for (int j = 0; j < 2; j++) {
					for (int k = 1; k <= n; k++) {
						if (r[j][k] == INF)
							continue;
						if (s[i + 1] == t[j][k - 1]) {
							u[j][k] = r[j][k] + 1;
							continue;
						}
						if (s[i + 1] == t[j][k + 1]) {
							if (k != 1)
								u[j][k - 1] = Math.min(u[j][k - 1], r[j][k] + 2);
						} else {
							u[j][k + 1] = Math.min(u[j][k + 1], r[j][k] + 2);
							if (k > 2)
								u[j][k - 2] = Math.min(u[j][k - 2], r[j][k] + 3);
						}
					}
				}
				u[1][1] = u[0][1] = Math.min(u[0][1], u[1][1]);
				int[][] tt = r;
				r = u;
				u = tt;
			}
			int ans = INF;
			for (int i = 0; i < 2; i++) {
				for (int j = 1; j <= n; j++)
					ans = Math.min(ans, r[i][j] + j);
			}
			out.println(ans);
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
