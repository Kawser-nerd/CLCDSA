import java.io.*;
import java.math.BigInteger;
import java.util.*;

/**
 * @author Egor Kulikov (egor@egork.net)
 *         Created on 14.03.2010
 */
public class TaskD implements Runnable {
	private InputReader in;
	private PrintWriter out;
	private long[] x;
	private int n;
	private long ans;
	private long[][] z;
	private List<Long>[] c1, c2;

	public static void main(String[] args) {
		new Thread(new TaskD()).start();
	}

	public TaskD() {
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
			x = new long[n];
			for (int i = 0; i < n; i++)
				x[i] = in.readLong();
			long f = in.readLong();
			long ff = f;
			Arrays.sort(x);
			f -= 2 * (x[n - 1] - x[0]);
			z = new long[n - 1][n];
			for (int i = 0; i < n - 1; i++) {
				for (int j = 0; j < n; j++)
					z[i][j] = (x[i + 1] - x[i]) * j * 2;
			}
			if (f < 0) {
				out.println("NO SOLUTION");
				continue;
			}
			ans = f;
			c1 = new List[n];
			c2 = new List[n];
			for (int i = 0; i < n; i++) {
				c1[i] = new ArrayList<Long>();
				c2[i] = new ArrayList<Long>();
			}
			go(1, 0, f);
			go2(n - 2, 0, f);
			for (int i = 0; i < n; i++) {
				Collections.sort(c1[i]);
				for (int j = Math.max(i - 1, 0); j <= i + 1 && j < n; j++) {
					Collections.sort(c2[j]);
					int ind = 0;
					for (int k = c1[i].size() - 1; k >= 0; k--) {
						long v = c1[i].get(k);
						while (ind < c2[j].size() && c2[j].get(ind) + v < f)
							ind++;
						if (ind == c2[j].size())
							continue;
						ans = Math.min(ans, c2[j].get(ind) + v - f);
					}
				}
			}
			out.println(ff - ans);
        }
		out.close();
	}

	private void go(int p, int q, long f) {
		if (p + q >= n)
			return;
//		if (p <= 10)
//			System.err.println(p + " " + q);
		if (p == n / 2) {
			c1[q].add(f);
			return;
		}
		if (f >= z[p][q + 1])
			go(p + 1, q + 1, f - z[p][q + 1]);
		if (f >= z[p][q])
			go(p + 1, q, f - z[p][q]);
		if (q > 0 && f >= z[p][q - 1])
			go(p + 1, q - 1, f - z[p][q - 1]);
	}

	private void go2(int p, int q, long f) {
		if (q >= p)
			return;
//		if (p <= 10)
//			System.err.println(p + " " + q);
		if (p == n / 2) {
			c2[q].add(f);
			return;
		}
		if (f >= z[p - 1][q + 1])
			go2(p - 1, q + 1, f - z[p - 1][q + 1]);
		if (f >= z[p - 1][q])
			go2(p - 1, q, f - z[p - 1][q]);
		if (q > 0 && f >= z[p - 1][q - 1])
			go2(p - 1, q - 1, f - z[p - 1][q - 1]);
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
