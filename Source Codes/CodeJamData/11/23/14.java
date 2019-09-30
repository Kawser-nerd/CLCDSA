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

public final class C {

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
		final int n = nextInt();
		final int m = nextInt();

		final int[] u = new int[m];
		for (int i = 0; i < m; ++i) {
			u[i] = nextInt() - 1;
		}

		final int[] v = new int[m];
		for (int i = 0; i < m; ++i) {
			v[i] = nextInt() - 1;
		}

		final boolean[][] rooms = new boolean[m + 1][];
		rooms[0] = new boolean[n];
		Arrays.fill(rooms[0], true);

		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < i + 1; ++j) {
				if (rooms[j][u[i]] && rooms[j][v[i]]) {
					final boolean[][] splitted = splitRoom(rooms[j], u[i],
							v[i], n);
					rooms[j] = splitted[0];
					rooms[i + 1] = splitted[1];
					break;
				}
			}
		}

		int mx = n;
		for (int i = 0; i < m + 1; ++i) {
			int k = 0;
			for (int j = 0; j < n; ++j) {
				if (rooms[i][j]) {
					++k;
				}
			}
			mx = Math.min(mx, k);
		}

		int goodC = 1;
		int[] ans = new int[n];
		Arrays.fill(ans, 0);

		for (int i = 2; i <= mx; ++i) {
			final int[] candidate = tryColor(rooms, i);
			if (candidate != null) {
				goodC = i;
				ans = candidate;
			}
		}

		out.printf("Case #%d: %d\n", testId, goodC);
		for (int i = 0; i < n; ++i) {
			out.printf(i == 0 ? "%d" : " %d", ans[i] + 1);
		}
		out.println();
	}

	private static int[] tryColor(final boolean[][] rooms, final int c) {
		final int n = rooms[0].length, m = rooms.length;
		final boolean[] satisfied = new boolean[c];
		final int[] colors = new int[n];
		Arrays.fill(colors, 0);

		while (true) {

			if (isValid(rooms, n, m, satisfied, colors, c)) {
				return colors;
			}

			int k = 0;
			while (colors[k] == c - 1) {
				colors[k] = 0;
				++k;
				if (k == n) {
					return null;
				}
			}
			++colors[k];
		}
	}

	private static boolean isValid(final boolean[][] rooms, final int n,
			final int m, final boolean[] satisfied, final int[] colors,
			final int c) {

		for (int i = 0; i < m; ++i) {
			final boolean[] room = rooms[i];
			Arrays.fill(satisfied, false);
			int k = 0;
			for (int j = 0; j < n; ++j) {
				final int color = colors[j];
				if (room[j] && !satisfied[color]) {
					satisfied[color] = true;
					++k;
					if (k == c) {
						break;
					}
				}
			}
			if (k < c) {
				return false;
			}
		}
		return true;
	}

	private static boolean[][] splitRoom(final boolean[] room, final int x,
			final int y, final int n) {

		final boolean[][] ans = new boolean[2][n];
		Arrays.fill(ans[0], false);
		Arrays.fill(ans[1], false);

		discover(room, x, y, ans[0], n);
		discover(room, y, x, ans[1], n);

		return ans;
	}

	private static void discover(final boolean[] room, final int x,
			final int y, final boolean[] ans, final int n) {

		for (int i = x;; i = (i + 1) % n) {

			ans[i] |= room[i];

			if (i == y) {
				break;
			}
		}

	}
}
