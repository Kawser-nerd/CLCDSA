import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.InputMismatchException;
import java.util.List;
import java.util.Set;
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

			String[] s = in.nextString().split("T");
			int x = in.nextInt(), y = in.nextInt();
			int len = s.length;
			List<Integer> xs = new ArrayList<>();
			List<Integer> ys = new ArrayList<>();
			for (int i = 0; i < len; i++) {
				if (i % 2 == 0) {
					xs.add(s[i].length());
				} else {
					ys.add(s[i].length());
				}
			}

			if (!xs.isEmpty()) {
				x -= xs.get(0);
				xs.remove(0);
			}
			out.println(can(xs, x) && can(ys, y) ? "Yes" : "No");


		}

		boolean can(List<Integer> xs, int x) {

			Set<Integer> set = new HashSet<>();
			set.add(0);

			for (int v : xs) {
				Set<Integer> next = new HashSet<>();
				for (int base : set) {
					next.add(base + v);
					next.add(base - v);
				}
				set = next;
			}

			return set.contains(x);
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