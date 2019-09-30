import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.InputMismatchException;
import java.util.List;
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

	static int INF = 1 << 30;
	static long LINF = 1L << 55;
	static int MOD = 1000000007;
	static int[] mh4 = { 0, -1, 1, 0 };
	static int[] mw4 = { -1, 0, 0, 1 };
	static int[] mh8 = { -1, -1, -1, 0, 0, 1, 1, 1 };
	static int[] mw8 = { -1, 0, 1, -1, 1, -1, 0, 1 };

	static class TaskX {

		int n;
		public void solve(int testNumber, InputReader in, PrintWriter out) {

			n = in.nextInt();
			List<P> list = new ArrayList<>();
			long suma = 0, sumb = 0;
			for (int i = 0; i < n; i++) {
				long a = in.nextLong();
				long b = in.nextLong();
				list.add(new P(a, i));
				list.add(new P(b, i));
				suma += a; sumb += b;
			}

			Collections.sort(list);

			long ans = f(list.toArray(new P[0]));

			ans = Math.min(ans, suma);
			ans = Math.min(ans, sumb);

			out.println(ans);

		}

		long f(P[] p) {
			long ret = LINF, base = 0;
			Map<Integer, Integer> map = new TreeMap<>();
			boolean ok = false;
			for (int i = 0; i < n; i++) {
				base += p[i].num;
				map.merge(p[i].idx, 1, Integer::sum);
				if (map.get(p[i].idx) >= 2) ok = true;
			}
			if (ok) {
				return base;
			}

			Map<Integer, Integer> tmap = new TreeMap<>(map);
			long tmp = base;
			tmp -= p[n-1].num;
			tmap.merge(p[n-1].idx, -1, Integer::sum);
			tmp += p[n].num;
			tmap.merge(p[n].idx, 1, Integer::sum);
			if (tmap.get(p[n].idx) >= 2) {
				ret = Math.min(ret, tmp);
			}

			tmap = new TreeMap<>(map);
			tmp = base;
			tmp -= p[n-1].num;
			tmap.merge(p[n-1].idx, -1, Integer::sum);
			tmp += p[n+1].num;
			tmap.merge(p[n+1].idx, 1, Integer::sum);
			if (tmap.get(p[n+1].idx) >= 2) {
				ret = Math.min(ret, tmp);
			}

			tmap = new TreeMap<>(map);
			tmp = base;
			tmp -= p[n-2].num;
			tmap.merge(p[n-2].idx, -1, Integer::sum);
			tmp += p[n].num;
			tmap.merge(p[n].idx, 1, Integer::sum);
			if (tmap.get(p[n].idx) >= 2) {
				ret = Math.min(ret, tmp);
			}

			return ret;
		}
	}

	static class P implements Comparable<P> {
		long num;
		int idx;

		public P(long num, int idx) {
			super();
			this.num = num;
			this.idx = idx;
		}

		@Override
		public String toString() {
			return "P [num=" + num + ", idx=" + idx + "]";
		}

		@Override
		public int compareTo(P o) {
			return Long.compare(this.num, o.num);
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

}