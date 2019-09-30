import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.List;
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
	static int modP = 1000000007;

	static int nh = 0, nw = 0;
	static int h, w, n;
	static class TaskX {
		public void solve(int testNumber, InputReader in, PrintWriter out) {

			h = in.nextInt(); w = in.nextInt(); n = in.nextInt();
			P[] a = new P[n];
			for (int i = 0; i < a.length; i++) {
				a[i] = new P(i+1, in.nextInt());
			}
			Arrays.sort(a, (x, y) -> y.count - x.count);

			List<Integer> list =new ArrayList<>();
			for (P p : a) {
				for (int i = 0; i < p.count; i++) {
					list.add(p.color);
				}
			}
			int c = 0;
			while (c < h*w) {
				int t = c;
				if ((c / w) % 2 == 0) {
					for (int i = t; i < t + w; i++) {
						if (i == t) {
							out.print(list.get(i));
						} else {
							out.print(" " + list.get(i));
						}
						c++;
					}
					out.print("\n");
				} else {
					for (int i = t + w - 1; i >= t; i--) {
						if (i == t + w - 1) {
							out.print(list.get(i));
						} else {
							out.print(" " + list.get(i));
						}
						c++;
					}
					out.print("\n");
				}
			}

		}
		static boolean isMoveRight() {
			return nw+1 == w ? false : true;
		}
		static boolean isMoveLeft() {
			return nw == 0 ? false : true;
		}
		static void right() {
			nw++;
		}
		static void left() {
			nw--;
		}
		static void down() {
			nh++;
		}
	}
	static class P {
		int color, count;
		P(int color, int count) {
			this.color = color;
			this.count = count;
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