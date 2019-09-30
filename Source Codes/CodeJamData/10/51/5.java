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
			System.err.println(testNumber);
			out.print("Case #" + (testNumber + 1) + ": ");
			long ans = -1;
			int d = in.readInt();
			int k = in.readInt();
			int[] a = new int[k];
			for (int i = 0; i < k; i++)
				a[i] = in.readInt();
			if (k <= 2) {
				if (k == 1 || a[0] != a[1])
					out.println("I don't know.");
				else
					out.println(a[0]);
				continue;
			}
			int max = 1;
			for (int i = 0; i < d; i++)
				max *= 10;
			boolean[] isPrime = new boolean[max];
			Arrays.fill(isPrime, true);
			isPrime[0] = isPrime[1] = false;
			for (int i = 2; i * i < max; i++) {
				if (isPrime[i]) {
					for (int j = i * i; j < max; j += i)
						isPrime[j] = false;
				}
			}
			int minp = 0;
			for (int A : a)
				minp = Math.max(minp, A + 1);
			for (int p = minp; p < max; p++) {
				if (isPrime[p]) {
					int d1 = a[0] - a[1];
					int d2 = a[1] - a[2];
					long aa, bb;
					if (d1 == 0) {
						if (d2 == 0) {
							aa = 1;
							bb = 0;
						} else
							continue;
					} else {
						aa = ((new BigInteger(d1 + "").modInverse(new BigInteger(p + "")).longValue() * d2) % p);
						bb = (a[1] - aa * a[0]) % p;
					}
					boolean good = true;
					for (int i = 1; i < k; i++) {
						long next = (aa * a[i - 1] + bb) % p;
						if (next < 0)
							next += p;
						if (next != a[i]) {
							good = false;
							break;
						}
					}
					if (good) {
						long cand = (a[k - 1] * aa + bb) % p;
						if (cand < 0)
							cand += p;
						if (ans == -1)
							ans = cand;
						else if (ans != cand) {
							ans = -1;
							break;
						}
					}
				}
			}
			if (ans == -1)
				out.println("I don't know.");
			else
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
