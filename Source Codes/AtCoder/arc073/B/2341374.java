import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.InputMismatchException;
import java.util.List;
import java.util.StringTokenizer;
import java.util.stream.Stream;

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

	static class TaskX {
		public void solve(int testNumber, InputReader in, PrintWriter out) {

			int N = in.nextInt();
			int W = in.nextInt();

			List<P>[] list = new ArrayList[4];
			list = Stream.generate(ArrayList::new).limit(N).toArray(List[]::new);

			int w1 = 0;
			for (int i = 0; i < N; i++) {
				int w = in.nextInt(), v = in.nextInt();
				if (i == 0) {
					w1 = w;
				}
				list[w-w1].add(new P(w, v));
			}

			for (int i = 0; i < 4; i++) {
				list[i].sort((a, b) -> b.v - a.v);
			}

			long ans = 0;
			for (int i = 0; i <= list[0].size(); i++) {
				for (int j = 0; j <= list[1].size(); j++) {
					for (int k = 0; k <= list[2].size(); k++) {
						for (int l = 0; l <= list[3].size(); l++) {

							long tmpW = 0;
							long tmpV = 0;

							int m = 0;
							while (0 < i && m < i) {
								tmpW += list[0].get(m).w;
								tmpV += list[0].get(m).v;
								m++;
							}

							m = 0;
							while (0 < j && m < j) {
								tmpW += list[1].get(m).w;
								tmpV += list[1].get(m).v;
								m++;
							}

							m = 0;
							while (0 < k && m < k) {
								tmpW += list[2].get(m).w;
								tmpV += list[2].get(m).v;
								m++;
							}

							m = 0;
							while (0 < l && m < l) {
								tmpW += list[3].get(m).w;
								tmpV += list[3].get(m).v;
								m++;
							}

							if (tmpW <= W) {
								ans = Math.max(ans, tmpV);
							}

						}
					}
				}
			}

			out.println(ans);

		}
	}
	static class P {
		int w,v;
		P (int w, int v) {
			this.w = w;
			this.v = v;
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

} Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.