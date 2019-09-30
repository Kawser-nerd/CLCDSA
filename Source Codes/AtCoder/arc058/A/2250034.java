import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.ArrayDeque;
import java.util.HashSet;
import java.util.InputMismatchException;
import java.util.Map;
import java.util.Queue;
import java.util.Set;
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

	static class TaskX {
		public void solve(int testNumber, InputReader in, PrintWriter out) {

			String n = in.nextString();
			int k = in.nextInt();
			Set<String> strs = new HashSet<>();
			for (int i = 0; i < 10; i++) {
				strs.add(String.valueOf(i));
			}
			for (int i = 0; i < k; i++) {
				strs.remove(in.nextString());
			}

			Queue<String> q = new ArrayDeque<>();
			for (String str : strs) {
				q.add(str);
			}

			int ans = Integer.MAX_VALUE;
			while (!q.isEmpty()) {
				String s = q.remove();
				if (s.length() > n.length()+1) {
					break;
				}
				int t = Integer.parseInt(s);
				if (t >= Integer.parseInt(n) && t <= ans) {
					ans = t;
				}

				for (String str : strs) {
					q.add(s+str);
				}

			}

			out.println(ans);

		}

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