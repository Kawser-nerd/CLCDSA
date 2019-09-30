import java.io.*;
import java.util.*;
import java.math.*;

public class A implements Runnable {
	private static BufferedReader in;
	private static PrintWriter out;
	private static StringTokenizer st;
	private static Random rnd;

	private void solve() throws IOException {
		int tests = nextInt();
		for (int test = 1; test <= tests; test++) {
			out.print("Case #" + test + ": ");
			solveOne();
		}
	}

	private void solveOne() throws IOException {
		long value = nextLong();
		out.println(solveSmart(value));
	}

	private long solveSmart(long value) {
		if (value <= 11)
			return value;

		long digitsCount = getDigitsCount(value);
		long powToRound = BigInteger.valueOf(10)
				.pow((int) ((digitsCount + 1) / 2)).longValue();
		long remain = value % powToRound;

		if (remain == 0) {
			return solveSmart(value - 1) + 1;
		} else {
			long newValue = value - remain;
			++newValue;
			long reversed = reverse(newValue);
			if (reversed == value) {
				return solveSmart(value - 1) + 1;
			} else {
				if (reversed > newValue)
					throw new AssertionError();
				long add = (reversed != newValue) ? 1 : 0;
				return (remain - 1) + solveSmart(reversed) + add;
			}
		}
	}

	private long getDigitsCount(long value) {
		long result = 0;
		while (value != 0) {
			++result;
			value /= 10;
		}
		return result;
	}

	private long reverse(long n) {
		long m = 0;
		while (n != 0) {
			long digit = n % 10;
			m = (10 * m + digit);
			n /= 10;
		}
		return m;
	}

	public static void main(String[] args) {
		new A().run();
	}

	public void run() {
		try {
			final String className = this.getClass().getName().toLowerCase();

			try {
				in = new BufferedReader(new FileReader(className + ".in"));
				out = new PrintWriter(new FileWriter(className + ".out"));
				// in = new BufferedReader(new FileReader("input.txt"));
				// out = new PrintWriter(new FileWriter("output.txt"));
			} catch (FileNotFoundException e) {
				in = new BufferedReader(new InputStreamReader(System.in));
				out = new PrintWriter(System.out);
			}

			rnd = new Random();

			solve();

			out.close();
		} catch (IOException e) {
			e.printStackTrace();
			System.exit(42);
		}
	}

	private String nextToken() throws IOException {
		while (st == null || !st.hasMoreTokens()) {
			String line = in.readLine();

			if (line == null)
				return null;

			st = new StringTokenizer(line);
		}

		return st.nextToken();
	}

	private int nextInt() throws IOException {
		return Integer.parseInt(nextToken());
	}

	private long nextLong() throws IOException {
		return Long.parseLong(nextToken());
	}

	private double nextDouble() throws IOException {
		return Double.parseDouble(nextToken());
	}
}