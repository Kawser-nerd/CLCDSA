import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.Arrays;
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

		static String[] moji = {"A", "B", "X", "Y"};
		static int len = (int)Math.pow(moji.length, 2);

		public void solve(int testNumber, InputReader in, PrintWriter out) {

			int n = in.nextInt();
			String str = in.nextString();

			String[] ptns = new String[len];

			int l = 0;
			for (int i = 0; i < moji.length; i++) {
				for (int j = 0; j < moji.length; j++) {
					ptns[l] = moji[i]+moji[j];
					l++;
				}
			}

			Set<Integer> count = new HashSet<>();
			for (int i = 0; i < ptns.length; i++) {
				for (int j = 0; j < ptns.length; j++) {
					String tmpstr = new String(str);
					if (ptns[i].equals(ptns[j])) {
						continue;
					}
					tmpstr = tmpstr.replaceAll(ptns[i], "R");
					tmpstr = tmpstr.replaceAll(ptns[j], "L");
					count.add(tmpstr.length());
				}
			}
			Integer[] ans = count.toArray(new Integer[count.size()]);
			Arrays.sort(ans);
			System.out.println(ans[0]);
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