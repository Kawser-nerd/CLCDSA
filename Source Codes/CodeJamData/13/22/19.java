import java.io.File;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class ProblemB {

	public static void main(String[] args) {

		try {

			final String fileIn = ProblemB.class.getSimpleName().toLowerCase() + ".in";
			final String fileOut = ProblemB.class.getSimpleName().toLowerCase() + ".out";

			final Scanner in = new Scanner(new File(fileIn));
			final PrintWriter out = new PrintWriter(new File(fileOut));

			new ProblemB().solve(in, out);

			out.flush();
			out.close();

		} catch (Exception ex) {

			ex.printStackTrace();
		}
	}

	private final void dfs(final int count, final int x, final double p, final int[] h, final double[][] m) {

		if (count == 0) {

			return;
		}

		if (h[x] == -1) {

			int tmp0, tmp1, tmp2;

			m[x][h[x] + 1] += p;

			tmp0 = h[x - 1];
			tmp1 = h[x];
			tmp2 = h[x + 1];

			h[x] += 2;
			h[x - 1] = h[x] - 1;
			h[x + 1] = h[x] - 1;

			dfs(count - 1, x, p, h, m);

			h[x - 1] = tmp0;
			h[x] = tmp1;
			h[x + 1] = tmp2;

			return;
		}

		int turnCount = 0;

		int y;
		int cx;

		y = h[x];
		cx = x;

		int lx = Integer.MAX_VALUE;
		int rx = Integer.MAX_VALUE;

		while (true) {

			--cx;
			if (h[cx] < y) {

				if (lx == Integer.MAX_VALUE) {

					turnCount++;
				}

				lx = cx;
				y = h[cx];

			} else if (h[cx] > y || h[cx] == -1) {
				break;
			}
		}

		y = h[x];
		cx = x;

		while (true) {

			++cx;
			if (h[cx] < y) {

				if (rx == Integer.MAX_VALUE) {

					turnCount++;
				}

				rx = cx;
				y = h[cx];
			} else if (h[cx] > y || h[cx] == -1) {
				break;
			}
		}

		if (turnCount == 0) {

			final int tmpx0 = h[x - 1];
			final int tmpx1 = h[x];
			final int tmpx2 = h[x + 1];

			m[x][h[x] + 1] += p;

			h[x] += 2;
			h[x - 1] = h[x] - 1;
			h[x + 1] = h[x] - 1;

			dfs(count - 1, h.length / 2, p, h, m);

			h[x - 1] = tmpx0;
			h[x] = tmpx1;
			h[x + 1] = tmpx2;
		} else if (turnCount == 2) {

			int tmp0, tmp1, tmp2;

			tmp0 = h[lx - 1];
			tmp1 = h[lx];
			tmp2 = h[lx + 1];

			m[lx][h[lx] + 1] += 0.5 * p;

			h[lx] += 2;
			h[lx - 1] = h[lx] - 1;
			h[lx + 1] = h[lx] - 1;

			dfs(count - 1, h.length / 2, 0.5 * p, h, m);

			h[lx - 1] = tmp0;
			h[lx] = tmp1;
			h[lx + 1] = tmp2;

			tmp0 = h[rx - 1];
			tmp1 = h[rx];
			tmp2 = h[rx + 1];

			m[rx][h[rx] + 1] += 0.5 * p;

			h[rx] += 2;
			h[rx - 1] = h[rx] - 1;
			h[rx + 1] = h[rx] - 1;

			dfs(count - 1, h.length / 2, 0.5 * p, h, m);

			h[rx - 1] = tmp0;
			h[rx] = tmp1;
			h[rx + 1] = tmp2;
		} else {

			if (lx == Integer.MAX_VALUE) {

				lx = rx;
			}

			int tmp0, tmp1, tmp2;

			tmp0 = h[lx - 1];
			tmp1 = h[lx];
			tmp2 = h[lx + 1];

			m[lx][h[lx] + 1] += p;

			h[lx] += 2;
			h[lx - 1] = h[lx] - 1;
			h[lx + 1] = h[lx] - 1;

			dfs(count - 1, h.length / 2, p, h, m);

			h[lx - 1] = tmp0;
			h[lx] = tmp1;
			h[lx + 1] = tmp2;
		}
	}

	private final void solve(final Scanner in, final PrintWriter out) throws Exception {

		final int testCount = in.nextInt();

		for (int testCase = 1; testCase <= testCount; ++testCase) {

			final int n = in.nextInt();

			int[] h = null;
			double[][] m = null;

			for (int i = 1; i <= n; ++i) {

				final int w = 4 * i;

				h = new int[w];
				Arrays.fill(h, -1);

				m = new double[w][w];

				dfs(i, h.length / 2, 1.0, h, m);

				// for (int x = 0; x < m.length; ++x) {
				//
				// for (int y = 0; y < m[x].length; ++y) {
				//
				// System.out.print(String.format("%.4f ", m[x][y]));
				// }
				//
				// System.out.println();
				// }
			}

			final int x = in.nextInt() + h.length / 2;
			final int y = in.nextInt();

			double result = 0.0;

			if (x < 0 || x >= m.length || y > m[x].length) {

			} else {

				result = m[x][y];
			}

			out.printf("Case #%d: %.15f%n", testCase, result);
		}
	}
}
