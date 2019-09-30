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
		TaskF solver = new TaskF();
		solver.solve(1, in, out);
		out.close();
	}

	static class TaskF {
		public void solve(int testNumber, FastScanner in, PrintWriter out) {
			int height = in.nextInt();
			int width = in.nextInt();
			char[][] s = new char[height][];
			int sv = -1;
			int tv = -1;
			for (int r = 0; r < height; r++) {
				s[r] = in.next().toCharArray();
				for (int c = 0; c < width; c++) {
					if (s[r][c] == 'S') {
						sv = r * width + c;
					}
					if (s[r][c] == 'T') {
						tv = r * width + c;
					}
				}
			}
			int[] q = new int[height * width];
			int[] d = new int[height * width];
			int[] p = new int[height * width];
			final int infinity = 1000000000;
			for (int ans = 0; ; ans++) {
				Arrays.fill(p, -1);
				Arrays.fill(d, infinity);
				int qt = 0;
				int qh = 1;
				q[0] = sv;
				d[sv] = 0;
				while (qt < qh) {
					int v = q[qt++];
					if (v == tv) {
						break;
					}

					int r = v / width;
					int c = v % width;
					for (int nr = 0; nr < height; nr++) {
						int nc = c;
						if (s[nr][nc] == '.') {
							continue;
						}
						int u = nr * width + nc;
						if (d[u] > 1 + d[v]) {
							d[u] = 1 + d[v];
							p[u] = v;
							q[qh++] = u;
						}
					}
					for (int nc = 0; nc < width; nc++) {
						int nr = r;
						if (s[nr][nc] == '.') {
							continue;
						}
						int u = nr * width + nc;
						if (d[u] > 1 + d[v]) {
							d[u] = 1 + d[v];
							p[u] = v;
							q[qh++] = u;
						}
					}
				}
				if (d[tv] >= infinity) {
					out.println(ans);
					return;
				}
				if (d[tv] == 1) {
					out.println(-1);
					return;
				}
				for (int v = tv; v >= 0; v = p[v]) {
					int r = v / width;
					int c = v % width;
					if (s[r][c] == 'o') {
						s[r][c] = '.';
					}
				}
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