import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.StringTokenizer;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
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
		TaskF solver = new TaskF();
		solver.solve(1, in, out);
		out.close();
	}

	static class TaskF {
		public void solve(int testNumber, FastScanner in, PrintWriter out) {
			int height = in.nextInt();
			int width = in.nextInt();
			char[][] s = new char[height][];
			for (int r = 0; r < height; r++) {
				s[r] = in.next().toCharArray();
			}
			boolean[][] a = new boolean[height - 1][width - 1];
			for (int r = 1; r < height; r++) {
				for (int c = 1; c < width; c++) {
					int k = 0;
					for (int dr = -1; dr <= 0; dr++) {
						for (int dc = -1; dc <= 0; dc++) {
							if (s[r + dr][c + dc] == '.') {
								++k;
							}
						}
					}
					if (k % 2 == 0) {
						a[r - 1][c - 1] = true;
					}
				}
			}
			int ans = Math.max(height, width);
			ans = Math.max(ans, maxRectangleOfOnes(a));
			out.println(ans);
		}

		private int maxRectangleOfOnes(boolean[][] a) {
			// false for 0, true for 1
			int height = a.length;
			int width = a[0].length;
			int[] prevMaxUp = new int[width];
			int[] maxUp = new int[width];
			int[] stack = new int[width];
			int[] left = new int[width];
			int[] right = new int[width];
			int maxArea = 0;
			for (int r = 0; r < height; r++) {
				for (int c = 0; c < width; c++) {
					if (a[r][c]) {
						maxUp[c] = 1 + prevMaxUp[c];
					} else {
						maxUp[c] = 0;
					}
				}

				int sp = 0;
				for (int c = 0; c < width; c++) {
					while (sp > 0) {
						if (maxUp[c] > maxUp[stack[sp - 1]]) {
							break;
						}
						--sp;
					}
					if (sp == 0) {
						left[c] = 0;
					} else {
						left[c] = stack[sp - 1] + 1;
					}
					stack[sp++] = c;
				}

				sp = 0;
				for (int c = width - 1; c >= 0; c--) {
					while (sp > 0) {
						if (maxUp[c] > maxUp[stack[sp - 1]]) {
							break;
						}
						--sp;
					}
					if (sp == 0) {
						right[c] = width - 1;
					} else {
						right[c] = stack[sp - 1] - 1;
					}
					stack[sp++] = c;
				}

				for (int c = 0; c < width; c++) {
//				maxArea = Math.max(maxArea, (right[c] - left[c] + 1) * maxUp[c]);
					maxArea = Math.max(maxArea, (right[c] - left[c] + 2) * (maxUp[c] + 1));
				}
				int[] tmp = maxUp;
				maxUp = prevMaxUp;
				prevMaxUp = tmp;
			}
			return maxArea;
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
					st = new StringTokenizer(in.readLine());
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