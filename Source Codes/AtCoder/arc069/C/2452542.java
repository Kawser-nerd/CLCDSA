import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collections;
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

	static class TaskX {
		public void solve(int testNumber, InputReader in, PrintWriter out) {

			int n = in.nextInt();

			List<P> list = new ArrayList<>();
			List<Integer> target = new ArrayList<>();
			for (int i = 0; i < n; i++) {
				long c = in.nextLong();
				list.add(new P(i, c));
			}

			long max = 0;
			for (int i = 0; i < n; i++) {
				if (max < list.get(i).c) {
					max = list.get(i).c;
					target.add(list.get(i).k);
				}
			}

			Collections.sort(list, (x, y) -> (int)x.c - (int)y.c);

			max = 0;
			int idx = 0;
			long sum = 0;
			long[] ans = new long[n];
			for (int i = 0; i < n; i++) {
				long c = list.get(i).c;
				if (max < c && list.get(i).k == target.get(idx)) {
					ans[list.get(i).k] = sum + (c - max)*(long)(n - i);
					max = c;
					idx++;
					sum = 0;
				} else {
					sum += list.get(i).c - max;
				}
			}

			for (long l : ans) {
				System.out.println(l);
			}

		}
	}
	static class P {
		int k; long c;

		public P(int k, long c) {
			this.k = k;
			this.c = c;
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