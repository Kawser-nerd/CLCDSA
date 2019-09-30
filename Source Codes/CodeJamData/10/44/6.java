import java.io.*;
import java.math.BigInteger;
import java.util.InputMismatchException;
import java.util.Locale;

/**
 * @author Egor Kulikov (egor@egork.net)
 *         Created on 14.03.2010
 */
public class TaskD implements Runnable {
	private InputReader in;
	private PrintWriter out;
	private int[] m;
	private int[][] c;
	private long[][][] res;

	public static void main(String[] args) {
		new Thread(new TaskD()).start();
//		new Template().run();
	}

	public TaskD() {
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
		Locale.setDefault(Locale.US);
        int numTests = in.readInt();
        for (int testNumber = 0; testNumber < numTests; testNumber++) {
			out.print("Case #" + (testNumber + 1) + ": ");
			in.readInt();
			int m = in.readInt();
			int cx1 = in.readInt();
			int cy1 = in.readInt();
			int cx2 = in.readInt();
			int cy2 = in.readInt();
			for (int i = 0; i < m; i++) {
				int x = in.readInt();
				int y = in.readInt();
				double s1, s2;
				{
					double alpha1 = Math.atan2(y - cy1, x - cx1) - Math.atan2(cy2 - cy1, cx2 - cx1);
					alpha1 = good(alpha1);
					double r = Math.hypot(x - cx1, y - cy1);
					s1 = (alpha1 - Math.sin(alpha1) * Math.cos(alpha1)) * r * r;
				}
				{
					double alpha1 = Math.atan2(y - cy2, x - cx2) - Math.atan2(cy1 - cy2, cx1 - cx2);
					alpha1 = good(alpha1);
					double r = Math.hypot(x - cx2, y - cy2); 
					s2 = (alpha1 - Math.sin(alpha1) * Math.cos(alpha1)) * r * r;
				}
				out.printf(" %.7f", s1 + s2);
			}
			out.println();
        }
		out.close();
	}

	private double good(double alpha1) {
		while (alpha1 > Math.PI)
			alpha1 -= 2 * Math.PI;
		while (alpha1 < -Math.PI)
			alpha1 += 2 * Math.PI;
		return Math.abs(alpha1);
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
