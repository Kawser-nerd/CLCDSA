import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;
import java.util.Map;
import java.util.HashMap;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */
public class Main {
	public static void main(String[] args) {
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		FastScanner in = new FastScanner(inputStream);
		PrintWriter out = new PrintWriter(outputStream);
		B_PowersOfTwo solver = new B_PowersOfTwo();
		solver.solve(1, in, out);
		out.close();
	}

	static class B_PowersOfTwo {
		public void solve(int testNumber, FastScanner in, PrintWriter out) {
			int n = in.nextInt();
			int[] a = new int[n];
			for (int i = 0; i < n; i++) {
				a[i] = in.nextInt();
			}
			Arrays.sort(a);
			Map<Integer, Integer> m = new HashMap<>();
			for (int x : a) {
				addOne(m, x);
			}
			int ans = 0;
			for (int i = n - 1; i >= 0; i--) {
				int x = a[i];
				if (!m.containsKey(x)) {
					continue;
				}
				removeOne(m, x);
				for (int bit = 30; bit >= 0; bit--) {
					int y = (1 << bit) - x;
					if (m.containsKey(y)) {
						removeOne(m, y);
						++ans;
						break;
					}
				}
			}
			out.println(ans);
		}

		private void addOne(Map<Integer, Integer> m, int x) {
			int v = 0;
			if (m.containsKey(x)) {
				v = m.get(x);
			}
			m.put(x, v + 1);
		}

		private void removeOne(Map<Integer, Integer> m, int x) {
			int v = m.get(x);
			if (v == 1) {
				m.remove(x);
			} else {
				m.put(x, v - 1);
			}
		}

	}

	static class FastScanner {
		private BufferedReader in;
		private StringTokenizer st;

		public FastScanner(InputStream stream) {
			in = new BufferedReader(new InputStreamReader(stream));
		}

		public String next() {
			while (st == null || !st.hasMoreTokens()) {
				try {
					String rl = in.readLine();
					if (rl == null) {
						return null;
					}
					st = new StringTokenizer(rl);
				} catch (IOException e) {
					throw new RuntimeException(e);
				}
			}
			return st.nextToken();
		}

		public int nextInt() {
			return Integer.parseInt(next());
		}

	}
}