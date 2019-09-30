import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.HashMap;
import java.util.Locale;
import java.util.StringTokenizer;

@SuppressWarnings("unchecked")
public class Main implements Runnable {
	private static final String TASKNAME = "b";
	
	private int[][] id;
	private int[][] height;
	private int current = 1;
	
	private static final int[][] MOVES = new int[][] {{0, -1}, {-1, 0}, {1, 0}, {0, 1}};
	
	private boolean inGrid(int y, int x) {
		if (y < 0 || x < 0 || y >= height.length || x >= height[0].length) {
			return false;
		}
		return true;
	}
	
	private int dfs(int y, int x) {
		if (id[y][x] != 0) {
			return id[y][x];
		}
		int bestX = -1;
		int bestY = -1;
		int bestHeight = height[y][x];
		for (int[] d : MOVES) {
			final int newY = y + d[1];
			final int newX = x + d[0];
			if (inGrid(newY, newX)) {
				if (height[newY][newX] < bestHeight) {
					bestHeight = height[newY][newX];
					bestY = newY;
					bestX = newX;
				}
			}
		}
		if (bestX == -1) {
			id[y][x] = current++;
		} else {
			id[y][x] = dfs(bestY, bestX);
		}
		return id[y][x];
	}

	private void solve() throws Exception {
		final int testN = nextInt();
		for (int test = 1; test <= testN; ++test) {
			printf("Case #%d:\n", test);
			final int h = nextInt();
			final int w = nextInt();
			height = new int[h][w];
			id = new int[h][w];
			for (int i = 0; i < h; ++i) {
				for (int j = 0; j < w; ++j) {
					height[i][j] = nextInt();
				}
			}
			
			for (int i = 0; i < h; ++i) {
				for (int j = 0; j < w; ++j) {
					if (id[i][j] == 0) {
						dfs(i, j);
					}
					if (id[i][j] == 0) {
						throw new IllegalStateException();
					}
				}
			}
			
			final HashMap<Integer, Character> map = new HashMap<Integer, Character>();
			
			for (int i = 0; i < h; ++i) {
				for (int j = 0; j < w; ++j) {
					if (!map.containsKey(id[i][j])) {
						map.put(id[i][j], (char)('a' + map.size()));
					}
					print(map.get(id[i][j]));
					print(j == w - 1 ? '\n' : ' ');
				}
			}
			if (map.size() > 26) {
				throw new IllegalStateException();
			}
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

		showWorkTime();
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
		return Double.parseDouble(next());
	}

	private int nextInt() throws IOException {
		return Integer.parseInt(next());
	}

	private String next() throws IOException {
		while (tokenizer == null || !tokenizer.hasMoreTokens()) {
			tokenizer = new StringTokenizer(reader.readLine());
		}
		return tokenizer.nextToken();
	}

	private static void showWorkTime() {
		System.err.printf("%.3f\n",
				(System.currentTimeMillis() - startTime) * 0.001);
	}

	public static void main(String[] args) {
		startTime = System.currentTimeMillis();
		Locale.setDefault(Locale.US);
		new Thread(new Main()).start();
	}

	private static long startTime;

	private BufferedReader reader;
	private PrintWriter writer;
	private StringTokenizer tokenizer;
}
