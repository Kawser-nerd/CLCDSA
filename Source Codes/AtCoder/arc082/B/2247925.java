import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.InputMismatchException;
import java.util.Map;
import java.util.StringTokenizer;
import java.util.TreeMap;

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

	static int count = 0;
	static class TaskX {
		public void solve(int testNumber, InputReader in, PrintWriter out) {

			int n = in.nextInt();
			int[] p = new int[n+1];
			for (int i = 0; i < n; i++) {
				p[i] = in.nextInt();
			}
			p[n] = -1;
			boolean[] isMatch = new boolean[n+1];
			for (int i = 0; i < n; i++) {
				if (p[i] == i+1) isMatch[i] = true;
			}

			for (int ban = 0; ban < n; ban++) {
				if (ban == 0) {
					if (isMatch[0]) {
						swap(p, 0, 1);
						ban++;
					}
				} else {
					if (isMatch[ban] && isMatch[ban+1]) {
						swap(p, ban, ban+1);
						ban++;
					} else if (isMatch[ban] && !isMatch[ban+1]) {
						swap(p, ban-1, ban);
					}
				}
			}
			out.println(count);

		}
	}
	static void swap(int[] p, int i, int j) {
		int tmp = p[i];
		p[i] = p[j];
		p[j] = tmp;
		count++;
	}

	static class ArrayUtils {
		public static Map<Integer, Integer> getCountMap(int[] array) {
			Map<Integer, Integer> map = new TreeMap<>();
			for (int x : array)
				map.merge(x, 1, Integer::sum);
			return map;
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