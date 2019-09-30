import static java.util.Arrays.deepToString;

import java.io.*;
import java.math.*;
import java.util.*;

public class C1 {
	static int n, P, cnt;
	static long[] a;
	static Random rng = new Random(0);
	static boolean found;
	static int[][] ans = new int[2][];

	static void solve(int test) {
		n = nextInt();
		a = new long[n];
		for (int i = 0; i < n; i++) {
			a[i] = nextLong();
		}

		cnt = 10;
		P = BigInteger.valueOf((long) (1e7)).nextProbablePrime().intValue();
		found = false;

		int[][] arr = new int[P][];
		// HashMap<Long, ArrayList<int[]>> map = new HashMap<>();
		debug("Test: " + test);
		while (!found) {
			for (int iter = 0; !found; iter++) {
				int[] ind = new int[cnt];
				long sum = 0;
				for (int i = 0; i < cnt; i++) {
					inner: while (true) {
						ind[i] = rng.nextInt(500);
						for (int j = 0; j < i; j++) {
							if (ind[i] == ind[j])
								continue inner;
						}
						break;
					}
					sum += a[ind[i]];
				}
				sum %= P;
				int sum_rem = (int) sum;
				Arrays.sort(ind);
				int[] lst = arr[sum_rem];
				if (lst == null) {
					arr[sum_rem] = ind;
				} else {
					compare(lst, ind);
					arr[sum_rem] = ind;
				}
			}
		}

		writer.printf("Case #%d:\n", test);
		long diff = 0;
		for (int subset = 0; subset < 2; subset++) {
			for (int i : ans[subset]) {
				writer.print(a[i] + " ");
				diff += subset == 0 ? a[i] : -a[i];
			}
			writer.println();
		}
		writer.println();
		debug(diff);
	}

	static void compare(int[] ind1, int[] ind2) {
		for (int i = 0; i < cnt; i++) {
			if (ind1[i] != ind2[i])
				break;
			if (i == cnt - 1)
				return;
		}
		long diff = 0;
		for (int i = 0; i < cnt; i++) {
			diff += a[ind1[i]] - a[ind2[i]];
		}
		if (diff == 0) {
			found = true;
			ans[0] = ind1;
			ans[1] = ind2;
		}
	}

	public static void main(String[] args) throws Exception {
		reader = new BufferedReader(new FileReader("c.in"));
		writer = new PrintWriter("c.out");

		setTime();
		int T = nextInt();
		for (int it = 0; it < T; it++) {
			solve(it + 1);
		}
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