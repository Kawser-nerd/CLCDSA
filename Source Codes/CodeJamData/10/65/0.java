import java.io.*;
import java.math.BigInteger;
import java.util.Arrays;
import java.util.Comparator;
import java.util.InputMismatchException;

/**
 * @author Egor Kulikov (egor@egork.net)
 *         Created on 14.03.2010
 */
public class TaskE implements Runnable {
	private InputReader in;
	private PrintWriter out;
	private int[][][] rr;
	private int[] x;
	private int[] y;
	private int n;
	private static final double EPS = 1e-8;

	public static void main(String[] args) {
		new Thread(new TaskE()).start();
	}

	public TaskE() {
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
			out.print("Case #" + (testNumber + 1) + ": ");
			n = in.readInt();
			int r = in.readInt();
			x = new int[n];
			y = new int[n];
			for (int i = 0; i < n; i++) {
				x[i] = in.readInt();
				y[i] = in.readInt();
			}
			out.println(go(0, Math.PI, r));
        }
		out.close();
	}

	private int go(final int ind, double ang, double r) {
		final double[] a = new double[n];
		for (int i = 0; i < n; i++) {
			if (i == ind)
				continue;
			a[i] = Math.atan2(y[i] - y[ind], x[i] - x[ind]);
			while (a[i] < ang - EPS)
				a[i] += 2 * Math.PI;
			while (a[i] > ang + 2 * Math.PI - EPS)
				a[i] -= 2 * Math.PI;
		}
		int ans = 0;
		Integer[] o = new Integer[n - 1];
		int cc = 0;
		for (int i = 0; i < n; i++) {
			if (i != ind)
				o[cc++] = i;
		}
		Arrays.sort(o, new Comparator<Integer>() {
			public int compare(Integer o1, Integer o2) {
				if (Math.abs(a[o1] - a[o2]) > EPS)
					return Double.compare(a[o1], a[o2]);
				return Double.compare(Math.hypot(x[o2] - x[ind], y[o2] - y[ind]), Math.hypot(x[o1] - x[ind], y[o1] - y[ind]));
			}
		});
		for (int i = 0; i < n - 1; i++) {
			int j = o[i];
			if (Math.hypot(x[j] - x[ind], y[j] - y[ind]) > r - EPS)
				continue;
			ans = Math.max(ans, 1 + go(j, a[j], r - Math.hypot(x[j] - x[ind], y[j] - y[ind])));
			r = Math.hypot(x[j] - x[ind], y[j] - y[ind]);
		}
		return ans;
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
