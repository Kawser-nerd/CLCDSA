import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.Locale;
import java.util.StringTokenizer;

public class ProblemA {

	public static void solve(FastScanner sc) {
		int R = sc.nextInt();
		int C = sc.nextInt();
		char[][] grid = new char[C][R];
		for (int i = 0; i < R; i++) {
			char[] arr = sc.next().toCharArray();
			for (int j = 0; j < C; j++) {
				grid[j][i] = arr[j];
			}
		}
		int problems = 0;
		for (int i = 0; i < C; i++) {
			for (int j = 0; j < R; j++) {
				// start walking, if you encounter an arrow, stop.
				if (grid[i][j] == '.') {
					continue;
				}
				boolean problem = walk(grid, i, j, grid[i][j]);
				if (problem) {
					problem = problem && walk(grid, i, j, '^');
					problem = problem && walk(grid, i, j, '>');
					problem = problem && walk(grid, i, j, 'v');
					problem = problem && walk(grid, i, j, '<');
					if (problem) {
						// impossible
						System.out.println("IMPOSSIBLE");
						return;
					} else {
						// change arrow
						problems++;
					}
				}
			}
		}
		System.out.println(problems);
	}

	public static boolean walk(char[][] grid, int i, int j, char dir) {
		int dX, dY;
		switch (dir) {
		case '>':
			dX = 1;
			dY = 0;
			break;
		case '<':
			dX = -1;
			dY = 0;
			break;
		case '^':
			dX = 0;
			dY = -1;
			break;
		case 'v':
			dX = 0;
			dY = 1;
			break;
		default:
			dX = 1;
			dY = 1;
			System.out.println("ERROR");
		}
		i += dX;
		j += dY;
		while (i >= 0 && i < grid.length && j >= 0 && j < grid[i].length) {
			if (grid[i][j] != '.') {
				return false;
			}
			i += dX;
			j += dY;
		}
		return true;
	}

	public static void main(String[] args) throws FileNotFoundException {
//		FastScanner sc = new FastScanner(new File("A-practice.in"));
//		 FastScanner sc = new FastScanner(new File("A-small-attempt0.in"));
		 FastScanner sc = new FastScanner(new File("A-large.in"));
		// sc.useLocale(Locale.US);
		int cases = sc.nextInt();

		for (int i = 1; i <= cases; i++) {
			System.out.format(Locale.US, "Case #%d: ", i);
			solve(sc);
		}
	}

	static class FastScanner {
		BufferedReader br = null;
		StringTokenizer st = null;

		FastScanner(InputStream in) {
			br = new BufferedReader(new InputStreamReader(System.in));
		}

		FastScanner(File in) throws FileNotFoundException {
			br = new BufferedReader(new FileReader(in));
		}

		public String next() {
			while (st == null || !st.hasMoreTokens()) {
				try {
					st = new StringTokenizer(br.readLine());
				} catch (IOException e) {
					e.printStackTrace();
				}
			}
			return st.nextToken();
		}

		public int nextInt() {
			return Integer.parseInt(next());
		}

		public long nextLong() {
			return Long.parseLong(next());
		}

		public double nextDouble() {
			return Double.parseDouble(next());
		}
	}

}
