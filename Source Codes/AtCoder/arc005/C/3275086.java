import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.ArrayDeque;
import java.util.InputMismatchException;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {

	public static void main(String[] args) throws IOException {
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		InputReader in = new InputReader(inputStream);
		PrintWriter out = new PrintWriter(outputStream);
		TaskX solver = new TaskX();
		solver.solve(1, in, out);
		out.close();
	}

	static int INF = 1 << 30;
	static long LINF = 1L << 55;
	static int MOD = 1000000007;
	static int[] mh4 = { 0, -1, 1, 0 };
	static int[] mw4 = { -1, 0, 0, 1 };
	static int[] mh8 = { -1, -1, -1, 0, 0, 1, 1, 1 };
	static int[] mw8 = { -1, 0, 1, -1, 1, -1, 0, 1 };

	static class TaskX {

		public void solve(int testNumber, InputReader in, PrintWriter out) {

			int h = in.nextInt(), w = in.nextInt();
			char[][] s = new char[h][w];
			for (int i = 0; i < h; i++) {
				s[i] = in.nextString().toCharArray();
			}

			int sh = -1, sw = -1, gh = -1, gw = -1;
			for (int i = 0; i < h; i++) {
				for (int j = 0; j < w; j++) {
					if (s[i][j] == 's') {
						sh = i;
						sw = j;
					} else if (s[i][j] == 'g') {
						gh = i;
						gw = j;
					}
				}
			}

			int[][][] cost = new int[h][w][3];
			fill(cost, INF);
			cost[sh][sw][0] = 0;

			Queue<P> q = new ArrayDeque<>();
			q.add(new P(sh, sw, 0));

			while (!q.isEmpty()) {
				P p = q.remove();

				for (int i = 0; i < 4; i++) {
					int mh = p.h + mh4[i];
					int mw = p.w + mw4[i];
					if (mh < 0 || mw < 0 || mh >= h || mw >= w) continue;
					if (p.c == 2 && s[mh][mw] == '#') continue;

					if (s[mh][mw] == '#') {
						if (cost[p.h][p.w][p.c] + 1 < cost[mh][mw][p.c+1]) {
							cost[mh][mw][p.c+1] = cost[p.h][p.w][p.c] + 1;
							q.add(new P(mh, mw, p.c+1));
						}
					} else if (s[mh][mw] == '.' || s[mh][mw] == 'g') {
						if (cost[p.h][p.w][p.c] + 1 < cost[mh][mw][p.c]) {
							cost[mh][mw][p.c] = cost[p.h][p.w][p.c] + 1;
							q.add(new P(mh, mw, p.c));
						}
					}
				}
			}

			boolean ok = false;
			for (int i = 0; i < 3; i++) {
				if (cost[gh][gw][i] != INF) ok = true;
			}

			out.println(ok ? "YES": "NO");
		}
	}

	static class P {
		int h, w, c;

		public P(int h, int w, int c) {
			super();
			this.h = h;
			this.w = w;
			this.c = c;
		}

		@Override
		public String toString() {
			return "P [h=" + h + ", w=" + w + ", c=" + c + "]";
		}
	}

	static void fill(int[][][] cost, int v) {
		for (int i = 0; i < cost.length; i++) {
			for (int j = 0; j < cost[0].length; j++) {
				for (int k = 0; k < cost[0][0].length; k++) {
					cost[i][j][k] = v;
				}
			}
		}
	}

	static class InputReader {
		BufferedReader in;
		StringTokenizer tok;

		public String nextString() {
			while (!tok.hasMoreTokens()) {
				try {
					tok = new StringTokenizer(in.readLine(), " ");
				} catch (IOException e) {
					throw new InputMismatchException();
				}
			}
			return tok.nextToken();
		}

		public int nextInt() {
			return Integer.parseInt(nextString());
		}

		public long nextLong() {
			return Long.parseLong(nextString());
		}

		public double nextDouble() {
			return Double.parseDouble(nextString());
		}

		public int[] nextIntArray(int n) {
			int[] res = new int[n];
			for (int i = 0; i < n; i++) {
				res[i] = nextInt();
			}
			return res;
		}

		public int[] nextIntArrayDec(int n) {
			int[] res = new int[n];
			for (int i = 0; i < n; i++) {
				res[i] = nextInt() - 1;
			}
			return res;
		}

		public int[] nextIntArray1Index(int n) {
			int[] res = new int[n + 1];
			for (int i = 0; i < n; i++) {
				res[i + 1] = nextInt();
			}
			return res;
		}

		public long[] nextLongArray(int n) {
			long[] res = new long[n];
			for (int i = 0; i < n; i++) {
				res[i] = nextLong();
			}
			return res;
		}

		public long[] nextLongArrayDec(int n) {
			long[] res = new long[n];
			for (int i = 0; i < n; i++) {
				res[i] = nextLong() - 1;
			}
			return res;
		}

		public long[] nextLongArray1Index(int n) {
			long[] res = new long[n + 1];
			for (int i = 0; i < n; i++) {
				res[i + 1] = nextLong();
			}
			return res;
		}

		public double[] nextDoubleArray(int n) {
			double[] res = new double[n];
			for (int i = 0; i < n; i++) {
				res[i] = nextDouble();
			}
			return res;
		}

		public InputReader(InputStream inputStream) {
			in = new BufferedReader(new InputStreamReader(inputStream));
			tok = new StringTokenizer("");
		}
	}

}