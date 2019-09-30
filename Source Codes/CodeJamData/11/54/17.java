import java.io.*;
import java.util.*;
import java.math.*;

public class Dsmall implements Runnable {

	void solve() {
		int t = nextInt();
		for (int test = 0; test < t; test++) {
			String s = nextToken();
			out.println("Case #" + (test + 1) + ": " + solve(s));
		}
	}

	static String solve(String s) {
		ArrayList<Integer> q = new ArrayList<Integer>();
		for (int i = 0; i < s.length(); i++) {
			if (s.charAt(i) == '?') {
				q.add(i);
			}
		}
		int n = q.size();
		char[] c = s.toCharArray();
		for (int i = 0; i < 1 << n; i++) {
			for (int j = 0; j < n; j++) {
				c[q.get(j)] = (char) ('0' + ((i >> j) & 1));
			}
			long number = Long.parseLong(new String(c), 2);
			if (isSquare(number)) {
				return new String(c);
			}
		}
		throw new AssertionError();
	}

	static boolean isSquare(long x) {
		long m = (long) Math.sqrt(x);
		while (m * m < x) {
			m++;
		}
		while (m * m > x) {
			m--;
		}
		return m * m == x;
	}

	FastScanner sc;
	PrintWriter out;

	public void run() {
		try {
			sc = new FastScanner("dsmall.in");
			out = new PrintWriter("dsmall.out");
			solve();
			sc.close();
			out.close();
		} catch (Throwable e) {
			e.printStackTrace();
			System.exit(1);
		}
	}

	int nextInt() {
		return sc.nextInt();
	}

	String nextToken() {
		return sc.nextToken();
	}

	long nextLong() {
		return sc.nextLong();
	}

	double nextDouble() {
		return sc.nextDouble();
	}

	BigInteger nextBigInteger() {
		return sc.nextBigInteger();
	}

	class FastScanner extends BufferedReader {
		StringTokenizer st;
		boolean eof;
		String buf;
		String curLine;
		boolean createST;

		public FastScanner(String fileName) throws FileNotFoundException {
			this(fileName, true);
		}

		public FastScanner(String fileName, boolean createST)
				throws FileNotFoundException {
			super(new FileReader(fileName));
			this.createST = createST;
			nextToken();
		}

		public FastScanner(InputStream stream) {
			this(stream, true);
		}

		public FastScanner(InputStream stream, boolean createST) {
			super(new InputStreamReader(stream));
			this.createST = createST;
			nextToken();
		}

		String nextLine() {
			String ret = curLine;
			if (createST) {
				st = null;
			}
			nextToken();
			return ret;
		}

		String nextToken() {
			if (!createST) {
				try {
					curLine = readLine();
				} catch (Exception e) {
					eof = true;
				}
				return null;
			}
			while (st == null || !st.hasMoreTokens()) {
				try {
					curLine = readLine();
					st = new StringTokenizer(curLine);
				} catch (Exception e) {
					eof = true;
					break;
				}
			}
			String ret = buf;
			buf = eof ? "-1" : st.nextToken();
			return ret;
		}

		int nextInt() {
			return Integer.parseInt(nextToken());
		}

		long nextLong() {
			return Long.parseLong(nextToken());
		}

		double nextDouble() {
			return Double.parseDouble(nextToken());
		}

		BigInteger nextBigInteger() {
			return new BigInteger(nextToken());
		}

		public void close() {
			try {
				buf = null;
				st = null;
				curLine = null;
				super.close();
			} catch (Exception e) {

			}
		}

		boolean isEOF() {
			return eof;
		}
	}

	public static void main(String[] args) {
		new Dsmall().run();
	}
}