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

public final class DiamondInheritance {

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
			// FileInputStream("c:\\var\\tmp\\in.txt")
			// : System.in);

			// in = new BufferedReader(new InputStreamReader(
			// file ? new FileInputStream("c:\\var\\tmp\\in.txt")
			// : System.in));

			in = new StreamTokenizer(new BufferedReader(new InputStreamReader(
					file ? new FileInputStream("c:\\var\\tmp\\in.txt")
							: System.in)));
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

	private static class Diamond extends Exception {
	}

	private static void solve(final int testId) throws IOException {
		final int n = nextInt();
		final int[][] parents = new int[n][];

		for (int i = 0; i < n; ++i) {
			final int m = nextInt();

			parents[i] = new int[m];
			for (int j = 0; j < m; ++j) {
				parents[i][j] = nextInt() - 1;
			}
		}

		final int[][] ancestors = new int[n][];

		try {
			for (int i = 0; i < n; ++i) {
				new Object() {
					public int[] dfs(final int node) throws Diamond {
						if (ancestors[node] == null) {
							final boolean[] isAncestor = new boolean[n];
							int nAncestors = 1;
							Arrays.fill(isAncestor, false);
							isAncestor[node] = true;
							for (final int parent : parents[node]) {
								for (final int ancestor : dfs(parent)) {
									if (isAncestor[ancestor]) {
										throw new Diamond();
									} else {
										isAncestor[ancestor] = true;
										++nAncestors;
									}
								}
							}
							ancestors[node] = new int[nAncestors];
							int k = 0;
							for (int j = 0; j < n; ++j) {
								if (isAncestor[j]) {
									ancestors[node][k] = j;
									++k;
								}
							}
						}
						return ancestors[node];
					}
				}.dfs(i);
			}
			out.printf("Case #%d: No\n", testId);
		} catch (final Diamond d) {
			out.printf("Case #%d: Yes\n", testId);
		}
	}
}
