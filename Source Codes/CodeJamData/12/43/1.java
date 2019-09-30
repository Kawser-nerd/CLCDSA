import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

public class C {

	private static void solve() throws IOException {
		int testCases = nextInt();
		for (int test = 1; test <= testCases; test++) {
			out.print("Case #" + test + ":");
			solveOneTest();
		}
	}

	static final int BIG = 1000000000;

	private static void solveOneTest() throws IOException {
		int n = nextInt();
		int[] see = new int[n - 1];
		for (int i = 0; i < n - 1; i++) {
			see[i] = nextInt() - 1;
		}
		// System.err.println("test");
		// System.err.println(Arrays.toString(see));
		int[] height = new int[n];
		for (int i = 0;; i = see[i]) {
			height[i] = BIG;
			if (i == n - 1) {
				break;
			}
		}
		for (int i = 0; i < n - 1; i = see[i]) {
			if (go(height, see, i, see[i], 0)) {
				out.println(" Impossible");
				return;
			}
		}
		for (int i = 0; i < n - 1; i++) {
			if (see(height, i) != see[i]) {
				System.err.println("FUCK! " + i + " sees " + see(height, i) + ", must see "
						+ see[i]);
				System.err.println(Arrays.toString(see));
				System.err.println(Arrays.toString(height));
			}
		}
		for (int i = 0; i < n; i++) {
			out.print(" " + height[i]);
		}
		out.println();
	}

	static boolean go(int[] height, int[] see, int from, int to, int diff) {
		if (to - from <= 1) {
			return false;
		}
		int last = from;

		for (int i = from + 1; i < to; i++) {
			if (see[i] > to) {
				return true;
			}
			if (see[i] == to) {
				height[i] = height[to] - diff * (to - i) - 1;
				if (go(height, see, last, i, diff + 1)) {
					return true;
				}
				last = i;
			}
		}

		return go(height, see, last, to, diff + 1);
	}

	static int see(int[] height, int from) {
		int ok = from + 1;
		for (int i = from + 2; i < height.length; i++) {
			long dx1 = ok - from;
			long dy1 = height[ok] - height[from];
			long dx2 = i - from;
			long dy2 = height[i] - height[from];
			if (dy2 * dx1 > dy1 * dx2) {
				ok = i;
			}
		}
		return ok;
	}

	public static void main(String[] args) {
		try {
			br = new BufferedReader(new FileReader("C.in"));
			out = new PrintWriter("C.out");
			solve();
			out.close();
		} catch (Throwable e) {
			e.printStackTrace();
			System.exit(239);
		}
	}

	static BufferedReader br;
	static StringTokenizer st;
	static PrintWriter out;

	static String nextToken() throws IOException {
		while (st == null || !st.hasMoreTokens()) {
			String line = br.readLine();
			if (line == null)
				return null;
			st = new StringTokenizer(line);
		}
		return st.nextToken();
	}

	static int nextInt() throws IOException {
		return Integer.parseInt(nextToken());
	}

	static long nextLong() throws IOException {
		return Long.parseLong(nextToken());
	}

	static double nextDouble() throws IOException {
		return Double.parseDouble(nextToken());
	}
}