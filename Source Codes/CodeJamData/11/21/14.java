import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintStream;
import java.io.PrintWriter;
import java.util.Locale;

public final class A {

	static {
		final Locale us = Locale.US;
		if (!Locale.getDefault().equals(us)) {
			Locale.setDefault(us);
		}
	}

	static boolean file = true;
	static boolean isLocal = true;

	private static int nextInt() throws IOException {
		return Integer.parseInt(nextWord());
	}

	private static String nextWord() throws IOException {
		return in.readLine();
	}

	static BufferedReader in;
	static {
		try {
			// in = new Scanner(file ? new
			// FileInputStream("f:\\var\\tmp\\in.txt")
			// : System.in);

			in = new BufferedReader(
					new InputStreamReader(file ? new FileInputStream(
							"F:/var/tmp/in.txt") : System.in));

			// in = new StreamTokenizer(new BufferedReader(new
			// InputStreamReader(
			// file ? new FileInputStream("f:\\var\\tmp\\in.txt")
			// : System.in)));
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

		final int n = Integer.parseInt(nextWord());

		final String[] rows = new String[n];
		for (int i = 0; i < n; ++i) {
			rows[i] = nextWord();
		}

		final int[] wins = new int[n];
		final int[] loses = new int[n];
		final double[] wp = new double[n];

		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				final char c = rows[i].charAt(j);
				if (c == '0') {
					++loses[i];
				} else if (c == '1') {
					++wins[i];
				}
			}
			wp[i] = wins[i] * 1.0 / (wins[i] + loses[i]);
		}

		final double[] owp = new double[n];
		for (int i = 0; i < n; ++i) {
			owp[i] = 0.0;
			for (int j = 0; j < n; ++j) {
				final char c = rows[i].charAt(j);
				if (c == '0') {
					owp[i] += (wins[j] - 1) * 1.0 / (wins[j] + loses[j] - 1);
				} else if (c == '1') {
					owp[i] += wins[j] * 1.0 / (wins[j] + loses[j] - 1);
				}
			}
			owp[i] /= wins[i] + loses[i];
		}

		final double[] oowp = new double[n];
		for (int i = 0; i < n; ++i) {
			oowp[i] = 0;
			for (int j = 0; j < n; ++j) {
				final char c = rows[i].charAt(j);
				if (c == '0' || c == '1') {
					oowp[i] += owp[j];
				}
			}
			oowp[i] /= wins[i] + loses[i];
		}

		final double[] rpi = new double[n];
		for (int i = 0; i < n; ++i) {
			rpi[i] = 0.25 * wp[i] + 0.5 * owp[i] + 0.25 * oowp[i];
		}

		out.printf("Case #%d:\n", testId);

		for (int i = 0; i < n; ++i) {
			out.printf("%.9f\n", rpi[i]);
		}
	}
}
