import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.HashSet;
import java.util.InputMismatchException;
import java.util.Map;
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

			int a = in.nextInt();
			int b = in.nextInt();
			int c = in.nextInt();
			int d = in.nextInt();
			int e = in.nextInt();
			int f = in.nextInt();
			Set<Integer> waters = new HashSet<>();
			Set<Integer> sugars = new HashSet<>();
			for (int i = 0; i <= f; i++) {
				for (int j = 0; j <= f; j++) {
					if ((100*i*a+100*j*b) <= f) {
						waters.add(100*i*a+100*j*b);
					}
					if ((i*c+j*d) <= f) {
						sugars.add(i*c+j*d);
					}
				}
			}

			double ans = 0;
			int answa = 0;
			int anssu = 0;

			for (int wa : waters) {
				for (int su : sugars) {
					if (wa + su > f || e * wa < su * 100 || wa + su == 0) {
						continue;
					}
					if (ans <= (100 * su/((double)wa+su))) {
						ans = (100 * su/((double)wa+su));
						answa = wa;
						anssu = su;
					}
				}
			}
			System.out.println((answa+anssu) +" " + anssu);
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