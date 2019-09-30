import static java.lang.Math.max;
import static java.lang.Math.min;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Set;
import java.util.StringTokenizer;

public class Dstupid {

	private static void solve() throws IOException {
		int testCases = nextInt();
		for (int test = 1; test <= testCases; test++) {
			out.print("Case #" + test + ": ");
			solveOneTest();
		}
	}

	private static void solveOneTest() throws IOException {
		int k = nextInt();
		String s = nextToken();
		Set<Character> all = new HashSet<Character>();
		for (int i = 0; i < s.length(); i++) {
			all.add(s.charAt(i));
			int index = FROM.indexOf(s.charAt(i));
			if (index >= 0) {
				all.add(TO.charAt(index));
			}
		}
		Map<Character, Integer> out1 = new HashMap<Character, Integer>();
		Map<Character, Integer> out2 = new HashMap<Character, Integer>();
		for (char c : all) {
			out1.put(c, 0);
			out2.put(c, 0);
		}

		Set<String> set2 = new HashSet<String>();
		for (int i = 0; i < s.length() - 1; i++) {
			int index1 = FROM.indexOf(s.charAt(i));
			int index2 = FROM.indexOf(s.charAt(i + 1));
			char[] arr1;
			if (index1 < 0) {
				arr1 = new char[] { s.charAt(i) };
			} else {
				arr1 = new char[] { s.charAt(i), TO.charAt(index1) };
			}
			char[] arr2;
			if (index2 < 0) {
				arr2 = new char[] { s.charAt(i + 1) };
			} else {
				arr2 = new char[] { s.charAt(i + 1), TO.charAt(index2) };
			}

			for (char c1 : arr1) {
				for (char c2 : arr2) {
					set2.add(c1 + "" + c2);
				}
			}
		}
		for (String ok : set2) {
			out1.put(ok.charAt(0), out1.get(ok.charAt(0)) + 1);
			out2.put(ok.charAt(1), out2.get(ok.charAt(1)) + 1);
		}
		int best = Integer.MAX_VALUE;
		for (char first : all) {
			for (char last : all) {
				int count = 0;
				for (char c : all) {
					int x = out1.get(c), y = out2.get(c);
					if (c == first) {
						y++;
					}
					if (c == last) {
						x++;
					}
					count += max(1, max(x, y));
				}
				best = min(best, count);
			}
		}
		out.println(best);
	}

	static String FROM = "oieastbg";
	static String TO = "01345789";

	public static void main(String[] args) {
		try {
			br = new BufferedReader(new FileReader("D.in"));
			out = new PrintWriter("D.out");
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