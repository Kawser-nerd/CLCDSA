import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintStream;
import java.io.PrintWriter;
import java.io.StreamTokenizer;
import java.util.Arrays;
import java.util.Locale;

public final class B {

	static {
		final Locale us = Locale.US;
		if (!Locale.getDefault().equals(us)) {
			Locale.setDefault(us);
		}
	}

	static boolean file = true;
	static boolean isLocal = true;

	private static int nextInt() throws IOException {
		in.nextToken();
		return (int) in.nval;
	}

	private static String nextWord() throws IOException {
		in.nextToken();
		return in.sval;
	}

	static StreamTokenizer in;
	static {
		try {
			// in = new Scanner(file ? new
			// FileInputStream("f:\\var\\tmp\\in.txt")
			// : System.in);

			// in = new BufferedReader(new InputStreamReader(
			// file ? new FileInputStream("f:\\var\\tmp\\in.txt")
			// : System.in));

			in = new StreamTokenizer(new BufferedReader(new InputStreamReader(
					file ? new FileInputStream("f:\\var\\tmp\\in.txt")
							: System.in)));
		} catch (final FileNotFoundException e) {
			e.printStackTrace();
		}
	}

	static PrintWriter out;
	static {
		try {
			out = file ? new PrintWriter(
					new FileWriter("f:\\var\\tmp\\out.txt")) : new PrintWriter(
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
		try {
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
		} finally {
			out.flush();
			if (file) {
				out.close();
			}
		}
	}

	private static void solve(final int testId) throws IOException {
		final int c = nextInt();
		final int d = nextInt() * 2;
		final int[] v = new int[200001];
		Arrays.fill(v, 0);

		int n = 0;

		for (int i = 0; i < c; ++i) {
			final int p = nextInt();
			v[p + 100000] += nextInt();
			n += v[p + 100000];
		}

		final long[] x = new long[n];

		for (int i = 0, j = 0; i < v.length; ++i) {
			for (int k = 0; k < v[i]; ++k) {
				x[j++] = 2 * i;
			}
		}

		long lbound = 0, rbound = (long) 1e15;
		while (lbound < rbound) {
			final long middle = (lbound + rbound) / 2;
			if (possible(x, middle, d)) {
				rbound = middle;
			} else {
				lbound = middle + 1;
			}
		}

		out.printf("Case #%d: %.9f\n", testId, 0.5 * lbound);
	}

	private static boolean possible(final long[] x, final long t, final long d) {

		long bound = (long) -1e15;
		for (int i = 0; i < x.length; ++i) {
			if (x[i] + t >= bound) {
				bound = Math.max(bound, x[i] - t) + d;
			} else {
				return false;
			}
		}
		return true;
	}
}
