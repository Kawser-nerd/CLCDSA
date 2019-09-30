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
	static int TATE = 1;
	static int YOKO = 0;

	static class TaskX {
		public void solve(int testNumber, InputReader in, PrintWriter out) {

			int n = in.nextInt();
			char[] s1 = in.nextString().toCharArray();
			char[] s2 = in.nextString().toCharArray();

			List<Integer> list = new ArrayList<>();
			for (int i = 0; i < n; i++) {
				if (s1[i] == s2[i]) {
					list.add(TATE);
				} else {
					list.add(YOKO);
					i++;
				}
			}

			long ans = 0;

			if (list.get(0) == TATE) {
				ans += 3;
			} else {
				ans += 6;
			}

			for (int i = 1; i < list.size(); i++) {
				if (list.get(i) == TATE) {
					if (list.get(i-1) == TATE) {
						ans = ans*2%MOD;
					} else {
						ans = ans*1%MOD;
					}
				} else {
					if (list.get(i-1) == TATE) {
						ans = ans*2%MOD;
					} else {
						ans = ans*3%MOD;
					}
				}
			}

			out.println(ans);

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