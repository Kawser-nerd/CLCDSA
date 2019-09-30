import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintStream;
import java.io.PrintWriter;
import java.util.HashMap;
import java.util.Locale;
import java.util.Map;
import java.util.Scanner;

public final class BoxFactory {

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
		out.printf("Case #%d: %d\n", testId, solve());
	}

	private static long solve() throws IOException {
		final int n = nextInt();
		final int m = nextInt();

		final long[] bcounts = new long[n];
		final int[] btypes = new int[n];

		for (int i = 0; i < n; ++i) {
			bcounts[i] = nextLong();
			btypes[i] = nextInt();
		}

		final long[] tcounts = new long[m];
		final int[] ttypes = new int[m];

		for (int i = 0; i < m; ++i) {
			tcounts[i] = nextLong();
			ttypes[i] = nextInt();
		}

		final long[] bparts = new long[n + 1];
		final long[] tparts = new long[m + 1];
		bparts[0] = 0;
		for (int i = 0; i < n; ++i) {
			bparts[i + 1] = bparts[i] + bcounts[i];
		}

		tparts[0] = 0;
		for (int i = 0; i < m; ++i) {
			tparts[i + 1] = tparts[i] + tcounts[i];
		}

		final Map<Long, Map<Long, Long>> cache = new HashMap<Long, Map<Long, Long>>();

		return new Object() {

			public long solve(final int skipBoxSeries,
					final long skipBoxesThere, final int skipToysSeries,
					final long skipToysThere) {

				if (skipBoxSeries == n || skipToysSeries == m) {
					return 0;
				}

				final long totalSkipBoxes = bparts[skipBoxSeries]
						+ skipBoxesThere;
				final long totalSkipToys = tparts[skipToysSeries]
						+ skipToysThere;

				if (!cache.containsKey(totalSkipBoxes)) {
					cache.put(totalSkipBoxes, new HashMap<Long, Long>());
				}

				if (!cache.get(totalSkipBoxes).containsKey(totalSkipToys)) {
					if (skipBoxesThere == bcounts[skipBoxSeries]) {
						return solve(skipBoxSeries + 1, 0, skipToysSeries,
								skipToysThere);
					}
					if (skipToysThere == tcounts[skipToysSeries]) {
						return solve(skipBoxSeries, skipBoxesThere,
								skipToysSeries + 1, 0);
					}

					final int t1 = btypes[skipBoxSeries], t2 = ttypes[skipToysSeries];

					if (t1 == t2) {
						final long bleft = bcounts[skipBoxSeries]
								- skipBoxesThere;
						final long tleft = tcounts[skipToysSeries]
								- skipToysThere;
						final long match = Math.min(bleft, tleft);
						final long ans = match
								+ solve(skipBoxSeries, skipBoxesThere + match,
										skipToysSeries, skipToysThere + match);
						cache.get(totalSkipBoxes).put(totalSkipToys, ans);
					} else {
						final long ans = Math.max(
								solve(skipBoxSeries + 1, 0, skipToysSeries,
										skipToysThere),
								solve(skipBoxSeries, skipBoxesThere,
										skipToysSeries + 1, 0));
						cache.get(totalSkipBoxes).put(totalSkipToys, ans);
					}
				}

				/*
				 * System.err.printf("Ans for (skip1, skip2) = (%d, %d) is %d\n",
				 * totalSkipBoxes, totalSkipToys, cache
				 * .get(totalSkipBoxes).get(totalSkipToys)); System.err.flush();
				 */
				return cache.get(totalSkipBoxes).get(totalSkipToys);
			}
		}.solve(0, 0, 0, 0);
	}
}
