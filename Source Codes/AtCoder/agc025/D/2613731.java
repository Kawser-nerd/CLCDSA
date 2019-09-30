import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.List;
import java.util.StringTokenizer;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */
public class Main {
	public static void main(String[] args) {
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		FastScanner in = new FastScanner(inputStream);
		PrintWriter out = new PrintWriter(outputStream);
		ProblemD solver = new ProblemD();
		solver.solve(1, in, out);
		out.close();
	}

	static class ProblemD {
		public void solve(int testNumber, FastScanner in, PrintWriter out) {
			int n = in.nextInt();
			int d1 = in.nextInt();
			int d2 = in.nextInt();

			int[][] col = new int[2 * n][2 * n];
			int[] qx = new int[4 * n * n];
			int[] qy = new int[4 * n * n];
			for (int step = 0; step < 2; step++) {
				int p3 = step == 0 ? 1 : 3;
				List<Point> ps = new ArrayList<>();
				for (int x = -2 * n; x <= 2 * n; x++) {
					for (int y = -2 * n; y <= 2 * n; y++) {
						Point pt = new Point(x, y);
						int d = x * x + y * y;
						if (step == 0 && d == d1) {
							ps.add(pt);
						}
						if (step == 1 && d == d2) {
							ps.add(pt);
						}
					}
				}

				for (int sx = 0; sx < 2 * n; sx++) {
					for (int sy = 0; sy < 2 * n; sy++) {
						int sc = (col[sx][sy] / p3) % 3;
						if (sc != 0) {
							continue;
						}
						qx[0] = sx;
						qy[0] = sy;
						int qt = 0;
						int qh = 1;
						col[sx][sy] += p3;
						while (qt < qh) {
							int x = qx[qt];
							int y = qy[qt];
							int c = (col[x][y] / p3) % 3;
							++qt;
							for (Point p : ps) {
								int nx = x + p.x;
								int ny = y + p.y;
								if (nx < 0 || nx >= 2 * n || ny < 0 || ny >= 2 * n) {
									continue;
								}
								int nc = (col[nx][ny] / p3) % 3;
								if (nc != 0) {
									if (nc != 3 - c) {
										throw new AssertionError();
									}
									continue;
								}
								col[nx][ny] += p3 * (3 - c);
								qx[qh] = nx;
								qy[qh] = ny;
								++qh;
							}
						}
					}
				}
			}

			int[] colSize = new int[9];
			for (int x = 0; x < 2 * n; x++) {
				for (int y = 0; y < 2 * n; y++) {
					++colSize[col[x][y]];
				}
			}
			int bestCol = 0;
			for (int i = 0; i < colSize.length; i++) {
				if (colSize[bestCol] < colSize[i]) {
					bestCol = i;
				}
			}
			int k = n * n;
			for (int x = 0; x < 2 * n; x++) {
				for (int y = 0; y < 2 * n; y++) {
					if (k > 0 && col[x][y] == bestCol) {
						out.println(x + " " + y);
						--k;
					}
				}
			}
			if (k != 0) {
				throw new AssertionError();
			}
		}

		class Point {
			int x;
			int y;

			Point(int x, int y) {
				this.x = x;
				this.y = y;
			}

		}

	}

	static class FastScanner {
		private BufferedReader in;
		private StringTokenizer st;

		public FastScanner(InputStream stream) {
			in = new BufferedReader(new InputStreamReader(stream));
		}

		public String next() {
			while (st == null || !st.hasMoreTokens()) {
				try {
					String rl = in.readLine();
					if (rl == null) {
						return null;
					}
					st = new StringTokenizer(rl);
				} catch (IOException e) {
					throw new RuntimeException(e);
				}
			}
			return st.nextToken();
		}

		public int nextInt() {
			return Integer.parseInt(next());
		}

	}
}