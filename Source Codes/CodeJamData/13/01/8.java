import java.io.*;
import java.util.*;
import java.math.*;

public class TicTacToe implements Runnable {
	static BufferedReader in;
	static PrintWriter out;
	static StringTokenizer st;
	static Random rnd;

	void solve() throws IOException {
		int tests = nextInt();

		for (int test = 1; test <= tests; test++)
			out.println("Case #" + test + ": " + solveOne());

	}

	final int n = 4;

	final int[] dx = { 1, 0, 1, 1 };
	final int[] dy = { 0, 1, 1, -1 };
	final char[] players = { 'X', 'O' };
	final char any = 'T';

	private String solveOne() throws IOException {
		char[][] field = new char[n][];
		for (int i = 0; i < n; i++)
			field[i] = nextToken().toCharArray();

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				for (int k = 0; k < dx.length; k++) {
					if (i + dx[k] * n > n || j + dy[k] * n > n
							|| i + dx[k] * n < -1 || j + dy[k] * n < -1)
						continue;

					for (char target : players) {
						boolean fail = false;
						for (int l = 0; l < n; l++) {
							char c = field[i + dx[k] * l][j + dy[k] * l];
							if (c != target && c != any)
								fail = true;
						}
						if (!fail)
							return target + " won";

					}
				}
			}
		}

		boolean empty = false;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				if (field[i][j] == '.')
					empty = true;
		return !empty ? "Draw" : "Game has not completed";
	}

	public static void main(String[] args) {
		new TicTacToe().run();
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