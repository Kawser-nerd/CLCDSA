import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.HashMap;
import java.util.InputMismatchException;
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
	static int modP = 1000000007;

	static P[] p;
	static Map<Long, Long> memo = new HashMap<>();
	static int N, W;
	static class TaskX {
		public void solve(int testNumber, InputReader in, PrintWriter out) {

			N = in.nextInt();
			W = in.nextInt();
			p = new P[N];
			for (int i = 0; i < N; i++) {
				int w = in.nextInt(), v = in.nextInt();
				p[i] = new P(w, v);
			}

			out.println(func(0, 0));

		}
	}

	static long func(int d, int j) {
		long key = (long)d << 32 | j;
		if (d == N) {
			memo.put(key, 0L);
			return 0;
		}
		if (memo.containsKey(key)) {
			return memo.get(key);
		}

		long ret = 0;

		if (j + p[d].w <= W) {
			ret = Math.max(func(d + 1, j), func(d + 1, j + p[d].w) + p[d].v);
		} else {
			ret = func(d + 1, j);
		}
		memo.put(key, ret);
		return ret;
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

}