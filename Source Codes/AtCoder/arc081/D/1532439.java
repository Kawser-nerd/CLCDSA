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
		LargestRectangleOfOnes solver = new LargestRectangleOfOnes();
		solver.solve(1, in, out);
		out.close();
	}

	static class LargestRectangleOfOnes {
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
			int[] prevMaxUp = new int[width + 1];
			int[] maxUp = new int[width + 1];
			int[] stack = new int[width + 1];
			// Sentinels.
			maxUp[width] = -1;
			prevMaxUp[width] = -1;
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
				for (int c = 0; c <= width; c++) {
					while (sp > 0 && maxUp[c] < maxUp[stack[sp - 1]]) {
						int dx = c - (sp >= 2 ? stack[sp - 2] + 1 : 0);
						int dy = maxUp[stack[sp - 1]];
						++dx;
						++dy;
						maxArea = Math.max(maxArea, dx * dy);
						--sp;
					}
					stack[sp++] = c;
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