import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
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
	static int MOD = 1000000007;
	static int[] mh4 = { 0, -1, 1, 0 };
	static int[] mw4 = { -1, 0, 0, 1 };
	static int[] mh8 = { -1, -1, -1, 0, 0, 1, 1, 1 };
	static int[] mw8 = { -1, 0, 1, -1, 1, -1, 0, 1 };

	static long[] w, p;
	static int n, k;
	static class TaskX {
		public void solve(int testNumber, InputReader in, PrintWriter out) {

			n = in.nextInt(); k = in.nextInt();
			w = new long[n]; p = new long[n];
			for (int i = 0; i < n; i++) {
				w[i] = in.nextInt();
				p[i] = in.nextInt();
			}

			double l = -1, r = INF;
			double m = -1;

			for (int j = 0; j < 100; j++) {
				m = (l+r)/2;
				if (C(m)) {
					l = m;
				} else {
					r = m;
				}
			}

			out.println(l);

		}

		static boolean C(double m) {
			List<Double> list =new ArrayList<>();

			for (int i = 0; i < n; i++) {
				list.add(w[i]*(p[i]-m));
			}

			Collections.sort(list, Comparator.reverseOrder());

			long tmp = 0;
			for (int i = 0; i < k; i++) {
				tmp += list.get(i);
			}

			return tmp >= 0;
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