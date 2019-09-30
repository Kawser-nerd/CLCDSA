import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.InputMismatchException;
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

	static int INF = 1 << 30;
	static long LINF = 1L << 55;
	static int MOD = 1000000007;
	static int[] mh4 = { 0, -1, 1, 0 };
	static int[] mw4 = { -1, 0, 0, 1 };
	static int[] mh8 = { -1, -1, -1, 0, 0, 1, 1, 1 };
	static int[] mw8 = { -1, 0, 1, -1, 1, -1, 0, 1 };

	static class TaskX {

		public void solve(int testNumber, InputReader in, PrintWriter out) {

			int k = in.nextInt();
			char[] s = in.nextString().toCharArray();

			TreeMap<Pair, Integer> map = new TreeMap<>();

			// ?????????????????????
			for (int i = 0; i < (1 << k); i++) {
				StringBuffer r = new StringBuffer();
				StringBuffer b = new StringBuffer();

				for (int j = 0; j < k; j++) {
					if (((i >> j) & 1) == 1) {
						r.append(s[k+j]);
					} else {
						b.append(s[k+j]);
					}
				}
				map.merge(new Pair(r.reverse().toString(), b.reverse().toString()), 1, Integer::sum);

			}

			long ans = 0;

			// ????????
			for (int i = 0; i < (1 << k); i++) {
				StringBuffer red = new StringBuffer();
				StringBuffer blue = new StringBuffer();

				for (int j = 0; j < k; j++) {
					if (((i >> j) & 1) == 1) {
						red.append(s[j]);
					} else {
						blue.append(s[j]);
					}
				}

				if (map.get(new Pair(red.toString(), blue.toString())) != null) {
					ans += map.get(new Pair(red.toString(), blue.toString()));
				}

			}
			out.println(ans);

		}

		static class Pair<U, V> implements Comparable<Pair<U, V>> {
			public final U first;
			public final V second;

			public static <U, V> Pair<U, V> makePair(U first, V second) {
				return new Pair<U, V>(first, second);
			}

			private Pair(U first, V second) {
				this.first = first;
				this.second = second;
			}

			public boolean equals(Object o) {
				if (this == o) {
					return true;
				}
				if (o == null || getClass() != o.getClass()) {
					return false;
				}

				Pair pair = (Pair) o;

				return !(first != null ? !first.equals(pair.first)
						: pair.first != null)
						&& !(second != null ? !second.equals(pair.second)
								: pair.second != null);
			}

			public int hashCode() {
				int result = first != null ? first.hashCode() : 0;
				result = 31 * result + (second != null ? second.hashCode() : 0);
				return result;
			}

			public String toString() {
				return "(" + first + "," + second + ")";
			}

			public int compareTo(Pair<U, V> o) {
				int value = ((Comparable<U>) first).compareTo(o.first);
				if (value != 0) {
					return value;
				}
				return ((Comparable<V>) second).compareTo(o.second);
			}

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

} Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.