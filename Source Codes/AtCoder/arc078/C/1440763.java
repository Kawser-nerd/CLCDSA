import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.io.PrintStream;
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
		TaskE solver = new TaskE();
		solver.solve(1, in, out);
		out.close();
	}

	static class TaskE {
		FastScanner in;
		PrintWriter out;
		boolean LOCAL_RUN = false;
		final String N = "123";

		public void solve(int testNumber, FastScanner in, PrintWriter out) {
			this.in = in;
			this.out = out;

			if (send("" + (int) 1e9)) {
				int ans = 1;
				while (!send("" + (ans + 1))) {
					ans *= 10;
				}
				out.println("! " + ans);
				out.flush();
				return;
			}

			int len = 1;
			while (send("" + (int) (Math.pow(10, len - 1)))) {
				++len;
			}
			--len;

			int l = (int) (Math.pow(10, len - 1));
			int r = (int) (Math.pow(10, len)) - 1;
			while (r - l > 1) {
				int m = (l + r) / 2;
				if (!send("" + m + "0")) {
					l = m;
				} else {
					r = m;
				}
			}

			out.println("! " + r);
			out.flush();
		}

		private boolean send(String s) {
			if (LOCAL_RUN) {
				boolean u = Long.parseLong(s) <= Long.parseLong(N);
				boolean v = s.compareTo(N) <= 0;
				boolean res = (u && v) || (!u && !v);
				System.out.println(s + " " + res);
				return res;
			}
			out.println("? " + s);
			out.flush();
			return in.next().equals("Y");
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

	}
}