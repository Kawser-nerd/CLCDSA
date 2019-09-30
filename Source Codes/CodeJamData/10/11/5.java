import java.io.*;
import java.lang.reflect.Array;
import java.util.*;

public class A implements Runnable {
	String fileName = "A-large";

	private void solution() throws IOException {
		int ts = in.nextInt();
		for (int cas = 1; cas <= ts; ++cas) {
			out.printf("Case #%d: %s\n", cas, solve());
		}
	}

	private String solve() throws IOException {
		int n = in.nextInt();
		int k = in.nextInt();
		char[][] grid = new char[n][];
		for (int i = 0; i < n; ++i) {
			grid[i] = in.next().toCharArray();
		}
		grid = rotateClockwise(grid);
		fall(grid);
		boolean blue = check(grid, k, 'B');
		boolean red = check(grid, k, 'R');
		if (blue && red) {
			return "Both";
		} else if (blue) {
			return "Blue";
		} else if (red) {
			return "Red";
		} else {
			return "Neither";
		}
	}

	private void fall(char[][] grid) {
		int n = grid.length;
		for (int j = 0; j < n; ++j) {
			int i = n - 1;
			while (i >= 0 && grid[i][j] != '.') {
				--i;
			}
			int free = i;
			while (i >= 0) {
				if (grid[i][j] != '.') {
					grid[free--][j] = grid[i][j];
					grid[i][j] = '.';
				}
				--i;
			}
		}
	}

	private boolean check(char[][] grid, int K, char c) {
		int n = grid.length;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				for (int dx = -1; dx <= 1; ++dx) {
					for (int dy = -1; dy <= 1; ++dy) {
						if (dx != 0 || dy != 0) {
							int mx = i + dx * (K - 1);
							int my = j + dy * (K - 1);
							if (mx >= 0 && my >= 0 && mx < n && my < n) {
								boolean ok = true;
								for (int k = 0; k < K; ++k) {
									if (grid[i + dx * k][j + dy * k] != c) {
										ok = false;
									}
								}
								if (ok) {
									return true;
								}
							}
						}
					}
				}
			}
		}
		return false;
	}

	private char[][] rotateClockwise(char[][] grid) {
		int n = grid.length;
		char[][] res = new char[n][n];
		int it = 0;
		for (int j = 0; j < n; ++j) {
			for (int i = n - 1; i >= 0; --i) {
				res[it / n][it % n] = grid[i][j];
				++it;
			}
		}
		return res;
	}

	private String toString(Object ob) {
		StringBuilder builder = new StringBuilder();
		try {
			int size = Array.getLength(ob);
			for (int i = 0; i < size; ++i) {
				if (i != 0) {
					builder.append(" ");
				}
				builder.append(Array.get(ob, i));
			}
		} catch (Exception e) {
			builder.append(ob);
		}
		return builder.toString();
	}

	public void run() {
		try {
			in = new Scanner(new FileReader(fileName + ".in"));
			out = new PrintWriter(fileName + ".out");
			solution();
			in.reader.close();
			out.close();
		} catch (Throwable e) {
			e.printStackTrace();
			System.exit(1);
		}
	}

	private class Scanner {
		private BufferedReader reader;
		private StringTokenizer tokenizer;

		public Scanner(Reader reader) {
			this.reader = new BufferedReader(reader);
			this.tokenizer = new StringTokenizer("");
		}

		public boolean hasNext() throws IOException {
			while (!tokenizer.hasMoreTokens()) {
				String next = reader.readLine();
				if (next == null) {
					return false;
				}
				tokenizer = new StringTokenizer(next);
			}
			return true;
		}

		public String next() throws IOException {
			hasNext();
			return tokenizer.nextToken();
		}

		public int nextInt() throws IOException {
			return Integer.parseInt(next());
		}

		public double nextDouble() throws IOException {
			return Double.parseDouble(next());
		}

		public long nextLong() throws IOException {
			return Long.parseLong(next());
		}

		public String nextLine() throws IOException {
			tokenizer = new StringTokenizer("");
			return reader.readLine();
		}
	}

	public static void main(String[] args) throws IOException {
		new Thread(null, new A(), "", 1 << 28).start();
	}
	PrintWriter out = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
	Scanner in = new Scanner(new InputStreamReader(System.in));
}
