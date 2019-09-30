import java.io.*;
import java.util.*;
import java.math.*;

public class B implements Runnable {
	private static BufferedReader in;
	private static PrintWriter out;
	private static StringTokenizer st;
	private static Random rnd;

	private void solve() throws IOException {
		int tests = nextInt();
		for (int test = 1; test <= tests; test++) {
			out.print("Case #" + test + ": ");
			solveOne();
		}
	}

	private void solveOne() throws IOException {
		int height = nextInt(), width = nextInt(), targetBits = nextInt();
		out.println(solveSmart(height, width, targetBits));
//		for (int h = 1; h <= 20; h++) {
//			for (int w = 1; w <= 20; w++) {
//				for (int t = 0; t <= h * w; t++) {
//					if (h * w <= 20) {
//						if (solveDumb(h, w, t) != solveSmart(h, w, t))
//							throw new AssertionError();
//					}
//				}
//			}
//		}
	}

	private int solveDumb(int height, int width, int targetBits) {
		boolean[][] cells = new boolean[height][width];
		int total = height * width;
		int result = Integer.MAX_VALUE;
		for (int mask = 0; mask < (1 << total); mask++) {
			if (Integer.bitCount(mask) != targetBits)
				continue;
			// out.println(mask);
			int currentResut = 0;
			for (int i = 0; i < height; i++) {
				for (int j = 0; j < width; j++) {
					int id = i * width + j;
					cells[i][j] = checkBit(mask, id);
				}
			}
			for (int i = 0; i < height; i++) {
				for (int j = 0; j < width; j++) {
					if (i + 1 < height && cells[i][j] && cells[i + 1][j])
						++currentResut;
					if (j + 1 < width && cells[i][j] & cells[i][j + 1])
						++currentResut;
				}
			}
			result = Math.min(result, currentResut);
		}
		return result;
	}

	private int solveSmart(int height, int width, int targetBits) {
		return Math.min(solveSmart(height, width, targetBits, 0),
				solveSmart(height, width, targetBits, 1));
	}

	private int solveSmart(int height, int width, int targetBits, int odd) {
		int result = 0;
		boolean[][] field = new boolean[height][width];
		for (int i = 0; i < height; i++) {
			for (int j = 0; j < width; j++) {
				if ((i + j) % 2 == odd && targetBits > 0) {
					field[i][j] = true;
					--targetBits;
				}
			}
		}
		if (targetBits > 0) {
			// out.println("Remain: " + targetBits);
			final int[] dx = { 1, -1, 0, 0 };
			final int[] dy = { 0, 0, 1, -1 };
			int[] pointsWithPenalty = new int[5];
			for (int i = 0; i < height; i++) {
				for (int j = 0; j < width; j++) {
					if (!field[i][j]) {
						int penalty = 0;
						for (int k = 0; k < 4; k++) {
							int x = i + dx[k], y = j + dy[k];
							if (x >= 0 && y >= 0 && x < height && y < width
									&& field[x][y]) {
								++penalty;
							}
						}
						// out.println(penalty);
						pointsWithPenalty[penalty]++;
					}
				}
			}
			for (int i = 0; i <= 4; i++) {
				while (targetBits > 0 && pointsWithPenalty[i] > 0) {
					result += i;
					--targetBits;
					--pointsWithPenalty[i];
				}
			}
		}
		if (targetBits != 0)
			throw new AssertionError();
		return result;
	}

	private boolean checkBit(int mask, int id) {
		return ((mask >> id) & 1) != 0;
	}

	public static void main(String[] args) {
		new B().run();
	}

	public void run() {
		try {
			final String className = this.getClass().getName().toLowerCase();

			try {
				in = new BufferedReader(new FileReader(className + ".in"));
				out = new PrintWriter(new FileWriter(className + ".out"));
				// in = new BufferedReader(new FileReader("input.txt"));
				// out = new PrintWriter(new FileWriter("output.txt"));
			} catch (FileNotFoundException e) {
				in = new BufferedReader(new InputStreamReader(System.in));
				out = new PrintWriter(System.out);
			}

			rnd = new Random();

			solve();

			out.close();
		} catch (IOException e) {
			e.printStackTrace();
			System.exit(42);
		}
	}

	private String nextToken() throws IOException {
		while (st == null || !st.hasMoreTokens()) {
			String line = in.readLine();

			if (line == null)
				return null;

			st = new StringTokenizer(line);
		}

		return st.nextToken();
	}

	private int nextInt() throws IOException {
		return Integer.parseInt(nextToken());
	}

	private long nextLong() throws IOException {
		return Long.parseLong(nextToken());
	}

	private double nextDouble() throws IOException {
		return Double.parseDouble(nextToken());
	}
}