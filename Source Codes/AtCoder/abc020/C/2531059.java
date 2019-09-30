import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.ArrayDeque;
import java.util.Arrays;
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
	static int MOD = 1000000007;
	static int[] mh4 = { 0, -1, 1, 0 };
	static int[] mw4 = { -1, 0, 0, 1 };

	static class TaskX {
		public void solve(int testNumber, InputReader in, PrintWriter out) {

			int h = in.nextInt(), w = in.nextInt(), t = in.nextInt();
			char[][] s = new char[h][w];
			for (int i = 0; i < h; i++) {
				s[i] = in.nextString().toCharArray();
			}

			int sh = -1, sw = -1;
			int gh = -1, gw = -1;
			for (int i = 0; i < h; i++) {
				for (int j = 0; j < w; j++) {
					if (s[i][j] == 'S') {
						sh = i;
						sw = j;
					} else if (s[i][j] == 'G') {
						gh = i;
						gw = j;
					}
				}
			}

			int l = 0, r = t;
			while (r - l > 1) {
				int mid = (r+l)/2;


				int[][] cost = new int[h][w];
				for (int i = 0; i < h; i++) {
					Arrays.fill(cost[i], INF);
				}

				Queue<P> q = new ArrayDeque<>();
				q.add(new P(sw, sh));
				cost[sh][sw] = 0;

				while (!q.isEmpty()) {
					P p = q.remove();
					int pw = p.x;
					int ph = p.y;

					for (int i = 0; i < 4; i++) {
						int tw = pw + mh4[i];
						int th = ph + mw4[i];

						if (tw < 0 || th < 0 || tw >= w || th >= h) {
							continue;
						}
						int c = s[th][tw] == '#' ? mid : 1;
						if (cost[th][tw] < cost[ph][pw] + c) {
							continue;
						}

						q.add(new P(tw, th));
						cost[th][tw] = cost[ph][pw] + c;
					}
				}

				if (cost[gh][gw] > t) {
					r = mid;
				} else {
					l = mid;
				}

			}

			out.println(l);

		}
	}
	static class P {
		int x, y, cost;
		P (int x, int y) {
			this.x = x;
			this.y = y;
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

		public long[] nextLongArray(int n) {
			long[] res = new long[n];
			for (int i = 0; i < n; i++) {
				res[i] = nextLong();
			}
			return res;
		}

		public InputReader(InputStream inputStream) {
			in = new BufferedReader(new InputStreamReader(inputStream));
			tok = new StringTokenizer("");
		}

	}

}