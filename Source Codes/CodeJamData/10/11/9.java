package q1a;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Locale;
import java.util.StringTokenizer;

@SuppressWarnings("unchecked")
public class Main implements Runnable {
	private static final String TASKNAME = "a";

	private void solve() throws Exception {
		int testN = nextInt();
		for (int test = 1; test <= testN; ++test) {
			final int n = nextInt();
			final int k = nextInt();
			char[][] grid = new char[n][];
			for (int i = 0; i < n; ++i) {
				grid[i] = nextToken().toCharArray();
			}

			char[][] newGrid = new char[n][n];
			for (int i = 0; i < n; ++i) {
				for (int j = 0; j < n; ++j) {
					newGrid[j][n - 1 - i] = grid[i][j];
				}
			}
			for (int i = 0; i < n; ++i) {
				for (int j = n - 1; j >= 0; --j) {
					if (newGrid[j][i] != '.') {
						int move = j;
						for (int l = j + 1; l < n; ++l) {
							if (newGrid[l][i] == '.') {
								move = l;
							} else {
								break;
							}
						}
						newGrid[move][i] = newGrid[j][i];
						if (j != move) {
							newGrid[j][i] = '.';
						}
					}
				}
			}
//			if (test == 2)
//			for (char[] a : newGrid) {
//				System.err.println(new String(a));
//			}

			boolean a = get(newGrid, 'R', k);
			boolean b = get(newGrid, 'B', k);
			
			printf("Case #%d: ", test);
			if (a && b) {
				println("Both");
			} else if (a && !b) {
				println("Red");
			} else if (!a && b) {
				println("Blue");
			} else {
				println("Neither");
			}
		}
	}

	private boolean get(char[][] grid, char c, int k) {
		int n = grid.length;
		int[] dx = { 0, 1, 1, 1 };
		int[] dy = { 1, 0, -1, 1 };
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				for (int dir = 0; dir < 4; ++dir) {
					boolean ok = true;
					int x = j;
					int y = i;
					for (int l = 0; l < k; ++l) {
						if (x < 0 || y < 0 || x >= n || y >= n) {
							ok = false;
							break;
						}
						if (grid[y][x] != c) {
							ok = false;
							break;
						}
//						System.err.println(l);
						x += dx[dir];
						y += dy[dir];
					}
					if (ok) {
						return true;
					}
				}
			}
		}
		return false;
	}

	private BufferedReader reader;
	private PrintWriter writer;
	private StringTokenizer tokenizer;

	public void run() {
		try {
			reader = new BufferedReader(new FileReader(TASKNAME + ".in"));
			writer = new PrintWriter(new BufferedWriter(new FileWriter(TASKNAME
					+ ".out")));

			solve();

			reader.close();
			writer.close();
		} catch (Throwable e) {
			throw new AssertionError(e);
		}
	}

	private void print(final Object o) {
		writer.print(o);
	}

	private void println(final Object o) {
		writer.println(o);
	}

	private void printf(final String format, final Object... o) {
		writer.printf(format, o);
	}

	private double nextDouble() throws IOException {
		return Double.parseDouble(nextToken());
	}

	private int nextInt() throws IOException {
		return Integer.parseInt(nextToken());
	}

	private long nextLong() throws IOException {
		return Long.parseLong(nextToken());
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
		final Thread thread = new Thread(null, new Main(), "", 1 << 23);
		thread.start();
		thread.join();
		System.err.printf("%.3f\n",
				(System.currentTimeMillis() - startTime) * 0.001);
	}
}
