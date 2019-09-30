import java.io.*;
import java.util.*;

public class B {

	private void solve() throws IOException {
		int r = nextInt();
		int c = nextInt();
		nextToken();
		int[][] grid = new int[r][c];
		for (int i = 0; i < r; i++) {
			String s = nextToken();
			for (int j = 0; j < c; j++) {
				grid[i][j] = s.charAt(j) - '0';
			}
		}
		int[][] sumX = new int[r + 1][c + 1];
		int[][] sumY = new int[r + 1][c + 1];
		int[][] sumMass = new int[r + 1][c + 1];
		for (int i = 0; i < r; i++) {
			int curX = 0;
			int curY = 0;
			int mass = 0;
			for (int j = 0; j < c; j++) {
				curX += grid[i][j] * i;
				curY += grid[i][j] * j;
				mass += grid[i][j];
				sumX[i + 1][j + 1] = sumX[i][j + 1] + curX;
				sumY[i + 1][j + 1] = sumY[i][j + 1] + curY;
				sumMass[i + 1][j + 1] = sumMass[i][j + 1] + mass;
			}
		}
		int res = 0;

		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				for (int k = 3; k + i <= r && k + j <= c; k++) {
					long curX = sumX[i + k][j + k] + sumX[i][j] - sumX[i][j + k] - sumX[i + k][j];
					long curY = sumY[i + k][j + k] + sumY[i][j] - sumY[i][j + k] - sumY[i + k][j];
					long mass = sumMass[i + k][j + k] + sumMass[i][j] - sumMass[i][j + k]
							- sumMass[i + k][j];
					curX -= grid[i][j] * i;
					curX -= grid[i][j + k - 1] * i;
					curX -= grid[i + k - 1][j] * (i + k - 1);
					curX -= grid[i + k - 1][j + k - 1] * (i + k - 1);
					curY -= grid[i][j] * j;
					curY -= grid[i][j + k - 1] * (j + k - 1);
					curY -= grid[i + k - 1][j] * j;
					curY -= grid[i + k - 1][j + k - 1] * (j + k - 1);
					mass -= grid[i][j];
					mass -= grid[i][j + k - 1];
					mass -= grid[i + k - 1][j];
					mass -= grid[i + k - 1][j + k - 1];

					if (curX * 2 == (2 * i + k - 1) * mass && curY * 2 == (2 * j + k - 1) * mass) {
						res = Math.max(res, k);
					}
				}
			}
		}
		out.println(res > 0 ? res : "IMPOSSIBLE");
	}

	public static void main(String[] args) {
		new B().run();
	}

	BufferedReader br;
	StringTokenizer st;
	PrintWriter out;

	static final boolean large = true;

	public void run() {
		try {
			String fileName = "B-" + (large ? "large" : "small");
			br = new BufferedReader(new FileReader(fileName + ".in"));
			out = new PrintWriter(fileName + ".out");
			st = new StringTokenizer("");
			int T = nextInt();
			for (int i = 1; i <= T; i++) {
				out.print("Case #" + i + ": ");
				solve();
				System.out.println(i + "/" + T + " done");
			}
			out.close();
		} catch (Throwable e) {
			e.printStackTrace();
			System.exit(239);
		}
	}

	String nextToken() throws IOException {
		while (!st.hasMoreTokens()) {
			String line = br.readLine();
			if (line == null) {
				return null;
			}
			st = new StringTokenizer(line);
		}
		return st.nextToken();
	}

	int nextInt() throws IOException {
		return Integer.parseInt(nextToken());
	}

	long nextLong() throws IOException {
		return Long.parseLong(nextToken());
	}

	double nextDouble() throws IOException {
		return Double.parseDouble(nextToken());
	}
}