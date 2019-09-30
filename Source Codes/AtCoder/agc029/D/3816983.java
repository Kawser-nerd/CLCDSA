import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
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
		D_GridGame solver = new D_GridGame();
		solver.solve(1, in, out);
		out.close();
	}

	static class D_GridGame {
		public void solve(int testNumber, FastScanner in, PrintWriter out) {
			int height = in.nextInt();
			int width = in.nextInt();
			int n = in.nextInt();
			Obstacle[] os = new Obstacle[n];
			for (int i = 0; i < n; i++) {
				os[i] = new Obstacle();
				os[i].x = in.nextInt() - 1;
				os[i].y = in.nextInt() - 1;
			}
			Arrays.sort(os, (a, b) -> (a.x - b.x));

			int p = 0;
			int[] maxY = new int[height];
			for (int x = 1; x < height; x++) {
				boolean canExtend = true;
				while (p < n && os[p].x == x) {
					if (maxY[x - 1] + 1 == os[p].y) {
						canExtend = false;
					}
					++p;
				}
				maxY[x] = maxY[x - 1];
				if (canExtend) {
					++maxY[x];
				}
			}

			int ans = height;
			for (int i = 0; i < n; i++) {
				if (os[i].x > 0 && maxY[os[i].x - 1] >= os[i].y) {
					ans = Math.min(ans, os[i].x);
				}
			}
			out.println(ans);
		}

		class Obstacle {
			int x;
			int y;

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