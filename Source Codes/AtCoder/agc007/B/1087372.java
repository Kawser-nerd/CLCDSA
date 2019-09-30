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
		public void solve(int testNumber, FastScanner in, PrintWriter out) {
			int n = in.nextInt();
			int[] p = new int[n];
			for (int i = 0; i < n; i++) {
				p[i] = in.nextInt() - 1;
			}
			int[] a = new int[n];
			int[] b = new int[n];
			int[] inv = new int[n];
			for (int i = 0; i < n; i++) {
				inv[p[i]] = i;
			}
			for (int i = 0; i < n; i++) {
				a[i] = n * i + 1;
				b[i] = n * (n - i - 1) + 1 + inv[i];
			}
			println(out, a);
			println(out, b);
		}

		private void println(PrintWriter out, int[] a) {
			for (int i = 0; i < a.length; i++) {
				if (i > 0) {
					out.print(" ");
				}
				out.print(a[i]);
			}
			out.println();
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