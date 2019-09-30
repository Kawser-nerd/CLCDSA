import static java.lang.Math.*;
import static java.util.Arrays.*;
import static java.util.Collections.*;
import java.io.*;
import java.math.*;
import java.util.*;

public class B {

	public static void main(String[] args) throws Exception {
		initFileIO(true);
		int cases = nextInt();
		for (int cas = 1; cas <= cases; cas++) {
			int L = nextInt();
			long t = nextLong();
			int N = nextInt(), C = nextInt();
			long[] a = new long[N];
			for (int i = 0; i < C; i++) {
				a[i] = nextLong() * 2;
			}
			for (int i = C; i < a.length;) {
				for (int j = 0; j < C && i < a.length; j++, i++) {
					a[i] = a[j];
				}
			}

			long x = t;
			int index = -1;
			long ans = 0;
			for (int i = 0; i < a.length; i++) {
				if (x - a[i] >= 0) {
					x -= a[i];
					ans += a[i];
				} else {
					index = i;
					ans += x;
					break;
				}
			}
			if (index >= 0) {
				long rem = a[index] - x;
				long sum = rem;
				ArrayList<Long> dists = new ArrayList<Long>();
				dists.add(rem);

				for (int i = index + 1; i < a.length; i++) {
					dists.add(a[i]);
					sum += a[i];
				}

				Long[] D = dists.toArray(new Long[0]);
				sort(D);
				int boosters = L;
				long distFast = 0;
				for (int i = D.length - 1; i >= 0 && boosters > 0; i--, boosters--) {
					distFast += D[i];
				}
				ans += distFast / 2 + (sum - distFast);
			}
			System.out.println("Case #" + cas + ": " + ans);
		}
	}

	static BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st = new StringTokenizer("");

	static void initFileIO(boolean large) throws Exception {
		System.setIn(new FileInputStream("B-" + (large ? "large" : "small-attempt0") + ".in"));
		System.setOut(new PrintStream("output"));
		in = new BufferedReader(new InputStreamReader(System.in));
	}

	static String next() throws Exception {
		while (!st.hasMoreTokens()) {
			String s = in.readLine();
			if (s == null)
				return null;
			st = new StringTokenizer(s);
		}
		return st.nextToken();
	}

	static int nextInt() throws Exception {
		return Integer.parseInt(next());
	}

	static long nextLong() throws Exception {
		return Long.parseLong(next());
	}

	static double nextDouble() throws Exception {
		return Double.parseDouble(next());
	}
}
