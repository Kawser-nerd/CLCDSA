import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.List;
import java.util.StringTokenizer;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.InputStream;
import java.util.ArrayList;

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
		TaskC solver = new TaskC();
		solver.solve(1, in, out);
		out.close();
	}

	static class TaskC {
		public void solve(int testNumber, FastScanner in, PrintWriter out) {
			long n = in.nextLong();
			List<Integer> a = construct(n + 1);
			out.println(2 * a.size());
			for (int i = 0; i < a.size(); i++) {
				if (i > 0) {
					out.print(" ");
				}
				out.print(a.get(i));
			}
			for (int i = 0; i < a.size(); i++) {
				out.print(" " + (i + 1));
			}
			out.println();
		}

		private List<Integer> construct(long n) {
			List<Integer> res = new ArrayList<>();
			if (n == 1) {
				return res;
			}
			if (n % 2 == 1) {
				List<Integer> a = construct(n - 1);
				res.add(a.size() + 1);
				res.addAll(a);
			} else {
				List<Integer> a = construct(n / 2);
				res.addAll(a);
				res.add(a.size() + 1);
			}
			return res;
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

		public long nextLong() {
			return Long.parseLong(next());
		}

	}
}