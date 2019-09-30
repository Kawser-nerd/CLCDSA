import java.io.*;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.List;

/**
 * @author Egor Kulikov (egor@egork.net)
 *         Created on 14.03.2010
 */
public class TaskD implements Runnable {
	private InputReader in;
	private PrintWriter out;
	private static final int MOD = 1000000007;
	private long[][] d;
	private long[][] d2;
	private int[] n;
	private int b;
	private long[][][][] r;
	private long[][] c;
	private long[] f;

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
        int numTests = in.readInt();
        for (int testNumber = 0; testNumber < numTests; testNumber++) {
			System.err.println(testNumber);
			out.print("Case #" + (testNumber + 1) + ": ");
			long nn = in.readLong();
			b = in.readInt();
			c = new long[b + 1][b + 1];
			for (int i = 0; i <= b; i++) {
				c[i][0] = 1;
				for (int j = 1; j <= i; j++)
					c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % MOD;
			}
			f = new long[b + 1];
			f[0] = 1;
			for (int i = 1; i <= b; i++)
				f[i] = (f[i - 1] * i) % MOD;
			List<Integer> nnn = new ArrayList<Integer>();
			while (nn != 0) {
				nnn.add((int) (nn % b));
				nn /= b;
			}
			n = new int[nnn.size()];
			for (int i = 0; i < nnn.size(); i++)
				n[i] = nnn.get(i);
			d = new long[b + 1][b * (b - 1) / 2 + 1];
			d[0][0] = 1;
			for (int i = 1; i < b; i++) {
				for (int j = b - 1; j >= 0; j--) {
					for (int k = 0; k < d[j].length; k++) {
						if (d[j][k] != 0)
							d[j + 1][k + i] = (d[j + 1][k + i] + d[j][k]) % MOD;
					}
				}
			}
//			d2 = new long[b + 1][b * (b - 1) / 2 + 1];
//			d2[0][0] = 1;
//			for (int i = 0; i < b; i++) {
//				for (int j = b - 1; j >= 0; j--) {
//					for (int k = 0; k < d2[j].length; k++) {
//						if (d2[j][k] != 0)
//							d2[j + 1][k + i] = (d2[j + 1][k + i] + d2[j][k]) % MOD;
//					}
//				}
//			}
			r = new long[n.length + 1][b][b + 1][2];
			for (long[][][] rr : r) {
				for (long[][] rrr : rr) {
					for (long[] rrrr : rrr)
						Arrays.fill(rrrr, -1);
				}
			}
			long ans = go(0, 0, b, 0);
			out.println(ans);
        }
		out.close();
	}

	private long go(int pos, int q, int p, int z) {
		if (r[pos][q][p][z] != -1)
			return r[pos][q][p][z];
		if (pos == n.length) {
			if (q == 0 && z == 0)
				return r[pos][q][p][z] = 1;
			return r[pos][q][p][z] = 0;
		}
		r[pos][q][p][z] = 0;
		int val = n[pos] - q;
		if (val < 0)
			val += b;
		for (int np = z; np <= p; np++) {
			for (int sum = val; sum < d[np].length; sum += b) {
				long cur = go(pos + 1, (sum + q) / b, np, 0);
				if (pos != 0) {
					cur = (cur * c[p - z][np - z]) % MOD;
					cur = (cur * f[np]) % MOD;
				}
				cur = (cur * d[np][sum]) % MOD;
				r[pos][q][p][z] += cur;
				if (np != 0) {
					long cur2 = go(pos + 1, (sum + q) / b, np, 1);
					if (pos != 0) {
						cur2 = (cur2 * c[p - z][np - z]) % MOD;
						cur2 = (cur2 * f[np]) % MOD;
					}
					cur2 = (cur2 * d[np - 1][sum]) % MOD;
					r[pos][q][p][z] += cur2;
				}
			}
		}
		return r[pos][q][p][z] %= MOD;
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
