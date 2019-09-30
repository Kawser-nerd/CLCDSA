import static java.lang.Math.*;
import static java.util.Arrays.*;
import static java.util.Collections.*;
import java.io.*;
import java.math.*;
import java.util.*;

public class C {

	public static void main(String[] args) throws Exception {
		initFileIO(false);
		int cases = nextInt();
		for (int cas = 1; cas <= cases; cas++) {
			int n = nextInt(), lo = nextInt(), hi = nextInt();
			int[] a = new int[n];
			for (int i = 0; i < a.length; i++) {
				a[i] = nextInt();
			}
			System.out.print("Case #" + cas + ": ");
			int ans = -1;
			for (int f = lo; f <= hi; f++) {
				boolean ok = true;
				for (int i = 0; i < a.length; i++) {
					ok &= (a[i] > 0 && f % a[i] == 0) || (f > 0 && a[i] % f == 0);
				}
				if (ok) {
					ans = f;
					break;
				}
			}
			if (ans < 0) {
				System.out.println("NO");
			} else {
				System.out.println(ans);
			}
		}
	}

	static BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st = new StringTokenizer("");

	static void initFileIO(boolean large) throws Exception {
		System.setIn(new FileInputStream("C-" + (large ? "large" : "small-attempt0") + ".in"));
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
