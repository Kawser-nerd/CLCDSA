import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintStream;
import java.io.PrintWriter;
import java.util.Locale;
import java.util.Scanner;

public final class OutOfGas {

	static {
		final Locale us = Locale.US;
		if (!Locale.getDefault().equals(us)) {
			Locale.setDefault(us);
		}
	}

	static boolean file = true;
	static boolean isLocal = true;

	private static int nextInt() throws IOException {
		return in.nextInt();
	}

	private static long nextLong() throws IOException {
		return in.nextLong();
	}

	private static double nextDouble() throws IOException {
		return in.nextDouble();
	}

	static Scanner in;
	static {
		try {
			in = new Scanner(file ? new FileInputStream("c:\\var\\tmp\\in.txt")
					: System.in);

			// in = new BufferedReader(new InputStreamReader(
			// file ? new FileInputStream("c:\\var\\tmp\\in.txt")
			// : System.in));

			// in = new StreamTokenizer(new BufferedReader(new
			// InputStreamReader(
			// file ? new FileInputStream("c:\\var\\tmp\\in.txt")
			// : System.in)));
		} catch (final FileNotFoundException e) {
			e.printStackTrace();
		}
	}

	static PrintWriter out;
	static {
		try {
			out = file ? new PrintWriter(
					new FileWriter("c:\\var\\tmp\\out.txt")) : new PrintWriter(
					System.out);
		} catch (final IOException e) {
			e.printStackTrace();
		}
	}

	static PrintStream err;
	static {
		err = System.err;
	}

	/**
	 * @param args
	 * @throws IOException
	 */
	public static void main(final String[] args) throws IOException {

		final long startTime = System.nanoTime();
		final int t = nextInt();

		for (int i = 0; i < t; ++i) {
			solve(i + 1);
			if (isLocal && file) {
				err.println(i + 1 + "/" + t);
			}
			if (isLocal && !file) {
				out.flush();
			}
		}

		if (isLocal) {
			err.println(String.format("Completed after %d ms.",
					(System.nanoTime() - startTime) / 1000000));
		}

		out.flush();
		if (file) {
			out.close();
		}

	}

	private static void Assert(final boolean x) {
		if (!x) {
			System.err.println("Assertion failed");
		}
	}

	private static void solve(final int testId) throws IOException {
		final double d = nextDouble();
		final int n = nextInt();
		final int A = nextInt();

		final double[] t = new double[n];
		final double[] x = new double[n];

		for (int i = 0; i < n; ++i) {
			t[i] = nextDouble();
			x[i] = nextDouble();
		}

		out.printf("Case #%d:\n", testId);
		for (int ai = 0; ai < A; ++ai) {
			final double a = nextDouble();

			final double ans = new Object() {

				public double solve() {
					final double t_free = Math.sqrt(2 * d / a);
					if (n == 1 || x[0] >= d) {
						return t_free;
					} else if (n == 2) {
						final double t_enemy = t[0] + (t[1] - t[0])
								* (d - x[0]) / (x[1] - x[0]);
						return Math.max(t_free, t_enemy);
					} else {
						throw new RuntimeException();
					}
				}

			}.solve();

			out.printf("%.9f\n", ans);
		}
	}
}
