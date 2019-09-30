import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.InputMismatchException;
import java.util.PriorityQueue;
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
	static int MOD = 998244353;
	static int[] mh4 = { 0, -1, 1, 0 };
	static int[] mw4 = { -1, 0, 0, 1 };
	static int[] mh8 = { -1, -1, -1, 0, 0, 1, 1, 1 };
	static int[] mw8 = { -1, 0, 1, -1, 1, -1, 0, 1 };

	static class TaskX {
		PriorityQueue<Segment> s1min;
		PriorityQueue<Segment> s1max;
		PriorityQueue<Segment> s2min;
		PriorityQueue<Segment> s2max;
		int n, num;
		boolean[] used;
		public void solve(int testNumber, InputReader in, PrintWriter out) {

			n = in.nextInt();
			s1min = new PriorityQueue<>((o1, o2) -> o1.r - o2.r);
			s1max = new PriorityQueue<>((o1, o2) -> o2.l - o1.l);
			s2min = new PriorityQueue<>((o1, o2) -> o1.r - o2.r);
			s2max = new PriorityQueue<>((o1, o2) -> o2.l - o1.l);

			for (int i = 0; i < n; i++) {
				int l = in.nextInt(), r = in.nextInt();
				s1min.add(new Segment(i, l, r));
				s1max.add(new Segment(i, l, r));
				s2min.add(new Segment(i, l, r));
				s2max.add(new Segment(i, l, r));
			}

			long a1 = 0, a2 = 0;
			// ?????????
			used = new boolean[n];
			num = 1;
			a1 = move();

			// ?????????
			used = new boolean[n];
			num = 0;
			s1min = s2min;
			s1max = s2max;
			a2 = move();

			out.println(Math.max(a1, a2));

		}
		long move() {

			long ret = 0;
			long now = 0;
			while (!s1min.isEmpty() || !s1max.isEmpty()) {
				// ?
				num ^= 1;
				if (num == 0) {
					while (!s1max.isEmpty()) {
						Segment s = s1max.poll();
						if (used[s.idx]) continue;
						if (s.l >= now) {
							ret += Math.abs(now - s.l);
							now = s.l;
						}
						used[s.idx] = true;
						break;
					}
				}
				// ?
				else if (num == 1) {
					while (!s1min.isEmpty()) {
						Segment s = s1min.poll();
						if (used[s.idx]) continue;
						if (s.r <= now) {
							ret += Math.abs(now - s.r);
							now = s.r;
						}
						used[s.idx] = true;
						break;
					}
				}
			}
			ret += Math.abs(now);

			return ret;
		}

	}

	static class Segment {
		int idx, l, r;

		public Segment(int idx, int l, int r) {
			super();
			this.idx = idx;
			this.l = l;
			this.r = r;
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