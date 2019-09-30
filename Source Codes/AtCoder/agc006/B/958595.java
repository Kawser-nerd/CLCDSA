import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.StringTokenizer;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.InputStream;

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
		TaskB solver = new TaskB();
		solver.solve(1, in, out);
		out.close();
	}

	static class TaskB {
		int[] ans;
		boolean[] used;
		int p;

		public void solve(int testNumber, FastScanner in, PrintWriter out) {
			int n = in.nextInt();
			int x = in.nextInt();
			if (x == 1 || x == 2 * n - 1) {
				out.println("No");
				return;
			}
			if (n == 2) {
				if (x == 2) {
					out.println("Yes");
					out.println("1");
					out.println("2");
					out.println("3");
				} else {
					out.println("No");
				}
				return;
			}
			ans = new int[2 * n - 1];
			used = new boolean[2 * n];
			p = 1;
			put(n - 2, 2 * n - 1);
			put(n - 1, x);
			put(n, 1);
			for (int i = 2 * n - 1; i > 0; i--) {
				if (!used[i]) {
					put(n + 1, i);
					break;
				}
			}
			for (int i = 0; i < ans.length; i++) {
				if (ans[i] == 0) {
					putAnything(i);
				}
			}
			out.println("Yes");
			for (int u : ans) {
				out.println(u);
			}
			// show(ans);
		}

		private void put(int pos, int x) {
			ans[pos] = x;
			used[x] = true;
		}

		private void putAnything(int pos) {
			while (p < used.length && used[p]) {
				++p;
			}
			put(pos, p);
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
					st = new StringTokenizer(in.readLine());
				} catch (IOException e) {
					throw new RuntimeException(e);
				}
			}
			return st.nextToken();
		}

		public int nextInt() {
			return Integer.parseInt(next());
		}

	}
}