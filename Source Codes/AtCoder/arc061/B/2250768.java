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

	static int[] ta = {-1,0,1,-1,0,1,-1,0,1};
	static int[] tb = {1,1,1,0,0,0,-1,-1,-1};

	static class TaskX {
		public void solve(int testNumber, InputReader in, PrintWriter out) {

			long h = in.nextLong();
			long w = in.nextLong();
			int n = in.nextInt();

			Map<Long, Integer> map = new HashMap<>();
			for (int i = 0; i < n; i++) {

				int a = in.nextInt();
				int b = in.nextInt();

				for (int j = 0; j < 9; j++) {
					int ma = a + ta[j];
					int mb = b + tb[j];
					if (2 <= ma && ma <= h-1 && 2 <= mb && mb <= w-1) {
						long hash = hash(ma, mb);
						int v = map.containsKey(hash) ? map.get(hash) : 0;
						map.put(hash, v+1);
					}
				}
			}

			long[] count = new long[10];
			for (int v : map.values()) {
				count[v]++;
			}

			count[0] = (h-2)*(w-2)-map.size();

			for (int i = 0; i < count.length; i++) {
				out.println(count[i]);
			}

		}
		static long hash(int ma, int mb) {
			return (long)ma<<32|mb;
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