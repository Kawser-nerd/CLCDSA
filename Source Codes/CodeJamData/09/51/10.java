import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.HashSet;
import java.util.Locale;
import java.util.StringTokenizer;

@SuppressWarnings("unchecked")
public class Main implements Runnable {
	private static final String TASKNAME = "a";

	private char[][] grid;
	private boolean[][] ends;
	private boolean[][] hasBox;
	
	private final int SIZE = (int)1e7;

	private final long[] queue = new long[SIZE];
	private final int[] distance = new int[queue.length];

	private static final int[][] MOVES = new int[][] { { 0, 1 }, { 0, -1 },
			{ 1, 0 }, { -1, 0 } };

	private int countComponent(int y, int x) {
		hasBox[y][x] = false;
		int answer = 1;

		for (int[] d : MOVES) {
			final int newY = y + d[0];
			final int newX = x + d[1];
			if (newY < 0 || newX < 0 || newY >= grid.length
					|| newX >= grid[0].length) {
				continue;
			}
			if (hasBox[newY][newX]) {
				answer += countComponent(newY, newX);
			}
		}

		return answer;
	}

	private void putBoxes(final int[] x, final int[] y, final boolean value) {
		for (int i = 0; i < x.length; ++i) {
			hasBox[y[i]][x[i]] = value;
		}
	}
	
	private void solve() throws Exception {
		final int testN = nextInt();
		for (int test = 1; test <= testN; ++test) {
			final int m = nextInt();
			final int n = nextInt();
			grid = new char[m][n];
			for (int i = 0; i < m; ++i) {
				grid[i] = nextToken().toCharArray();
			}

			ends = new boolean[m][n];
			hasBox = new boolean[m][n];
			for (int i = 0; i < m; ++i) {
				for (int j = 0; j < n; ++j) {
					if (grid[i][j] == 'x' || grid[i][j] == 'w') {
						ends[i][j] = true;
					}
				}
			}

			int boxCounter = 0;
			long state = 0;
			for (int i = 0; i < m; ++i) {
				for (int j = 0; j < n; ++j) {
					if (grid[i][j] == 'o' || grid[i][j] == 'w') {
						state = (state * 12 + i) * 12 + j;
						++boxCounter;
					}
				}
			}

			int ql = 0;
			int qr = 0;
			queue[qr++] = state;
			final int[] x = new int[boxCounter];
			final int[] y = new int[boxCounter];

			final HashSet<Long> added = new HashSet<Long>();
			added.add(state);

			int answer = -1;
			main: while (ql != qr) {
				int dist = distance[ql];
				state = queue[ql++];
				for (int i = boxCounter - 1; i >= 0; --i) {
					x[i] = (int) (state % 12);
					state /= 12;
					y[i] = (int) (state % 12);
					state /= 12;
				}
				
				boolean found = true;
				for (int i = 0; i < x.length; ++i) {
					found &= ends[y[i]][x[i]];
				}
				if (found) {
					answer = dist;
					break main;
				}

				putBoxes(x, y, true);
				boolean needSafe = countComponent(y[0], x[0]) != boxCounter;
				putBoxes(x, y, false);

				for (int i = 0; i < x.length; ++i) {
					for (int[] d : MOVES) {
						final int newY = y[i] + d[0];
						final int newX = x[i] + d[1];
						if (newY < 0 || newX < 0 || newY >= grid.length
								|| newX >= grid[0].length) {
							continue;
						}
						final int prevY = y[i] - d[0];
						final int prevX = x[i] - d[1];
						if (prevY < 0 || prevX < 0 || prevY >= grid.length
								|| prevX >= grid[0].length) {
							continue;
						}
						
						putBoxes(x, y, true);
						if (grid[newY][newX] != '#' && !hasBox[newY][newX]
								&& grid[prevY][prevX] != '#'
								&& !hasBox[prevY][prevX]) {
							if (needSafe) {
								putBoxes(x, y, true);
								hasBox[y[i]][x[i]] = false;
								hasBox[newY][newX] = true;
								
								final int cnt = countComponent(newY, newX);
								boolean ok = cnt == boxCounter;
								hasBox[newY][newX] = false;
								if (!ok) {
									continue;
								}
							}
							
							long key = 0;
							boolean finalPositon = true;
							
							y[i] += d[0];
							x[i] += d[1];
							
							for (int j = 0; j < x.length; ++j) {
								key = (key * 12 + y[j]) * 12 + x[j];
								finalPositon &= ends[y[j]][x[j]];
							}
							
							y[i] -= d[0];
							x[i] -= d[1];
							
							if (finalPositon) {
								answer = dist + 1;
								break main;
							}
							if (added.contains(key)) {
								continue;
							}
							added.add(key);
							distance[qr] = dist + 1;
							queue[qr++] = key;
						}
						putBoxes(x, y, false);
					}
					putBoxes(x, y, false);
				}
				putBoxes(x, y, false);
			}
			added.clear();
			System.gc();
			printf("Case #%d: %d\n", test, answer);
			writer.flush();
		}
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
			e.printStackTrace();
			System.exit(13);
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
}
