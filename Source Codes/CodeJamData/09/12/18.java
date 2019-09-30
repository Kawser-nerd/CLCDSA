import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Locale;
import java.util.StringTokenizer;

@SuppressWarnings("unchecked")
public class Main implements Runnable {
	private static final String TASKNAME = "b";

	private void solve() throws Exception {
		final int testN = nextInt();
		for (int test = 1; test <= testN; ++test) {
			printf("Case #%d: ", test);
			final int m = nextInt();
			final int n = nextInt();
			final int[][] south = new int[m][n];
			final int[][] west = new int[m][n];
			final int[][] start = new int[m][n];

			for (int i = m - 1; i >= 0; --i) {
				for (int j = 0; j < n; ++j) {
					south[i][j] = nextInt();
					west[i][j] = nextInt();
					start[i][j] = nextInt();
				}
			}

			long[][] distance = new long[m * 2][n * 2];
			boolean[][] col = new boolean[m * 2][n * 2];
			for (long[] l : distance) {
				Arrays.fill(l, Long.MAX_VALUE / 2);
			}
			distance[0][0] = 0;
			int[][] id = new int[m * 2][n * 2];
			int cnt = 2;
			for (int i = 1; i < m * 2 - 1; i += 2) {
				id[i][0] = cnt;
				id[i + 1][0] = cnt;
				++cnt;
				id[i][n * 2 - 1] = cnt;
				id[i + 1][n * 2 - 1] = cnt;
				++cnt;
			}
			for (int i = 1; i < n * 2 - 1; i += 2) {
				id[0][i] = cnt;
				id[0][i + 1] = cnt;
				++cnt;
				id[m * 2 - 1][i] = cnt;
				id[m * 2 - 1][i + 1] = cnt;
				++cnt;
			}
			id[0][n * 2 - 1] = ++cnt;
			id[m * 2 - 1][0] = ++cnt;
			id[m * 2 - 1][n * 2 - 1] = ++cnt;
			id[0][0] = ++cnt;

			for (int i = 1; i < m * 2 - 1; i += 2) {
				for (int j = 1; j < n * 2 - 1; j += 2) {
					id[i][j] = cnt;
					id[i + 1][j] = cnt;
					id[i][j + 1] = cnt;
					id[i + 1][j + 1] = cnt;
					++cnt;
				}
			}

			final int[][] moves = new int[][] { { 0, 1 }, { 0, -1 }, { 1, 0 },
					{ -1, 0 } };
			for (int iteration = 0; iteration < m * n * 4; ++iteration) {
				int r = -1;
				int c = -1;
				long min = Long.MAX_VALUE / 2;
				for (int i = 0; i < distance.length; ++i) {
					for (int j = 0; j < distance[i].length; ++j) {
						if (!col[i][j] && distance[i][j] < min) {
							r = i;
							c = j;
							min = distance[i][j];
						}
					}
				}
				col[r][c] = true;

				final long time = distance[r][c];
				for (int[] d : moves) {
					int y = r + d[0];
					int x = c + d[1];
					if (y < 0 || x < 0 || y >= distance.length
							|| x >= distance[0].length) {
						continue;
					}
					long length;
					if (id[r][c] == id[y][x]) {
						length = 2;
					} else {
						long s = south[r / 2][c / 2];
						long w = west[r / 2][c / 2];
						long st = start[r / 2][c / 2];
						long rem = time % (s + w);
						st %= (s + w);
						rem -= st;
						rem = (rem % (s + w) + s + w) % (s + w);
						if (rem < 0 || rem >= s + w) {
							throw new IllegalStateException();
						}
						boolean toS = d[0] != 0;
						length = 1;
						if (toS) {
							if (rem >= s) {
								length += s + w - rem;
							}
						} else {
							if (rem < s) {
								length += s - rem;
							}
						}
					}
					distance[y][x] = Math.min(distance[y][x], distance[r][c]
							+ length);
				}
			}
			// for (long[]l : distance) {
			// for (long ll : l) {
			// System.err.print(ll + " ");
			// }
			// System.err.println();
			// }
			println(distance[distance.length - 1][distance[0].length - 1]);
			System.err.println(test + " ok");
		}
	}

	public void run() {
		try {
			reader = new BufferedReader(new FileReader(TASKNAME + ".in"));
			writer = new PrintWriter(new BufferedWriter(new FileWriter(
					new File(TASKNAME + ".out"))));

			solve();

			reader.close();
			writer.close();
		} catch (Throwable e) {
			e.printStackTrace();
			System.exit(13);
		}
	}

	private void print(Object o) {
		writer.print(o);
	}

	private void println(Object o) {
		writer.println(o);
	}

	private void printf(String format, Object... o) {
		writer.printf(format, o);
	}

	private double nextDouble() throws IOException {
		return Double.parseDouble(nextToken());
	}

	private int nextInt() throws IOException {
		return Integer.parseInt(nextToken());
	}

	private String nextToken() throws IOException {
		while (tokenizer == null || !tokenizer.hasMoreTokens()) {
			tokenizer = new StringTokenizer(reader.readLine());
		}
		return tokenizer.nextToken();
	}

	public static void main(String[] args) throws InterruptedException {
		final long startTime = System.currentTimeMillis();
		Locale.setDefault(Locale.US);
		final Thread thread = new Thread(new Main());
		thread.start();
		thread.join();
		System.err.printf("%.3f\n",
				(System.currentTimeMillis() - startTime) * 0.001);
	}

	private BufferedReader reader;
	private PrintWriter writer;
	private StringTokenizer tokenizer;
}
