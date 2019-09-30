import java.io.*;
import java.util.*;
import java.math.*;

public class Lawnmower implements Runnable {
	static BufferedReader in;
	static PrintWriter out;
	static StringTokenizer st;
	static Random rnd;

	void solve() throws IOException {
		int tests = nextInt();

		for (int test = 1; test <= tests; test++)
			out.println("Case #" + test + ": " + solveOne());

	}

	final int minValue = 1, maxValue = 100;

	private String solveOne() throws IOException {
		int n = nextInt(), m = nextInt();

		int[][] field = new int[n][m];
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				field[i][j] = nextInt();

		for (int value = minValue; value <= maxValue; value++) {
			for (int i = 0; i < n; i++)
				for (int j = 0; j < m; j++)
					if (field[i][j] < value)
						field[i][j] = value;

			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++) {
					if (!checkHor(n, m, field, i, j)
							&& !checkVer(n, m, field, i, j))
						return "NO";
				}
			}
		}
		return "YES";
	}

	private boolean checkVer(int n, int m, int[][] field, int x, int y) {
		for (int i = 0; i < n; i++)
			if (field[i][y] > field[x][y])
				return false;
		return true;
	}

	private boolean checkHor(int n, int m, int[][] field, int x, int y) {
		for (int j = 0; j < m; j++)
			if (field[x][j] > field[x][y])
				return false;
		return true;
	}

	public static void main(String[] args) {
		new Lawnmower().run();
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

	String nextToken() throws IOException {
		while (st == null || !st.hasMoreTokens()) {
			String line = in.readLine();

			if (line == null)
				return null;

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