import java.io.*;
import java.math.BigInteger;
import java.util.InputMismatchException;

/**
 * @author Egor Kulikov (egor@egork.net)
 *         Created on 14.03.2010
 */
public class TaskA implements Runnable {
	private InputReader in;
	private PrintWriter out;

	public static void main(String[] args) {
		new Thread(new TaskA()).start();
//		new Template().run();
	}

	public TaskA() {
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
			int n = in.readInt();
			int k = in.readInt();
			char[][] t = new char[n][n];
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++)
					t[i][j] = in.readCharacter();
			}
			for (int i = 0; i < n; i++) {
				int cur = n - 1;
				for (int j = n - 1; j >= 0; j--) {
					if (t[i][j] != '.') {
						char c = t[i][j];
						t[i][j] = '.';
						t[i][cur--] = c;
					}
				}
			}
			boolean winB = false;
			boolean winR = false;
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					boolean good1 = true;
					boolean good2 = true;
					boolean good3 = true;
					boolean good4 = true;
					for (int l = 0; l < k; l++) {
						if (i + l >= n || t[i + l][j] != t[i][j])
							good1 = false;
						if (j + l >= n || t[i][j + l] != t[i][j])
							good2 = false;
						if (i + l >= n || j + l >= n || t[i + l][j + l] != t[i][j])
							good3 = false;
						if (i + l >= n || j - l < 0 || t[i + l][j - l] != t[i][j])
							good4 = false;
					}
					if (t[i][j] == 'R' && (good1 || good2 || good3 || good4))
						winR = true;
					if (t[i][j] == 'B' && (good1 || good2 || good3 || good4))
						winB = true;
				}
			}
			out.print("Case #" + (testNumber + 1) + ": ");
			if (winB) {
				if (winR)
					out.println("Both");
				else
					out.println("Blue");
			} else {
				if (winR)
					out.println("Red");
				else
					out.println("Neither");				
			}
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