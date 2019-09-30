import static java.lang.Math.min;
import static java.util.Arrays.copyOf;

import java.io.*;
import java.util.*;

public class C {

	private static void solve() throws IOException {
		// test();
		int testCases = nextInt();
		int passed = 1;
		for (int test = passed; test <= testCases; test++) {
			out.println("Case #" + test + ":");
			solveOneTest();
			out.flush();
		}
	}

	private static void solveOneTest() throws IOException {
		int n = nextInt();
		long[] s = new long[n];
		for (int i = 0; i < n; i++) {
			s[i] = nextLong();
		}
		s = copyOf(s, min(s.length, 50));
		n = s.length;
		long[] answer = solveStupid(s);
		long answer1 = answer[0], answer2 = answer[1];
		long both = answer1 & answer2;
		answer1 ^= both;
		answer2 ^= both;
		boolean first = true;
		for (int i = 0; i < n; i++) {
			if ((answer1 & (1L << i)) != 0) {
				if (!first) {
					out.print(' ');
				} else {
					first = false;
				}
				out.print(s[i]);
			}
		}
		out.println();
		first = true;
		for (int i = 0; i < n; i++) {
			if ((answer2 & (1L << i)) != 0) {
				if (!first) {
					out.print(' ');
				} else {
					first = false;
				}
				out.print(s[i]);
			}
		}
		out.println();
	}

	static long[] genTest() {
		long[] s = new long[50];
		for (int i = 0; i < 50; i++) {
			s[i] = rng.nextInt(1000000000) * 1000L + rng.nextInt(1000);
		}
		return s;
	}

	static void test() {
		System.err.println(1L << 50);
		while (true) {
			solveStupid(genTest());
			System.err.println("good");
		}
	}

	static Random rng = new Random(58);

	static long[] solveStupid(long[] s) {
		int it = 0;
		while (true) {
			if ((++it & 0xFFFFF) == 0) {
				System.err.println(it + " " + map.size());
			}
			long mask = rng.nextLong();
			mask &= (1L << s.length) - 1;
			long sum = 0;
			for (int i = 0; i < s.length; i++) {
				if ((mask & (1L << i)) != 0) {
					sum += s[i];
				}
			}
			Long inMap = map.get(sum);
			if (inMap == null) {
				map.put(sum, mask);
			} else {
				if (inMap.longValue() != mask) {
					map.clear();
					return new long[] { mask, inMap.longValue() };
				}
			}
		}
	}

	static Map<Long, Long> map = new HashMap<Long, Long>(10000000);

	public static void main(String[] args) {
		try {
			br = new BufferedReader(new FileReader("c.in"));
			out = new PrintWriter("c.out");
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