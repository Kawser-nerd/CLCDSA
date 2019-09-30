import static java.util.Arrays.deepToString;

import java.io.*;
import java.math.*;
import java.util.*;

public class A {

	static void solve() {
		int T = nextInt();
		for (int it = 0; it < T; it++) {
			writer.print("Case #" + (it + 1) + ":");
			int n = nextInt();
			int S = 0;
			int[] s = new int[n];
			for (int i = 0; i < n; i++) {
				s[i] = nextInt();
				S += s[i];
			}
			for (int i = 0; i < n; i++) {
				double L = 0.0, R = 1.0;
				for (int iter = 0; iter < 200; iter++) {
					double M = (L + R) / 2;
					double sumY = M;
					for (int j = 0; j < n; j++) {
						if (j != i) {
							sumY += Math.max(0, (s[i] + S * M - s[j]) / S);
						}
					}
					if (sumY > 1) {
						R = M;
					} else {
						L = M;
					}
				}
				writer.printf(" %.9f", L * 100);
			}
			writer.println();
		}
	}

	public static void main(String[] args) throws Exception {
		reader = new BufferedReader(new FileReader("a.in"));
		writer = new PrintWriter("a.out");
		Locale.setDefault(Locale.US);

		setTime();
		solve();
		printTime();
		printMemory();

		writer.close();
	}

	static BufferedReader reader;
	static PrintWriter writer;
	static StringTokenizer tok = new StringTokenizer("");
	static long systemTime;

	static void debug(Object... o) {
		System.err.println(deepToString(o));
	}

	static void setTime() {
		systemTime = System.currentTimeMillis();
	}

	static void printTime() {
		System.err.println("Time consumed: " + (System.currentTimeMillis() - systemTime));
	}

	static void printMemory() {
		System.err.println("Memory consumed: " + (Runtime.getRuntime().totalMemory() - Runtime.getRuntime().freeMemory()) / 1000 + "kb");
	}

	static String next() {
		while (!tok.hasMoreTokens()) {
			String w = null;
			try {
				w = reader.readLine();
			} catch (Exception e) {
				e.printStackTrace();
			}
			if (w == null)
				return null;
			tok = new StringTokenizer(w);
		}
		return tok.nextToken();
	}

	static int nextInt() {
		return Integer.parseInt(next());
	}

	static long nextLong() {
		return Long.parseLong(next());
	}

	static double nextDouble() {
		return Double.parseDouble(next());
	}

	static BigInteger nextBigInteger() {
		return new BigInteger(next());
	}
}