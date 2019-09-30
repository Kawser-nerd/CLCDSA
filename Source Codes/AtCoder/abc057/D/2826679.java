import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.HashMap;
import java.util.InputMismatchException;
import java.util.List;
import java.util.Map;
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

			int n = in.nextInt(), a = in.nextInt(), b = in.nextInt();
			Map<Double, Integer> map = new HashMap<>();
			List<Double> list = new ArrayList<>();
			for (int i = 0; i < n; i++) {
				double v = in.nextDouble();
				list.add(v);
				map.merge(v, 1, Integer::sum);
			}
			Collections.sort(list, Comparator.reverseOrder());

			double max = list.get(0);
			double sum = 0.0;
			int y = 0;
			int ca = 0;
			for (int i = 0; i < n; i++) {
				if (i < a) {
					sum += list.get(i);
					ca++;
					if (list.get(i).equals(list.get(a-1))) {
						y++;
					}
				} else if (max == list.get(i)) {
					sum += list.get(i);
					ca++;
				} else {
					break;
				}
			}

			// ??????
			out.println(sum / ca);

			// ??
			long ans = 0;
			if (max == list.get(a-1)) {
				int min = Math.min(map.get(max), b);
				for (int i = a; i <= min; i++) {
					ans += ncr(ca, i);
				}
				out.println(ans);
			} else {
				out.println(ncr(map.get(list.get(a-1)), y));
			}
		}

		static long ncr(int a, int b) {
			if (b == 0) return 1;
			long res = ncr(a - 1, b - 1);
			res *= a;
			res /= b;
			return res;
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