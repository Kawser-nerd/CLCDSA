import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.InputMismatchException;
import java.util.List;
import java.util.Map;
import java.util.StringTokenizer;
import java.util.stream.Stream;

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
	static long LINF = 1L << 55;
	static int MOD = 1000000007;
	static int[] mh4 = { 0, -1, 1, 0 };
	static int[] mw4 = { -1, 0, 0, 1 };
	static int[] mh8 = { -1, -1, -1, 0, 0, 1, 1, 1 };
	static int[] mw8 = { -1, 0, 1, -1, 1, -1, 0, 1 };

	static class TaskX {

		public void solve(int testNumber, InputReader in, PrintWriter out) {

			int n = in.nextInt();
			Map<Character, Character> map = initMap();

			char[][] s = new char[n][];
			for (int i = 0; i < n; i++) {
				s[i] = in.nextString().toCharArray();
			}

			List<Character>[] list = new ArrayList[n];
			list = Stream.generate(ArrayList::new).limit(n).toArray(List[]::new);

			for (int i = 0; i < n; i++) {
				for (char c : s[i]) {
					if (map.containsKey(Character.toLowerCase(c))) {
						list[i].add(map.get(Character.toLowerCase(c)));
					}
				}
			}

			boolean isFirst = true;
			for (int i = 0; i < n; i++) {
				if (list[i].size() == 0) continue;
				if (!isFirst) {
					out.print(" ");
				}
				isFirst = false;
				for (char cc : list[i]) {
					out.print(cc);
				}
			}
			out.print("\n");
		}
	}

	static Map<Character, Character> initMap() {
		HashMap<Character, Character> map = new HashMap<>();
		map.put('b', '1');
		map.put('c', '1');
		map.put('d', '2');
		map.put('w', '2');
		map.put('t', '3');
		map.put('j', '3');
		map.put('f', '4');
		map.put('q', '4');
		map.put('l', '5');
		map.put('v', '5');
		map.put('s', '6');
		map.put('x', '6');
		map.put('p', '7');
		map.put('m', '7');
		map.put('k', '8');
		map.put('h', '8');
		map.put('g', '9');
		map.put('n', '9');
		map.put('z', '0');
		map.put('r', '0');
		return map;
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

		public int[] nextIntArrayDec(int n) {
			int[] res = new int[n];
			for (int i = 0; i < n; i++) {
				res[i] = nextInt() - 1;
			}
			return res;
		}

		public int[] nextIntArray1Index(int n) {
			int[] res = new int[n + 1];
			for (int i = 0; i < n; i++) {
				res[i + 1] = nextInt();
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

		public long[] nextLongArrayDec(int n) {
			long[] res = new long[n];
			for (int i = 0; i < n; i++) {
				res[i] = nextLong() - 1;
			}
			return res;
		}

		public long[] nextLongArray1Index(int n) {
			long[] res = new long[n + 1];
			for (int i = 0; i < n; i++) {
				res[i + 1] = nextLong();
			}
			return res;
		}

		public double[] nextDoubleArray(int n) {
			double[] res = new double[n];
			for (int i = 0; i < n; i++) {
				res[i] = nextDouble();
			}
			return res;
		}

		public InputReader(InputStream inputStream) {
			in = new BufferedReader(new InputStreamReader(inputStream));
			tok = new StringTokenizer("");
		}
	}

} Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.